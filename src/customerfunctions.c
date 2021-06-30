#include <stdio.h>
#include <string.h>
#include "header.h"



void addcustomer(struct customer* c){
/*
This function takes the phone number from the user and uses it to verify the existence of 
the same number in the structure.
If it finds the phone number, it will inform the user.
If the number does not exist already it will also take the customer name from the user and save it into 
an empty location of the structure.
*/
    int i=0,flag=0,num;
    
    //if phone number exists set flag to 1, otherwise remain 0
    
    printf("\tEnter Phone Number: ");
            scanf("%d",&num);

    //checking if number exists already or not, also handles case when number does exist
    for (i=0;i<100;i++){
        if(num==(c+i)->phno){
            printf("\tNumber Already Exists.\n\n");
            flag=1;
            break;
        }
    }
    
    
    //if number does not exist in database
    if(flag==0){
        i=0;
        while(1){
            //searching for empty location in structure to add customer details to it
            if((c+i)->phno==-1){
                //an empty slot was found in array, therefore place values of new customer record here
                (c+i)->phno = num;

                printf("\tEnter Name: ");
                char temp[20];
                fflush(stdin);
                scanf("%[^\n]s",temp);
                fflush(stdin);
                strcpy((c+i)->name,temp);
                printf("\tCustomer Added\n\n");

                break;
            }
            else
                i++;
        }
    }
}

void viewCustomer(struct customer *c){
/*
Function is used to view the list of all customers that are present in the structure.
*/

    //format for viewing the list of customers
    printf("\t****************************************\n");
    printf("\tPhone Number\t\t\tName\n");
    printf("\t****************************************\n");
    int i=0;

    //if phno=-1 meaning record does not exist so skip
    for (int i=0;i<100;i++){
        if((c+i)->phno!=-1)
            printf("\t%d\t\t\t\t%s\n",(c+i)->phno,(c+i)->name);
    }
}

void removecustomer(struct customer* c){
/*
Takes phone number as user input and uses it to find the phone number in the structure.
If it finds the phone number, it deletes it from the structure.
If it doesn't find the phone number it will mention it to the user.
*/
    int i=0,del=0,num;
    //incase record is found set del to 1, else remain 0

    //taking number input to search through array of structures
    printf("Enter Phone Number: ");
    scanf("%d",&num);

    //check if customer exists, by using phno...if found set to -1 else continue
    for (i=0;i<100;i++){
        if((c+i)->phno==num){
            (c+i)->phno = -1;
            printf("Customer Entry Removed\n\n"); 
            del=1;  //setting flag to 1 as successful deletion
            break;
        }
    }

    if (del==0)
        //since deletion flag was not set to 1, meaning a phno was not found
        printf("Phone Number Not Found\n\n");
}
