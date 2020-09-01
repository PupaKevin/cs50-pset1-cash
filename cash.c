/*Use get_float to get the user’s input and printf to output your answer.
Assume that the only coins available are quarters (25¢), dimes (10¢), nickels (5¢),
and pennies (1¢).

    We ask that you use get_float so that you can handle dollars and cents,
    albeit sans dollar sign. In other words, if some customer is owed $9.75
    (as in the case where a newspaper costs 25¢ but the customer pays with a $10 bill),
    assume that your program’s input will be 9.75 and not $9.75 or 975.
    However, if some customer is owed $9 exactly, assume that your program’s
    input will be 9.00 or just 9 but, again, not $9 or 900. Of course,
    by nature of floating-point values, your program will likely work with
    inputs like 9.0 and 9.000 as well; you need not worry about checking
    whether the user’s input is “formatted” like money should be.

You need not try to check whether a user’s input is too large to fit in a float.
Using get_float alone will ensure that the user’s input is indeed a floating-point
(or integral) value but not that it is non-negative.
If the user fails to provide a non-negative value, your program should re-prompt
the user for a valid amount again and again until the user complies.
So that we can automate some tests of your code, be sure that your program’s
last line of output is only the minimum number of coins possible: an integer
followed by \n.
Beware the inherent imprecision of floating-point values. Recall floats.c from class,
wherein, if x is 2, and y is 10, x / y is not precisely two tenths!
And so, before making change, you’ll probably want to convert the user’s
inputted dollars to cents (i.e., from a float to an int) to avoid tiny errors
that might otherwise add up!

Take care to round your cents to the nearest penny, as with round,
which is declared in math.h. For instance, if dollars is a float with
the user’s input (e.g., 0.20), then code like
*/

#include <cs50.h>
#include <math.h>
#include <stdio.h>

int totalquarters(int quarters);
int totaldimes(int dimes);
int totalpennies(int pennies);
int totalnickels(int nickels);


int main(void)
{
    /* ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ */
    float change;;                          //value input by user is a floating variable called dollars
    int h = 100;                            //multiply user entry by a 100
    int q = 25;                             //value of a quarter is 25
    int d = 10;                             //value of a dime is 10
    int n = 5;                              //value of a nickel is 5
    int p = 1;                              //value of a penny is 1.
    /* ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ */

    /* do while loop to keep prompting the user to enter the  value  */
    do
    {
        change = get_float("What's The change Owed: "); //get the amount in cents and round it up
    }
    while (change < 0);


//dollars value converted into an integer called cents
    int cents = round(change * h);
// define quarters, dimes, nickels, pennies

    int quarters  = cents / q;
    int dimes     = (cents % q) / d;
    int nickels   = ((cents % q) % d) / n;
    int pennies   = ((cents % q) % d) % n;

    printf("You are owed $%.2f\n", change);
    printf("You will be receieving a Total of %d coins:\n", quarters + dimes + nickels + pennies);
    if (quarters > 1)
    {
        totalquarters(quarters);
    }
    else 
    {
       printf("Quarter: %d\n", quarters);
    }
    if (dimes > 0)
    {
        totaldimes(dimes);
    }
    if (nickels > 0)
    {
        totalnickels(nickels);
    }
    else 
    {
        totalpennies(pennies);
    }
    
    
}
    
int totalquarters(int quarters)

{

    printf("Quarters: %d\n", quarters);
    return 0;
}

int totaldimes(int dimes)
{
    printf("Dimes: %d\n", dimes);
    return 0;
}

int totalnickels(int nickels)
{
    printf("nickels: %d\n", nickels);
    return 0;
}
int totalpennies(int pennies)
{
    printf("pennies: %d\n", pennies);
    return 0;
}
