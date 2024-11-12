/*

#include <iostream> 
#include <vector> 
#include <stack> 

using namespace std;

int main()
{
    int N; 
    cin >> N;

    vector<int> integers(N + 1); 

    for (int i = 1; i <= N; i++) 
    {
        cin >> integers[i];
    }

    stack<int> stack_Monotonic; // 定义一个整型栈stack_Monotonic，用于实现单调栈算法  

    for (int i = 1; i <= N; i++) 
    {
        // 当栈不为空且栈顶元素小于等于当前元素时，弹出栈顶元素  
        // 这个过程是为了保持栈的单调性（在这个例子中，是单调递减）  
        while (!stack_Monotonic.empty() && stack_Monotonic.top() <= integers[i])
        {
            stack_Monotonic.pop(); // 弹出栈顶元素  
        }

        // 将当前元素压入栈中  
        // 此时，栈顶元素是当前元素左边第一个比它大的元素（如果不存在，则栈为空）  
        stack_Monotonic.push(integers[i]);

    }

    return 0;
}

// 注意：此代码段仅构建了单调栈，但并未输出任何结果。  
// 如果需要输出每个元素左边第一个比它大的元素的信息，  
// 可以在构建单调栈的过程中，使用一个额外的向量来记录这些信息，  
// 或者在单调栈构建完成后，通过逆序遍历栈和heights向量来输出这些信息。

*/


/*
    将单调栈存储元素索引 
#include <iostream>  
#include <vector>  
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n; // 读取元素的数量  

    vector<int> integers(n + 1); // 存储输入的元素，数组大小为n+1，但只使用从1到n的索引  
    vector<int> subscipt(n + 1); // 存储每个元素在LIS中前一个元素的索引，初始化为0  
    stack<int> stack_monotonic; // 使用单调栈来辅助计算  

    // 读取输入的元素  
    for (int i = 1; i <= n; i++)
    {
        cin >> integers[i];
    }

    // 从后往前遍历元素，利用单调栈找到每个元素在LIS中可能的前一个元素的索引  
    for (int i = n; i >= 1; i--)
    {
        // 当栈不为空且栈顶元素对应的值小于等于当前元素时，弹出栈顶元素  
        // 因为我们要保证栈是单调递减的，以找到每个元素的最大可行前驱  
        while (!stack_monotonic.empty() && integers[stack_monotonic.top()] <= integers[i])
        {
            stack_monotonic.pop();
        }

        // 如果栈为空，说明当前元素i没有可行的前驱，或者它是LIS的起始元素  
        // 否则，栈顶元素就是当前元素i在LIS中的前一个元素的索引  
        subscipt[i] = stack_monotonic.empty() ? 0 : stack_monotonic.top();

        // 将当前元素i的索引压入栈中  
        stack_monotonic.push(i);
    }

    //subscipt存储的是数列中第i个元素之后第一个大于a(i)的元素的下标

    return 0;
}

*/