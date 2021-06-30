#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"


void buildstruct(struct billform* b, struct itemlist* il, struct customer* c){
/*
Function used to set up the default setting as deleted mode for the structures.
*/
    printf("Initializing Structures...\n");
    for (int i=0;i<100;i++){
        (b+i)->itemid=-1;
        (il+i)->itemid=-1;
        (c+i)->phno=-1;
    }    
    printf("Done...\n\n");
}


void readcustomer(struct customer* c){
/*
This function reads customer data stored in a file and adds it to the customer structure.
Uses filehandling methods to do the same.
*/
    printf("Building Customer List...\n");
    FILE* fp = fopen("customer.txt","r");
    int i=0;
    char tempnum[10],tempname[20];
    while(!feof(fp)){ //if pointer does not point to EOF proceed into while loop

        fgets(tempnum,10,fp);   //reads first line
        (c+i)->phno = atoi(tempnum); //converts the string to integer (reading number here)
                                     //and assigns it to structure phone number

        fgets(tempname,20,fp);  //reads next line and assigns to structure
        strcpy((c+i)->name,tempname);
        (c+i)->name[strlen((c+i)->name)-1] = '\0'; //removing \n obtained from reading the file

        i++;

        //doing this cause sometimes despite reading last line, EOF is not achieved,so replication occurs
        tempnum[0] = -1;
        tempname[0] = '\0';            
    }

    
    //during EOF additional blank element is created with phno as 0 setting that to -1
    for(int i=0;i<100;i++){
        if((c+i)->phno==0)
            (c+i)->phno=-1;
    }
    fclose(fp);
    printf("Built Customer List\n");
    
}


void readitem(struct itemlist* il){
/*
This function reads item data stored in a file and adds it to the item structure.
Uses filehandling methods to do the same.
*/
    printf("Building Item List...\n");
    FILE* fp = fopen("items.txt","r");
    int i=0;
    char tempid[10],tempprice[10],tempname[20];
    while(!feof(fp)){

        fgets(tempid,10,fp);
        (il+i)->itemid = atoi(tempid);

        fgets(tempprice,10,fp);
        (il+i)->value = atoi(tempprice);

        fgets(tempname,20,fp);
        strcpy((il+i)->itemname,tempname);
        (il+i)->itemname[strlen((il+i)->itemname)-1] = '\0'; //removing \n obtained from reading the file

        i++;

        tempid[0] = -1;
        tempname[0] = '\0';
        tempprice[0] = 0;
    }

    //during EOF additional blank element is craeted with id as 0 setting that to -1
    for (int i=0;i<100;i++){
        if((il+i)->itemid==0)
            (il+i)->itemid=-1;
    }
    fclose(fp);
    printf("Built Item List\n");
}