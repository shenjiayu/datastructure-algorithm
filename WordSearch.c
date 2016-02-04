#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 10

bool helper(char board[3][4], int boardRowSize, int boardColSize, int i, int j, int index, char* word) {
	if (index == strlen(word)) return true;
	if (i < 0 || j < 0 || i > boardRowSize || j > boardColSize) return false;
	if (board[i][j] != word[index]) return false;
	bool path = helper(board, boardRowSize, boardColSize, i + 1, j, index + 1, word) ||
				helper(board, boardRowSize, boardColSize, i - 1, j, index + 1, word) ||
				helper(board, boardRowSize, boardColSize, i, j + 1, index + 1, word) ||
				helper(board, boardRowSize, boardColSize, i, j - 1, index + 1, word);
	return path;
}

bool exists(char board[3][4], int boardRowSize, int boardColSize, char* word) {
	int i, j;
	if (boardRowSize == 0 && boardColSize == 0) return false;
	for (i = 0; i < boardColSize; i++) {
		for (j = 0; j < boardRowSize; j++) {
			if (helper(board, boardRowSize, boardColSize, i, j, 0, word)) return true;
		}
	}
	return false;
}

int main() {
	char board[3][4] = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
	printf("%d\n", exists(board, 3, 4, "AD"));
	return 0;
}