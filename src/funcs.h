#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SNAKES 5
#define LADDERS 5

#define KNRM "\x1B[0m"
#define KRED "\x1B[31m"
#define KGRN "\x1B[32m"
#define KYEL "\x1B[33m"
#define KBLU "\x1B[34m"
#define KMAG "\x1B[35m"
#define KCYN "\x1B[36m"
#define KWHT "\x1B[37m"

struct board
{
    int a[3][3];
} initial;

void print_array(int *array, int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d\n", array[i]);
    }
}

int randrange(int start, int end)
{
    return ((rand() % (end - start + 1)) + start);
}
