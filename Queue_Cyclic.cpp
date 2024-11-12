
/*

#include <iostream>
using namespace std;

#define MAXSIZE 0xffff

class CyclicQueue
{
private:
	int* space;
	int maxsize;
	int rear;
	int front;
	int len = 0;
public:
	CyclicQueue() :rear(0), front(0), maxsize(MAXSIZE)//将头尾指针都赋值为0 牺牲第一个元素 达成循环
	{
		space = new int[maxsize];
		if (space == nullptr)
		{
			cout << "动态存储分配失败！" << endl;
			exit(1);
		}
	}

	CyclicQueue(int size) :rear(0), front(0), maxsize(size)
	{
		space = new int[maxsize];
		if (space == nullptr)
		{
			cout << "动态存储分配失败！" << endl;
			exit(1);
		}
	}

	~CyclicQueue()
	{
		delete[] space;
	}
	bool empty();
	bool full();
	int size();
	int Front();
	int back();
	void push(int tp);
	int pop();
};
bool CyclicQueue::empty()
{
	return rear == front ? true : false;
}

bool CyclicQueue::full()
{
	return (rear + 1) % maxsize == front ? true : false;
}

int CyclicQueue::Front()
{
	if (!empty())
	{
		if (front == 0)
		{
			return space[++front];
		}
		else
		{
			return space[front % maxsize];
		}
	}
	else
	{
		cout << "队空 无元素" << endl;
		return -1;
	}
}

int CyclicQueue::back()
{
	if (!empty())
	{
		return space[rear];
	}
	else
	{
		cout << "队空 无元素" << endl;
		return -1;
	}
}

void CyclicQueue::push(int tp)
{
	if (!full())
	{
		rear = (rear + 1) % maxsize;
		space[rear] = tp;
		len++;
	}
	else
	{
		cout << "队满 无法入队" << endl;
	}
}

int CyclicQueue::pop()
{
	if (!empty())
	{
		front++;
		len--;
		return space[front % maxsize];
	}
	else
	{
		cout << "队空 无法出队" << endl;
		return -1;
	}
}

int CyclicQueue::size()
{
	return len;
}

int main()
{
	CyclicQueue queue(7);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string choice;
		cin >> choice;
		if (choice == "front")
		{
			cout << queue.Front() << endl;
		}
		else if (choice == "back")
		{
			cout << queue.back() << endl;
		}
		else if (choice == "push")
		{
			int m;
			cin >> m;
			queue.push(m);
		}
		else if (choice == "pop")
		{
			cout << queue.pop() << endl;
		}
		else if (choice == "size")
		{
			cout << queue.size() << endl;
		}
		else
		{
			cout << "输入错误" << endl;
		}
	}
}

*/