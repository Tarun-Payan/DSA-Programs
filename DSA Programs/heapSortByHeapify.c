#include<stdio.h>

void heapify(int arr[], int larg, int n){
    int leftchild;
    int rightchild;

    while(larg <= n){
        leftchild = (larg * 2) + 1;
        rightchild = (larg * 2) + 2;
        if(arr[])
    }
}

void heapSort(int arr[], int n){
    int i;
    for(i = (n - 1)/2; i >= 0; i--){
        heapify(arr, i, n);
    }

    for(i = n-1; i >= 0; i--);{
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, 0, i-1);
    }
}

void printArr(int a[], int n){
    int i;
    for(i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
}

int main(){
    int arr[] =  {3, 54, 2 , 44, 12, 41, 93, 33};
    int n = sizeof(arr)/sizeof(int);

    printf("Printing array elements before sorting : \n");
    printArr(arr, n);

    printf("\nPrinting array elements after sorting : \n");
    heapSort(arr, n);
    printArr(arr, n);

    return 0;
}