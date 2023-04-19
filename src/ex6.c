#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hashtab.h"
#include <sys/time.h>

#define MAX_BUFFER_SIZE 33
#define STEPS 200001
#define DEBUG 0

double wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

int getrand(int min, int max)
{
    return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}

int main()
{
    char words[STEPS][MAX_BUFFER_SIZE];
    FILE *fp = popen("shuf words.txt", "r");
    for (int i = 0; i < STEPS; i++)
    {
        char *buffer = malloc(MAX_BUFFER_SIZE * sizeof(char));
        fgets(buffer, MAX_BUFFER_SIZE, fp);
        buffer = strtok(buffer, "\n");
        memcpy(words[i], buffer, MAX_BUFFER_SIZE);
        free(buffer);
    }
    fclose(fp);
    int i = 0;
    struct listnode *hashtab[STEPS];
    hashtab_init(hashtab);
    int k = 1;
    int rand_test = getrand(0, STEPS / 20 - 1);
    char tests[MAX_BUFFER_SIZE];
    int colisions = 0;
    while (  i < STEPS )
    {
        if ( i == rand_test )
        {
            memcpy(tests, words[i], MAX_BUFFER_SIZE);
        }
        hashtab_add(hashtab, words[i], i, &colisions);
        if ( i % ( ( STEPS - 1 ) / 20 ) == 0 && i != 0 )
        {
            double start = wtime();
            int hresp = hashtab_lookup(hashtab, tests)->value;
            double hend = wtime() - start;
            if ( DEBUG )
            {
                printf("i = %d\n", i);
                printf("%d %s\n", hresp, tests);
                printf("Hash: %lf\n", hend);
                printf("Colisions: %d\n", colisions);
                printf("========================\n");
            } else printf("%d\t%lf\t%d\n", i, hend, colisions);
            k++;
            rand_test = getrand(i, STEPS / 20 * k - 1);
        }
        i++;
    }
}