#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    int data;
    struct node *next;
}*head,*newnode,*ptr,*temp,*head1;

void create_node();
int count_node();
void insert_beginning();
void insert_end();
void insert_after();
void insert_before();
void delete_beginning();
void delete_end();
void delete_after();
void delete_before();

void splitting();
void merging();
void sorting();

void display(struct node *);

main()
{
    int a;
    //MENU FOR USER TO CHOOSE
    printf("=======================================================");
    printf("\n Enter 1 to CREATE a node.");
    printf("\n Enter 2 to INSERT node at the BEGINNING.");
    printf("\n Enter 3 to INSERT node at the END.");
    printf("\n Enter 4 to INSERT AFTER a given position.");
    printf("\n Enter 5 to INSERT BEFORE a given position.");
    printf("\n Enter 6 to DELETE node at the BEGINNING.");
    printf("\n Enter 7 to DELETE node at the END.");
    printf("\n Enter 8 to DELETE AFTER a given position.");
    printf("\n Enter 9 to DELETE BEFORE a given position.");
    printf("\n Enter 10 to SPLIT the nodes.");
    printf("\n Enter 11 to MERGE the nodes.");
    printf("\n Enter 12 to SORT the nodes.");
    printf("\n Enter 13 to DISPLAY the node.");
    printf("\n=======================================================");
    //MENU DRIVEN CODE USING SWITCH CASE
    while(a!=0)
    {
       switch(a)
       {
           case 1:create_node();        //CREATE A NODE
               break;
           case 2:insert_beginning();   //INSERT A NODE AT THE BEGINNING
               break;
           case 3:insert_end();         //INSERT A NODE AT THE END
               break;
           case 4:insert_after();       //INSERT A NODE AFTER A GIVEN POSITION
               break;
           case 5:insert_before();      //INSERT A NODE BEFORE A GIVEN POSITION
               break;
           case 6:delete_beginning();    //DELETE A NODE AT THE BEGINNING
               break;
           case 7:delete_end();           //DELETE A NODE AT THE END
               break;
           case 8:delete_after();         //DELETE A NODE AFTER A GIVEN POSITION
               break;
           case 9:delete_before();        //DELETE A NODE BEFORE A GIVEN POSITION
               break;
           case 10:splitting();           //SPLITS THE NODE INTO 2 PARTS
               break;
           case 11:merging();               //MERGES THE SPLITTED NODES
               break;
           case 12:sorting();              //SORT THE NODES
                break;
           case 13:display(head);          //DISPLAY THE NODES
               break;
       }
        printf("\n Choose number : ");          //CHOOSING FROM THE MENU ABOVE
        scanf("%d",&a);
    }
}


void create_node()
{
    int value;
    newnode=(struct node*)malloc(sizeof (struct node));
    printf("Enter the value of DATA : ");
    scanf("%d",&value);
    newnode->data=value;
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
        temp=newnode;
    }
    else
    {
        temp->next=newnode;
        temp=newnode;
    }
}

int count_node()
{
    int count=0;
    temp=head;
    while(temp != 0)
    {
        count++;
        temp=temp->next;
    }
    return count;
}

void insert_beginning()
{
    int a;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the DATA to INSERT at the BEGINNNING : ");
    scanf("%d",&a);
    newnode->data = a;
    newnode->next = head;
    head = newnode;
}

void insert_end()
{
    int a;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\n Enter DATA to INSERT at the END: ");
    scanf("%d",&a);
    
    newnode->data = a;
    temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}

void insert_after()
{
    int a,pos,count,i=1;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter POSITION AFTER which you want to INSERT the node:");
    scanf("%d",&pos);
    printf("\n Enter DATA to INSERT AFTER a given position: ");
    scanf("%d",&a);
    
    count = count_node();
    newnode ->data = a;
    if(pos > count)
    {
        printf("\nInvalid position");
    }
    else
    {
        temp = head;
        for(i=1;i<pos;i++)
        {
            temp = temp->next;
        }
        newnode -> next = temp->next;
        temp -> next = newnode;
        temp = newnode;
    }
}

void insert_before()
{
    int a,pos=0,count=0,i=1;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter POSITION BEFORE which you want to INSERT the node:");
    scanf("%d",&pos);
    printf("\n Enter DATA to BEFORE AFTER a given position: ");
    scanf("%d",&a);
    
    newnode->data = a;

    count=count_node();
    temp=head;
    
    if(pos > count)
    {
        printf("\n Invalid position");
    }
    else
    {
        if(pos == 1)
        {
            newnode->data = a;
            newnode->next = head;
            head = newnode;
        }
        else
        {
            temp = head;
            for(i=1;i<pos-1;i++)
            {
                temp = temp->next;
            }
            newnode -> next = temp->next;
            temp -> next = newnode;
            temp = newnode;
        }
    }
}

void delete_beginning()
{
    temp = head;
    head = head->next;
    temp->next = NULL;
    free(temp);
}

void delete_end()
{
    temp = head;
    while(temp->next != NULL)
    {
        ptr = temp;
        temp = temp->next;
    }
    ptr->next = NULL;
    free(temp);
}

void delete_after()
{
    int pos=0,count=0,i=1;
    printf("Enter POSITION AFTER which you want to DELETE the node:");
    scanf("%d",&pos);

    count=count_node();
    
    if(pos > count)
    {
        printf("\n Invalid position.");
    }
    else if(pos == count)
    {
        printf("\n No node exist");
    }
    else
    {
        temp = head;
        for(i=1;i<pos+1;i++)
        {
            ptr = temp;
            temp = temp->next;
        }
        ptr ->next = temp->next;
        free(temp);
    }
}

void delete_before()
{
    int pos=0,count=0,i=1;
    printf("Enter POSITION BEFORE which you want to DELETE the node:");
    scanf("%d",&pos);

    count=count_node();
    
    if(pos > count)
    {
        printf("\n Invalid position");
    }
    else if(pos == 1)
    {
        printf("\n No node exist");
    }
    else if(pos == 2)
    {
        temp = head;
        head = head->next;
        temp->next = NULL;
        free(temp);
    }
    else
    {
        temp = head;
        for(i=1;i<pos-1;i++)
        {
            ptr = temp;
            temp = temp->next;
        }
        ptr ->next = temp->next;
        free(temp);
    }
}

void splitting()
{
    int count = 0,pos=0,i=1;
    count = count_node();
    pos = count/2;
    
    temp = head;
    for(i=1;i<pos;i++)
    {
        temp = temp->next;
    }
    head1 = temp->next;
    temp->next = NULL;
    display(head);
    printf("\n");
    display(head1);
}

void merging()
{
    splitting();
    
    temp = head;
    while(temp -> next != NULL)
    {
        temp = temp ->next;
    }
    temp->next = head1;
    printf("\n");
    display(head);
}

void sorting()
{
    int a;
    temp = head;
    while(temp->next != NULL)
    {
        ptr = temp->next;
        while(ptr != NULL)
        {
            if(temp->data > ptr->data)
            {
                a = temp->data;
                temp->data = ptr->data;
                ptr->data = a;
            }
            ptr = ptr->next;
        }
        temp = temp->next;
    }
}

void display(struct node *head)
{
    temp=head;
    printf("head -> ");
    while(temp != NULL)
    {
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
}

