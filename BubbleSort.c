//Bubble sort practice
#include <stdio.h>
#include <stdbool.h>

void bubbleSort(int* nums, int size) {
	int i, pivot;
	bool swapped;
	do {
		for (i = 0, swapped = false; i < (size - 1); i++) {
			if (nums[i] > nums[i + 1]) {
				pivot = nums[i];
				nums[i] = nums[i + 1];
				nums[i + 1] = pivot;
				swapped = true;
			}
		}
	} while (swapped);
}

int main() {
	int nums[] = {5, 3, 6, 2, 1, 9, 10};
	int size = sizeof(nums) / sizeof(nums[0]);
	bubbleSort(nums, size);
	return 0;
}