#include <stdio.h>
#include<stdlib.h>
struct Node
{
	 struct Node *prev;
	 int data;
	 struct Node *next;
}*first=NULL;
void create(int A[],int n)
{
	 struct Node *t,*last;
	 int i;

	 first=(struct Node *)malloc(sizeof(struct Node));
	 first->data=A[0];
	 first->prev=first->next=NULL;
	 last=first;

	 for(i=1;i<n;i++)
	 {
		 t=(struct Node *)malloc(sizeof(struct Node));
		 t->data=A[i];
		 t->next=last->next;
		 t->prev=last;
		 last->next=t;
		 last=t;
	 }
}
void displayfrombeg(struct Node *p)
{
	 while(p)
	 {
		 printf("%d ",p->data);
		 p=p->next;
	 }
	 printf("\n");
}

void insert(struct Node *p,int index,int x)
{
	 struct Node *t;
	 int i;

	 if(index==0)
	 {
		 t=(struct Node *)malloc(sizeof(struct Node));
		 t->data=x;
		 t->prev=NULL;
		 t->next=first;
		 first->prev=t;
		 first=t;
	 }
	 else
	 {
		 for(i=0;i<index-1;i++)
		 p=p->next;
		 t=(struct Node *)malloc(sizeof(struct Node));
		 t->data=x;

		 t->prev=p;
		 t->next=p->next;
		 if(p->next)
		 	p->next->prev=t;
		 p->next=t;

	 }
}
int delete(struct Node *p, int key)
{
	int x;
    while(p)
    {
        if(key==p->data)
        {
            (p->prev)->next=p->next;
            if(p->next)
           		 (p->next)->prev=p->prev;
           	x=p->data;
            free(p);
        }
        p=p->next;
    }
    return x;
}
void displayfromend(struct Node *p)
{
	while((p->next)!=NULL)
		p=p->next;
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->prev;
	}
	printf("\n");
}


int main()
{
	 int A[10];
	 int pos,i,choice, n,value;
	 char t;
	 printf("Enter no of nodes: ");
	 scanf("%d",&n);
	 printf("Enter the values: ");
	 for(i=0;i<n;i++)
	 	scanf("%d",&A[i]);
	 do
	 {
	 printf("Menu: \n1. Create a Doubly Linked List\n2. Display Linked List from the beginning\n3. Display Linked List from the end.\n4. Insert a node of given value in the Linked List\n5. Delete a node of given value from the Linked List\n6. Exit\nChoose one: ");
	 scanf("%d",&choice);
	 switch(choice)
	 {
	 	case 1: 
	 			create(A,n);	
	 			break;
	 	case 2: 
	 			displayfrombeg(first);
	 			break;
	 	case 3: 
	 			displayfromend(first);
	 			break;
	 	case 4: 
	 			printf("Enter position and value to be inserted: ");
	 			scanf("%d%d",&pos,&value);
	 			insert(first, pos, value);
	 			break;
	 	case 5: 
	 			printf("Enter value to be deleted: ");
	 			scanf("%d",&value);
				int d=delete(first, value);
				printf("\nNumber %d is deleted.\n",d);
				break;
		case 6: 
				return;
				break;
		default: 
				printf("Wrong choice.");
	}
	printf("Do you want to continue? (y or n) ");
	fflush(stdin);
	scanf("%c",&t);
	}while(t=='y' || t=='Y');

	 return 0;
}
