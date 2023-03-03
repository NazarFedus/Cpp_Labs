#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// Сортування Шелла
void ShellSort(int n, int mass[])
{
    int i, j, step;
    int tmp;
    for (step = n / 2; step > 0; step /= 2)
        for (i = step; i < n; i++)
        {
            tmp = mass[i];
            for (j = i; j >= step; j -= step)
            {
                if (tmp < mass[j - step])
                    mass[j] = mass[j - step];
                else
                    break;
            }
            mass[j] = tmp;
        }
}

// Швидке сортування
void QuickSort (int *arr, int a, int b){

     int i=a, j=b, m = rand ()% (b-a) +a;
     int x = * (arr+m);

     do{
          while (i<=b && * (arr+i) < x) i++;
          while (j>=a && * (arr+j) > x) j--;

          if (i <= j){
               if (i < j){
                    int buf=* (arr+i);
                    * (arr+i) =* (arr+j);
                    * (arr+j) =buf;
               }
               i++;
               j--;
          }

     } while (i <= j);

     if (i < b) QuickSort (arr, i,b);

     if (a < j) QuickSort (arr,a,j);
}

int main(){
     
}