#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>



int length;

int passwordLength (int length);
void generate (int length, char *s3);


void website (char *s1);
void username (char *s2);


int numberOfArrays = 4;

    char lowerCase [] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    char upperCase [] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    char num [] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    char sym [] = {'!', '@', '#', '$', '%', '&', '*', '?', '='};

    
int main ()
{
    // set random seed using time
    srand( time(NULL) );

    length = passwordLength(length);

    //array 'buckets' that will decay into pointers 
    //  for the strings being made in website + username
    char ret1 [256];
    char ret2 [256];
    char ret3 [256];

    // ? user input of website and username strings, that copy to s1/s2
    //  ? which are the pointers of ret1/ret2
    website(ret1);
    username(ret2); 

    generate (length, ret3);
    
    printf(" WEBSITE : %s\n", ret1);
    printf("USERNAME : %s\n", ret2);
    printf("PASSWORD : %s\n", ret3);

    return 0;

}



void website(char *s1)
{   
// create temp array for user input
    char temp1[256];

    printf("WEBSITE : ");
    scanf("%256s", temp1);

// temp1 gets binned when website() returns, so copy temp1 to s1
    strcpy(s1, temp1);
}

void username(char *s2)
{   
    char temp2[256];

    printf("USERNAME : ");
    scanf("%256s", temp2);

    strcpy(s2, temp2);
}

int passwordLength (int length)
{
    length = 12;
    do
    {
        printf("LENGTH : ");
        scanf("%i", &length);
    } while (length < 0 || length > 16);
    return length;
}

void generate (int length, char *s3)
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
        else printf("FAILED");
       
    }
    strcpy(s3, password);

}
