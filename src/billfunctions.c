#include <stdio.h>
#include <string.h>
#include "header.h"


void newbill(struct billform* b){
/*
Function is designed to clear the bill every time the function is called.
*/
    for (int i=0;i<100;i++)
        (b+i)->itemid=-1;
}

void addbillitem(struct billform* b,struct itemlist* il){
/*
This function fetches items from the itemlist and puts them onto to the bill structure.
For this, it takes the item id and searches in the item list.
If it finds the item in the itemlist it will then proceed to add it to the bill.
If in bill the item was already added it will just increase the quantity.
If the item was not present in the bill, it will search for an empty location where it will add all the
information from the itemlist.
*/
    int id,quantity,itemflag=0,billflag=0,itemloc,billloc;
    printf("Enter ItemID: ");
    scanf("%d",&id);

    for (int i=0;i<100;i++){
        if ((il+i)->itemid == id){
            itemflag = 1; //since item found in itemlist set flag to 1
            itemloc = i; //save location of item id 
            break;
        }
    }

    if (itemflag==1){ //item found so proceed to adding into bill
        printf("Enter Item Quantity: ");
        scanf("%d",&quantity);
        //checking if item was already added to bill
        for (int i=0;i<100;i++){
            if ((b+i)->itemid==id){
                billflag = 1; //since item already exists in bill set flag to 1
                billloc=i;  //save location of item in bill
                break;
            }
        }
        if (billflag==1){   //since item is existing in bill increase the quantitiy
             (b+billloc)->qty+=quantity;
        }
        else{
            //since item does not exist find an empty location to add the item to
            for(int i=0;i<100;i++){
                if((b+i)->itemid==-1){
                    (b+i)->itemid = id;
                    strcpy((b+i)->itemname,(il+itemloc)->itemname);
                    (b+i)->price = (il+itemloc)->value;
                    (b+i)->qty = quantity;
                    break;
                }
            }
        }
    }
    else
        printf("Item Not Found\n");
}


void removebillitem(struct billform* b){
/*
This function takes an item id from the user and then uses it to search for the existence of the item.
If it finds the item it will proceed to delete it.
If it is unable to find it it will inform the user.
*/
    int id,flag=0;
    printf("Enter ItemID: ");
    scanf("%d",&id);

    for(int i=0;i<100;i++){
        if((b+i)->itemid == id){
            (b+i)->itemid = -1;
            flag=1; //flag set to 1 due to successful deletion
            break;
        }
    }

    if (flag==1)
        printf("Item Deleted Successfully...\n");
    else
        printf("Item Not Found...\n");       
}


void showbill(struct billform* b,struct customer* c,int phno){
/*
Function takes bill structure and customer structure as arguments along with the phone number.
Using the phone number it locates the customer data in the structure and fetches the name and phone number
and saves it.
As for the showing the bill, the bill structure is scanned for elements which are valid and then proceeds to print
them with the given present structur, it will also add customer name and phno to the bill along with 
the final payable amount (with taxes)
*/
    float tax = (float)5/(float)100;
    float total=0,amt;
    int j;
    //finding final payable amount
    for (int i=0;i<100;i++){
        if((b+i)->itemid!=-1){
            total+= ((b+i)->price)*((b+i)->qty);
        }
    }
    amt = total + tax*total;

    //fetching customer name
    for (int i=0;i<100;i++){
        if (phno == (c+i)->phno){
            j=i; //saving location of customer in array
            break;
        }
    }


    //creating the bill format
    printf("\n\n");
    printf("-------------------------------------------------------------------------------------------------------\n");
    printf("ItemID\t\tItemName\t\t\t\tQuantity\t\tPrice\t\tAmount\n");
    printf("-------------------------------------------------------------------------------------------------------\n");
    for(int i =0; i<100;i++){
        if((b+i)->itemid!=-1)
            printf("%d\t\t%s\t\t\t\t%d\t\t%f\t\t%f\n",(b+i)->itemid,(b+i)->itemname,(b+i)->qty,(b+i)->price,((b+i)->price)*((b+i)->qty));
    }
    printf("-------------------------------------------------------------------------------------------------------\n");
    printf("Phone Number: %d\t\t\t\t\tAmount Payable: %f\n",(c+j)->phno,amt);
    printf("Customer Name: %s\n",(c+j)->name);
}
    