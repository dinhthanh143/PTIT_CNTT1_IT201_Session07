#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
void printArray(int *arr, int n, char text[]) {
   printf("\n%s", text);
   for (int i =0; i<n; i++) {
      printf("%d\t", arr[i]);
   }
}
void swap(int *a, int*b) {
   int temp = *a;
   *a = *b;
   *b = temp;
}
int partition(int arr[], int left, int right) {
   int pivot = arr[right];
   int i = left - 1;
   for ( int j = left; j <right; j++) {
      if (arr[j]<pivot) {
         swap(&arr[++i], &arr[j]);
      }
      swap(&arr[i+1], &arr[right]);
   }
   return i+1;
}
void quickSort(int arr[], int left, int right) {
   if (left<right) {
      int pivot = partition(arr, left, right);
      quickSort(arr, left, pivot-1);
      quickSort(arr, pivot+1, right);
   }
}
int main(){
   int n;
   while (1) {
      printf("Moi nhap so luong phan tu: ");
      scanf("%d", &n);
      if (n<=0 || n>1000) {
         printf("\n so luong k hop le");
      }else {
         break;
      }
   }
   int *arr = (int*)malloc(n*sizeof(int));
   for (int i = 0; i<n; i++) {
      printf("\n moi nhap phan tu thu %d: ", i+1);
      scanf("%d", &arr[i]);
   }
   printArray(arr, n, "before: ");
   quickSort(arr, 0, n-1);
   printArray(arr, n, "after: ");
   free(arr);
   return 0;
}
