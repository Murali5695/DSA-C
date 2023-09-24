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
    while(choice!=3){
        printf("\n********************MAINMENU******************\n");
        printf("\n1.insertatbegin\n2.insertatend\n3.insertatpos\n4.delatbegin\n5.delatend\n6.delatpos\n7.display\n8.exit\n");
        printf("\nEnter the choice:\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:insertatbegin();
            break;
            case 2:display();
            break;
            case 3:exit(0);
            break;
            default:
            printf("Enter the valid number");
        }
    }
}
void insertatbegin(){
    struct node *temp,*newnode;
    int x;
    printf("Enter the number to insertatbegin:\n");
    scanf("%d",&x);
    newnode=(struct node*)malloc(sizeof(struct node));
    if(head==NULL){
        head=newnode;
        head->next=newnode;
    }
    else{
        temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        newnode->next=head;
        head=newnode;
        temp->next=head;
    }
}

void insertatend(){
    int x;
    printf("Enter the number to insert:");
    scanf("%d",&x);
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    if(head==NULL){
        head=newnode;
        newnode->next=head;
    }
    else{
        temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=head;
    }
    printf("\nNODE IS INSERTED\n");
}
void insertatpos(){
    int pos,x;
    int i=1;
    printf("Enter the number to insertatpos:");
    scanf("%d",&x);
    printf("\nEnter the position:");
    scanf("%d",&pos);
    if(head==NULL){
        head=newnode;
        head->next=newnode;
    }
    else{
        temp=head;
        while(i<pos){
            temp=temp->next;
            i++;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
}
void delatend(){
    struct node *temp;
    temp=head;
    if(head==NULL){
        printf("UNDERFLOW");
    }
    else if(temp->next==head){
        head=NULL;
        freee(temp);
    }
    else{
        temp
    }
}
void display(){
    struct node *temp;
    temp=head;
    if(head=NULL){
        printf("\nUNDERFLOW\n");
    }
    else{
        while(temp->next!=head){
            printf("%d-->",temp->data);
            temp=temp->next;
        }
        printf("%d",temp->data);
    }
}