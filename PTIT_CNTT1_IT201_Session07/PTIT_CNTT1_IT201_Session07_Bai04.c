#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
void sortString(char *str, int size) {
   if (size<1) {
      printf("\n Chuoi khong hop le");
      return;
   }
   char temp[100];
   for (int i = 0; i<size-1; i++) {
      int min = i;
      for (int j = i+1; j <size; j++) {
         if (str[j]< str[min]) {
            min = j;
         }
      }
      if (min != i) {
         char temp = str[i];
         str[i] = str[min];
         str[min] = temp;
      }
   }
}
int main(){
   char str[100];
   printf("Moi nhap chuoi: ");
   fgets(str, 100,stdin);
   str[strcspn(str, "\n")] = 0;
   int size = strlen(str);
   sortString(str, size);
   printf("str = %s",   str);
   return 0;
}
