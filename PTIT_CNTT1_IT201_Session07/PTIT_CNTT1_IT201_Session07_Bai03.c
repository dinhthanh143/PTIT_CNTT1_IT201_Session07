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
void insertionSort(int *arr, int n) {
   for (int i = 1; i<n; i++) {
      int temp = arr[i];
      int j = i-1;
      while ( j>=0 && arr[j]>temp) {
            arr[j+1] = arr[j];
            j--;
      }
      arr[j+1] = temp;
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
   insertionSort(arr, n);
   printArray(arr, n, "after: ");
   free(arr);
   return 0;
}
