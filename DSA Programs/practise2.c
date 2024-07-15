#include<stdio.h>

int linearSearch(int arr[], int size, int val){
    int i;
    for(i = 0; i < size; i++){
        if(arr[i] == val)
            return i;
    }

    return -1;
}

int binarySearch(int arr[], int size, int val){
    int lowest_ind = 0;
    int highest_ind = size - 1;

    do{
        int mid = (lowest_ind + highest_ind)/2;
        if(arr[mid] == val)
            return mid;
        else{
            if(val > arr[mid])
                lowest_ind = mid + 1;
            else
                highest_ind = mid - 1;
        }
    }while(lowest_ind <= highest_ind);

    return -1;
}

void bubbleSort(int arr[], int size){
    for(int i = size-1; i > 0; i--){
        for(int j = 0; j < i; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void printArr(int arr[], int size){
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
}

int main(){
    int arr[] = {2, 43, 53, 12, 53, 74, 82, 26, 49};
    int size = sizeof(arr)/sizeof(arr[0]);
    int sval = 82;

    int ind = linearSearch(arr, size, sval);
    printf("%d is stored at %d indexed", sval, ind);
    printf("\n");
    bubbleSort(arr, size);
    printArr(arr, size);
    ind = binarySearch(arr, size, sval);
    printf("\n%d is stored at %d indexed", sval, ind);

    return 0;
}