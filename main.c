#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void decodiere(FILE *geheim, FILE *goodpad, FILE *ausgabe){
    int a,b;
    if(geheim == NULL || goodpad == NULL || ausgabe == NULL){
        printf("konnte datei nicht oeffnen\n");
        return 1;
    }
    else{
        while(1){
            a = fgetc(geheim);
            if(a == EOF){
                break;
            }
            b = fgetc(goodpad);
            if(b == EOF){
                rewind(goodpad);
            }
            fputc(a^b, ausgabe);
        }

    }
}

int main(int argc, char* argv[]) {
    if(argc < 2 || argc > 4){
        printf("Falsche Eingabe!\n");
        printf("cipher.exe <geheim> <goodpad> (<ausgabe>)");
        exit(0);
    }

    FILE *geheim;
    FILE *goodpad;
    FILE *ausgabe;
    int i, temp;

    geheim = fopen(argv[1], "rb");
    goodpad = fopen(argv[2], "rb");

    if(argv[3] != NULL) {
        ausgabe = fopen(argv[3], "wb");
    } else {
        ausgabe = fopen(strcat(argv[1],".cip"), "wb");
    }

    decodiere(geheim, goodpad, ausgabe);

    return 0;
}
