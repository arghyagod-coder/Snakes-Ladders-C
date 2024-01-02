#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int main()
{
    time_t t;
    int random_numbers[10];
    int count = 0;

    srand((unsigned)time(&t));

    while (count < 10)
    {
        srand(time(0));
        int randNum = (rand() % 100-1)+1; // Generate a random number
        bool found = false;   // assume the random number hasnt been generated

        // make sure the random number hasnt already been generated
        for (int i = 0; i < 10; i++)
        {
            if (random_numbers[i] == randNum)
            {
                found = true;
                break; // once we have located the number we dont need to continue checking
            }

            if (!found)
            {
                random_numbers[i] = randNum;
                count++;
            }
        }

        // we have a new random number
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", random_numbers[i]);
    }
    return 0;
}