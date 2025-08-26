#include <stdio.h>
#define _GNU_SOURCE
#include <string.h>

struct Contact
{
    char name[20];
    char phone[15];
    char email[25];
};
 void Displaymenu(){
    printf("--Contact Management System---\n");
    printf("1:Add new contact\n");
    printf("2:View all contact\n");
    printf("3:Search for a contact\n");
    printf("4:Modify a contact\n");
    printf("5:Delete a contact\n");
    printf("6:Exit the program\n");

    printf("Choose the number:");
    

 }

int main(){
    struct Contact Contact1;
    printf("Please enter your name:");
    fgets(Contact1.name, sizeof(Contact1.name), stdin);
    Contact1.name[strcspn(Contact1.name, "\n")] = '\0';

    printf("Enter your phone:-");
    scanf("%14s",Contact1.phone);
    printf("Enter your email:-");
    scanf(" %20s", Contact1.email);

    printf("----Saved Contacts----\n");
    printf("Name:-%s\n", Contact1.name);
    printf("Phone:-%s\n", Contact1.phone);
    printf("Email:-%s\n", Contact1.email);


    return 0;
}