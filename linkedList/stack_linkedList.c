#include <stdio.h>
#include <stdlib.h>

struct node {
     int data;
     struct node *next;
};

typedef struct node node;

node *makeNode(int x){
    node *newNode=malloc(sizeof(node));
    newNode->data=x;
    newNode->next=NULL;
    return newNode;
}

void push(node **top, int x){
    node *newNode=makeNode(x);
    newNode->next = *top;
    *top=newNode;
}

void pop(node **top){
    if (*top==NULL) return;
    node *temp=*top;
    *top=temp->next;
    free(temp);
}

int size(node *top){
    int count=0;
    while (top!=NULL){
        count++;
        top=top->next;
    }
    return count;
}

int top(node *top){
    if (top!=NULL){
        return top->data;
    }
}

int main (){
    node *st=NULL;
    while (1){
       printf ("---------------------------------\n");
       printf ("1. push\n");
       printf ("2. pop\n");
       printf ("3. top\n");
       printf ("4. size\n");
       printf ("0. thoat\n");
       printf ("nhap lua chon cua ban: \n");
        printf ("---------------------------------\n");
       int lc, x;
       scanf ("%d", &lc);

       if (lc==1){
        printf ("nhap x: \n");
        scanf ("%d", &x );
        push(&st, x);
       }

       if (lc==2){
        if (st==NULL){
            printf ("EMPTY\n");
        }
        pop(&st);
       }

       if (lc==3){
        if (top==NULL){
            printf ("EMPTY\n");
        }
        printf ("%d\n", top (st));
       }

       if (lc==4){
        printf ("%d\n", size(st));
       }

       if (lc==0){
            break;
       }
    }
    return 0;

}