//#include <algorithm>
//#include <iostream>
//#include <sstream>
//#include <vector>
//
//using namespace std;
//
//class illegalParameterValue :public exception
//{
//public:
//	illegalParameterValue(const string& message) :Message(message) {}
//	virtual const char* what()const noexcept override
//	{
//		return Message.c_str();
//	}
//private:
//	string Message;
//};
//
//class illegalIndex :public exception
//{
//public:
//	illegalIndex(const string& message) :Message(message) {}
//	virtual const char* what()const noexcept override
//	{
//		return Message.c_str();
//	}
//private:
//	string Message;
//};
//
//template<class T>
//class linearList
//{
//public:
//	virtual ~linearList() {};
//	virtual bool empty() const = 0;
//					//返回 true ，当且仅当线性表为空
//	virtual int size() const = 0;
//					//返回线性表的元素个数
//	virtual T& get(int theIndex) const = 0;
//					//返回索引为 theIndex 的元素
//	virtual int indexOf(const T& theElement) const = 0;
//					//返回元素 theElement 第一次出现时的索引
//	virtual void erase(int theIndex) = 0;
//					//删除索引为 theIndex 的元素
//	virtual void insert(int theIndex, const T& theElement) = 0;
//					//把 theElement 插入线性表中索引为 theIndex 的位置上
//	virtual void output(ostream& out)const = 0;
//					//把线性表插入输出流 out
//};
//
//template<class T>
//class arrayList :public linearList<T>
//{
//public:
//	arrayList(int initialCapacity = 10);
//	arrayList(const arrayList<T>&); //复制构造函数
//	~arrayList() { delete[]element; }
//
//	//ADT方法
//	bool empty()const { return listSize == 0; }
//	int size()const { return listSize; }
//	T& get(int theIndex) const override;
//	int indexOf(const T& theElement) const override;
//	void erase(int theIndex) override;
//	void insert(int theIndex, const T& theElement) override;
//	void output(ostream& out) const override;
//
//	//其他方法
//	int capacity() const { return arrayLength; }
//
//public:
//	void checkIndex(int theIndex) const;
//	void resizeList(int newLength);
//	T* element;
//	int arrayLength;
//	int listSize;
//};
//
//
//template<class T>
//class vectorList :public linearList<T>
//{
//public:
//	vectorList(int initialCapacity = 10);
//	vectorList(const vectorList<T>&);
//	~vectorList() { delete element; }
//	
//	bool empty()const { return element->empty(); }
//	int size() const { return element->size(); }
//	T& get(int theIndex) const override;
//	int indexOf(const T& theElement)const override;
//	void erase(int theIndex)override;
//	void insert(int theIndex, const T& theElement)override;
//	void output(ostream& out) const override;
//
//	int capacity()const { return element->capacity(); }
//
//public:
//	void checkIndex(int tehIndex)const;
//	vector<T>  element;
//};
//
//
//template<class T>
//arrayList<T>::arrayList(int initialCapacity)
//{
//	if (initialCapacity <= 0)
//	{
//		ostringstream s;
//		s << "Initial capacity = " << initialCapacity << " must be > 0";
//		throw illegalParameterValue(s.str());
//	}
//	arrayLength = initialCapacity;
//	element = new T[initialCapacity];
//	listSize = 0;
//}
//
//template<class T>
//vectorList<T>::vectorList(int initialCapacity)
//{
//	if (initialCapacity <= 0)
//	{
//		ostringstream s;
//		s << "Initial capacity = " << initialCapacity << "must be > 0";
//		throw illegalParameterValue(s.str());
//	}
//	element.reserve(initialCapacity);
//}
//
//template<class T>
//arrayList<T>::arrayList(const arrayList<T>& theList)
//{
//	arrayLength = theList.arrayLength;
//	listSize = theList.listSize;
//	element = new T[arrayLength];
//
//	copy(theList.element, theList.element + listSize, element);
//}
//
//template<class T>
//vectorList<T>::vectorList(const vectorList<T>& theList)
//{
//	element(theList.element);
//}
//
//template<class T>
//void arrayList<T>::checkIndex(int theIndex) const
//{
//	if (theIndex < 0 || theIndex >= listSize)
//	{
//		ostringstream s;
//		s << "Index out of range:  index =  " << theIndex << " size = " << listSize;
//		throw illegalIndex(s.str());
//	}
//}
//
//template<class T>
//void vectorList<T>::checkIndex(int theIndex) const
//{
//	if (theIndex < 0 || theIndex >= listSize)
//	{
//		ostringstream s;
//		s << "Index out of range：index = " << theIndex << " size = " << listSize;
//		throw illegalIndex(s.str());
//	}
//}
//
//template<class T>
//void arrayList<T>::resizeList(int newLength)
//{
//	if (newLength < 0)
//	{
//		throw illegalParameterValue("new length must be >= 0");
//	}
//	T* temp = new T[newLength];
//	int number = min(arrayLength, newLength);
//	copy(element, element + number, temp);
//	delete[] element;
//	arrayLength = newLength;
//	element = temp;
//}
//
//template<class T>
//T& arrayList<T>::get(int theIndex) const
//{
//	checkIndex(theIndex);
//	return element[theIndex];
//}
//
//template<class T>
//T& vectorList<T>::get(int theIndex) const
//{
//	checkIndex(theIndex);
//	return element[theIndex];
//}
//
//template<class T>
//int arrayList<T>::indexOf(const T& theElement) const
//{
//	//若存在 返回第一次出现的索引 若不存在 返回-1
//	int theIndex = (int)(find(element, element + listSize, theElement) - element);
//	//find()返回值：如果找到元素，则返回一个指向该元素的迭代器；如果未找到，则返回结束迭代器。
//	if (theIndex == listSize)
//	{
//		return -1;
//	}
//	else return theIndex;
//}
//
//template<class T>
//int vectorList<T>::indexOf(const T& theElement) const
//{
//	auto it = find(element.begin(), element.end(), theElement);
//	if (it != element.end())
//	{
//		return distance(element.begin(), it);
//	}
//	return -1;
//}
//
//template<class T>
//void arrayList<T>::erase(int theIndex)
//{
//	checkIndex(theIndex);
//	copy(element + theIndex + 1, element + listSize, element + theIndex);
//	listSize--;
//}
//
//template<class T>
//void vectorList<T>::erase(int theIndex)
//{
//	checkIndex(theIndex);
//	element.erase(element.begin() + theIndex);
//}
//
//template<class T>
//void arrayList<T>::insert(int theIndex, const T& theElement)
//{
//	if (theIndex < 0 || theIndex > listSize)
//	{
//		ostringstream s;
//		s << "index = " << theIndex << " size = " << listSize;
//		throw illegalIndex(s.str());
//	}
//	if (listSize == arrayLength)
//	{
//		resizeList(2 * arrayLength);
//	}
//	copy_backward(element + theIndex, element + listSize, element + listSize + 1);
//	element[theIndex] = theElement;
//	++listSize;
//
//}
//
//template<class T>
//void vectorList<T>::insert(int theIndex, const T& theElement)
//{
//	if (theIndex<0 || theIndex>element.size())
//	{
//		ostringstream s;
//		s << "index = " << theIndex << " size = " << element.size();
//		throw illegalIndex(s.str());
//	}
//	element.insert(element.begin() + theIndex, theElement);
//}
//
//template<class T>
//ostream& operator<<(ostream& out, const arrayList<T>& x)
//{
//	x.output(out);
//	return out;
//}
//
//template<class T>
//void arrayList<T>::output(ostream& out) const
//{
//	copy(element, element + listSize, ostream_iterator<T>(out, " "));
//}
//
//
//template<class T>
//ostream& operator<<(ostream& out, const vectorList<T>& x)
//{
//	x.output(out);
//	return out;
//}
//template<class T>
//void vectorList<T>::output(ostream& out)const
//{
//	for (const auto& item : element)
//	{
//		out << item << " ";
//	}
//	out << endl;
//}
//
//int main()
//{
//	try
//	{
//		linearList<int>* x = new arrayList<int>(100);
//		arrayList<double> y(100);
//		arrayList<char> z;
//
//		 
//		for (int i = 0, j = 10; j <= 80; i++, j += 10)
//		{
//			x->insert(i, j);
//		}
//
//		cout << "List x：" << *static_cast<arrayList<int>*>(x) << endl;
//		cout << "Size of list x：" << x->size() << endl;
//		cout << "Index of 40 in x：" << x->indexOf(40) << endl;
//		cout << "Element at index 0 in x：" << x->get(0) << endl;
//
//		x->erase(0);
//		std::cout << "List x after erasing index 0：" << *static_cast<arrayList<int>*>(x) << endl;
//		cout << "Size of list x after erasing：" << x->size() << endl << endl;
//
//	
//
//		y.insert(0, 3.14);
//		y.insert(1, 2.71);
//
//		std::cout << "List y： ";
//		y.output(cout);
//		cout << endl << "Index of 2.71 in y： " << y.indexOf(2.71) << endl;
//		cout << "Element at index 0 in y： " << y.get(0) << endl;
//		y.erase(1);
//		cout << "List y after erasing index 1： " << y << endl << endl;
//
//
//
//		z.insert(0, 'a');
//		z.insert(1, 'b');
//		cout << "List z: " << z << endl << endl;
//
//
//		arrayList<double> w(y);
//		cout << "List w (copy of y before modifications)：";
//		w.output(cout);
//
//		w.insert(1, 1.61);
//
//		cout << endl << "List w after inserting 1.61：";
//		w.output(cout);
//
//		cout << endl << "List y after w inserting 1.61：";
//		y.output(cout);
//		cout << endl << endl;
//
//		delete x;
//	}
//	catch (const std::exception& e)
//	{ 
//		std::cerr << "Exception caught: " << e.what() << std::endl;
//	}
//}
//
//
