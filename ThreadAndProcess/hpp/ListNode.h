#pragma once
#include "PublicHeader.h"

class ListNode
{
public:
    ListNode* next=nullptr;
    int data=0;
    ListNode* prev=nullptr;
private:
    struct Node {
        int data=0;
        Node* next=nullptr;
    };
    Node* head;

public:
	ListNode();
	~ListNode();
    void insertNode(int data,int position);
    void deleteNode(int position);
    int findData(int data);
    void ReserverList();

public:
	ListNode* ReserverList(ListNode *pHead,bool style=true);
	ListNode* clear(ListNode* pHead);

};