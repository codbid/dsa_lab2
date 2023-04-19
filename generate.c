#include <stdio.h>

int main(){
    char aplha[] = "abcdefghijklmnopqrstuvwxyz";
    FILE *fp = fopen("text.txt", "w");
    for ( int i = 0; i < 26; i++) {
        for ( int j = 0; j < 26; j++) {
            for ( int k = 0; k < 26; k++) {
                for ( int l = 0; l < 26; l++) {
                    fprintf(fp, "%c%c%c%c\n", aplha[i],  aplha[j], aplha[k], aplha[l]);
                }
            }
        }
    }
    fclose(fp);
}