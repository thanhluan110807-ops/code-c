#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct word{
    char tu[50];
    char nghia[100];
    char loaiTu[50];
    char phienAm[100];
    struct word *next;
};

typedef struct word word;

int soLuong(word *head){
    int dem=0;
    while(head!=NULL){
        dem++;
        head=head->next;
    }
    return dem;
}


word* nhapTu(){
    word *infor = malloc(sizeof(word));

    printf ("\nnhap tu tieng anh: ");
    fgets(infor->tu,sizeof(infor->tu), stdin );
    infor->tu[strcspn(infor->tu, "\n")]='\0'; //xoa \n cuoi chuoi

    printf ("\nnhap nghia tieng viet: ");
    fgets(infor->nghia, sizeof(infor->nghia), stdin);
    infor->nghia[strcspn(infor->nghia, "\n")]='\0';

    printf ("\nnhap loai tu: ");
    fgets(infor->loaiTu, sizeof(infor->loaiTu), stdin);
    infor->loaiTu[strcspn(infor->loaiTu, "\n")]='\0';

    printf ("\nnhap phien am: ");
    fgets (infor->phienAm, sizeof(infor->phienAm), stdin);
    infor->phienAm[strcspn(infor->phienAm, "\n")]='\0';

    infor->next=NULL;
    return infor;
}


void addWord (word **head){
    word *newWord= nhapTu();
    newWord->next=*head;
    *head=newWord;
}


void xuat (word *head){
    while(head != NULL){
        printf ("\n\n");
        printf ("\nTu: %s", head->tu);
        printf ("\nLoai tu: %s", head->loaiTu);
        printf ("\nNghia: %s", head->nghia);
        printf ("\nPhien am: %s", head->phienAm);
        printf ("\n\n");
        head=head->next;
    }

}

void xoaDau (word **head){
    word *temp=*head;
    *head=(*head)->next;
    free(temp);
}

void xoaTu(word **head, int viTri){//vi tri tu 1->n
    if(viTri < 0 || viTri > soLuong(*head)){
        return;
    }

    if(*head == NULL) return;

    if ((*head)->next == NULL){
        free(*head);
        *head = NULL;
        return;
    }

    if(viTri==1){
        xoaDau(head);
    }
    else{
        word *temp=*head;
        for (int i=1; i<=viTri-2; i++){
            temp=temp->next;
        }
        word *k=temp->next;//k la vi tri muon xoa
        temp->next=k->next;
        free(k);
    }

    
}


int main(){
    word *head=NULL;
    int n;
    printf ("Nhap so luong tu vung muon them: ");
    scanf ("%d", &n);
    getchar();//xoa dau enter
    for (int i=0; i<n; i++){
        addWord(&head);
    }
    printf ("\n-------DANH SACH TU VUNG-------\n");
    xuat(head);
    return 0;
}