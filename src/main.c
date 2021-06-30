#include <stdio.h>
#include <string.h>
#include "header.h"

int main(){
    //setting up necessary variables
    struct billform bill[100];
    struct customer cust[100];
    struct itemlist items[100];
    int s,y,phno,flag=0,custloc;
    
    //setting up the structures
    buildstruct(bill,items,cust);
    
    //reading files
    readcustomer(cust);
    readitem(items);


/*
        INTERFACE BEGINS FROM HERE
*/
    printf("\n");
    printf("*****************************************    BILLING SYSTEM    *************************************************\n");
    printf("\n");

    seg_mmenu:
        printf("**************************\n");
        printf("Please Select An Option:\n");
        printf("**************************\n");
        printf("\t1. Customer\n");
        printf("\t2. Create Bill\n");
        printf("\t3. Items List\n");
        printf("\t0. Exit\n");
        printf("\t4.SAFE EXIT\n\n");
        
        printf("Enter Choice: ");
        scanf("%d",&s);

        switch(s){
            //CUSTOMER PANEL
            case 1:
                seg_cust:
                    printf("**************************\n");
                    printf("Please Select An Option:\n");
                    printf("**************************\n");
                    printf("\t1. New Customer\n");
                    printf("\t2. Show Customers\n");
                    printf("\t3. Delete Record\n");
                    printf("\t4. Main Menu\n\n");
                    
                    printf("Enter Choice: ");
                    scanf("%d",&y);
                    switch(y){
                        case 1: //function to create new customer entries
                                addcustomer(cust);
                                printf("\n\n");
                                goto seg_cust;
                        case 2: //function to view a list of all customers
                                viewCustomer(cust);
                                printf("\n\n");
                                 goto seg_cust;
                        case 3: //function to remove a customer entry
                                removecustomer(cust);
                                printf("\n\n");
                                goto seg_cust;

                        case 4: printf("\n\n"); //sends back to mainmenu
                                goto seg_mmenu;
                        
                        default:printf("Invalid Input\n"); //handles invalid inputs
                                printf("\n\n");
                                goto seg_cust;
                    }
            //BILLING PANEL
            case 2:
                newbill(bill);
                flag=0;
                printf("Enter Customer Phone Number: ");
                scanf("%d",&phno);
                for (int i=0;i<=100;i++){ //searching for phonenumber in customer structure
                    if(cust[i].phno==phno){
                        flag=1; //since found set flag to 1
                        custloc=i; //save customer location
                        break;
                    }
                }
                if (flag==1){
                    printf("Customer Details Are:\n");
                    printf("Name: %s\n",cust[custloc].name);
                    printf("Phone: %d\n",cust[custloc].phno);
                    printf("\n\n");

                    seg_bill:
                        //generating bill fo customer whose details were provided
                        printf("**************************\n");
                        printf("Please Select An Option:\n");
                        printf("**************************\n");
                        printf("\t1. Add Item\n");
                        printf("\t2. Remove Item\n");
                        printf("\t3. Show Bill\n");
                        printf("\t4. Main Menu\n\n");
                        
                        printf("Enter Choice: ");
                        scanf("%d",&y);
                        switch(y){
                            case 1: //function to add item to the bill
                                    addbillitem(bill,items);
                                    printf("\n\n");
                                    goto seg_bill;
                            case 2: //function to remove an item from the bill
                                    removebillitem(bill);
                                    printf("\n\n");
                                    goto seg_bill;
                            case 3: //function to display the bill
                                    showbill(bill,cust,phno);
                                    printf("\n\n");
                                    goto seg_bill;

                            case 4: printf("\n\n"); //sends back to mainmenu
                                    goto seg_mmenu;
                                
                            default:printf("Invalid Choice\n"); //handles invalid inputs
                                    printf("\n\n");
                                    goto seg_bill;
                        }                
                }
                else{
                    printf("Phone Number Not Found\n\n");
                    goto seg_mmenu;
                }

            //PRESET ITEMS PANEL
            case 3:{
                seg_items:
                    printf("**************************\n");
                    printf("Please Select An Option:\n");
                    printf("**************************\n");
                    printf("\t1. Show Items\n");
                    printf("\t2. New Entry\n");
                    printf("\t3. Remove Entry\n");
                    printf("\t4. Main Menu\n\n");

                    printf("Enter Choice: ");
                    scanf("%d",&y);
                    switch(y){
                        case 1: //function to view list of items
                                viewitems(items);
                                printf("\n\n");
                                goto seg_items;
                        case 2: //function to add new item to  items
                                additem(items);
                                printf("\n\n");
                                goto seg_items;
                        case 3: //function to remove an item from items
                                removeitem(items);
                                printf("\n\n");
                                goto seg_items;

                        case 4: printf("\n\n"); //sends back to main menu
                                goto seg_mmenu;
                        default:printf("Invalid Choice\n"); //handling invalid inputs
                                goto seg_items;
                    
                }
            }
            case 0: //to exit from the program
                writecustomer(cust);
                writeitem(items);
                printf("Exiting...\n");
                return 0;
            case 4:
                printf("INITIATED SAFE EXIT...\n");
                return 0;
            default: //handles invalid inputs
                printf("Invalid Choice\n");
                printf("\n\n");
                goto seg_mmenu;
        }
}