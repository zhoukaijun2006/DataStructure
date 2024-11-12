/*

#include <iostream>
using namespace std;

class List
{
public:
	int val;
	List* next;
};

void printList(List* L)
{
	List* cur = L;

	while (cur != nullptr)
	{
		cout << cur->val << " ";
		cur = cur->next;
	}
	cout << endl;

}

void InsertTail(List*& L, int val)
{
	if (L == NULL)
	{
		List* newNode = new List;
		L = newNode;
		L->val = val;
		L->next = nullptr;
		return;
	}
	else
	{
		List* cur = L;

		while (cur->next != nullptr)
		{
			cur = cur->next;
		}

		List* newNode = new List;

		newNode->val = val;
		newNode->next = nullptr;

		cur->next = newNode;

		return;
	}
}

void InsertFront(List*& L1, int val)
{

	List* newNode = new List;

	newNode->val = val;
	newNode->next = L1;

	L1 = newNode;

	return;
}

int main()
{
	List* L1 = new List;
	L1->val = 10;
	L1->next = nullptr;

	List* L2 = new List;
	L2->val = 20;
	L2->next = nullptr;

	List* L3 = new List;
	L3->val = 30;
	L3->next = nullptr;

	L1->next = L2;
	L2->next = L3;

	List* cur = L1;

	List* L = NULL;

	printList(L1);

	InsertTail(L1, 40);
	printList(L1);

	InsertTail(L, 100);
	InsertTail(L, 300);
	printList(L);

	InsertFront(L1, 0);
	printList(L1);

	return 0;
}

*/