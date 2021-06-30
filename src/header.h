struct billform{
    int itemid;
    char itemname[20];
    int qty;
    float price;
};

struct itemlist{
    int itemid;
    float value;
    char itemname[20];
    
};

struct customer{
    char name[20];
    int phno;
};

//billfunctions.c
void newbill(struct billform* b);
void addbillitem(struct billform* b,struct itemlist* il);
void removebillitem(struct billform* b);
void showbill(struct billform* b,struct customer* c,int phno);

//customerfunctions.c
void addcustomer(struct customer* c);
void viewCustomer(struct customer *c);
void removecustomer(struct customer* c);

//initialization.c
void buildstruct(struct billform* b, struct itemlist* il, struct customer* c);
void readcustomer(struct customer* c);
void readitem(struct itemlist* il);


//writedata.c
void writecustomer(struct customer* c);
void writeitem(struct itemlist* il);

//itemfunctions.c
void viewitems(struct itemlist* il);
void additem(struct itemlist* il);
void removeitem(struct itemlist* il);
