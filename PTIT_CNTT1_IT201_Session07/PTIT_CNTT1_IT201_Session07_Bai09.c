#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
void sort(int *arr, int n) {
   int *odd = NULL;
   int *even = NULL;
   int j = 0;
   int k = 0;
   for (int i = 0; i<n; i++) {
      if ( arr[i] %2 != 0) {
         j++;
         odd = realloc(odd, j*sizeof(int));
         odd[j-1] = arr[i];
      }else if (arr[i]%2 == 0) {
         k++;
         even = realloc(even, k*sizeof(int));
         even[k-1] = arr[i];
      }
   }
//sort
   for (int i = 0; i<k-1; i++) {
      for (int h = 0; h<k-i-1; h++) {
         if (even[h+1]< even[h]) {
            int temp = even[h];
            even[h] = even[h+1];
            even[h+1] = temp;
         }
      }
   }
   for (int i = 1; i<j; i++) {
      int temp = odd[i];
      int h = i-1;
      while ( h>=0 && odd[h]<temp) {
         odd[h+1] = odd[h];
         h--;
      }
      odd[h+1] = temp;
   }
      for (int i = 0; i<k; i++) {
         arr[i] = even[i];
      }
      for (int i = 0; i<j; i++) {
         arr[k] = odd[i];
         k++;
      }
      free(odd);
      free(even);
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
