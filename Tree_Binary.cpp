#include <iostream>
#include <queue>
using namespace std;

template<class T>
class binaryTreeNode
{
public:
	T data;
	binaryTreeNode<T>* leftChild;
	binaryTreeNode<T>* rightChild;
	binaryTreeNode(T value) :data(value), leftChild(nullptr), rightChild(nullptr) {}

};

template<class T>
class binaryTree
{
public:
	virtual ~binaryTree() {}
	virtual bool empty() const = 0;
	virtual int size()const = 0;
	virtual void preOrder(void (*)(T*)) = 0;
	virtual void inOrder(void(*)(T*)) = 0;	
	virtual void postOrder(void(*)(T*)) = 0;
	virtual void levelOrder(void(*)(T*)) = 0;

};

template<class E>
class linkedBinaryTree :public binaryTree<binaryTreeNode<E>>
{
public:
	linkedBinaryTree() :root(nullptr), treeSize(0) {}
	~linkedBinaryTree() 
	{ 
		erase();
	}
	bool empty()const 
	{
		return treeSize == 0; 
	}
	int size()const
	{
		return treeSize; 
	}
	void setRoot(binaryTreeNode<E>* newNode)
	{
		root = newNode;
		if (newNode != nullptr)
		{
			++treeSize;
		}
	}
	void preOrder(void (*theVisit)(binaryTreeNode<E>*))
	{
		visit = theVisit;
		preOrderHelper(root);
	}
	void inOrder(void(*theVisit)(binaryTreeNode<E>*))
	{
		visit = theVisit;
		inOrderHelper(root);
	}
	void postOrder(void(*theVisit)(binaryTreeNode<E>*))
	{
		visit = theVisit;
		postOrderHelper(root);	
	}
	void levelOrder(void (*theVisit)(binaryTreeNode<E>*))
	{
		queue<binaryTreeNode<E>*> q;
		q.push(root);
		auto visitNode = theVisit; 
		while (!q.empty())
		{
			binaryTreeNode<E>* node = q.front();
			q.pop();
			visitNode(node);
			if (node->leftChild)
			{
				q.push(node->leftChild);
			}
			if (node->rightChild)
			{
				q.push(node->rightChild);
			}
		}
	}
	void erase()
	{
		postOrder(dispose);
		root = nullptr;
		treeSize = 0;
	}
	int height()const
	{
		return heightHelper(root);
	}
	friend void infixPrint(binaryTreeNode<E>* t);
private:
	binaryTreeNode<E>* root;
	int treeSize;

	static void (*visit)(binaryTreeNode<E>*);
	static void preOrderHelper(binaryTreeNode<E>* t);
	static void inOrderHelper(binaryTreeNode<E>* t);
	static void postOrderHelper(binaryTreeNode<E>* t);
	static int heightHelper(binaryTreeNode<E>* t);
	static void dispose(binaryTreeNode<E>* t);
};

template<class E>
void (*linkedBinaryTree<E>::visit)(binaryTreeNode<E>*) = nullptr;

template<class E>
void linkedBinaryTree<E>::preOrderHelper(binaryTreeNode<E>* t)
{
	if (t != nullptr)
	{
		linkedBinaryTree<E>::visit(t);	
		preOrderHelper(t->leftChild);
		preOrderHelper(t->rightChild);
	}
}

template<class E>
void linkedBinaryTree<E>::inOrderHelper(binaryTreeNode<E>* t)
{
	if (t != nullptr)
	{
		inOrderHelper(t->leftChild);
		linkedBinaryTree<E>::visit(t);
		inOrderHelper(t->rightChild);
	}
}

template<class E>
void linkedBinaryTree<E>::postOrderHelper(binaryTreeNode<E>* t)
{
	if (t != nullptr)
	{
		postOrderHelper(t->leftChild);
		postOrderHelper(t->rightChild);
		linkedBinaryTree<E>::visit(t);
	}
}

template<class E>
int linkedBinaryTree<E>::heightHelper(binaryTreeNode<E>* t)
{
	if (t == nullptr)
	{
		return 0;
	}
	int hl = heightHelper(t->leftChild);
	int hr = heightHelper(t->rightChild);
	if (hl > hr)
	{
		return ++hl;
	}
	else
	{
		return ++hr;
	}
}

template<class E>
void linkedBinaryTree<E>::dispose(binaryTreeNode<E>* t)
{
	delete t;
}

template<class E>
void infixPrint(binaryTreeNode<E>* t)
{
	if (t != nullptr)
	{
		cout << '(';
		infixPrint(t->leftChild);
		cout << t->data;
		infixPrint(t->rightChild);
		cout << ')';
	}
}
template<class E>
void printNode(binaryTreeNode<E>* node) {
	if (node != nullptr) {
		cout << node->data << " ";
	}
}

int main() 
{
	// 创建一个整数类型的二叉树
	linkedBinaryTree<int> tree;

	// 创建节点
	binaryTreeNode<int>* root = new binaryTreeNode<int>(1);
	binaryTreeNode<int>* leftChild = new binaryTreeNode<int>(2);
	binaryTreeNode<int>* rightChild = new binaryTreeNode<int>(3);
	binaryTreeNode<int>* leftLeftChild = new binaryTreeNode<int>(4);
	binaryTreeNode<int>* leftRightChild = new binaryTreeNode<int>(5);

	// 构建树结构
	root->leftChild = leftChild;
	root->rightChild = rightChild;
	leftChild->leftChild = leftLeftChild;
	leftChild->rightChild = leftRightChild;

	// 设置根节点（这里应该通过公有方法添加节点，但为了简化，我们直接设置root）
	// 注意：在实际应用中，应该避免直接设置root，而是通过添加节点的方法构建树
	tree.setRoot(root);

	// 由于我们已经直接设置了root，这里不需要再手动更新treeSize
	// 因为setRoot方法已经处理了treeSize的更新

	// 使用各种遍历方法打印树的内容
	cout << "Pre-order traversal: ";
	tree.preOrder(printNode<int>);
	cout << endl;

	cout << "In-order traversal: ";
	tree.inOrder(printNode<int>);
	cout << endl;

	cout << "Post-order traversal: ";
	tree.postOrder(printNode<int>);
	cout << endl;

	cout << "Level-order traversal: ";
	tree.levelOrder(printNode<int>);
	cout << endl;

	// 计算并打印树的高度
	cout << "Height of the tree: " << tree.height() << endl;

	// 清理并删除树
	tree.erase();

	// 此时，树应为空，且root指针应为nullptr
	cout << "Is the tree empty after erase? " << (tree.empty() ? "Yes" : "No") << endl;

	return 0;
}