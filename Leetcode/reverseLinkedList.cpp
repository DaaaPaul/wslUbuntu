#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) {
	if(!head || !head->next) return head;

	ListNode* fetch = reverseList(head->next);

	head->next->next = head;
	head->next = nullptr;

	return fetch;
}

void printList(ListNode* head) {
	if(!head) return;
	if(!head->next) {
		std::cout << head->val << ' ';
		return;
	}

	std::cout << head->val << ' ';
	printList(head->next);
}

int main() {
	ListNode n1(111); 
	ListNode n2(222);
	ListNode n3(333);
	n1.next = &n2;
	n2.next = &n3;
	n3.next = nullptr;
	ListNode* n1p = &n1;
	ListNode* n2p = &n2;
	ListNode* n3p = &n3;

	printList(n1p);
	std::cout << '\n';
	ListNode* reversed = reverseList(n1p);
	printList(reversed);
}
