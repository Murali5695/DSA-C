#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *front=NULL;
struct node *rear=NULL;
void enqueue();
void dequeue();
void peek();
void display();
void enqueue(){
    int x;
    printf("Enter the number to insert:");
    scanf("%d",&x);
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;
    if(rear==0){
        front=rear=newnode;
        rear->next=front;
        printf("\nNODE is inserted\n");
    }
    else{
        rear->next=newnode;
        rear=newnode;
        rear->next=front;
        printf("\nNODE is INSERTED\n");
    }
}
void dequeue(){
        struct node *temp;
        temp=front;
        if(front==0&&rear==0){
            printf("\nunderflow\n");
        }
        else if(front==rear){
            front=rear=0;
            free(temp);
            printf("\nNODE is Deleted\n");
        }
        else{
            front=front->next;
            rear->next=front;
            free(temp);
            printf("\nNODE is Deleted\n");
        }
}
void peek(){
    if(front==0&&rear==0){
        printf("\nUnderflow\n");
    }
    else{
        printf("\nThe top most element is %d",front->data);
    }
}
void display(){
    if(front==0&&rear==0){
        printf("\nUnderflow\n");
    }
    else{
        struct node *temp;
        temp=front;
        while(temp->next!=front){
            printf("%d->",temp->data);
            temp=temp->next;
        }
        printf("%d",rear->data);
    }
}
int main(){
    int choice;
    while(choice!=5){
        printf("\nEnter the choice:\n1.insertion\n2.deletion\n3.display\n4.peek\n");
        printf("\nEnter the choice:\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: enqueue();
            break;
            case 2: dequeue();
            break;
            case 3: display();
            break;
            case 4:  peek();
            break;
            case 5: exit(0);
            break;
            default:
            printf("Enter the valid number");
        }
    }
}