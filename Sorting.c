#include<stdio.h>

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
  }
  return 0;
}
