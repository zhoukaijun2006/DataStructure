/*
	c++栈的方法的基本用法：
		push() : 向栈内压入一个成员；
		pop() : 从栈顶弹出一个成员；
		empty() : 如果栈为空返回true，否则返回false；
		top() : 返回栈顶，但不删除成员；
		size() : 返回栈内元素的大小；
*/

/*

#include <iostream>
#include <stack>

int main()
{
	std::stack<int> stk;
	for (int i = 0; i <= 50; i++)
	{
		stk.push(i);
	}
	std::cout << "栈的大小" << size(stk) << std::endl;
	while (!stk.empty())
	{

		std::cout << stk.top() << std::endl;
		stk.pop();
	}
	std::cout << "栈的大小" << stk.size() << std::endl;

}

*/