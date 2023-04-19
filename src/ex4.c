#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bstree.h"
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
    //FILE *fp = popen("sort -r words.txt", "r");  //bad
    FILE *fp = popen("shuf words.txt", "r");   //average
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
    struct bstree *tree;
    tree = bstree_create(words[0], 0);
    int k = 1;
    int rand_test = getrand(0, STEPS / 20 - 1);
    char tests[MAX_BUFFER_SIZE];
    while (  i < STEPS )
    {
        if ( i == rand_test )
        {
            memcpy(tests, words[i], MAX_BUFFER_SIZE);
        }
        bstree_add(tree, words[i], i);
        if ( i % ( ( STEPS - 1 ) / 20 ) == 0 && i != 0 )
        {
            double start = wtime();
            struct bstree *tresp = bstree_min(tree);
            double tend = wtime() - start;
            if ( DEBUG )
            {
                printf("i = %d\n", i);
                printf("Tree: %lf\n", tend);
                printf("%d %s\n", tresp->value, tresp->key);
                printf("========================\n");
            } else printf("%d\t%lf\n", i, tend);
            k++;
            rand_test = getrand(i, STEPS / 20 * k - 1);
        }
        i++;
    }
}