#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head=NULL;
void insertatbegin();
void insertatend();
void insertatpos();
void delatbegin();
void delatend();
//void delatpos();
void display();
void insertatbegin(){
    int x;
    printf("Enter the element to insert : ");
    scanf("%d",&x);
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->prev=NULL;
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
    }
    else{
        newnode->data=x;
        newnode->prev=NULL;
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
    }
    printf("\nNODE IS INSERTED\n");
}
void insertatend(){
    int y;
    printf("Enter to data insertatend: ");
    scanf("%d",&y);
    struct node *newnode,*temp;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=y;
    newnode->next=NULL;
    if(head==NULL){
        newnode->prev=NULL;
        head=newnode;
    }
    else{
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->prev=temp;
        newnode->next=NULL;
    }
    printf("\nNODE is insertedatend\n");
}
void display(){
    struct node *temp;
    if(head==NULL){
        printf("UNDERFLOW\n");
    }
    else{
        temp=head;
        while(temp!=NULL){
            printf("%d->",temp->data);
            temp=temp->next;
        }
    }
}
void insertatpos(){
    struct node *newnode,*temp;
    newnode=(struct node*)malloc(sizeof(struct node));
    int x,pos;
    int i=1;
    printf("Enter the num to insertatpos: ");
    scanf("%d",&x);
    printf("Enter the location to insert: ");
    scanf("%d",&pos);
    newnode->data=x;
    if(head==NULL){
        newnode->prev=newnode->next=NULL;
        head=newnode;
    }
    else{
        temp=head;
        while(i<pos-1){
            temp=temp->next;
            i++;
        }
        newnode->next=temp->next;
        newnode->prev=temp;
        temp->next=newnode;
        temp->next->prev=newnode;
    }
    printf("\nNODE IS INSERTED\n");
}

void delatbegin(){
    struct node *temp;
    temp=head;
    if(head==NULL){
        printf("\nunderflow\n");
    }
    else if(head->next==NULL){
        head=NULL;
        free(head);
    }
    else{
        head=head->next;
        head->prev=NULL;
        free(temp);
    }
    printf("\nNODE IS DELETED\n");
}

void delatend(){
    struct node *temp;
    temp=head;
    if(head==NULL){
        printf("\nUnderflow\n");
    }
    else if(head->next==NULL){
        head=NULL;
        free(head);
        printf("\nNODE IS DELETED\n");
    }
    else{
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->prev->next=NULL;
        free(temp);
        printf("\nNODE IS DELETED\n");
    }
}

int main(){
    int choice;
    while(choice!=7){
        printf("\n ********MAINMENU**********\n");
        printf("\n1.insertatbegin\n2.insertatend\n3.insertatpos\n4.delatbigin\n5.delatend\n6.display\n");
        printf("Enter the choice:");
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
            case 6:display();
            break;
            case 7:exit(0);
            break;
            default:
            printf("Enter the valid number:\n");
        }
    }
}