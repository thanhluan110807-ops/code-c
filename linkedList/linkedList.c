#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node node;

node* makeNode(int x){
    node *newNode=malloc(sizeof( node));
    newNode->data=x;
    newNode->next=NULL;
    return newNode;
}

void duyet(node *head){
    while (head != NULL){
        printf ("%d", head->data);
        printf (" ");
        head=head->next;
    }
}

int count (node *head){
    int dem=0;
    while (head!=NULL){
        dem++;
        head=head->next;
    }
    return dem;
}

void insertHead(node **head, int x){
    node *newNode =makeNode(x);
    newNode->next=*head;
    *head=newNode;
}

void insertBack (node **head, int x){
    node *temp=*head;
    node *newNode=makeNode(x);
    if (*head==NULL){
        *head=newNode;
        return;
    }
    while (temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;

    
}

void popFront(node **head){
    if (*head == NULL) return;

    node *temp=*head;
    *head=(*head)->next;
    free(temp);

}

void popBack(node **head){
    if (*head == NULL) return;
    if ((*head)->next == NULL){
        free(*head);
        *head=NULL;
        return;
    }

    node *temp=*head;
    while (temp->next->next != NULL){
        temp=temp->next;
    }
    free(temp->next);
    temp->next=NULL;
}

int main (){
    
}