#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target) {
	int i, j, index1, index2;
	int *r = (int *)malloc(sizeof(int *));
	for (i = 0; i < numsSize; i++) {
		for (j = i + 1; j < numsSize; j++) {
			if (nums[i] + nums[j] == target) {
				r[0] = i + 1;
				r[1] = j + 1;
				return r;
			}
		}
	}
	return r;
}

int main() {
	int nums[4] = {0, 4, 3, 0};
	int *r = twoSum(nums, 4, 0);
	for (int i = 0; i < 2; i++)
		printf("%d\n", r[i]);
	return 0;
}