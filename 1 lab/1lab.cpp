#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

#define N 100000
#define REPEAT (count, code) for(int i = 0; i < count; i++){ code }

double getCurrentTime(){
     clock_t time = clock();
     if(time != (clock_t) - 1){
          return ((double)time / (double)CLOCKS_PER_SEC);
     }
     return 0;
}


// ShellSort
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

// QuickSort
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

     double startTime, endTime;

     // For ShellSort
          // input data
          int mass[N];
          for(int i = 0; i < N; i++){
               mass[i] = rand() % 100;
          }
          // sort
          startTime = getCurrentTime();
          ShellSort(N, mass);
          endTime = getCurrentTime();

          cout << "ShellSort: " << endTime - startTime << endl;

     // For QuickSort
          // input data
          int arr[N];
          for(int i = 0; i < N; i++){
               arr[i] = rand() % 100;
          }
          // sort
          startTime = getCurrentTime();
          QuickSort(arr, 0, N-1);
          endTime = getCurrentTime();

          cout << "QuickSort: " << endTime - startTime << endl;
}