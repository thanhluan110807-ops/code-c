#include <stdio.h>
#include <stdlib.h>

int timMax(int *a, int n){
    int max=*a;
    for (int i=0; i<n; i++){
        if (max < *(a+i)) max= *(a+i);
    }
    return max;
}

int main (){
    int *a, n;
    printf ("nhap vao so phan tu: ");
    scanf ("%d", &n);
    a=(int*)malloc(n*sizeof(int));
    for (int i=0; i<n; i++){
        scanf ("%d", a+i);
    }
    printf ("%d", timMax(a, n));
    free(a);
}