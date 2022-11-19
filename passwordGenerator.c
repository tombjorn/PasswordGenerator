#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


int generate (int length);

void display (int );
// todo input username and/or website function

// todo append the username and password to a txt file 

int numberOfArrays = 4;

    char lowerCase [] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    char upperCase [] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    char num [] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    char sym [] = {'!', '@', '#', '$', '%', '&', '*', '?', '='};

int main ()
{
    srand( time(NULL) );

    printf("Length : ");
    int length;
    scanf("%i", &length);
    
    generate (length);

    display(length);




return 0;

}

int generate (int length)
{
    char password[length];


    for (int i = 0; i < length; i++)
    {
        int rand1 = (rand() % numberOfArrays) + 1;

        if (rand1 == 1)
        {
            char x = lowerCase[(rand() % sizeof(lowerCase)/sizeof(char)) + 1];
            password [i] = x;
        } 
        else if (rand1 == 2)
        {
            char y = upperCase[(rand() % sizeof(upperCase)/sizeof(char)) + 1];
            password [i] = y;
        } 
        else if (rand1 == 3)
        {
            char z = num[(rand() % sizeof(num)/sizeof(char)) + 1];
            password [i] = z;
        } 
        else if (rand1 == 4)
        {
            char q = sym[(rand() % sizeof(sym)/sizeof(char)) + 1];
            password [i] = q;
        }
        else printf("failed");
       
    }
    return 0;
}

void display (length)
{
    printf("Password = ");
    for (int j = 0; j < length; j++)
    {
        printf("%c", password[j]);
    }
    printf("\n");
}
