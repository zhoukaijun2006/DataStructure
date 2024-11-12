//#include <iostream>
//#include <vector>
//using namespace std;
//
//vector<int> ComputeNext(const string& pattern)
//{
//	int pattern_length = (int)pattern.length();
//	vector<int>next(pattern_length, 0);
//	next[0] = 0;
//
//	for (int i = 1, j = 0; i < pattern_length; i++)
//	{
//		while (j > 0 && pattern[i] != pattern[j])
//		{
//			j = next[j - 1];
//		}
//		if (pattern[i] == pattern[j])
//		{
//			j++;
//		}
//		next[i] = j;
//	}
//	return next;
//}
//
//void KMP_Search(const string& target, const string& pattern)
//{
//	int target_length = (int)target.length();
//	int pattern_length = (int)pattern.length();
//
//	vector<int>next = ComputeNext(pattern);
//
//	for (int i = 0, j = 0; i < target_length; i++)
//	{
//		while (j > 0 && target[i] != pattern[j])
//		{	
//			j = next[j - 1];
//		}
//		if (target[i] == pattern[j])
//		{
//			j++;
//		}
//		if (j == pattern_length)
//		{
//			cout << "Found pattern at " << i - j + 1 << " position " << endl;
//			j = next[j - 1];
//		}
//	}
//
//	return;
//}
//
//int main()
//{
//	string pattern = "ABABC", target = "ABABAABABCABAACAADBABABCAADKDABC";
//	KMP_Search(target, pattern);
//
//	return 0;
//}