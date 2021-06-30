#include <stdio.h>
#include <string.h>
#include "header.h"


void viewitems(struct itemlist* il){
/*
This function is used to view all the items present in the items structure.
*/
    //format for viewing the list of items
    printf("\t****************************************\n");
    printf("\tItemID\t\t\tItemName\n");
    printf("\t****************************************\n");
    for (int i=0;i<100;i++){
            //if itemid = -1 meaning it does not exist, so ignore
        if((il+i)->itemid!=-1)
            printf("\t%d\t\t\t%s\n",(il+i)->itemid,(il+i)->itemname);
    }
}

void additem(struct itemlist* il){
/*
Function takes item id as user input and uses it to find any preexisting items with same id.
If it finds it informs the user of the same.
If it doesn't find it, it will further ask details of item price and name.
Finally it will search for an empty slot in the structure and save it to that
*/
    int id,flag=0;
    printf("\n\nEnter ItemID: ");
    scanf("%d",&id);

    //check if id is already in use
    for (int i=0;i<100;i++){
        if (id == (il+i)->itemid){
            flag=1; //id is already in use
            printf("ID Already in Use\n");
            break;
        }
    }

    if(flag==0){ //since id doesn't exist
        int i=0;
        while(1){
            //searching for empty location in structure
            if((il+i)->itemid==-1){
                //empty slot found
                (il+i)->itemid = id;
                char name[20];
                printf("Enter Item Name: ");
                fflush(stdin);
                scanf("%[^\n]s",name);
                fflush(stdin);
                strcpy((il+i)->itemname,name);

                printf("Enter Item Price:");
                scanf("%f",&((il+i)->value));

                
                printf("Item Added\n");
                break;
            }
            else
                i++;
        }
    }
}

void removeitem(struct itemlist* il){
/*
Uses itemid as input to verify the existence of a given item id in the structure.
If it is found it will delete it.
If it is not found it will tell the user the same.
*/
    int i=0,del=0,id;
    
    printf("Enter ItemID: ");
    scanf("%d",&id);

    //check if item exists, using item id
    for (i=0;i<100;i++){
        if((il+i)->itemid==id){
            (il+i)->itemid = -1;
            printf("Item Entry Successfully\n");
            del = 1; //set to 1 since id is found so deletion occurs
            break;
        }
    }

    if (del==0){
        //remains 0 meaning it wasnt not able to find the item id
        printf("ItemID Does Not Exist\n");
    }
}