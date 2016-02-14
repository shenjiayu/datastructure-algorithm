#include <stdio.h>

int binarySearch(int c[], int n, int target) {
	int left = 1, right = n;
    while(left <= right){
        int mid = (left + right)/2;
        printf("MID: %d, Comparing %d and %d\n", mid, c[mid], target);
        if(c[mid] > target)
            right = mid - 1;
        else if(c[mid] < target)
            left = mid + 1;
        else 
            return mid;
    }
    return left;
}

int lengthOfLIS(int* nums, int numsSize) {
	const int len = numsSize;
    if(len <= 1)  return len;
    int c[len+1],ret = 1;
    for(int i = 0; i <= len; i++){
         c[i] = 0;
    }
    c[1] = nums[0];
    for(int i = 1; i < len; i++){
        int temp = binarySearch(c, ret, nums[i]);
        c[temp] = nums[i];
        if(ret < temp)  ret = temp;
    }
    return ret;
}

int main() {
	int nums[] = {10, 9, 2, 5, 3, 7, 101, 18};
	int length = lengthOfLIS(nums, 8);
	printf("%d\n", length);
	return 0;
}