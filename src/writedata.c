#include <stdio.h>
#include <string.h>
#include "header.h"

void writecustomer(struct customer* c){
/*
At the end of the program this function is
used to put all the customer data present in the structure to the files.
For this it scans the functions and finds customer elements that are valid and finally writes them to the file.
*/
    printf("Writing customer.txt...\n");
    FILE *fp = fopen("customer.txt","w");
    fprintf(fp,"====================\n");
    fprintf(fp,"phno--customer name\n");
    fprintf(fp,"====================\n");
    for (int i=0;i<100;i++){
        if((c+i)->phno!=-1){
            //checking if element exists, if it exists then write to file otherwise skip
            //fprintf(fp,"%d\n%s\n",(c+i)->phno,(c+i)->name);
            fprintf(fp,"%d--%s\n",(c+i)->phno,(c+i)->name);
        }              
    }
    fclose(fp);
    printf("Success\n");
}


void writeitem(struct itemlist* il){
    /*
At the end of the program this function is
used to put all the item data present in the structure to the files.
For this it scans the functions and finds item elements that are valid and finally writes them to the file.
*/
    printf("Writing items.txt...\n");
    FILE* fp = fopen("items.txt","w");
    fprintf(fp,"====================\n");
    fprintf(fp,"id--item name--price\n");
    fprintf(fp,"====================\n");
    for(int i=0;i<100;i++){
        if((il+i)->itemid!=-1){
            //check if element exists, if it does then write to file else skip
            //fprintf(fp,"%d\n%0.0f\n%s\n",(il+i)->itemid,(il+i)->value,(il+i)->itemname);
            fprintf(fp,"%d--%s--%0.0f\n",(il+i)->itemid,(il+i)->itemname,(il+i)->value);
        }
    }
    fclose(fp);
    printf("Success\n");
}