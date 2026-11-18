#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
int createname(char *Name);
int createphone(char *Phone);
int createemail(char *Email);
void listContacts(AddressBook *addressBook)
{
    // Sort contacts alphabetically by name using simple bubble sort
    for (int i = 0; i < addressBook->contactCount - 1; i++) {
        for (int j = i + 1; j < addressBook->contactCount; j++) {
            if (strcmp(addressBook->contacts[i].name, addressBook->contacts[j].name) > 0) {
                // Swap the contacts
                Contact temp = addressBook->contacts[i];
                addressBook->contacts[i] = addressBook->contacts[j];
                addressBook->contacts[j] = temp;
            }
        }
    }

    // Print all contacts
    printf("\n---------List of all contacts--------\n");
    for (int i = 0; i < addressBook->contactCount; i++) {
        printf("%d. %s | %s | %s\n",i+1,
               addressBook->contacts[i].name,
               addressBook->contacts[i].phone,
               addressBook->contacts[i].email);
    }
    printf("\n--------------------------------------\n");
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
int exit_program(int choice)
{
        if(choice == 0)
        {
                printf("Program Terminated\n");
                exit(0);
        }
        return 0;
}              
void createContact(AddressBook *addressBook)
{
    /* Define the logic to create a Contacts */
    char Name[50];
    char Phone[20];
    char Email[50];

     int a, b, c;
    do{

        printf("Enter your name :");
        scanf(" %[^\n]",Name);

        a = createname(Name);

        if(a == 0)
        {
            printf("Error : Invalid name\n");
        }
    }while(a == 0);

    strcpy(addressBook -> contacts[addressBook -> contactCount].name,Name);

    do{
        printf("Enter Phone number :");
        scanf(" %[^\n]",Phone);

        b = createphone(Phone);

        int i =0 , f = 0;
        while(i < addressBook -> contactCount)
        {
         f = strcmp(addressBook -> contacts[i].phone,Phone);

         if(f == 0)
         {
            printf("Error : Already exist\n");
           b = 0;
          }  
        i++;
        }

    }while(b == 0);

    strcpy(addressBook -> contacts[addressBook ->contactCount].phone,Phone);

    do{
        printf("Enter E-mail address :");
        scanf(" %[^\n]",Email);

        c = createemail(Email);

        int i = 0, f = 0;
        while(i < addressBook -> contactCount)
        {
           f = strcmp(addressBook -> contacts[i].email,Email);

           if(f == 0)
           {
            printf("Email Already exist\n");
            c = 0;
           }
           i++;
        }

        if(c == 0)
        {
            printf("Error : Invalid email\n");
        }
    }while(c == 0);

    strcpy(addressBook -> contacts[addressBook ->contactCount].email,Email);
     
    addressBook ->contactCount++;
    printf("Contacts Created\n");

}

int createname(char *name)
{
    int i = 0;
     while(name[i])
     {
        if(name[0] == ' ' || name[0] == '.')
          return 0;
            
        if(!(name[i] >= 'A' && name[i] <= 'Z' || name[i] >= 'a' && name[i] <= 'z' || name[i] == ' '))
        {
            return 0;
        }
        if(name[i] == ' ' && name[i+1] == ' ')
        {
            return 0;
        }
        i++;
     }

     return 1;
}

int createphone(char *phone)
{
    int i = 0, len;
    
    len = strlen(phone);

    while(phone[i])
    {
        if(!(phone[i] >= '0' && phone[i] <= '9'))
        {
            printf("Error :All elements shuold be numbers\n");
            return 0;
        }
        i++;
    }
    
    if(!(len == 10))
     {
       printf("Phone number must be 10 digit\n");
       return 0;
     }
    return 1;
   
}

int createemail(char *email)
{
    int i = 0, len = strlen(email), count = 0;

    if(email[0] == '@' || email[0] == '.' || email[len -1] == '@' || email[len - 1] == '.')
    {
        return 0;
    }
    char *p = strchr(email ,'@');
    if(p == NULL)
    {
        return 0;
    }
    if(!(strstr(p,".com") || strstr(p,".in") || strstr(p,".edu")))
    {
        return 0;
    }
    while(email[i])
    {
        if(!(email[i] >= 'a' && email[i] <= 'z' || email[i] == '@' || email[i]== '.' || email[i] >= '0' && email[i] <= '9'))
        {
            return 0;
        }
        if(email[i] == '@')
        {
            count++;
            if(count != 1)
            {
                return 0;
            }
        }
        if( email[i] == '@' && email[i+1] == '.' || (email[i] == '.' && email[i+1] == '.'))
        {
            return 0;
        }
       
        i++;
    }
    return 1;
}

int searchContact(AddressBook *addressBook)
{
    /* Define the logic for search */   
    char Name[50];
    char Phone[20];
    char Email[50];

    int choice;
    do{
        printf("--------------------------------\n");
        printf("Search By :\n");
        printf("1) Name \n");
        printf("2) Phone number \n");
        printf("3) Email \n");
        printf("4) Back to menu \n");
        printf("--------------------------------\n");
        printf(" Enter your choice :");
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1:
                {
                 int x,count, a;
                 int arr[20];
                   while(1){
                    printf("Enter your name:");
                    scanf(" %[^\n]",Name);
                       x = createname(Name);
                     if(x == 0)
                     {
                        printf("Invalid Name.Please try again. \n");
                       continue;
                     }
                          count = 0;
                         int i = 0;
                        while(i < addressBook -> contactCount)
                        {
                       if(strcmp(addressBook -> contacts[i].name,Name) == 0)
                         {
                            arr[count++] = i;
                         }
                         i++;
                        }
                        if(count == 0)
                        {
                            printf("Contact not found.Try again\n");
                            continue;
                        }
                         for(int j = 0; j < count ; j++)
                         {
                            a = arr[j];
                         printf(" %d. | %s | %s | %s \n",j+1,addressBook -> contacts[a].name,addressBook -> contacts[a].phone,addressBook -> contacts[a].email);
                         }
                         
                         if(count == 1)
                         {
                            return arr[0];
                         }
                         
                         int select, t;
                         printf("Select contact by serial number :");
                         scanf("%d",&select);

                         if(select >= 1 && select <= count)
                         {
                            t = arr[select - 1];
                            printf(" %d. | %s | %s | %s \n",select,addressBook -> contacts[t].name,addressBook -> contacts[t].phone,addressBook -> contacts[t].email);
                            return arr[select - 1];
                         }
                         else
                         {
                            printf("Invalid selection\n");
                            continue;
                         }
                    }
                }
            break;
            case 2:
               {
                 int x ;
                 while(1)
                 {
                    printf("Enter Phone number:");
                    scanf(" %[^\n]",Phone);
                       x = createphone(Phone);
                     if(x == 0)
                     {
                        printf("Invalid Phone number.Please try again. \n");
                        continue;
                     }
                    
                         int i = 0, found = 0;
                        while(i < addressBook -> contactCount)
                        {
                       if(strcmp(addressBook -> contacts[i].phone,Phone) == 0)
                         {
                         printf("\n-----------Contact found--------------\n");
                         printf(" %d. | %s | %s | %s ", i+1,addressBook -> contacts[i].name,addressBook -> contacts[i].phone,addressBook -> contacts[i].email);
                         printf("\n--------------------------------------\n");
                          found = 1;
                          return i;
                         }
                          i++;
                        }
                        if(found == 0)
                        {
                         printf("contact not found\n");
                        }
                    }                
        
                }
            break;
            case 3:
                {
                  int x; 
                 while(1){
                    printf("Enter Email Id:");
                    scanf(" %[^\n]",Email);
                       x = createemail(Email);
                     if(x == 0)
                     {
                        printf("Invalid Email Id.Please try again. \n");
                        continue;
                     }
    
                         int i = 0,found = 0;
                        while(i < addressBook -> contactCount)
                        {
                       if(strcmp(addressBook -> contacts[i].email,Email) == 0)
                         {
                         printf("\n-----------Contact found--------------\n");
                         printf(" %d. | %s | %s | %s ", i+1,addressBook -> contacts[i].name,addressBook -> contacts[i].phone,addressBook -> contacts[i].email);
                         printf("\n--------------------------------------\n");
                          found = 1;
                          return i;
                         }
                          i++;
                        }
                        if(found == 0)
                        {
                         printf("contact not found\n");
                        }
                    }
                
                }
            break;
            case 4:
            break;
            default:
               printf("Invalid choice. Please try again.\n");
        }
    }while(choice != 4);
}


