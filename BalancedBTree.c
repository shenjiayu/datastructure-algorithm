#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int height(struct TreeNode *root) {
	if (root == NULL) {
		return 0;
	}
	int leftHeight, rightHeight;
	leftHeight = height(root->left);
	rightHeight = height(root->right);
	return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

bool isBalanced(struct TreeNode *root) {
	if (!root) return true;
	if (root->left == NULL && root->right == NULL) return true;
	int leftHeight, rightHeight;
	leftHeight = height(root->left);
	rightHeight = height(root->right);
	if (abs(leftHeight - rightHeight) > 1) 
		return false;
	else
		return isBalanced(root->left) && isBalanced(root->right);
}

int main() {
	struct TreeNode *root = (struct TreeNode*)malloc(sizeof(struct TreeNode*));
	struct TreeNode *leftNode = (struct TreeNode*)malloc(sizeof(struct TreeNode*));
	root->val = 1;
	leftNode->val = 2;
	leftNode->left = NULL;
	leftNode->right = NULL;
	root->left = leftNode;
	isBalanced(root);
	free(root);
	free(leftNode);
	return 0;
}