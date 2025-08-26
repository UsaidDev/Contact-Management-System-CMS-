#include <stdio.h>
#define _GNU_SOURCE
#include <string.h>

struct Contact
{
    char name[20];
    char phone[15];
    char email[25];
};
 void Addnewcontact(){
    struct Contact Contact1;
    printf("Please enter your name:");
    getchar();
    fgets(Contact1.name, sizeof(Contact1.name), stdin);
    Contact1.name[strcspn(Contact1.name, "\n")] = '\0';

    printf("Enter your phone:-");
    scanf("%14s",Contact1.phone);
    printf("Enter your email:-");
    scanf(" %20s", Contact1.email);
    printf("Contact add successfully!");

    // printf("----Saved Contacts----\n");
    // printf("Name:-%s\n", Contact1.name);
    // printf("Phone:-%s\n", Contact1.phone);
    // printf("Email:-%s\n", Contact1.email);
 }
 void Displaymenu(){
    int choise;
    printf("--Contact Management System---\n");
    printf("1:Add new contact\n");
    printf("2:View all contact\n");
    printf("3:Search for a contact\n");
    printf("4:Modify a contact\n");
    printf("5:Delete a contact\n");
    printf("6:Exit the program\n");

    printf("\nChoose a number:");
    scanf("%d",&choise);
    switch (choise)
    {
    case 1:
        Addnewcontact();
        break;
    case 2:
        break;
    default:
        break;
    }

 }

int main(){
    Displaymenu();

    return 0;
}