#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};

struct node* reverse(struct node *head){
	struct node* curr=head;
	struct node* prev=NULL;
	struct node* nxt;
	while(curr!=NULL){
		nxt=curr->next;
		curr->next=prev;
		prev=curr;
		curr=nxt;
	}
	return prev;
}

struct node* createnode(int value){
	struct node* temp=malloc(sizeof(struct node));
	temp->data=value;
	temp->next=NULL;
	return temp;
}

struct node* addList(struct node* head1,struct node* head2){
	struct node *temp,*result,*head3;
	result = NULL;
	int carry=0;
	int val;
	head3=result;
	while(head1!=NULL&&head2!=NULL){
		val=(head1->data)+(head2->data)+carry;
		head1 = head1->next;
		head2 = head2->next;
		temp=createnode(val%10);
		carry=val/10;
		if(result==NULL){
			result=temp;
			head3 = result;
		}
		else{
			result->next=temp;
			result=result->next;
		}
	}
	while(head1!=NULL){
		val=(head1->data)+carry;
		head1=head1->next;
		temp=createnode(val%10);
		carry=val/10;
		if(result==NULL)
		{
			result=temp;
			head3 = result;
		}
		else
		{
			result->next=temp;
			result=result->next;
		}
	}
	while(head2!=NULL){
                val=(head2->data)+carry;
		head2 = head2->next;
                temp=createnode(val%10);
                carry=val/10;
                if(result==NULL)
                {
                        result=temp;
			head3 = result;
                }
                else
                {
                        result->next=temp;
                        result=result->next;
                }
        }
	return head3;
}

struct node * createList(int item,struct node * head){
	struct node * head1 = head;
	struct node * temp = createnode(item);
	if(head == NULL){
		head = temp;
		return head;
	}
	while(head->next != NULL){
		head = head->next;
	}
	head->next = temp;
	return head1;
}
void display(struct node * head){
	while(head!=NULL){
		printf("%d->",head->data);
		head = head->next;
	}
	printf("\n");
}
int main()
{	
	int item,choice;
        struct node *head1, *head2, *head3;
        head1 = NULL;
        head2 = NULL;
        choice = 1;
        while(choice==1){
		printf("Enter Data in list 1");
		scanf("%d",&item);
		head1 = createList(item,head1);
		printf("\nDo you want to insert nore");
		scanf("%d",&choice);

       }
       printf("Creating Linked List 2");
       choice = 1;
       while(choice == 1){
		printf("Enter Data in list 2");
                scanf("%d",&item);
                head2 = createList(item,head2); 
                printf("\nDo you want to insert nore");
                scanf("%d",&choice);
	}
	display(head1);
	display(head2);
	head1 = reverse(head1);
	head2 = reverse(head2);
	//display(head1);
	//display(head2);
	head3 = addList(head1,head2);
	head3 = reverse(head3);
	display(head3);
	
	//insert(item);
	
}
