#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funcs.h"

void get_rules(int ladders[LADDERS][2], int snakes[SNAKES][2])
{
    printf("\n\nSnakes And Ladders\n\n%sGAME SETTINGS%s\n\n", KGRN, KNRM);
    for (int i = 0; i < LADDERS; i++)
    {
        printf("%sLadder %d:%s %d --> %d\t", KBLU, i + 1, KNRM, ladders[i][0] + 1, ladders[i][1] + 1);
    }
    printf("\n\n");
    for (int i = 0; i < SNAKES; i++)
    {
        printf("%sSnake %d:%s %d --> %d\t", KRED, i + 1, KNRM, snakes[i][0] + 1, snakes[i][1] + 1);
    }
    printf("\n\nRemember that the board is setup from %sTOP%s to %sBOTTOM%s\n\n", KGRN, KNRM, KGRN, KNRM);
}

char(*generate_board())
{
    int snakes[SNAKES][2];
    int ladders[LADDERS][2];

    srand(time(0));

    for (int i = 0; i < LADDERS; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            ladders[i][j] = randrange(1, 100);
        }
    }

    for (int i = 0; i < SNAKES; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            snakes[i][j] = randrange(1, 100);
        }
    }

    static char initial[100];

    for (int i = 0; i < 100; i++)
    {
        initial[i] = '0';
    }

    for (int i = 0; i < SNAKES; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            initial[snakes[i][j]] = 'm';
        }
    }

    for (int i = 0; i < LADDERS; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            initial[ladders[i][j]] = '-';
        }
    }

    // get_rules(ladders, snakes);

    return initial;
}

void print_updated_board(char c, int newlineflag)
{
    if (newlineflag == 1)
    {
        switch (c)
        {
        case 'm':
            printf("%s %c \n", KRED, c);
            break;
        case '-':
            printf("%s %c \n", KBLU, c);
            break;
        default:
            printf("%s %c \n", KWHT, c);
        }
    }
    else
    {
        {
            switch (c)
            {
            case 'm':
                printf("%s %c ", KRED, c);
                break;
            case '-':
                printf("%s %c ", KBLU, c);
                break;
            default:
                printf("%s %c ", KWHT, c);
            }
        }
    }
}