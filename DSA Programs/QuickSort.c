#include <stdio.h>

void printArr(int arr[], int n)
{
    int i = 0;
    for (; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

int findPartition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low + 1, j = high, temp;

    do
    {
        while (arr[i] <= pivot)
        {
            i++;
        }

        while (arr[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } while (i < j);

    if (j > low)
    {
        temp = arr[low];
        arr[low] = arr[j];
        arr[j] = temp;
    }

    return j;
}

void QuickSort(int arr[], int low, int high)
{
    int partition = findPartition(arr, low, high);
    // printf("%d \n", arr[partition]);
    if (low < high)
    {

        QuickSort(arr, low, partition - 1);
        QuickSort(arr, partition + 1, high);
    }
}

int main()
{
    int a[] = {3, 24, 65, 23, 61, 55, 78, 91};
    // int n = sizeof(a)/sizeof(a[0]);
    int n = 8;

    printf("Printing elements before sorting :\n");
    printArr(a, n);

    printf("\nPrinting elements after sorting :\n");
    QuickSort(a, 0, n - 1);
    printArr(a, n);

    return 0;
}




// int p = low, temp;

    // for(int i = low+1; i <= high; i++){
    //     if(arr[i] <= arr[p]){
    //         temp = arr[p+1];
    //         arr[p+1] = arr[p];
    //         arr[p] = arr[i];
    //         arr[i] = temp;

    //          p++;
    //     }
    // }

    // if(arr[p] == arr[p-1])
    //     return p-1;
    // else
    //     return p;