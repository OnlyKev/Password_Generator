#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void clear_keyboard_buffer(void);

// Precondition: the user has entered something from keyboard buffer
// Postcondition: determines if user indicated to continue with the program or exit the program
void choice(char a);
// Precondition: the user has indicated that they want to continue with the program
// Postcondition: verifies that user has entered valid inputs and displays results to user
void inputVerify(void);
//precondition: the user has indicated to continue with the program in choice and has entered valid inputs in inputVerify
// postcondition: Generate a random password using the specific numbers, uppercase letters, lowercase letters, and special characters that user has
// indicated and generates the total length of password by combining numbers, uppercase letters, lowercase letters, and special characters
// Prints out the password and its respective length
void passwordGen(int num, int charup, int charlow, int forSpecialChar);

int main(int argc, char* argv[])
{
    char userStart; // BEGINS PROGRAM
    srand(time(NULL));

    printf("RECOMMENDATION!!!\n");
    printf("FOR A STRONG PASSWORD, PLEASE USE AT LEAST 4 OF EACH OPTION\n");
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
    int forSpecialChar = 0;
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

    printf("ENTER A POSITIVE NUMBER OF SPECIAL CHARACTERS IN PASSWORD \n");
    noc = scanf("%d", &forSpecialChar);
    clear_keyboard_buffer();
    while (noc != 1 && forSpecialChar <= 0)
    {
        printf("Please enter a valid input. ex. 0 1 2 3 ... \n");
        noc = scanf("%d", &forSpecialChar);
        clear_keyboard_buffer();
    }


    printf(" - %d numbers of numbers \n - %d numbers of uppercase letters \n - %d numbers of lowercase letters \n - %d numbers of special characters\n", forNum,forCharUp, forCharLow, forSpecialChar);
    passwordGen(forNum, forCharUp, forCharLow, forSpecialChar);
}

void passwordGen(int num, int charup, int charlow, int SpecialChar)
{
    // the amount that the user choose for length
    int i = 0; // length of numbers
    int j = 0; // length of uppercase letters
    int k = 0; // length of lowercase letters
    int o = 0; // length of special characters

    // the index in the passArr where values will be added
    int s = 0; // numbers
    int x = 1; // upper case letters
    int y = 2; // lowercase letters
    int z = 3; // special characters


    int numCombine = num + charup + charlow + SpecialChar; // combines all values and used to generate password length
    int totalPassLength = numCombine; // used in displaying total length of password to user
    char numbers[11] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '10', '\0'};
    char charactersUpper[26] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    char charactersLower[26] = {"abcdefghijklmnopqrstuvwxyz"};
    int specialChar[8] = {33, 64, 35, 36,37,94,38,42}; // uses ASCII representation of special charaters
    char passArr[numCombine + 1] ; // password holding array





    while (numCombine != 0)
    {

        int n = (rand() %  (9 - 0 + 1))+ 0;
        int l = (rand() %  (25 - 0 + 1)) + 0;
        int m = (rand() %  (25 - 0 + 1)) + 0;
        int u = (rand() %  (7 - 0 + 1)) + 0;

        if (i < num)
        {
            passArr[s] = numbers[n];
            numCombine -= 1;
            i++;
            s+=4;
        }
        if (j < charup)
        {
            passArr[x] = charactersUpper[l];
            numCombine -= 1;
            j++;
            x+=4;
        }
        if (k < charlow)
        {
            passArr[y] = charactersLower[m];
            numCombine -= 1;
            k++;
            y+=4;
        }
        if (o < specialChar)
        {
            passArr[z] = specialChar[u];
            numCombine -= 1;
            o++;
            z += 4;
        }
    }
    passArr[totalPassLength] = + '\0'; // adds a null terminator in array

    printf("\n");
    printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("Copy Password : %s\n", passArr);
    printf("The password total length is %d\n", totalPassLength);
   // printf("\nDISCLAIMER!!! IF A PASSWORD GENERATED HAS A SPACE FOLLOWED BY A FEW RANDOM CHARACTERS AFTER DISREGARD THE RANDOM CHARACTERS AND THE VERY LAST CHARACTER IN THE FULL PASSWORD\n");
    printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");






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