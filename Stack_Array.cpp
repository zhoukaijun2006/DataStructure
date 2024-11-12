///*
//	栈的实现过程
//*/
//
//#include<iostream>
//using namespace std;
//
//#define MAXSIZE 0xffff
//
//template <class type>
//class my_stack
//{
//private:	
//	int top;
//	int maxsize;
//	type* my_s;
//public:
//	my_stack() :top(-1), maxsize(MAXSIZE)
//	{
//		my_s = new type[maxsize];
//		if (my_s == NULL)
//		{
//			cout << "动态存储分配失败！" << endl;
//			exit(1);
//		}
//	}
//
//	my_stack(int size) :top(-1), maxsize(size)
//	{
//		my_s = new type[maxsize];
//		if (my_s == NULL)
//		{
//			cout << "动态存储分配失败！" << endl;
//			exit(1);
//		}
//	}
//
//	~my_stack()
//	{
//		delete[] my_s;
//	}
//
//	bool Empty();
//	void Push(type tp);
//	type Top();
//	void Pop();
//	int Size();
//};
//
//template <class type>
//	// 判断栈是否为空
//bool my_stack<type>::Empty()
//{
//	if (top == -1)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//
//template<class type>
//
//type my_stack<type>::Top() // 返回栈顶元素
//{
//	if (top != -1) // 如果栈不为空
//	{
//		return my_s[top]; // 返回栈顶元素
//	}
//	else
//	{
//		cout << "栈空" << endl;
//		exit(1);
//	}
//}
//
//template<class type>
//void my_stack<type>::Push(type tp) // 压栈操作
//{
//	if (top + 1 < maxsize)  // 如果栈未满
//	{
//		my_s[++top] = tp; // 先将栈顶指针加1，然后将新元素放入栈顶
//	}
//	else
//	{
//		cout << "栈满" << endl;
//		exit(1);
//	}
//}
//
//template<class type>
//void my_stack<type>::Pop()// 出栈操作
//{
//	if (top >= 0) // 如果栈不为空
//	{
//		top--; // 将栈顶指针减1，实现出栈
//	}
//	else
//	{
//		cout << "栈空" << endl;
//		exit(1);
//	}
//}
//
//template<class type>
//int my_stack<type>::Size() // 返回栈中元素的数量
//{
//	return top + 1; // 栈顶指针加1即为栈中元素的数量
//}
//
//
//int main() {
//	// 创建一个整数栈，使用默认的最大大小 MAXSIZE  
//	my_stack<int> intStack;
//
//	// 压栈操作  
//	intStack.Push(10);
//	intStack.Push(20);
//	intStack.Push(30);
//
//	// 输出栈的大小  
//	cout << "栈的大小: " << intStack.Size() << endl;
//
//	// 输出栈顶元素  
//	cout << "栈顶元素: " << intStack.Top() << endl;
//
//	// 出栈操作  
//	intStack.Pop();
//	cout << "出栈后栈顶元素: " << intStack.Top() << endl;
//
//	// 检查栈是否为空  
//	if (intStack.Empty()) {
//		cout << "栈为空" << endl;
//	}
//	else {
//		cout << "栈不为空" << endl;
//	}
//
//	// 继续出栈操作，直到栈为空  
//	while (!intStack.Empty()) {
//		cout << "出栈元素: " << intStack.Top() << endl;
//		intStack.Pop();
//	}
//
//	// 再次检查栈是否为空  
//	if (intStack.Empty()) {
//		cout << "栈为空" << endl;
//	}
//
//	return 0;
//}
