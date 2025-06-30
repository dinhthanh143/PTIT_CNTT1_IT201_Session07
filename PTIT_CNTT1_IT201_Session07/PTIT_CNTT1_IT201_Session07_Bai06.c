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

void merge(int *arr, int left, int mid, int right) {
   int i = left;
   int j = mid +1;
   int k = 0;
   int *temp = malloc((right-left+1)*sizeof(int));
   while ( i<=mid && j<=right) {
      temp[k++] = (arr[i]<arr[j]) ? arr[i++] : arr[j++];
   }
   while (i<= mid) temp[k++] = arr[i++];
   while ( j<= right) temp[k++] = arr[j++];
   for ( int i = left, k = 0; i<=right; i++, k++) {
      arr[i] = temp[k];
   }
}
void mergeSort(int *arr, int left, int right) {
   if (left>=right) return;
   int mid = (left + right)/2;
   mergeSort(arr,left, mid);
   mergeSort(arr, mid+1, right);
   merge(arr,left,mid,right);
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
   mergeSort(arr, 0, n-1);
   printArray(arr, n, "after: ");
   free(arr);
   return 0;
}
