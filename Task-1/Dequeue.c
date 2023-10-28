//DEQUEUE
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int info;
	struct node*next;
} node;
//get node function
node* getnode()
{
	node*p;
	p=(node*)malloc(sizeof(node));
	return p;
}
typedef struct queue
{
	node*front;
	node*rear;
} dequeue;


// insert rear function
 void insertrear(dequeue * dq,int x)
 {
 	node*p;
 	p=getnode(); p->info=x;
 	p->next=NULL;
 	if(dq->rear==NULL)
 	{
 		dq->rear=p;
 		dq->front=p;
	 }
	 else
	 {
	 	(dq->rear)->next=p;
	 	dq->rear=p;
	 }
 }
// delete queue
int deletefront(dequeue *dq)
{
	int x;node *p;
	if(dq->front==NULL)
	{
		printf("dq is empty");
		return 0;
	}
	else
	{
		p=dq->front;
		x=p->info;
		dq->front=p->next;
		free(p);
       if(dq->front==NULL)
	    {
		  dq->rear=NULL;
        }  
	    
	   return (x);			
	}

}
// insertfront
void insertfront(dequeue *dq,int x)
{
	node*p;
	p=getnode(); p->info=x;
	p->next=NULL;
	if(dq->front==NULL)
	  { dq->rear=p;
	   dq->front=p;
	  }
	else
	{
		p->next=dq->front;
		dq->front=p;
	}
}
// delete rear
int deleterear(dequeue *dq)
{
	int x; node*p;
	if(dq->rear==NULL)
	{ printf(" dq is empty");
	   return 0;
	}
	else
	{
		p=dq->front;
		if(p=dq->rear)
		{
			x=p->info;
			dq->front=dq->rear=NULL;
		
		}
		else 
    	{
		    while(p->next!=dq->rear)
		    p=p->next;
		    x=(dq->rear)->info;
		    free(dq->rear);
		   dq->rear=p; 
		   p->next=NULL;
	    }
	    return (x);
	} 
	  
	
}

//display function
void display(dequeue dq)
{
	node*p;
	p=dq.front;
	
	printf(" /n queue is :");
	 while(p!=NULL)
	 {
	 	printf("%d->",p->info);
	 	p=p->next;
	 }
}

// main function
void main()
 {
 	dequeue dq;
 	int ch,x;
 	dq.front=NULL;
 	dq.rear=NULL;
 	do
 	{
 		printf(" \n 1. insertrear 2.deletefront 3. insert front 4. delete rear 5. exit");
 		printf(" enter your choice :");
 		scanf("%d",&ch);
 		switch(ch)
 		{
 			 case 1: printf(" \n enter element to be inserted :");
 			         scanf("%d",&x);
					 insertrear(&dq,x);
					 display(dq);
					 break;
			 case 2: x=deletefront(&dq);
			         if(x!=0)
			         printf(" deleted element is %d",x);
			         display(dq);
					  break; 
			 case 3: printf(" \n enter element to be inserted :");
 			         scanf("%d",&x);
					 insertfront(&dq ,x);
					 display(dq);
					 break;
			 case 4 :x=deleterear(&dq);
			         if(x!=0)
			         printf(" deleted element is %d",x);
			         display(dq);
					 break; 
			 case 5 : printf(" thank you");
			 	
			 default: printf(" \n incorect choice");
			          break;
					  		  						  
		 }
	 } while(ch>=1&&ch<=4);
 }

