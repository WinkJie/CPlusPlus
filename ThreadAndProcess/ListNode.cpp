#include "ListNode.h"

ListNode::ListNode()
{
	head = nullptr;
}

ListNode::~ListNode()
{
}

void ListNode::insertNode(int data, int position)
{
	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = NULL;
	if (position == 0) {
		newNode->next = head;
		head = newNode;
	}
	else {
		Node* temp = head;
		for (int i = 0; i < position - 1; i++) {
			temp = temp->next;
		}
		newNode->next = temp->next;
		temp->next = newNode;
	}
}

void ListNode::deleteNode(int position)
{
	if (head == NULL) {
		return;
	}
	Node* temp = head;
	if (position == 0) {
		head = temp->next;
		delete temp;
		return;
	}
	for (int i = 0; temp != NULL && i < position - 1; i++) {
		temp = temp->next;
	}

	if (temp == NULL || temp->next == NULL) {
		return;
	}
	Node* next = temp->next->next;
	delete temp->next;
	temp->next = next;
}

int ListNode::findData(int data)
{
	int position = 0;
	Node* temp = head;
	while (temp != NULL) {
		if (temp->data == data) {
			return position;
		}
		position++;
		temp = temp->next;
	}
	return -1;
}

void ListNode::ReserverList()
{	
	Node* prev = NULL;
	Node* current = head;
	Node* next = NULL;
	while (current != NULL) 
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
}

ListNode* ListNode::ReserverList(ListNode* pHead, bool style)
{
	ListNode* num = nullptr;
	if (style) 
	{
		//方式一：递归方式
		if (!pHead || !pHead->next)
			return pHead;
		ListNode* tail = ReserverList(pHead->next);
		pHead->next->next = pHead;
		pHead->next = nullptr;
		num = tail;
	}
	else
	{
		//方式二：
		if (pHead == nullptr || pHead->next == nullptr)
			return pHead;
		ListNode* prev = NULL;
		ListNode* current = pHead;
		ListNode* next = NULL;
		while (current != nullptr) {
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}
		num = prev;
	}	
	return num;
}

ListNode* ListNode::clear(ListNode* pHead)
{
	pHead->next = nullptr;
	return pHead;
}
