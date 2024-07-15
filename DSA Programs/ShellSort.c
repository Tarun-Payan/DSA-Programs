#include<stdio.h>

void Shell_sort(int arr[], int n){
    int gap, i, j;

    for(gap = n/2; gap > 0; gap /= 2){
        for(j = gap; j < n; j++){
            for(i = j-gap; i >= 0; i -= gap){
                if(arr[i+gap] > arr[i]){
                    //swap(arr[i+gap], arr[i]);
                    arr[i+gap] = arr[i+gap] + arr[i];
                    arr[i] = arr[i+gap] - arr[i];
                    arr[i+gap] = arr[i+gap] - arr[i];
                }
                else 
                    break;
            }
        }
    }
}

void display(int arr[], int n){
    for(int i = 0; i < n; i++){
        printf("%d  ",arr[i]);
    }
}

int main(){
    int arr[] = {3, 54, 34, 95, 5, 10, 43};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Before sorting :\n");
    display(arr, n);
    Shell_sort(arr, n);
    printf("After sorting :\n");
    
    display(arr, n);
}