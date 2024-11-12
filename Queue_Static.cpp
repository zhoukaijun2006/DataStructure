/*
#include <iostream>
using namespace std;

#define MAXSIZE 0xffff
class Queue
{
private:
	int front;
	int rear;
	int maxsize;
	int* value;
public:
	Queue() :front(0), rear(-1), maxsize(MAXSIZE)
	{
		value = new int[maxsize];
		if (value == nullptr)
		{
			cout << "动态存储分配失败！" << endl;
			exit(1);
		}
	}
	Queue(int size) :front(0), rear(-1), maxsize(size)
	{
		value = new int[size];
		if (value == nullptr)
		{
			cout << "动态存储分配失败！" << endl;
			exit(1);
		}
	}
	~Queue()
	{
		delete[] value;
	}
	bool empty();
	int size();
	int head();
	int back();
	void push(int x);
	void pop();
};

bool Queue::empty()
{
	return rear + 1 == front ? true : false;
}

int Queue::size()
{
	return rear - front + 1;
}

int Queue::head()
{
	if (!empty())
	{
		return value[front];
	}
	else
	{
		return -1;
	}
}

int Queue::back()
{
	if (!empty())
	{
		return value[rear];
	}
	else
	{
		return -1;
	}
}

void Queue::push(int x)
{
	value[++rear] = x;
}

void Queue::pop()
{
	if (!empty())
	{
		front++;
	}
	else
	{
		return;
	}
}

int main() 
{
	Queue q; 

	q.push(10);
	q.push(20);
	q.push(30);

	cout << "队首元素: " << q.head() << endl;
	cout << "队尾元素: " << q.back() << endl;
	cout << "队列大小: " << q.size() << endl;

	q.pop();
	cout << "出队后，队首元素: " << q.head() << endl;
	cout << "出队后，队列大小: " << q.size() << endl;
	cout << "队列是否为空: " << (q.empty() ? "是" : "否") << endl;

	q.push(40);
	q.push(50);

	q.pop();
	q.pop();

	cout << "当前队列大小: " << q.size() << endl;
	cout << "当前队列是否为空: " << (q.empty() ? "是" : "否") << endl;
	return 0;
}

*/