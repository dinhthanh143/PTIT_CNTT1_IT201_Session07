#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
void sort(int *arr, int n) {
   int index = 0;
   int *postitive = NULL;
   int *negative = NULL;
   int j = 0;
   int k = 0;
   for (int i = n-1; i>=0; i--) {
    if ( arr[i]<0) {
       k++;
       negative = realloc(negative, k*sizeof(int));
       negative[k-1] = arr[i];
    }else if (arr[i]>0) {
       j++;
       postitive = realloc(postitive, j*sizeof(int));
      postitive[j-1] = arr[i];
    }
   }

   for (int i = 0; i<k; i++) {
      arr[i] = negative[i];
   }
   arr[k] = 0;
   int l = k+1;
   for (int i = 0; i<j; i++) {
      arr[l] = postitive[i];
      l++;
   }
   free(negative);
   free(postitive);
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
   sort(arr, n);
   for (int i =0; i<n; i++) {
      printf("%d\t", arr[i]);
   }
   return 0;
}
