#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

void extend(char* s, int left, int right, char* longest) {
	int length;
	length = strlen(s);
	while (left >= 0 && right <= length) {
		if (s[left] != s[right]) {
			return;
		} else if ((right - left + 1) > strlen(longest)){
			strncpy(longest, s+left, right - left + 1);
		}
		left--;
		right++;
	}
}

char* longestPalindrome(char* s) {
    if (s == NULL) return NULL;
    int i, length;
    char* longest = (char*)malloc(sizeof(char*));
    length = strlen(s);
    for (i = 0; i < length; i++) {
    	extend(s, i, i, longest);
    	extend(s, i, i + 1, longest);
    }
    return longest;
}

int main() {
	printf("%s\n", longestPalindrome("zeusnilemacaronimaisanitratetartinasiaminoracamelinsuez"));
	return 0;
}