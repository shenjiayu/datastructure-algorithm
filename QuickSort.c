#include <stdio.h>

void quickSort(int* nums, int first, int last) {
	int left, right, pivot, temp;
	if (first < last) {
		left = first;
		right = last;
		pivot = first;
		while (left < right) {
			while (nums[left] <= nums[pivot] && left < last)
				left++;
			while (nums[right] > nums[pivot])
				right--;
			printf("Left: %d, Right: %d\n", left, right);
			if (left < right) {
				temp = nums[left];
				nums[left] = nums[right];
				nums[right] = temp;
			}
		}
		temp = nums[pivot];
		nums[pivot] = nums[right];
		nums[right] = temp;
		quickSort(nums, first, right - 1);
		quickSort(nums, right + 1, last);
	}
}

int main() {
	int nums[] = {5, 2, 3, 1, 4, 9, 7};
	int size = sizeof(nums) / sizeof(nums[0]);
	quickSort(nums, 0, size - 1);
	int i;
	for (i = 0; i < size; i++)
		printf("%d\n", nums[i]);
	return 0;
}