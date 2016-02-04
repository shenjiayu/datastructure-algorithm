#include <stdio.h>

void merge(int *num1, int m, int *num2, int n) {
	while (n > 0) {
		if (m > 0 && num1[m-1] > num2[n-1]) {
			num1[m+n-1] = num1[m-1];
			m--;
		} else {
			num1[m+n-1] = num2[n-1];
			n--;
		}
	}
}

int main() {
	int num1[] = {1, 3, 5, 8, 0, 0, 0, 0};
	int num2[] = {2, 4, 6, 7};
	merge(num1, 4, num2, 4);
	for (int i = 0; i < 8; i++)
		printf("%d\n", num1[i]);
	return 0;
}