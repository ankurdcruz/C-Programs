#include <stdio.h>
#include <stdlib.h>
struct Node
{
	 int data;
	 struct Node *next;
}*first=NULL;
void create(int A[],int n)
{
	 int i;
	 struct Node *t,*last;
	 first=(struct Node *)malloc(sizeof(struct Node));
	 first->data=A[0];
	 first->next=NULL;
	 last=first;

	 for(i=1;i<n;i++)
	 {
		 t=(struct Node*)malloc(sizeof(struct Node));
		 t->data=A[i];
		 t->next=NULL;
		 last->next=t;
		 last=t;
	 }
}
void Display(struct Node *p)
{
	 while(p!=NULL)
	 {
		 printf("%d ",p->data);
		 p=p->next;
 	 }
}
int Delete(struct Node *p, int index, int noOfNodes)
{
	 struct Node *q=NULL;
	 int x=-1,i;

	 if(index < 1 || index > noOfNodes)
		 return -1;
	 if(index==1)
	 {
		 q=first;
 		 x=first->data;
		 first=first->next;
		 free(q);
		 return x;
	 }
	 else
	 {
	 for(i=0;i<index-1;i++)
 		{
 			 q=p;
			 p=p->next;
		}
	 	 q->next=p->next;
		 x=p->data;
		 free(p);
		 return x;

    }
}
int main()
{
	 int l,a[l];
	 int i,n;
	 printf("How many nodes do you want? ");
	 scanf("%d",&l);
	 for(i=0; i<l; i++)
	 	scanf("%d",&a[i]);
	 create(a,l);
	 printf("Delete which node: ");
	 scanf("%d",&n);
	 int d=Delete(first,n,l);
	 if(d==-1)
	 	printf("Node does not exist \n");
	 else
	 	printf("Number deleted is: %d \n",d);

	 printf("The numbers in the linked list are: ");
 	 Display(first);

 return 0;
}