#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int term;
    term=*a;
    *a=*b;
    *b=term;
}

void quicksort(int *pl, int *pr){
    int *i=pl;
    int *j=pr;
    int pivot=*((pr-pl)/2+pl);
    while (i<=j){
        while (*i>pivot) i++;
        while (*j<pivot) j--;
        if (i<=j){
            swap (i, j);
            i++;
            j--;
        }
    }
    if (pl<j) quicksort (pl, j);
    if (i<pr) quicksort (i, pr);
}

int main (){
    int  n, *a;
    printf ("nhap vao so phan tu cua mang: ");
    scanf ("%d", &n);
    a=(int*)malloc(n*sizeof(int));
    for (int i=0; i<n; i++){
        printf ("a[%d]=", i);
        scanf ("%d", a+i);
    }
    printf ("mang truoc khi sap xep:");
    for (int i=0; i<n; i++){
        printf ("%d\n", *(a+i));
    }
    quicksort(a, a+n-1);
    printf ("mang sau khi sap xep: ");
    for (int i=0; i<n; i++){
        printf ("%d\n", *(a+i));
    }
    
    
}