#include<stdio.h>

void printArr(int arr[], int n)
{
    int i = 0;
    for (; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

void merge(int arr[], int low, int mid, int hig){
    int i,j,k;
    int a[(hig - low)+1];
    i = low;
    j = mid+1;
    k = 0;
    while(i <= mid && j <= hig){
        if(arr[i] < arr[j]){
            a[k] = arr[i];
            k++;
            i++;
        }
        else{
            a[k] = arr[j];
            k++;
            j++;
        }
    }

    while(i <= mid){
        a[k] = arr[i];
        k++;
        i++;
    }

    while(j <= hig){
        a[k] = arr[j];
        k++;
        j++;
    }

    for(i = 0, j = low; j <= hig; j++, i++){
        arr[j] = a[i];
    }
}

void MergeSort(int arr[], int low, int hig){
    int mid = (low + hig)/2;

    if(low < hig){
        MergeSort(arr, low, mid);
        MergeSort(arr, mid+1, hig);
        merge(arr, low, mid, hig);
    }
}

int main()
{
    int a[] = {3, 24, 65, 23, 61, 55, 78, 91};
    int n = sizeof(a)/sizeof(a[0]);

    printf("Printing elements before sorting :\n");
    printArr(a, n);

    printf("\nPrinting elements after sorting :\n");
    MergeSort(a, 0, n - 1);
    printArr(a, n);

    return 0;
}