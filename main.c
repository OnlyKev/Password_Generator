#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void clear_keyboard_buffer(void);

// Precondition: the user has entered something from keyboard buffer
// Postcondition: determines if user indicated to continue with the program or exit the program
void choice(char a);
// Precondition: none
// Postcondition: verifies that user has entered valid inputs and displays results to user
void inputVerify(void);
//precondition: the user has indicated to continue with the program in choice and has entered valid inputs in inputVerify
// postcondition: Generate a random password using the specific numbers, uppercase letters, and lowercase letters that user has
// indicated and generates the total length of password by combining numbers, uppercase letters, and lowercase letters.
// Prints out the password and its respective length
void passwordGen(int num, int charup, int charlow);

int main(int argc, char* argv[])
{
    char userStart; // BEGINS PROGRAM

    printf("Hello, would you like to generate some passwords today? (Y/N)\n");
    scanf("%c", &userStart);
    clear_keyboard_buffer();

    choice(userStart);

    return 0;
}

void choice(char userStart)
{
   // char userStart;

    switch(userStart) // checks if user choose Y or n
    {
        case 'y':
        case 'Y':
            inputVerify();
            break;
        case 'n':
        case 'N':
            exit(0);
            break;
        default:
            while (userStart != 'Y' || userStart != 'y' && userStart != 'N' || userStart != 'n' )
            {
                printf("please enter Y or N\n");
                scanf("%c", &userStart);
                clear_keyboard_buffer();
                choice(userStart);
            }
            break;
    }
}

void inputVerify(void)
{

    int forNum = 0;
    int forCharUp = 0;
    int forCharLow = 0;
    int noc = 0;

    printf("ENTER A POSITIVE NUMBER FOR NUMBERS IN PASSWORD \n");
    noc = scanf("%d", &forNum);
    clear_keyboard_buffer();
    while (noc != 1 || forNum < 0)
    {
        printf("Please enter a valid input. ex. 0 1 2 3 ... \n");
        noc = scanf("%d", &forNum);
        clear_keyboard_buffer();
    }

    printf("ENTER A POSITIVE NUMBER OF UPPERCASE CHARACTERS IN PASSWORD \n");
    noc = scanf("%d", &forCharUp);
    clear_keyboard_buffer();
    while (noc != 1 && forCharUp <= 0)
    {
        printf("Please enter a valid input. ex. 0 1 2 3 ... \n");
        noc = scanf("%d", &forCharUp);
        clear_keyboard_buffer();
    }

    printf("ENTER A POSITIVE NUMBER OF LOWERCASE CHARACTERS IN PASSWORD \n");
    noc = scanf("%d", &forCharLow);
    clear_keyboard_buffer();
    while (noc != 1 && forCharLow <= 0)
    {
        printf("Please enter a valid input. ex. 0 1 2 3 ... \n");
        noc = scanf("%d", &forCharLow);
        clear_keyboard_buffer();
    }
    printf("%d numbers of numbers ||%d numbers of uppercase letters ||%d numbers of lowercase letters\n", forNum,forCharUp, forCharLow);
    passwordGen(forNum, forCharUp, forCharLow);
}

void passwordGen(int num, int charup, int charlow)
{
    // the amount that the user choose for length
    int i = 0; // length of numbers
    int j = 0; // length of uppercase letters
    int k = 0; // length of lowercase letters

    // the index in the passArr where values will be added
    int s = 0; // numbers
    int y = 1; // uppercase letters
    int z = 2; // lowercase letters

    int numCombine = num + charup + charlow;
    int totalPassLength = numCombine;
    int numbers[10] = {48,49,50,51,52,53,54,55,56,57,}; // uses ASCII representation of numbers
    char charactersUpper[26] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    char charactersLower[26] = {"abcdefghijklmnopqrstuvwxyz"};
    char passArr[numCombine];




    srand(time(NULL));

    while (numCombine != 0)
    {

        int n = (rand() %  (9 - 0 + 1))+ 0;
        int l = (rand() %  (25 - 0 + 1)) + 0;
        int m = (rand() %  (25 - 0 + 1)) + 0;
        if (i < num)
        {
            passArr[s] = numbers[n];
            numCombine -= 1;
            i++;
            s+=3;
        }
        if (j < charup)
        {
            passArr[y] = charactersUpper[l];
            numCombine -= 1;
            j++;
            y+=3;
        }
        if (k < charlow)
        {
            passArr[z] = charactersLower[m];
            numCombine -= 1;
            k++;
            z+=3;
        }
    }
    printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("Copy Password : %s\n", passArr);
    printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("the password total length is %d\n", totalPassLength);





    /*
    for (i = 0; i <= num; i++)
    {
            passArr[i] = numbers[n];
            for (j = 0; j <= charup; j++)
            {
                passArr[j + 1] = charactersUpper[l];
                for (k = 0; k <= charlow; k++)
                {
                    passArr[k + 2] = charactersLower[m];
                    break;
                }
            }
    }
     */

}
void clear_keyboard_buffer(void)
{
    char c;
    scanf("%c", &c);
    while (c != '\n')
    {
        scanf("%c", &c);
    }
}