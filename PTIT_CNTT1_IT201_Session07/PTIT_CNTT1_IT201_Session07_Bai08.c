#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int *insertArray(int **arr, int *row, int *col) {
   arr = (int **)malloc(*row * sizeof(int *));
   for (int i = 0; i < *row; i++) {
      arr[i] = (int *)malloc(*col * sizeof(int));
      for (int j = 0; j < *col; j++) {
         printf("\nMoi nhap phan tu arr[%d][%d]=:", i, j);
         scanf("%d", &arr[i][j]);
      }
   }
   return arr;
}

int main(){
   int **arr = NULL;
   int row;
   int col;
   printf("Moi nhap so hang: ");
   scanf("%d", &row);
   printf("Moi nhap so cot: ");
   scanf("%d", &col);
   arr = insertArray(arr, &row, &col);
   int k;
   printf("Moi nhap cot muon sap xep: ");
   scanf("%d", &k);
   if ( k <= 0 || k > col) {
      printf("Cot khong hop le");
      return 0;
   }
   k--;
   for (int i = 0; i < row-1; i++) {
      for (int j = 0; j <row-1-i; j++) {
         if (arr[j][k]>arr[j+1][k]) {
            int temp = arr[j][k];
            arr[j][k] = arr[j+1][k];
            arr[j+1][k] = temp;
         }
      }
   }
   for (int i = 0; i < row; i++) {
      printf("\n");
      for (int j=0; j<col; j++) {
         printf("%d\t", arr[i][j]);
      }
   }
   free(arr);
   return 0;
}
