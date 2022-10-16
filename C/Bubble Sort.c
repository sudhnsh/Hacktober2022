#include <stdio.h>

void swap(int *a, int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
    
void bubblesort(int arr[], int size){
    int i,j;
    for(i=0;i<size-1;i++){
        for(j=0;j<size-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
}

void printarray(int arr[], int size){
    int i;
    for(i=0;i<size;i++){
        printf("%d",arr[i]);
        printf("\n");
    }
}

int main() {
    int arr[]={10,9,8,7,6,5,4,3,2,1,110,12,0,-8,-90};
    int size=sizeof(arr)/sizeof(arr[0]);
    bubblesort(arr,size);
    printf("Sorted array using Bubble Sort: \n");
    printarray(arr,size);
    
    return 0;
}
