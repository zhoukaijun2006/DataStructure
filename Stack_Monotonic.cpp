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

    stack<int> stack_Monotonic; // ����һ������ջstack_Monotonic������ʵ�ֵ���ջ�㷨  

    for (int i = 1; i <= N; i++) 
    {
        // ��ջ��Ϊ����ջ��Ԫ��С�ڵ��ڵ�ǰԪ��ʱ������ջ��Ԫ��  
        // ���������Ϊ�˱���ջ�ĵ����ԣ�����������У��ǵ����ݼ���  
        while (!stack_Monotonic.empty() && stack_Monotonic.top() <= integers[i])
        {
            stack_Monotonic.pop(); // ����ջ��Ԫ��  
        }

        // ����ǰԪ��ѹ��ջ��  
        // ��ʱ��ջ��Ԫ���ǵ�ǰԪ����ߵ�һ���������Ԫ�أ���������ڣ���ջΪ�գ�  
        stack_Monotonic.push(integers[i]);

    }

    return 0;
}

// ע�⣺�˴���ν������˵���ջ������δ����κν����  
// �����Ҫ���ÿ��Ԫ����ߵ�һ���������Ԫ�ص���Ϣ��  
// �����ڹ�������ջ�Ĺ����У�ʹ��һ���������������¼��Щ��Ϣ��  
// �����ڵ���ջ������ɺ�ͨ���������ջ��heights�����������Щ��Ϣ��

*/


/*
    ������ջ�洢Ԫ������ 
#include <iostream>  
#include <vector>  
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n; // ��ȡԪ�ص�����  

    vector<int> integers(n + 1); // �洢�����Ԫ�أ������СΪn+1����ֻʹ�ô�1��n������  
    vector<int> subscipt(n + 1); // �洢ÿ��Ԫ����LIS��ǰһ��Ԫ�ص���������ʼ��Ϊ0  
    stack<int> stack_monotonic; // ʹ�õ���ջ����������  

    // ��ȡ�����Ԫ��  
    for (int i = 1; i <= n; i++)
    {
        cin >> integers[i];
    }

    // �Ӻ���ǰ����Ԫ�أ����õ���ջ�ҵ�ÿ��Ԫ����LIS�п��ܵ�ǰһ��Ԫ�ص�����  
    for (int i = n; i >= 1; i--)
    {
        // ��ջ��Ϊ����ջ��Ԫ�ض�Ӧ��ֵС�ڵ��ڵ�ǰԪ��ʱ������ջ��Ԫ��  
        // ��Ϊ����Ҫ��֤ջ�ǵ����ݼ��ģ����ҵ�ÿ��Ԫ�ص�������ǰ��  
        while (!stack_monotonic.empty() && integers[stack_monotonic.top()] <= integers[i])
        {
            stack_monotonic.pop();
        }

        // ���ջΪ�գ�˵����ǰԪ��iû�п��е�ǰ������������LIS����ʼԪ��  
        // ����ջ��Ԫ�ؾ��ǵ�ǰԪ��i��LIS�е�ǰһ��Ԫ�ص�����  
        subscipt[i] = stack_monotonic.empty() ? 0 : stack_monotonic.top();

        // ����ǰԪ��i������ѹ��ջ��  
        stack_monotonic.push(i);
    }

    //subscipt�洢���������е�i��Ԫ��֮���һ������a(i)��Ԫ�ص��±�

    return 0;
}

*/