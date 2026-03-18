#include <stdio.h>
#include <stdlib.h>

struct elementType {
    char* name;
    int id;
};


struct listInfo{
    int capacity;
    struct elementType *theArray;
    unsigned int count;
};

typedef struct listInfo *list;
typedef int position;

list create( int capacity){
    list L= malloc(sizeof(struct listInfo));
    if (L==NULL){
        printf ("cannot print the list");
        return NULL;
    }

    L->theArray= malloc (sizeof (struct elementType)*capacity);

    if (L->theArray==NULL){
        printf ("cannot print the list");
        return NULL;
    }

    L->capacity = capacity;
    L->count=0;

    return L;
}

int isEmpty( list L){
    return L->count == 0;
}

int isFull(list L){
    return L->count == L->capacity;
}

int insert(list L, struct elementType e, position p){
    if (p > L->count || isFull(L)){
        return 0;
    }
    position current = L->count;
    while (current!=p){
        L->theArray[current] = L->theArray[current-1];
        current--;
    }
    L->theArray[current] = e;
    L->count++;
    return 1;
}

void showlist (list L){
    if (isEmpty(L)){
        printf ("the list is empty");
        return;
    }
    for (int i=0; i < L->count; i++){
        printf ("ID: %u     Name: %s\n", L->theArray[i].id, L->theArray[i].name);
    }
}


int delete(list L, position p){
    if (p < 0 || p >= L->count)
        return 0;
    while (p < L->count-1){
        L->theArray[p] = L->theArray[p +1];
        p++;
    }
    L->count--;
    return 1;
}

position find (list L, int id){
    for (int i = 0; i < L->count; i++){
        if (L->theArray[i]int )
    }
}

int main (){
    list lstCTDL16= create(50);

    struct elementType std1;
    struct elementType std2;
    struct elementType std3;
   
    std1.id=1; std1.name = "Nguyen Van A";
    std2.id=2; std2.name = "Nguyen Van B";
    std3.id=3; std3.name = "Nguyen Van C";

    insert (lstCTDL16, std1, 0);
    insert (lstCTDL16, std2, 1);
    insert (lstCTDL16, std3, 2);

    showlist(lstCTDL16);

    return 0;
}