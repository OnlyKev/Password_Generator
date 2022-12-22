#include <stdio.h>


// Precondition: none
// Postcondition: verifies that user has entered valid inputs and displays results to user
void inputVerify(void);

int main() {

    inputVerify();
    return 0;
}

void inputVerify(void)
{
    int forNum = 0;
    int forChar = 0;
    int noc;

    printf("ENTER A POSITIVE NUMBER FOR NUMBERS IN PASSWORD \n");
    noc = scanf("%d", &forNum);
    while (noc == 1 || forNum <= 0)
    {
        printf("Please enter a valid input. ex. 0 1 2 3 ... \n");
        noc = scanf("%d", &forNum);
    }

    printf("ENTER A POSITIVE NUMBER OF CHARACTERS IN PASSWORD \n");
    noc = scanf("%d", &forChar);

    while (noc != 1 && forChar <= 0)
    {
        printf("Please enter a valid input. ex. 0 1 2 3 ...");
        noc = scanf("%d", &forChar);
    }
    printf("%d||%d", forNum,forChar);

    return;
}