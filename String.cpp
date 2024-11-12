//#include <cstdlib>
//#include <iostream>
//#include <cstring>
//
//using namespace std;
//
//enum Status { OK, Error };
//
//typedef struct {
//	char* ch;
//	int length;
//}Hstring;
//
//Status StrAssign(Hstring& T, const char* chars)
//{
//	if (T.ch)
//	{
//		free(T.ch);
//		T.ch = NULL;
//	}
//	int len = 0; 
//	const char* temp = chars;
//	while (*temp != '\0')
//	{
//		len++;
//		temp++;
//	}
//
//	T.ch = (char*)malloc((len + 1) * sizeof(char));
//	if (!T.ch)
//	{
//		return Error;
//	}
//	for (int i = 0; i < len; i++)
//	{
//		T.ch[i] = chars[i];
//	}
//	T.ch[len] = '\0';
//
//	T.length = len;
//	return OK;
//}
//
//int StrLength(Hstring s)
//{
//	return s.length;
//}
//
//int StrCompare(Hstring S, Hstring T)
//{
//	for (int i = 0; i < S.length && i < T.length; i++)
//	{
//		if (S.ch[i] != T.ch[i])
//		{
//			return S.ch[i] - T.ch[i];
//		}
//	}
//	return S.length - T.length;
//}
//
//Status ClearString(Hstring& S)
//{
//	if (S.ch)
//	{
//		free(S.ch);
//	}
//	S.ch = NULL;
//	S.length = 0;
//	return OK;
//}
//
//Status Concat(Hstring& T, Hstring S1, Hstring S2)
//{
//	if (T.ch)
//	{
//		free(T.ch);
//		T.ch = NULL;
//	}
//	T.ch = (char*)malloc((S1.length + S2.length + 1) * sizeof(char));
//	int count = 0;
//
//	if (!T.ch)
//	{
//		return Error;
//	}
//	for (int i = 0; i < S1.length; i++)
//	{
//		T.ch[count++] = S1.ch[i];
//	}
//	for (int j = 0; j < S2.length; j++)
//	{
//		T.ch[count++] = S2.ch[j];
//	}
//	T.ch[count] = '\0';
//
//	T.length = count;
//
//	return OK;
//}
//
//Status SubString(Hstring& Sub, Hstring S, int pos, int len)
//{
//	if (pos<1 || pos>S.length || len<0 || len>S.length - pos + 1)
//	{
//		return Error;
//	}
//	if (Sub.ch)
//	{
//		free(Sub.ch);
//	}
//	if (!len)
//	{
//		Sub.ch = NULL;
//		Sub.length = 0;
//	}
//	else
//	{
//		Sub.ch = (char*)malloc(len + 1 * sizeof(char));
//		if (!Sub.ch)
//		{
//			return Error;
//		}
//		for (int i = 0; i < len; i++)
//		{
//			if (Sub.ch)
//			{
//				Sub.ch[i] = S.ch[pos++ - 1];
//			}
//		}
//		Sub.ch[len] = '\0';
//		Sub.length = len;
//	}
//	return OK;
//}
//	
//
//int main() 
//{
//	Hstring str1, str2, result, subStr;
//	str1.ch = NULL;
//	str2.ch = NULL;
//	result.ch = NULL;
//	subStr.ch = NULL;
//	StrAssign(str1, "Hello");
//	StrAssign(str2, "World");
//
//	std::cout << "Length of str1: " << StrLength(str1) << std::endl;
//	std::cout << "Length of str2: " << StrLength(str2) << std::endl;
//
//	int cmpResult = StrCompare(str1, str2);
//	if (cmpResult < 0) 
//	{
//		std::cout << "str1 is less than str2" << std::endl;
//	}
//	else if (cmpResult > 0) 
//	{
//		std::cout << "str1 is greater than str2" << std::endl;
//	}
//	else 
//	{
//		std::cout << "str1 is equal to str2" << std::endl;
//	}
//
//
//	Status concatStatus = Concat(result, str1, str2);
//	if (concatStatus == OK) 
//	{
//		std::cout << "Concatenated string: " << result.ch << std::endl;
//	}
//	else 
//	{
//		std::cout << "Error concatenating strings" << std::endl;
//	}
//
//	Status subStrStatus = SubString(subStr, result, 2, 5);
//	if (subStrStatus == OK) 
//	{
//		std::cout << "Substring: " << subStr.ch << std::endl;
//	}
//	else 
//	{
//		std::cout << "Error getting substring" << std::endl;
//	}
//
//	// Clear strings
//	ClearString(str1);
//	ClearString(str2);
//	ClearString(result);
//	ClearString(subStr);
//
//	std::cout << "str1 cleared" << std::endl;
//	std::cout << "str2 cleared" << std::endl;
//	std::cout << "result cleared" << std::endl;
//	std::cout << "subStr cleared" << std::endl;
//
//	return 0;
//}