void editContact(AddressBook *addressBook)
{
    /* Define the logic for Editcontact */
     char Name[50];
    char Phone[20];
    char Email[50];
    
    
    printf("\n=========Edit contact==========\n");
    int index = searchContact(addressBook);
    
    if(index == -1)
    {
        return;
    }

     int choice;
    do{
        printf("--------------------------------\n");
        printf("Edit By :\n");
        printf("1) Edit Name \n");
        printf("2) Edit Phone number \n");
        printf("3) Edit Email \n");
        printf("4) Back to menu \n");
        printf("--------------------------------\n");
        printf(" Enter your choice :");
        scanf("%d",&choice);
         
        switch(choice)
        {
              case 1:
                {
                  int P;
                  do{
                    printf("Enter Name to Edit:");
                    scanf(" %[^\n]",Name);
                     P = createname(Name);
                     if(P == 0)
                     {
                         printf("Invalid Name .Please try again.\n");
                     }
                     else
                     {
                       strcpy(addressBook -> contacts[index].name,Name);
                       printf("Name Edited succesfully\n");
                     }
                  }while(P == 0);
                }
              break;
              case 2:
                 {
                  int P;
                    do{
                       printf("Enter Phone number to Edit:");
                       scanf(" %[^\n]",Phone);
                          P = createphone(Phone);
                        if(P == 0)
                          {
                            printf("Invalid Phone number .Please try again.\n");
                          }
                          else
                          {
                            strcpy(addressBook -> contacts[index].phone,Phone);
                            printf("Phone number Edited succesfully\n");
                    }
                   }while(P == 0);
                }
              break;
              case 3:
                  {
                   int P;
                   do{
                   printf("Enter Email ID to Edit:");
                   scanf(" %[^\n]",Email);
                    P = createemail(Email);
                    if(P == 0)
                    {
                        printf("Invalid Email ID .Please try again.\n");
                    }
                    else
                    {
                    strcpy(addressBook -> contacts[index].email,Email);
                    printf("Email ID Edited succesfully\n");
                    }
                    }while(P == 0);
                }
              break;
              case 4:
              break;
              default:
                   printf("Invalid choice. Please try again.\n");
         }
    }while(choice != 4);

}

void deleteContact(AddressBook *addressBook)
{
    /* Define the logic for deletecontact */

         if(addressBook->contactCount == 0)
         {
            printf(" 0 Contacts ");
            return;
         }
    
      printf("\n========Delete contact=========\n");

    int index = searchContact(addressBook);
    
    if(index == -1)
    {
        return;
    }

    printf("Selected contact \n");

    char s_no;

    printf("Delete this contact? (y/n) :");
    if(scanf(" %c",&s_no) != 1)
    {
        while(getchar() != '\n');
        printf("Invalid input.\n");
        return;
    }

    if(s_no != 'y' && s_no != 'Y')
    {
        printf("Deletion cancelles.");
        return;
    }

    for(int i = index ; i < addressBook->contactCount-1;i++)
    {
        addressBook->contacts[i] = addressBook->contacts[i+1];
    }
    addressBook->contactCount--;

    printf("Successfully contact delete");

}