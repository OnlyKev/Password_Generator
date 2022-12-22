#include <stdio.h>

void clear_keyboard_buffer(void);

char choice(char a);
// Precondition: none
// Postcondition: verifies that user has entered valid inputs and displays results to user
void inputVerify(void);
//precondition:
void passwordGen(int num, int charup, int charlow);


int main(int argc, char* argv[])
{
    char userStart; // BEGINS PROGRAM
    char a;
    int numbers[10] = {0,1,2,3,4,5,6,7,8,9};
    char charactersUpper[26] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    char charactersLower[26] = {"abcdefghijklmnopqrstuvwxyz"};

    int *forNum = 0;
    int *forCharUp = 0;
    int *forCharLow = 0;

    printf("Hello, would you like to generate some passwords today? (Y/N)\n");
    scanf("%c", &userStart);
    clear_keyboard_buffer();

    userStart = choice(a);

    switch(userStart) // checks if user choose Y or n
    {
        case 'y':
        case 'Y':
            inputVerify();
            break;
        case 'N':
        case 'n':
            return 0;
        default:
            while (userStart != 'Y' || userStart != 'y' && userStart != 'N' || userStart != 'n' )
            {
                printf("please enter Y or N\n");
                scanf("%c", &userStart);
                clear_keyboard_buffer();

            }
            break;
    }

    return 0;
}

char choice(char a)
{
    char userStart;

    switch(userStart) // checks if user choose Y or n
    {
        case 'y':
        case 'Y':
            inputVerify();
            break;
        case 'N':
        case 'n':
            break;
        default:
            while (userStart != 'Y' || userStart != 'y' && userStart != 'N' || userStart != 'n' )
            {
                printf("please enter Y or N\n");
                scanf("%c", &userStart);
                clear_keyboard_buffer();
                choice();
            }
            break;
    }
    return userStart;
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
    while (noc != 1 || forNum <= 0)
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
    printf("%d||%d||%d", forNum,forCharUp, forCharLow);
    passwordGen(forNum, forCharUp, forCharLow);
    return;
}

void passwordGen(int num, int charup, int charlow)
{
    int numbers[10] = {0,1,2,3,4,5,6,7,8,9};
    char charactersUpper[26] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    char charactersLower[26] = {"abcdefghijklmnopqrstuvwxyz"};


    return;



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