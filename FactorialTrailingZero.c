#include <stdio.h>

int trailingZeroes(int n) {
    int num = 0;
    while (n != 0) {
    	n /= 5;
    	num += n;
    }
    return num;
}

int main() {
	int number = 12345;
	printf("%d\n", trailingZeroes(number));
	return 0;
}