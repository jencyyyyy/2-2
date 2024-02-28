#include <stdio.h>
/*
    Output :
    Odd Numbers : 1,3,5,7,9
    Even Numbers : 2,4,6,8,10;

*/

int main()
{
    int i, SIZE;
    printf("\n\n\nTell me the size of your array :) \n");
    scanf("%d", &SIZE);

    int numbers[SIZE];

    for (i = 0; i < SIZE; i++)
    {
        printf("Enter element %d: \n", i + 1);
        scanf("%d", &numbers[i]);
    }

    // Storage
    int even_numbers[SIZE]; // Shob Even Number Thakbe
    int odd_numbers[SIZE];  // Shob Odd NUmber thakbe
    int no_of_even = 0;     // Kotogula seta bolbe
    int no_of_odd = 0;

    int k = 0;
    int p = 0;

    for (i = 0; i < SIZE; i++)
    {
        if (numbers[i] % 2 == 1)
        {
            odd_numbers[k] = numbers[i];
            k++;
            no_of_odd++;
        }

        else
        {
            even_numbers[p] = numbers[i];
            p++;
            no_of_even++;
        }
    }

    // Print Odd Numbers
    printf("Odd Numbers : ");
    for (i = 0; i < no_of_odd; i++)
    {
        printf("%d,", odd_numbers[i]);
    }
    printf("\n");

    printf("Even Numbers : ");

    // Print Even Numbers
    for (i = 0; i < no_of_even; i++)
    {
        printf("%d,", even_numbers[i]);
    }
    printf("\n");
}
