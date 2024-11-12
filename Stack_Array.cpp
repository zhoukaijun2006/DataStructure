///*
//	ջ��ʵ�ֹ���
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
//			cout << "��̬�洢����ʧ�ܣ�" << endl;
//			exit(1);
//		}
//	}
//
//	my_stack(int size) :top(-1), maxsize(size)
//	{
//		my_s = new type[maxsize];
//		if (my_s == NULL)
//		{
//			cout << "��̬�洢����ʧ�ܣ�" << endl;
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
//	// �ж�ջ�Ƿ�Ϊ��
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
//type my_stack<type>::Top() // ����ջ��Ԫ��
//{
//	if (top != -1) // ���ջ��Ϊ��
//	{
//		return my_s[top]; // ����ջ��Ԫ��
//	}
//	else
//	{
//		cout << "ջ��" << endl;
//		exit(1);
//	}
//}
//
//template<class type>
//void my_stack<type>::Push(type tp) // ѹջ����
//{
//	if (top + 1 < maxsize)  // ���ջδ��
//	{
//		my_s[++top] = tp; // �Ƚ�ջ��ָ���1��Ȼ����Ԫ�ط���ջ��
//	}
//	else
//	{
//		cout << "ջ��" << endl;
//		exit(1);
//	}
//}
//
//template<class type>
//void my_stack<type>::Pop()// ��ջ����
//{
//	if (top >= 0) // ���ջ��Ϊ��
//	{
//		top--; // ��ջ��ָ���1��ʵ�ֳ�ջ
//	}
//	else
//	{
//		cout << "ջ��" << endl;
//		exit(1);
//	}
//}
//
//template<class type>
//int my_stack<type>::Size() // ����ջ��Ԫ�ص�����
//{
//	return top + 1; // ջ��ָ���1��Ϊջ��Ԫ�ص�����
//}
//
//
//int main() {
//	// ����һ������ջ��ʹ��Ĭ�ϵ�����С MAXSIZE  
//	my_stack<int> intStack;
//
//	// ѹջ����  
//	intStack.Push(10);
//	intStack.Push(20);
//	intStack.Push(30);
//
//	// ���ջ�Ĵ�С  
//	cout << "ջ�Ĵ�С: " << intStack.Size() << endl;
//
//	// ���ջ��Ԫ��  
//	cout << "ջ��Ԫ��: " << intStack.Top() << endl;
//
//	// ��ջ����  
//	intStack.Pop();
//	cout << "��ջ��ջ��Ԫ��: " << intStack.Top() << endl;
//
//	// ���ջ�Ƿ�Ϊ��  
//	if (intStack.Empty()) {
//		cout << "ջΪ��" << endl;
//	}
//	else {
//		cout << "ջ��Ϊ��" << endl;
//	}
//
//	// ������ջ������ֱ��ջΪ��  
//	while (!intStack.Empty()) {
//		cout << "��ջԪ��: " << intStack.Top() << endl;
//		intStack.Pop();
//	}
//
//	// �ٴμ��ջ�Ƿ�Ϊ��  
//	if (intStack.Empty()) {
//		cout << "ջΪ��" << endl;
//	}
//
//	return 0;
//}
