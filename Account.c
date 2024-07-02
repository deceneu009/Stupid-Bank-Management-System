#include "Account.h"

char *name = NULL, *surname = NULL, *fullname = NULL, *filename = NULL;

void Edit()
{
    char column[10];
    char *Opt[] = {"IBAN", "Coin", "Amount"};
    printf("And which column do you want to modify?(IBAN, Coin, Amount)\n");
    scanf("%9s", column);

    // Convert both input and options to lowercase for case-insensitive comparison
    char columnLower[10];
    strcpy(columnLower, column);
    for (int i = 0; columnLower[i]; i++)
    {
        columnLower[i] = tolower(columnLower[i]);
    }

    // Check if the input matches any of the options
    int found = 0;
    for (int i = 0; i < sizeof(Opt) / sizeof(Opt[0]); i++)
    {
        if (strcasecmp(columnLower, Opt[i]) == 0)
        {
            found = 1;
            break;
        }
    }

    if (found)
    {
        printf("\n");
        View_account(filename);
        Edit_account(column, filename);
        printf("\n=========================\n");
        printf("\n");
    }
    else
    {
        printf("You can't edit that!\n");
    }
}

void View()
{
    View_account(filename);
    printf("\n=========================\n");
}

void Create()
{
    // If the file doesn't exist then create csv file and then create account
    Create_account(filename, fullname);
}

void Transaction()
{
    // we get the surname and the name of the other account database
    char name2[50], surname2[50];
    char fullname2[50], *filename2;

    printf("With who do you want to make the transition?\n");
    scanf("%s %s", surname2, name2);
    printf("\n");

    // Same thing as the first fullname. We concatenate surname with name in order to obtain the second fullname
    strlwr(surname2);
    strlwr(name2);
    strcpy(fullname2, strcat(surname2, name2));
    filename2 = (char *)malloc(strlen(fullname) + 5);
    strcpy(filename2, fullname2);
    // we concatenate the fullname and .csv in order to create the csv file and access it by the fullname
    strcat(filename2, ".csv");

    printf("Your account:\n");
    printf("\n=========================\n");
    // We view the accounts so that it is easier for us to see
    View_account(filename);
    printf("The other account:\n");
    View_account(filename2);

    Transactions(fullname, fullname2);
    printf("\n=========================\n");

    free(filename2);
}

void Delete()
{
    deleteAccount(filename);
}

void Add_New_Account()
{
}

char *person_init(char *argv1, char *argv2)
{
    // we put the arguments into the variables surname and name which will becaome the fullname
    surname = argv1;
    name = argv2;

    // Validate input strings
    if (surname[0] == '\0' || name[0] == '\0')
    {
        printf("Surname and name must not be empty\n");
        return "error";
    }

    strlwr(name);
    strlwr(surname);

    fullname = malloc(sizeof(name) + sizeof(surname) + 1);

    strcpy(fullname, strcat(surname, name));
    filename = malloc(strlen(fullname) + 5); // ".csv" + null terminator
    if (filename == NULL)
    {
        perror("Error allocating memory");
        return "error";
    }
    strcpy(filename, fullname);
    // we concatenate the fullname and .csv in order to create the csv file and access it by the fullname
    strcat(filename, ".csv");

    return filename;
}

int check_option(int option)
{
    // Read the option (in case it is not an integer it will print an error)
    while (scanf(" %d", &option) != 1)
    {
        printf("\nInvalid input. Please enter a number from 1 to 6!.\n");

        // Clear input buffer
        int c;
        while ((c = getchar()) != '\n' && c != EOF)
            continue; // Restart the loop

        if (c == '\n')
        {
            printf("Choose:");
        }
        // return 1;
    }
    printf("\n");

    return option;
}