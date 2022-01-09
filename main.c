#include "functions.h"

int main(void) {

    srand(time(0));
    int length = 10, height = 10, c;
    int play, pSize, pStruct;

    do {

        printf("\n\n");

        printf("\tPlay the game?  > ");
        scanf("%d", &play);

        while (pSize < 2 || pSize > 5) {
            printf("\tHow many players?  > ");
            scanf("%d", &pSize);

            if (pSize < 2 || pSize > 5)
                printf("Player count should be between 2 and 5. \n");
        }

        // initializes player position
        int py[pSize], pp[pSize]; // stores old location;
        for (int i = 0; i < pSize; i++) 
            py[i] = 0;

        printf("\tLocations: ");
        for (int j = 0; j < pSize; j++) 
            printf("P%d: %d  ", j+1, py[j]);

        int pSequence = playerSequence(pSize);
        printf("\tPlayer Sequence roll: %d\n", pSequence);

        // inverse sequence
        int iSequence = 0;
        for (; pSequence != 0; pSequence /= 10, iSequence *= 10)
            iSequence += pSequence % 10;

        iSequence /= 10;
        printf("\tInverse Sequence roll: %d\n", iSequence);

        printf("\n\n");

        do {
            pStruct = iSequence;

            // game start
            for(;pStruct != 0; pStruct /= 10, c = 0) {

                // find alternative
                getch();

                int pCurrent = (pStruct%10)-1;
                printf("\tCurrent Player: %d\n", pCurrent+1);

                // roll location
                pp[pCurrent] = rollDice(py[pCurrent]);
                printf("\tNew Location: %d\n\n", pp[pCurrent]);
                pp[pCurrent] = overflow(pp[pCurrent]);

                // getting quirk
                pp[pCurrent] = getQuirk(py[pCurrent], pp[pCurrent]);
                printf("\tQuirk Location: %d\n\n", pp[pCurrent]);
                pp[pCurrent] = overflow(pp[pCurrent]);

                printf("\n\n");
                // store new location into current
                py[pCurrent] = pp[pCurrent];

                
            }

            // prints location of the round
            for (int i = 0; i < pSize; i++) 
                printf("\tPlayer %d: %d", i+1, py[i]);

            printf("\n\n");
            printBoard(length, height, py, pSize);
            printf("\n\n");

            printf("\n\n\n\n\n");

        } while(!isWin(py, pSize));




        // game start
        // print board
        // roll dice with animation
        // cog chooser for quirk
        // do quirk with animation

        // next player
        // ... end
        // winner splashscreen
        // display results
        // back to main menu
        

        // * printing
        /*
                player n start !
                roll the dice -> move to new position
                roll the dice -> determine 
                    if doggo
                    if ladder
                    if snake
                    if uturn
                    if 5-5
                    if 3-3
                next player
        */

        printf("\n\n");

        /*
        gradualPrint(5*10000, "\tTest sentence.\n");
        scanf("%c", &c);
        */

    } while (play);
}