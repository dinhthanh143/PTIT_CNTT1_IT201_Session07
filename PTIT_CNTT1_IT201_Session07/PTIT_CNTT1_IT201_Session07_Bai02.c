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
void selectionSort(int *arr, int n) {
   for (int i= 0; i< n-1; i++) {
      int min = i;
      for (int j = i+1; j<n; j++) {
         if (arr[j]<arr[min]) {
            min = j;
         }
      }
      if (min != i) {
         int temp = arr[i];
         arr[i] = arr[min];
         arr[min] = temp;
      }
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
   selectionSort(arr, n);
   printArray(arr, n, "after: ");

   free(arr);
   return 0;
}
