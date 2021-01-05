#include "sort.h"
#include <stdio.h>
#define N 50

int main(){

    int arr[N];
    for(int i=0; i<N; i++){
        printf("enter value for arr[%d]: \n",i);
        if (scanf("%d", &(*(arr+i))) != 1) {
            printf("bad input, try again\n");
            int c = getchar(); // clear input buffer
            while (c != '\n' && c != EOF)
                c = getchar();
            i--;
        }
    }
    insertion_sort(arr,N);
    printf("output:\n");
    for (int i = 0; i < N-1; i++)
    {
        printf("%d,", arr[i]);
    }
    printf("%d",arr[N-1]);
    printf("\n");
    return 0;
}