#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"


   void listContacts(AddressBook *addressBook)
{
    if (addressBook->contactCount == 0) 
    {
        printf("No contacts available\n");
        return;
    }
    Contact temp[100];
    for (int i = 0; i < addressBook->contactCount; i++) 
    {
        temp[i] = addressBook->contacts[i];
    }
    for (int i = 0; i < addressBook->contactCount - 1; i++) 
    {
        for (int j = i + 1; j < addressBook->contactCount; j++)
         {
            if (strcmp(temp[i].name, temp[j].name) > 0) 
            {
                Contact c = temp[i];
                temp[i] = temp[j];
                temp[j] = c;
            }
        }
    }
    for (int i = 0; i < addressBook->contactCount; i++) 
    {
        printf("%s | %s | %s\n", temp[i].name,temp[i].phone,temp[i].email);
    }
}



void initialize(AddressBook *addressBook)
{
    addressBook->contactCount = 0;

    // Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook)
{
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS);              // Exit the program
}

 void createContact(AddressBook *addressBook)
{
    if (addressBook->contactCount >= 100) 
    {
        printf("Address book full\n");
        return;
    }

    Contact newContact;
    printf("Enter name: ");
    scanf(" %[^\n]", newContact.name);

    if (strlen(newContact.name) == 0 || strlen(newContact.name) > 50) 
    {
        printf("Invalid name\n");
        return;
    }
    for (int i = 0; newContact.name[i] != '\0'; i++) 
    {
        char c = newContact.name[i];
        if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == ' ')) 
        {
            printf("Name must have only letters and spaces\n");
            return;
        }
    }

    printf("Enter phone: ");
    scanf(" %[^\n]", newContact.phone);
    if (newContact.phone[0] == '0')
     {
    printf("Phone number cannot start with 0\n");
    return;
    }
    if (strlen(newContact.phone) != 10) 
    {
        printf("Phone must be 10 digits\n");
        return;
    }
    for (int i = 0; i < 10; i++) 
    {
        if (newContact.phone[i] < '0' || newContact.phone[i] > '9') 
        {
            printf("Phone must be digits only\n");
            return;
        }
    }
    for (int i = 0; i < addressBook->contactCount; i++) 
    {
        if (strcmp(addressBook->contacts[i].phone, newContact.phone) == 0)
         {
            printf("Phone already exists\n");
            return;
        }
    }

    printf("Enter email: ");
    scanf(" %[^\n]", newContact.email);
    const char *at = strchr(newContact.email, '@');
    const char *dot = strrchr(newContact.email, '.');
    if (!at || !dot || at > dot || strcmp(newContact.email + strlen(newContact.email) - 4, ".com") != 0)
     {
        printf("Invalid email\n");
        return;
    }
    for (int i = 0; i < addressBook->contactCount; i++)
     {
        if (strcmp(addressBook->contacts[i].email, newContact.email) == 0) 
        {
            printf("Email already exists\n");
            return;
        }
    }
    int atCount = 0;
for (int i = 0; newContact.email[i] != '\0'; i++) {
    if (newContact.email[i] == '@') {
        atCount++;
    }
}

if (atCount != 1) {
    printf("Invalid email (must contain exactly one '@')\n");
    return;
}

    addressBook->contacts[addressBook->contactCount++] = newContact;
    printf("Contact added\n");
}
  void searchContact(AddressBook *addressBook)
{
    if (addressBook->contactCount == 0) 
    {
        printf("No contacts\n");
        return;
    }

    int opt;
    char term[100];
    printf("Search by 1.Name 2.Phone 3.Email: ");
    scanf("%d", &opt);
    printf("Enter value: ");
    scanf(" %[^\n]", term);

    int found = 0;
    for (int i = 0; i < addressBook->contactCount; i++) 
    {
        if ((opt == 1 && strcmp(addressBook->contacts[i].name, term) == 0) ||
            (opt == 2 && strcmp(addressBook->contacts[i].phone, term) == 0) ||
            (opt == 3 && strcmp(addressBook->contacts[i].email, term) == 0)) 
        {
            printf("%s | %s | %s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
            found = 1;
        }
    }

    if (!found)
     {
        printf("Not found\n");
     }
}

void editContact(AddressBook *addressBook) 
{
    if (addressBook->contactCount == 0)
     {
        printf("No contacts to edit\n");
        return;
    }

    int option, index = -1;
    char term[100];

    printf("Edit by: 1.Name 2.Phone 3.Email: ");
    scanf("%d", &option);
    printf("Enter value: ");
    scanf(" %[^\n]", term);

    for (int i = 0; i < addressBook->contactCount; i++)
     {
        if ((option == 1 && strcmp(addressBook->contacts[i].name, term) == 0) ||
            (option == 2 && strcmp(addressBook->contacts[i].phone, term) == 0) ||
            (option == 3 && strcmp(addressBook->contacts[i].email, term) == 0)) 
        {
            index = i;
            break;
        }
    }

    if (index == -1)
     {
        printf("Contact not found\n");
        return;
     }

    int choice;
    char input[100];

    do {
        printf("\nEditing Contact: %s | %s | %s\n", addressBook->contacts[index].name,addressBook->contacts[index].phone,addressBook->contacts[index].email);
        printf("Choose field to edit:\n");
        printf("1. Name\n2. Phone\n3. Email\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
         {
            case 1:
                printf("Enter new name: ");
                scanf(" %[^\n]", input);
                strcpy(addressBook->contacts[index].name, input);
                printf("Name updated\n");
                break;

            case 2:
                printf("Enter new phone: ");
                scanf(" %[^\n]", input);
                if(strlen(input) != 10)
                {
                    printf("Invalid phone\n");
                    break;
                }
                strcpy(addressBook->contacts[index].phone, input);
                printf("Phone updated\n");
                break;

            case 3:
                printf("Enter new email: ");
                scanf(" %[^\n]", input);
                strcpy(addressBook->contacts[index].email, input);
                printf("Email updated\n");
                break;

            case 4:
                printf("Exiting edit\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while(choice != 4);
}
void deleteContact(AddressBook *addressBook) 
{
    if (addressBook->contactCount == 0)
    {
        printf("No contacts to delete\n");
        return;
    }

    int option;
    char term[100];
    printf("Delete by: 1.Name 2.Phone 3.Email: ");
    scanf("%d", &option);
    printf("Enter value: ");
    scanf(" %[^\n]", term);

    int found = 0;
    for (int i = 0; i < addressBook->contactCount; i++)
   {
        if ((option == 1 && strcmp(addressBook->contacts[i].name, term) == 0) ||
            (option == 2 && strcmp(addressBook->contacts[i].phone, term) == 0) ||
            (option == 3 && strcmp(addressBook->contacts[i].email, term) == 0)) 
         {

            
            for (int j = i; j < addressBook->contactCount - 1; j++) 
            {
                addressBook->contacts[j] = addressBook->contacts[j + 1];
            }
            addressBook->contactCount--;
            found = 1;
            printf("Contact deleted successfully\n");
            break; 
         }
    }

    if (!found)
     {
        printf("No contact found with given value\n");
     }
}