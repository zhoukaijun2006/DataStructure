//#include <iostream>
//
//using namespace std;
//
//#define MAXSIZE 0xffff
//
//template<class T>
//class ListNode
//{
//public:
//	T val;
//	ListNode<T>* next = nullptr;
//	ListNode(T t) :val(t) {}
//
//};
//
//template<class T>
//void delete_List(ListNode<T>* head)
//{
//	ListNode<T>* cur = ListNode<T>*head;
//	ListNode<T>* next = nullptr;
//
//	while (cur != nullptr)
//	{
//		next = cur->next;
//		delete cur;
//		cur = next;
//	}
//};
//
//template<class T>
//class Linked_stack
//{
//private:
//	ListNode<T>* stackTop;
//public:
//	Linked_stack() : stackTop(nullptr) {}
//	~Linked_stack()
//	{
//		delete_List(stackTop);
//	}
//
//	bool isEmpty();
//	void push(T t);
//	void pop();
//	T top();
//	int size();
//	
//};
//
//template<class T>
//bool Linked_stack<T>::isEmpty()
//{
//	return stackTop == nullptr;
//}
//
//template<class T>
//void Linked_stack<T>::push(T t)
//{
//	ListNode<T>* newNode = new ListNode<T>(t);
//	newNode->next = stackTop;// 新节点指向当前栈顶  
//	stackTop = newNode; // 更新栈顶为新节点
//}
//
//template<class T>
//void Linked_stack<T>::pop()
//{
//	if (isEmpty())
//	{
//		cout << "Stack is empty" << endl;
//	}
//	else
//	{
//
//	}
//}
//
//int main()
//{
//
//}