#include<stdio.h>

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
  return 0;
}
