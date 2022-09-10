#include<stdio.h>
#include<math.h>

//Function to swap numbers
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
// Function to print an array of size n
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// INSERTION SORT
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// SELECTION SORT
void selectionSort(int arr[], int n)
{
    int i, j, min;

    for (i = 0; i < n-1; i++)
    {
        // find the minimum element in unsorted array
        min = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min])
            min = j;

        // swap the minimum element with the first element
           if(min != i)
            swap(&arr[min], &arr[i]);
    }
}

// BUBBLE SORT
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

// MERGE SORT
//merge the two halves
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements*/
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements*/
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
        // sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// QUICK SORT
// function to find the partition position
int partition(int array[], int low, int high) {

  int pivot = array[high];

  // pointer for greater element
  int i = (low - 1);

  // traverse each element of the array
  // compare them with the pivot
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {

      // if element smaller than pivot is found
      // swap it with the greater element pointed by i
      i++;

      // swap element at i with element at j
      swap(&array[i], &array[j]);
    }
  }

  // swap the pivot element with the greater element at i
  swap(&array[i + 1], &array[high]);

  // return the partition point
  return (i + 1);
}
void quickSort(int array[], int low, int high) {
  if (low < high) {

    // find the pivot element
    int pi = partition(array, low, high);

    quickSort(array, low, pi - 1);
    quickSort(array, pi + 1, high);
  }
}

int main(){
  int sort;
  int n;
  printf("Enter the number of the type of sort to be implemented\n1.Insertion Sort\n2.Selection Sort\n3.Bubble Sort\n4.Merge Sort\n5.Quick Sort\n");
  scanf("%d", &sort);
  printf("Enter the size of Unsorted Array: ");
  scanf("%d", &n);
  printf("Enter the Unsorted Array:\n");
  int arr[n];
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }
  switch (sort) {
    case 1:
    printf("Sorted array using Insertion Sort: \n");
    insertionSort(arr, n);
    printArray(arr, n);
    break;

    case 2:
    printf("Sorted array using Selection Sort: \n");
    selectionSort(arr, n);
    printArray(arr, n);
    break;

    case 3:
    printf("Sorted array using Bubble Sort: \n");
    bubbleSort(arr, n);
    printArray(arr, n);
    break;

    case 4:
    printf("Sorted array using Merge Sort: \n");
    mergeSort(arr, 0, n - 1);
    printArray(arr, n);
    break;

    case 5:
    printf("Sorted array using Quick Sort: \n");
    quickSort(arr, 0, n - 1);
    printArray(arr, n);
    break;

    default:
    printf("Error! Enter a valid number for the type of sort\n");
    break;
    }
  }
  return 0;
}
