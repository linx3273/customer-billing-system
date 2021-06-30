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
/*  
                        OLD METHOD
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
*/
    char temp[20],buffer[30];
    int i=0;
    //ignoring first 3 lines of file
    for(int j=0;j<3;j++)
        fgets(buffer,30,fp);

    //reading data from file
    for(i;!feof(fp);i++){
        fgets(buffer,30,fp); //reading entire line and applying it into buffer
        
        strcpy(temp,strtok(buffer,"--")); //extracting phone number from buffer and copying it to temp
        (c+i)->phno = atoi(temp); //converting phone number to integer format and storing it in structure
        
        strcpy((c+i)->name,strtok(buffer+strlen(temp)+2,"")); //extacting customer name from buffer and copying to to structure
        //the +2 is placed to send pointer ahead of the first -- encountered
        (c+i)->name[strlen((c+i)->name)-1] = '\0'; //replacing the newline tokens with null for each name
    }

    //replication occurs in case of the final line, so eliminating it
    (c+i-1)->phno = -1; 
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
/*
                OLD METHOD
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
*/
    char temp[20],buffer[40];
    int i=0,count;

    //ignoring first 3 lines of file
    for(int j=0;j<3;j++)
        fgets(buffer,40,fp);

    for(i;!feof(fp);i++){
        count=0;
        fgets(buffer,40,fp); //reads entire line and copies it to buffer

        strcpy(temp,strtok(buffer,"--")); //extracting item id from buffer and copying it to temp
        (il+i)->itemid = atoi(temp); //converting item id to integer format and storing in structure
        count+=strlen(temp)+2; //setting up pointer for itemname
        //+2 to consider the -- while setting up pointer location

        strcpy((il+i)->itemname,strtok(buffer+count,"--")); //extracting item name and copying it to the structure
        count+=strlen((il+i)->itemname)+2; //seting up pointer for value
        //+2 to consider the -- while setting up pointer location

        strcpy(temp,strtok(buffer+count,""));
        (il+i)->value = atoi(temp);
    }

    //eliminating last line replication
    (il+i-1)->itemid = -1;

    fclose(fp);
    printf("Built Item List\n");
}