#include <stdio.h>
#define _GNU_SOURCE
#include <string.h>

struct Contact
{
    char name[20];
    char phone[15];
    char email[25];
};

// GLOBAL VARIABLES
struct Contact Contacts[100];
int Contactcount = 0;
char searchname[50];

void ClearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}

// ADDCONTACTS FUNCTION
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

    printf("Contact added!\n");
    Contactcount++;
}

// VIEWSCONTACTS FUNCTION
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

// SEARCH FUCNTION
void Searchcontact()
{
    printf("Search the person name: \n");
    ClearInputBuffer();
    fgets(searchname, sizeof(searchname), stdin);
    searchname[strcspn(searchname, "\n")] = '\0';
    
    int found = 0;

    for (int i = 0; i < Contactcount; i++)
    {
        if (strcmp(Contacts[i].name, searchname) == 0)
        {
            printf("Search result found!\n");
            printf("Contact #%d\n", i + 1);
            printf("Name: %s\n", Contacts[i].name);
            printf("Phone: %s\n", Contacts[i].phone);
            printf("Email: %s\n", Contacts[i].email);
            found = 1;
            printf("-----------------\n");
            break;
        }
    }
    if (!found)
    {
        printf("Contact not found.\n");
    }
}

// UPDATE FUNCTION
void Updatecontact()
{
    int choise;
    char update[50];
    int found = 0;
    printf("Enter the contact name you want to update:\n");
    ClearInputBuffer();
    fgets(update, sizeof(update), stdin);
    update[strcspn(update, "\n")] = '\0';
    for (int i = 0; i < Contactcount; i++)
    {
        if (strcmp(Contacts[i].name, update) == 0)
        {
            found = 1;
            printf("1:Name\n");
            printf("2:Phone\n");
            printf("3:Email:\n");
            printf("Enter your choise(1,2):\n");
            scanf("%d", &choise);
            ClearInputBuffer();

            switch (choise)
            {
            case 1:
                printf("Enter new name: \n");
                fgets(Contacts[i].name, sizeof(Contacts[i].name), stdin);
                Contacts[i].name[strcspn(Contacts[i].name, "\n")] = '\0';
                printf("Name updated Successful\n");
                break;
            case 2:
                printf("Enter new phone:\n");
                scanf("%14s", Contacts[i].phone);
                printf("Phone updated Successful\n");
                break;
            case 3:
                printf("Enter new email: ");
                scanf("%24s", Contacts[i].email);
                printf("Email updated Successfully\n");
                break;
            default:
                printf("Invalid selection");
                break;
            }
            break;
        }
    }
    if (!found)
    {
        printf("Contact not found. \n");
    }
}

void Deletecontact()
{
    char delete[50];
    int found = 0;
    printf("Enter the contact name you want to delete:\n");
    ClearInputBuffer();
    fgets(delete, sizeof(delete), stdin);
    delete[strcspn(delete, "\n")] = '\0';

    for (int i = 0; i < Contactcount; i++)
    {
        if (strcmp(Contacts[i].name, delete) == 0)
        {
            for (int j = i; j < Contactcount - 1; j++)
            {
                Contacts[j] = Contacts[j + 1];
            }
            Contactcount--;
            found = 1;
            printf("Contact deleted Successfully\n");
            break;
        }
    }
    if (!found)
    {
        printf("Contact not found.\n");
    }
}

// DISPLAYMENUE FUNCTION
void Displaymenu()
{
    int choise;
    while (1)
    {
        printf("\n--Contact Management System---\n");
        printf("1:Add new contact\n");
        printf("2:View all contact\n");
        printf("3:Search for a contact\n");
        printf("4:Update a contact\n");
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
        case 3:
            Searchcontact();
            break;
        case 4:
            Updatecontact();
            break;
        case 5:
            Deletecontact();
            break;
        case 6:
            printf("Thank you!\n");
            return;
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