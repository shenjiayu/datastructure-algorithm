#include <stdio.h>
#include <math.h>

int findMaxNum(int* nums, int size) {
	int maxNum, i;
	maxNum = 0;
	for (i = 0; i < size; i++) {
		if (*(nums + i) > maxNum) {
			maxNum = *(nums + i);
		}
	}
	return maxNum;
}

int getLoopTime(int maxNum) {
	int count = 1;
	while (maxNum/10 > 0) {
		count++;
		maxNum /= 10;
	}
	return count;
}

void initLoop(int array[10][20], int x, int y) {
	int i, j;
	for (i = 0; i < x; i++) {
		for (j = 0; j < y; j++) {
			array[i][j] = -1;
		}
	}
}

void radixSort(int* nums, int size, int index) {
	int bucket[10][20] = {};
	initLoop(bucket, 10, 20);
	int denominator = (int)pow(10, index);
	int i, j, k, remainder;
	for (i = 0; i < size; i++) {
		remainder = (*(nums + i) / denominator) % 10;
		for (j = 0; j < 20; j++) {
			if (bucket[remainder][j] == -1) {
				bucket[remainder][j] = *(nums + i);
				break;
			}
		}
	}

	//put elements in bucket back to array
	k = 0;
	for (i = 0; i < size; i++) {
		for (j = 0; j < 20; j++) {
			if (bucket[i][j] != -1) 
				*(nums + (k++)) = bucket[i][j];
		}
	}
}

void radixSortHelper(int* nums, int size) {
	int i;
	int maxNum = findMaxNum(nums, size);
	int loopTime = getLoopTime(maxNum);
	for (i = 0; i < loopTime; i++) {
		/**
		 * @param nums => the array list of elements to be sorted
		 * @param size => the size of the array list
		 * @param i => current position to be sorted
		 */
		radixSort(nums, size, i);
	}
}

int main() {
	int nums[] = {2, 343, 342, 1, 123, 43, 4343, 433, 687, 654, 3};
	int size = sizeof(nums) / sizeof(nums[0]);
	int i;
	radixSortHelper(nums, size);
	return 0;
}