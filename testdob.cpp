#include<stdio.h>
#include<stdlib.h>

void main()
{
	struct node{
		int data;
		struct node *next;	
	};
	struct node *head,*temp,*tail,*del,*bel;
	int item,num,flag,f,g,h;
	head=NULL;
		void atbeg()
		{
			if(head==NULL)
			{
				printf("Inserting First node \n");
				head = (struct node*)malloc(sizeof(struct node));
				printf("enter the data \n");
				scanf("%d",&item);
				head->data=item;
				head->next= temp;
				head=temp;
			}
			else
			{   
		        struct node *ptr = (struct node*)malloc(sizeof(struct node));
				printf("Inserting at first pos \n");
				printf("enter the data \n");
				scanf("%d",&item);
				ptr->data=item;
				ptr->next=head;
				head=ptr;
	        
			}
		}
		void display()
		{
			printf("After inserting:\n");
		    if (head == NULL) 
			{
		        printf("Node empty\n");
		    }
		    else 
				{
			        temp=head;
			        while (temp != head) {
			                
			                item = temp->data;
			                
			                printf("%d \n", item);
			                temp = temp->next;
			        }
				}
	
		}
		while(1)
		{
			scanf("%d",&f);
			switch(f){
				case 1:atbeg();
				break;
				case 2:display();
				break;
				case 3: exit(0);
				break;
			}
		}
}