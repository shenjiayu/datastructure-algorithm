#include <stdio.h>
#include <stdbool.h>

void insertionSort(int* nums, int size) {
	int i, j, index, pivot, k, current;
	bool neededSwap = false;
	for (i = 1; i < size; i++) {
		for (j = 0, neededSwap = false; j < i; j++) {
			if (nums[i] < nums[j]) {
				index = j;
				neededSwap = true;
				break;
			}
		}
		current = nums[i];
		if (neededSwap) {
			k = i;
			for (; k > index; k--) {
				nums[k] = nums[k - 1];
			}
		}
		nums[j] = current;
	}
}

int main() {
	int nums[] = {3, 5, 2, 1, 8, 6};
	int size = sizeof(nums) / sizeof(nums[0]);
	insertionSort(nums, size);
	return 0;
}