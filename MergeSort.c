#include <stdio.h>
#include <stdlib.h>

void merge(int* nums, int left, int middle, int right) {
	int i, j, k;
	int sizeLeft = middle - left + 1;
	int sizeRight = right - middle;
	int* LEFT = (int*)malloc(sizeof(int) * sizeLeft);
	int* RIGHT = (int*)malloc(sizeof(int) * sizeRight);

	for (i = 0; i < sizeLeft; i++)
		LEFT[i] = nums[left + i];
	for (j = 0; j < sizeRight; j++)
		RIGHT[j] = nums[middle + j + 1];

	i = j = 0;
	k = left;
	while (i < sizeLeft && j < sizeRight) {
		if (LEFT[i] < RIGHT[j]) {
			nums[k] = LEFT[i++];
		} else {
			nums[k] = RIGHT[j++];
		}
		k++;
	}
	while (i < sizeLeft) {
		nums[k++] = LEFT[i++];
	}
	while (j < sizeRight) {
		nums[k++] = RIGHT[j++];
	}
}

void mergeSortHelper(int* nums, int left, int right) {
	int middle;
	if (left < right) {
		middle = (left + right) / 2;
		mergeSortHelper(nums, left, middle);
		mergeSortHelper(nums, middle + 1, right);
		merge(nums, left, middle, right);
	}
}

int main() {
	int nums[] = {3, 5, 1, 2, 8, 4};
	int size = sizeof(nums) / sizeof(nums[0]);
	mergeSortHelper(nums, 0, size - 1);
	return 0;
}