#include <stdio.h>
#include "file.h"
#include<string.h>

void saveContactsToFile(AddressBook *addressBook)
 {
    FILE *fp = fopen("contact.csv", "w");
    if (fp == NULL) 
    
    {
        printf("Error opening file for saving!\n");
        return;
    }
    fprintf(fp, "%d\n",addressBook->contactCount);
    // fprintf( "Name,Phone,Email\n");
    for (int i = 0; i < addressBook->contactCount; i++) 
    {
        fprintf(fp, "%s,%s,%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }

    fclose(fp);
    printf("Contacts saved successfully  \n");
}
void loadContactsFromFile(AddressBook *addressBook)
{
    FILE *fp = fopen("contact.csv", "r");
    if (fp == NULL) 
    {
        printf("Error opening file for loading!\n");
        return;
    }

    fscanf(fp, "%d\n", &addressBook->contactCount);

    for (int i = 0; i < addressBook->contactCount; i++) 
    {
        fscanf(fp, "%[^,],%[^,],%[^\n]\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }

    fclose(fp);
    printf("Contacts loaded successfully.\n");
}
