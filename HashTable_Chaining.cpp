/*

#include <iostream>
using namespace std;

class Item //��
{
public:
	string name;
	string drink;
	Item* next;
	Item() :name("empty"), drink("empty"), next(nullptr) {}
	Item(string n, string d) :name(n), drink(d), next(nullptr) {}
};

class Hash
{
private:
	static const int tablesize = 10;
	Item* HashTable[tablesize];
public:
	Hash();
	int	HashFunction(string key);
	void AddItem(string name, string drink);
	int NumberOfItemIndex(int index);
	void PrintTable();
	void PrintItemsIndex(int index);
	void FindDrink(string name);
	void RemoveItem(string name);
};

// ���캯������ʼ����ϣ���ÿ����λ
Hash::Hash()
{
	for (int i = 0; i < tablesize; i++)
	{
		HashTable[i] = new Item();
	}
}

// ��ϣ���������ڼ�����Ĺ�ϣֵ
int Hash::HashFunction(string key)
{
	int sum = 0;
	int index = 0;

	for (char ch : key)
	{
		sum += static_cast<int>(ch);
	}

	index = sum % tablesize;

	return index;
}

// ������ϣ�� 
void Hash::AddItem(string name, string drink)
{
	int index = HashFunction(name);

	if (HashTable[index]->name == "empty")
	{
		HashTable[index]->name = name;
		HashTable[index]->drink = drink;
	}
	else
	{
		Item* Node = HashTable[index];
		Item* Next = new Item(name, drink);

		while (Node->next != nullptr)
		{
			Node = Node->next;
		}

		Node->next = Next;
	}
}

// ����ָ��������������
int Hash::NumberOfItemIndex(int index)
{
	int count = 0;
	Item* Node = HashTable[index];

	if (Node->name != "empty")
	{
		count++;
	}

	while (Node->next != nullptr)
	{
		Node = Node->next;
		count++;
	}

	return count;
}

// ��ӡ��ϣ�������  
void Hash::PrintTable()
{
	int number = 0;
	for (int i = 0; i < tablesize; i++)
	{
		cout << "i= " << i << ": " << endl;
		number = NumberOfItemIndex(i);
		PrintItemsIndex(i);
		cout << "# of items " << number << endl << endl;
	}
}

// ��ӡָ����������������
void Hash::PrintItemsIndex(int index)
{
	Item* Node = HashTable[index];
	if (Node->name == "empty")
	{
		cout << "index = " << index << " is empty" << endl;
		cout << "Name: " << Node->name << "    " << "Drink: " << Node->drink << endl;
	}
	else
	{
		cout << "index = " << index << " contains the following items" << endl;
		cout << "Name: " << Node->name << "    " << "Drink: " << Node->drink << endl;

		while (Node->next != nullptr)
		{
			Node = Node->next;
			cout <<"Name: " << Node->name << "    " <<"Drink: " << Node->drink << endl;
		}
	}
}

// ����ָ�����ֵ�������� 
void Hash::FindDrink(string name)
{
	int index = HashFunction(name);

	string drink;
	bool FindName = false;

	Item* Node = HashTable[index];

	while (Node != nullptr)
	{
		if (Node->name == name)
		{
			FindName = true;
			drink = Node->drink;
			break;
		}
		Node = Node->next;
	}

	if (FindName == true)
	{
		cout << name << " 's info found successfully. The drink is " << drink << " ." << endl;
		cout << "Its index is number " << index << "." << endl;
	}
	else
	{
		cout << name << " 's info was not found in the hash table." << endl;
	}
}

// �ӹ�ϣ�����Ƴ�ָ�����ֵ���
void Hash::RemoveItem(string name)
{
	int index = HashFunction(name);

	// �����������ͷ�ڵ��Ƿ�Ϊ��
	if (HashTable[index]->name == "empty" && HashTable[index]->drink == "empty")
	{
		cout << name << " was not found in the hash table." << endl;
	}
	// ͷ������Ҫɾ���Ľڵ㲢��û�к����ڵ�
	else if (HashTable[index]->name == name && HashTable[index]->next == nullptr)
	{
		HashTable[index]->name = "empty";
		HashTable[index]->drink = "empty";
		cout << name << " was removed from the hash table" << endl;
	}
	//ͷ������Ҫɾ���Ľڵ㲢���к����ڵ�
	else if (HashTable[index]->name == name && HashTable[index]->next != nullptr)
	{
		Item* deleteNode = HashTable[index]; //deleteNode��HashTable[index] ��ָ��ͬһ��Item����
		HashTable[index] = HashTable[index]->next;
		delete deleteNode; // ɾ�� deleteNode ָ��� Item ���󣬼�ԭ�� HashTable[index] ָ��Ķ���
		cout << name << " was removed from the hash table" << endl;
	}
	//ͷ��㲻��Ҫɾ���Ľڵ�
	else
	{
		Item* Node = HashTable[index];
		while (Node != nullptr && Node->name != name)
		{
			Node = Node->next;
		}

		if (Node == nullptr)
		{
			cout << name << " was not removed from the hash table" << endl;
		}
		else
		{
			Item* deleteNode = Node;
			Node = Node->next;
			delete deleteNode;
			cout << name << " was removed from the hash table" << endl;
		}
	}
}




int main()
{
	Hash hash;

	hash.PrintTable();
	cout << "-----------------------------------------------------------" << endl << endl;

	hash.AddItem("Paul", "Locha");
	hash.AddItem("Kim", "Iced Mocha");
	hash.AddItem("Anni", "Strawberry Smoothy");
	hash.AddItem("Sara", "Passion Tea");
	hash.AddItem("Mike", "Tea");
	hash.AddItem("steve", "Apple cider");
	hash.AddItem("Sill", "Root beer");
	hash.AddItem("Bill", "Lochs");
	hash.AddItem("Susan", "Cola");
	hash.AddItem("Joe", "Green Tea");

	hash.PrintTable();

	cout << "-----------------------------------------------------------" << endl << endl;
	hash.FindDrink("Paul");

	cout << "-----------------------------------------------------------" << endl << endl;
	hash.RemoveItem("Paul");

	cout << "-----------------------------------------------------------" << endl << endl;
	hash.PrintTable();

	return 0;
}

*/