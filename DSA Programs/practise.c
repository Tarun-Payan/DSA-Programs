#include<stdio.h>
//Buble sort
void bubleSort(int arr[], int size){
    int i,j,temp;
    for(i = 0; i < size; i++){
        for(j = 0; j < size-i-1; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// insertionSort
void insertionSort(int arr[], int size){
    int i, j, temp;
    for(i = 1; i < size; i++){
        for(j = i; arr[j] < arr[j-1]; j--){
            temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
        }
    }
}

// selectionSort
void selectionSort(int arr[], int size){
    int i, j, smallest, temp;
    for(i = 0; i < size-1; i++){
        smallest = i;
        // This loop find index of smallest element for i th index
        // array elements are sorted after the i th index, so not find element for them
        for(j = i+1; j < size; j++){
            if(arr[j] < arr[smallest]){
                smallest = j;
            }
        }
        // if smallest element is not at i th index then swap it
        if(smallest != i){
            temp = arr[smallest];
            arr[smallest] = arr[i];
            arr[i] = temp;
        }
    }
}

// Shell Sort
void shellSort(int arr[], int size);

// Merge Sort
void mergeSort(int arr[], int low, int high);
void merge(int arr[], int low, int high, int mid);

// Quick Sort
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);

void printArr(int arr[], int size){
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
}

// Heap Sort
void heapSort(int arr[], int size);
void heapify(int arr[], int root, int size);

int main(){
    int arr[] = {2, 43, 53, 12, 53, 74, 82, 26, 49};
    int size = sizeof(arr)/sizeof(arr[0]);

    printf("Array after sorting\n");
    printArr(arr, size);

    // printf("\nArray before buble sorting\n");
    // bubleSort(arr, size);
    // printArr(arr, size);

    // printf("\nArray before insertion sorting\n");
    // insertionSort(arr, size);
    // printArr(arr, size);

    // printf("\nArray before selection sorting\n");
    // selectionSort(arr, size);
    // printArr(arr, size);

    printf("\nArray before shell sorting\n");
    shellSort(arr, size);
    printArr(arr, size);

    // printf("\nArray before merge sorting\n");
    // mergeSort(arr, 0, size-1);
    // printArr(arr, size);

    // printf("\nArray before quick sorting\n");
    // quickSort(arr, 0, size-1);
    // printArr(arr, size);

    // printf("\nArray before heap sorting\n");
    // heapSort(arr, size-1);
    // printArr(arr, size);

    return 0;
}

void shellSort(int arr[], int size){
    int i, j, temp;
    int gap;

    for(gap = size/2; gap > 0; gap /= 2){
        for(j = gap; j < size; j++){
            for(i = j - gap; i >= 0; i -= gap){
                if(arr[i] > arr[i+gap]){
                    temp = arr[i];
                    arr[i] = arr[i+gap];
                    arr[i+gap] = temp;
                }
                else
                    break;
            }
        }
    }
}

void mergeSort(int arr[], int low, int high){
    int mid = (high + low)/2;

    if(low < high){
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, high, mid);
    }
}

void merge(int arr[], int low, int high, int mid){
    int i, j, k;
    int a[(high-low)+1];
    i = low;
    j = mid+1;
    k = 0;

    while(i <= mid && j <= high){
        if(arr[i] <= arr[j]){
            a[k] = arr[i];
            i++;
            k++;
        }
        else if(arr[i] > arr[j]){
            a[k] = arr[j];
            j++;
            k++;
        }
    }

    while(i <= mid){
        a[k] = arr[i];
        k++;
        i++;
    }

    while(j <= high){
        a[k] = arr[j];
        k++;
        j++;
    }

    for(i = low, j = 0; i <= high; i++, j++){
        arr[i] = a[j];
    }
}

void quickSort(int arr[], int low, int high){
    int pivot;

    if(low < high){
        pivot = partition(arr, low, high);

        quickSort(arr, low, pivot-1);
        quickSort(arr, pivot+1, high);
    }
}

int partition(int arr[], int low, int high){
    //  {2, 43, 53, 12, 53, 74, 82, 26, 49};
    //  {2} {12, 26, 43j, 53i, 74, 82, 53, 49}
    //  {2} {12j, 26i} {43} {53, 49, 53ij, 82, 74}
    //  {2} {12, 26} {43} {49, 53} {53} {74, 82}
    //  {2} {12} {26} {43} {49} {53} {53} {74} {82}

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

void heapSort(int arr[], int size){
    for(int i = size/2 ; i >= 0; i--){
        heapify(arr, i, size);
    }

    for(int i = size; i > 0; i--){
        int temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;

        heapify(arr, 0, i-1);
    }
}

void heapify(int arr[], int root, int size){
    int leftChild = (root*2)+1;
    int rightChild = (root*2)+2;
    int largest = root;

    if(arr[leftChild] > arr[largest] && leftChild <= size){
        largest = leftChild;
    }
    if(arr[rightChild] > arr[largest] && rightChild <= size){
        largest = rightChild;
    }
    if(arr[largest] > arr[root] && largest != root){
        int temp = arr[largest];
        arr[largest] = arr[root];
        arr[root] = temp;

        heapify(arr, largest, size);
    }
}