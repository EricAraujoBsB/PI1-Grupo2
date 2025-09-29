#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char buffer[] = "1FF0023";
    int i = 0;
    while(i<strlen(buffer)){
        if(buffer[i] == '1'){
            printf("percorrendo x cm\n");
            char comprimento[4] = "";
            i++;
            for(int j=0; j<4; j++){
                comprimento[j] = buffer[i];
                i++;
                printf("comprimento = %s\n", comprimento);
                printf("percorrendo o comprimento %d\n", j);
                printf("%d\n", i);
            }    
        }else if(buffer[i] == '2'){
            printf("virando à direita\n");
        }else if(buffer[i] == '3'){
            printf("virando à esquerda\n");
        }
    i++;
    printf("%d\n", i);
    }
}
