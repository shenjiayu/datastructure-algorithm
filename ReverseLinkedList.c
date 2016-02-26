#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int val;
	struct Node* next;
} Node;

/*
 * steps:
 * (1.) 0->1->2->3->4
 * (2.) 1->0->2->3->4
 * ...
 * @param Node* head
 * @return void
 */
void reverseLinkedList(Node* head) {
	Node* currentNode = head->next;
	//the head node is always needed to be kept 
	Node* currentTmpHead = head;
	while (currentNode) {
		head->next = currentNode->next;
		currentNode->next = currentTmpHead;
		currentTmpHead = currentNode;
		currentNode = head->next;
	}
}

int main() {
	Node* head = (Node*)malloc(sizeof(Node));
	Node* node1 = (Node*)malloc(sizeof(Node));
	Node* node2 = (Node*)malloc(sizeof(Node));
	Node* node3 = (Node*)malloc(sizeof(Node));
	Node* node4 = (Node*)malloc(sizeof(Node));
	head->val = 0;
	head->next = node1;
	node1->val = 1;
	node1->next = node2;
	node2->val = 2;
	node2->next = node3;
	node3->val = 3;
	node3->next = node4;
	node4->val = 4;
	node4->next = NULL;
	reverseLinkedList(head);
	free(head);
	free(node1);
	free(node2);
	free(node3);
	free(node4);
	return 0;
}