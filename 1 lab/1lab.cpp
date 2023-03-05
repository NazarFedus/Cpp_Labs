#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DATA_SIZE 32
#define REPEAT_COUNT 1000000

// Macro for repeat code
#define REPEATOR(count, code) \
for (unsigned int indexIteration = (count); indexIteration--;){ code; }
double getCurrentTime() {
	clock_t time = clock();
	if (time != (clock_t)-1) {
		return ((double)time / (double)CLOCKS_PER_SEC);
	}
	return 0.; // else
}

// Function to output array
void printVector(void* data, int count/* 0 - full DATA_SIZE*/) {
	int index = 0;
	for (index = 0; (!count || index < count) && index < DATA_SIZE; index++) {
		printf("%d ", ((int*)data)[index]);
	}
	printf("\n");
}

//QuickSort
void quickSort(int* array, int leftIndex, int rightIndex) {
	int iIndex = leftIndex;
	int jIndex = rightIndex;
	int xElemntValue = array[(leftIndex + rightIndex) / 2];
	do {
		while ((array[iIndex] < xElemntValue) && (iIndex < rightIndex)) {
			++iIndex;
		}
		while ((xElemntValue < array[jIndex]) && (jIndex > leftIndex)) {
			--jIndex;
		}
		if (iIndex <= jIndex) {
			int temp = array[iIndex];
			array[iIndex] = array[jIndex];
			array[jIndex] = temp;
			++iIndex;
			--jIndex;
		}
	} while (iIndex <= jIndex);
	if (leftIndex < jIndex) {
		quickSort(array, leftIndex, jIndex);
	}
	if (iIndex < rightIndex) {
		quickSort(array, iIndex, rightIndex);
	}
}

//ShellSort
void shellSort(int* array, int leftIndex, int rightIndex){

	int dIndex, iIndex, jIndex;
	int sortingSize = rightIndex - leftIndex + 1;
	for (dIndex = leftIndex + sortingSize / 2; dIndex >= leftIndex + 1; dIndex /= 2)
	{
		for (iIndex = dIndex; iIndex < sortingSize; iIndex++)
		{
			for (jIndex = iIndex; jIndex >= dIndex && array[jIndex - dIndex] >
				array[jIndex]; jIndex -= dIndex) {
				int temp = array[jIndex];
				array[jIndex] = array[jIndex - dIndex];
				array[jIndex - dIndex] = temp;
			}
		}
	}
}


int main(void){
     // begin array for quickSort
	int data[DATA_SIZE] = { 11, 2, 29, 28, 10, 26, 25, 24,
		23, 24, 21, 30, 19, 18, 7, 16,
		17, 14, 13, 12, 10, 27, 9, 8,
		7, 6, 5, 4, 3, 1, 0, 31 };
	double startTime, endTime;

	startTime = getCurrentTime();
	REPEATOR(REPEAT_COUNT, quickSort(data, 0, DATA_SIZE-1));
	endTime = getCurrentTime();

     // output result
	printf("QuickSort (run time): %dns\r\n\r", (unsigned int)((endTime - startTime) * (double)(1000000000 / REPEAT_COUNT)));

     printf("Sorted array: ");
	printVector(data, 0);

     // begin array for shellSort
	int data1[DATA_SIZE] = { 11, 2, 29, 28, 10, 26, 25, 24,
		23, 24, 21, 30, 19, 18, 7, 16,
		17, 14, 13, 12, 10, 27, 9, 8,
		7, 6, 5, 4, 3, 1, 0, 31 };

	startTime = getCurrentTime();
	REPEATOR(REPEAT_COUNT, shellSort(data1, 0, DATA_SIZE - 1));
	endTime = getCurrentTime();

     // output result
	printf("\nShellSort (run time): %dns\r\n\r", (unsigned int)((endTime - startTime) * (double)(1000000000 / REPEAT_COUNT)));

     printf("Sorted array: ");
     printVector(data1, 0);

	return 0;
}
