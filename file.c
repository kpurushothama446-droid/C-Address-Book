#include <stdio.h>
#include "file.h"

void saveContactsToFile(AddressBook *addressBook)
{
    // Function to save all contacts from AddressBook to a CSV file

FILE *fptr;

fptr = fopen("contacts.csv", "w+"); // Open file in write mode (creates or overwrites)

// First Line: store the number of contacts fprintf(fptr, "%d\n", addressBook->contactCount);

//fprintf(fptr,"%d\n",addressBook->contactCount);

// Write each contact in CSV format: name, phone, email for (int i=0; i < addressBook->contactCount; i++)

for(int i=0;i<addressBook->contactCount;i++)
{
fprintf(fptr, "%s, %s, %s\n",
addressBook->contacts[i].name,
addressBook->contacts[i].phone,
addressBook->contacts[i].email);
}

fclose(fptr); // Close the file
}

void loadContactsFromFile(AddressBook *addressBook)
{
    FILE *fptr;
    fptr = fopen("contacts.csv", "r+");

    fscanf(fptr,"%d\n",&addressBook->contactCount);

    for(int i=0;i<addressBook->contactCount;i++)
{
fscanf(fptr, "%[^,], %[^,], %[^\n]",
addressBook->contacts[i].name,
addressBook->contacts[i].phone,
addressBook->contacts[i].email);
}

fclose(fptr); // Close the file

}