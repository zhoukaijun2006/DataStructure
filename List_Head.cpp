
/*

#include<iostream>
using namespace std;

template <typename T>

class List
{
public:
	T val;
	List<T>* next = nullptr;
};

template <typename T>
void deleteList(List<T>* head)
{
	List<T>* cur = head;
	List<T>* next = nullptr;

	while (cur != nullptr)
	{
		next = cur->next;
		delete cur;
		cur = next;
	}
}

template <typename T>
void printList(List<T>* cur)
{
	while (cur != nullptr)
	{
		cout << cur->val << " ";
		cur = cur->next;
	}
	cout << endl;
}

template <typename T>

void removeNode(List<T>*& cur, T val)
{ 
	List<int>* ListNode = cur;
	while (ListNode->next != nullptr)
	{
		if (ListNode->next->val == val)
		{
			ListNode->next = ListNode->next->next;
		}
		else
		{
			ListNode = ListNode->next;
		}
	}
}

template <typename T>
void insertNode(List<T>*& cur, T val, T newval)
{
	List<T>* ListNode = cur;
	while (ListNode->next != nullptr)
	{
		if (ListNode->next->val == val)
		{
			List<T>* newNode = new List<T>;
			newNode->val = newval;
			newNode->next = ListNode->next->next;
			ListNode->next = newNode; 
		}
		else
		{
			ListNode = ListNode->next;
		}
	}
}

int main()
{
	List<int>* head = new List <int>;
	List<int>* cur = head;

	for (int i = 0; i <= 100; i += 10)
	{
		cur->next = new List<int>;

		cur = cur->next;

		cur->val = i;

	}

	cur = head->next;

	printList(cur);

	cur = head->next;

	removeNode(cur, 50);

	printList(cur);

	cur = head->next;
	insertNode(cur, 60, 65);

	printList(cur);
}

*/