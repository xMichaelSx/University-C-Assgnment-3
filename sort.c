#include "sort.h"
#include <stdio.h>

void shift_element(int* arr, int i){

    if (i == 0 || arr == NULL){
        printf("Nothing to do here");
        return;
    }
    int *end_ptr = (arr + i); // takes me to the length-1 place of the array.
    while (end_ptr != arr){
        *(end_ptr+1) = *(end_ptr);
        *(end_ptr) = 0;
        end_ptr--;
    }
}

void insertion_sort(int* arr , int len){

    int *begin = arr;
    int *temp_p = arr;        // temp pointer.
    int *end = (arr + len-1); // pointer to last element.
    int temp = 0;             // temp value.

    while(arr != end){
        if(*(arr) <= *(arr+1)) 
            arr++;
        else
        {
            temp = *(arr+1);
            temp_p = arr;
            while( arr != begin-1  && temp<*(arr))
            {
                arr--;
            }
            shift_element(arr,temp_p-arr);
            *(arr+1) = temp;
            arr = temp_p+1;
        }
    }
}
