#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 26

struct TrieNode {
	struct TrieNode *children[MAX_SIZE];
	bool isWord;
};

struct TrieNode* newTrieNode() {
	struct TrieNode *node = (struct TrieNode *)malloc(sizeof(struct TrieNode));
	if (node == NULL)
		exit(1);
	int i;
	memset(node->children, 0x0, sizeof(struct TrieNode *)*26);
	node->isWord = false;
	return node;
}

void insert(struct TrieNode *root, char *word) {
	int i, length, index;
	length = strlen(word);
	if (length <= 0) return;
	struct TrieNode *current = root;
	for (i = 0; i < length; i++) {
		index = word[i] - 'a';
		if (current->children[index] == NULL) {
			current->children[index] = newTrieNode();
		}
		current = current->children[index];
	}
	current->isWord = true;
}

bool search(struct TrieNode *root, char *word) {
	int i, length, index;
	length = strlen(word);
	if (length <= 0) return true;
	struct TrieNode *current = root;
	for (i = 0; i < length; i++) {
		index = word[i] - 'a';
		current = current->children[index];
		if (current == NULL) return false;
	}
	return current->isWord;
}

bool startsWith(struct TrieNode *root, char *prefix) {
	int i, length, index;
	length = strlen(prefix);
	if (length <= 0) return true;
	struct TrieNode *current = root;
	for (i = 0; i < length; i++) {
		index = prefix[i] - 'a';
		current = current->children[index];
		if (current == NULL) return false;
	}
	return true;
}

void trieFree(struct TrieNode *root) {
	if (!root) return;
	int i;
	for (i = 0; i < MAX_SIZE; i++) {
		struct TrieNode *node = root->children[i];
		if (!node) trieFree(node);
	}
	free(root);
}

int main() {
	struct TrieNode *root = newTrieNode();
	insert(root, "hello");
	printf("%d\n", search(root, "hel"));
	free(root);
	return 0;
}