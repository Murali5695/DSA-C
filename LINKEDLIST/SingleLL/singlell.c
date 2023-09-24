#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head=NULL;
void insertatbegin();
void insertatend();
void insertatpos();
void delatbegin();
void delatend();
void delatpos();
void display();
int main(){
    int choice;
    while(choice!=8){
    printf("\nMAINMENU:\n");
    printf("1.insert at begin \n2.insert at end\n 3.insertion at position\n4.deletion at begin\n5.del at end\n6.del at position\n7.display\n8.exit\n");
    printf("\nEnter the choice:\n");
    scanf("%d",&choice);
    switch(choice){
        case 1:insertatbegin();
        break;
        case 2:insertatend();
        break;
        case 3:insertatpos();
        break;
        case 4:delatbegin();
        break;
        case 5:delatend();
        break;
        case 6:delatpos();
        break;
        case 7:display();
        break;
        case 8:exit(0);
        break;
        default:
        printf("invalid number");
    }
  }
}
void insertatbegin(){
    int item;
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the number to insert");
    scanf("%d",&item);
    newnode->data=item;
    newnode->next=NULL;
    head=newnode;
    printf("\nNODE is inserted\n");
}
void insertatend(){
    int item;
    struct node *newnode,*temp;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the number to insert at end");
    scanf("%d",&item);
    temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->next=NULL;
}
void insertatpos(){
    int item,pos;
    int i=1;
    struct node *newnode,*temp;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the position:");
    scanf("%d",&pos);
    printf("Enter the number to insert");
    scanf("%d",&item);
    temp=head;
    while(i<pos){
        temp=temp->next;
        i++;
    }
    newnode->next=temp->next;
    temp->next=newnode;
    printf("\nnode is inserted\n");
} 

void delatbegin(){
    struct node *temp;
    if(head==NULL){
        printf("underflow");
    }
    else{
        temp=head;
        head=head->next;
        free(temp);
    }
    printf("Node is deleted.\n");
}
void delatend(){
    struct node *temp,*prevnode;
    temp=head;
    while(temp->next!=NULL){
        prevnode=temp;
        temp=temp->next;
    }
    prevnode->next=NULL;
    free(temp);
}
void delatpos(){
    struct node *temp,*nextnode;
    temp=head;
    int pos,i=1;
    printf("Enter the position:");
    scanf("%d",&pos);
    while(i<pos-1){
        temp=temp->next;
        i++;
    }
    nextnode=temp->next;
    temp->next=nextnode->next;
    free(nextnode);
}
void display(){
    struct node*temp;
    temp=head;
    if(head==NULL){
        printf("List is Empty");
    }
    else{
        printf("\nprinting values:\n");
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    }
}