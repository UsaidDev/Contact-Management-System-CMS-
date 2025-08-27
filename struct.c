#include <stdio.h>
#define _GNU_SOURCE
#include <string.h>

struct Contact
{
    char name[20];
    char phone[15];
    char email[25];
};

// Global variables
struct Contact Contacts[100];
int Contactcount = 0;

void ClearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}
// Add contacts function
void Addnewcontact()
{
    printf("Name: ");
    ClearInputBuffer();
    fgets(Contacts[Contactcount].name, sizeof(Contacts[Contactcount].name), stdin);
    Contacts[Contactcount].name[strcspn(Contacts[Contactcount].name, "\n")] = '\0';

    printf("Phone: ");
    scanf("%14s", Contacts[Contactcount].phone);

    printf("Email: ");
    scanf("%24s", Contacts[Contactcount].email);

    printf("Contact added!");
    Contactcount++;
}

// View contact function
void Viewcontact()
{
    if (Contactcount == 0)
    {
        printf("No contact added!!\n");
        return;
    }

    for (int i = 0; i < Contactcount; i++)
    {
        printf("Contact #%d\n", i + 1);
        printf("Name: %s\n", Contacts[i].name);
        printf("Phone: %s\n", Contacts[i].phone);
        printf("Email: %s\n", Contacts[i].email);
        printf("-----------------\n");
    }
}

void Displaymenu()
{
    int choise;
    while (1)
    {
        printf("\n--Contact Management System---\n");
        printf("1:Add new contact\n");
        printf("2:View all contact\n");
        printf("3:Search for a contact\n");
        printf("4:Modify a contact\n");
        printf("5:Delete a contact\n");
        printf("6:Exit the program\n");

        printf("\nChoose a number:");
        scanf("%d", &choise);
        switch (choise)
        {
        case 1:
            Addnewcontact();
            break;
        case 2:
            Viewcontact();
            break;
        default:
            printf("Invalid choise\n");
        }
    }
}

int main()
{
    Displaymenu();
    return 0;
}