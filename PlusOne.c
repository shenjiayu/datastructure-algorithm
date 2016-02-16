//66. Plus One
#include <stdio.h>
#include <stdlib.h>

int* plusOne(int* digits, int digitsSize, int* result) {
	if (digits == NULL) return NULL;
	int i;
	i = digitsSize - 1;
	if (digits[digitsSize - 1] < 9) {
		digits[digitsSize - 1]++;
	} else {
		while (digits[i] == 9 && i >= 0) {
			digits[i] = 0;
			i--;
		}
	}
	if (digits[0] == 0) {
		result[0] = 1;
		for (i = 1; i < digitsSize; i++) 
			result[i] = digits[i - 1];
	} else {
		for (i = 0; i < digitsSize; i++)
			result[i] = digits[i];
	}

	return result;
}

int main() {
	int digits[] = {9,8,7,6,5,4,3,2,1,0};
	int* result = (int*)malloc(sizeof(int) * 11);
	int i;
	for (i = 0; i < 11; i++) 
		result[i] = 0;
	plusOne(digits, 10, result);
	for (int i = 0; i < 11; i++) 
		printf("%d\n", result[i]);
	return 0;
}