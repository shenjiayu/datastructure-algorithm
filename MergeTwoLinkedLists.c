#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode *l1, struct ListNode *l2) {
	if (!l1 || !l2)
		return l1 == NULL ? l2 : l1;

	struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode *));
	struct ListNode *cur;

	//find the first node
	if (l1->val > l2->val) {
		cur = head = l2;
		l2 = l2->next;
	} else {
		cur = head = l1;
		l1 = l1->next;
	}

	while (l1 && l2) {
		if (l1->val > l2->val) {
			cur->next = l2;
			l2 = l2->next;
		} else {
			cur->next = l1;
			l1 = l1->next;
		}
		cur = cur->next;
	}

	if (l1) {
		cur->next = l1;
	} else if (l2) {
		cur->next = l2;
	}

	return head;
}

int main() {
	struct ListNode *l1 = (struct ListNode *)malloc(sizeof(struct ListNode *));
	struct ListNode *l2 = (struct ListNode *)malloc(sizeof(struct ListNode *));
	struct ListNode *result;

	l1->val = 1;
	l2->val = 2;
	
	mergeTwoLists(l1, l2);
	free(l1);
	free(l2);
	free(result);
	return 0;
}