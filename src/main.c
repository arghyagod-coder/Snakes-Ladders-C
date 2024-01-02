/*
    Program structure:

    Process a 10x10 2d array of a snakes and ladder board.

    - Generate board

        ..........
        ..m...-...
        ........m..
        ..-.....^...
        ..........
        ....^...-..
        ..........
        ..-.....m.
        ....^.....
        ..........

    -

 */

#include <stdio.h>
#include <stdio_ext.h>
#include "board.h"
#include <stdlib.h>
#include <time.h>

int main()
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
    char(*boardp) = generate_board();
    int position = 0;

    while (1)
    {
        fputs("\033c", stdout);

        get_rules(ladders, snakes);

        char *eboard = boardp;
        eboard[position] = '*';

        for (int i = 0; i < 100; i++)
        {
            if ((i + 1) % 10 == 0)
            {
                print_updated_board(eboard[i], 1);
            }
            else
            {
                print_updated_board(eboard[i], 0);
            }
        }

        int dice_roll;
        printf("Enter dice roll: ");
        scanf("%d", &dice_roll);

        eboard[position] = '0';

        if ((position + dice_roll) < 99)
        {
            position += dice_roll;
        }
        else if ((position + dice_roll) == 99)
        {
            fputs("\033c", stdout);
            printf("%s YOU WIN!", KGRN);
            break;
        }
        // else if (eboard[dice_roll + input] == "m"){
        // }
    }
    return 0;
}