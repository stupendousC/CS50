#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float change = -1.00;
    while (change < 0)
    {
        change = get_float("what's the amount owed?\n>>> ");
    }
    int cents = round(change*100);
    printf("you're getting %i cents back", cents);
    
    static const char *coins[] = {"quarters", "dimes", "nickels", "pennies"};
    static const char *coin[] = {"quarter", "dime", "nickel", "penny"};
    int till[4] = {25, 10, 5, 1};
    int payout[4] = {0,0,0,0};
    for (int i = 0; i<4; i++)
    {
        printf("\n\tDISPENSING COIN VALUE OF: %i\n", till[i]);
        int coinS = cents/till[i];
        printf("\tgive #%i coin\n", coinS);
        payout[i] = coinS;
        cents = cents - (coinS*till[i]);
        printf("\t%i cents leftover\n", cents);
        
    }
    
    printf("\nAmount owed to customer:\n");
    for (int i = 0; i<4; i++)
    {
        if (payout[i] == 1)
        {
            printf("\t%i %s\n", payout[i], coin[i]);
        }
        else if (payout[i] > 1)
        {
            printf("\t%i %s\n", payout[i], coins[i]);
        }
    }
    return 0;
        
    
    
}
