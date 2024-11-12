//#include <iostream>
//using namespace std;
//

//// 节点类  
//class Node {
//public:
//    int data;
//    Node* next;
//
//    Node(int val) : data(val), next(nullptr) {}
//};
//
//// 队列类  
//class Queue {
//private:
//    Node* front;
//    Node* rear;
//    int size;
//
//public:
//    Queue() : front(nullptr), rear(nullptr), size(0) {}
//    ~Queue();
//
//    bool isEmpty() const { return size == 0; }
//    int getSize() const { return size; }
//    void enqueue(int data);
//    int dequeue();
//    int getFront() const;
//    int getRear() const; // 新增：读取队尾元素  
//
//private:
//    void clear();
//};
//
//// 析构函数  
//Queue::~Queue() {
//    clear();
//}
//
//// 辅助函数：清除队列  
//void Queue::clear() {
//    Node* current = front;
//    while (current != nullptr) {
//        Node* temp = current;
//        current = current->next;
//        delete temp;
//    }
//    front = rear = nullptr;
//    size = 0;
//}
//
//// 队列操作  
//void Queue::enqueue(int data) {
//    Node* newNode = new Node(data);
//    if (isEmpty()) {
//        front = rear = newNode;
//    }
//    else {
//        rear->next = newNode;
//        rear = newNode;
//    }
//    size++;
//}
//
//int Queue::dequeue() {
//    if (isEmpty()) {
//        // 可以选择抛出异常或返回特殊值  
//        return -1; // 这里返回-1表示队列为空  
//    }
//    Node* temp = front;
//    int data = front->data;
//    front = front->next;
//    if (front == nullptr) {
//        rear = nullptr;
//    }
//    delete temp;
//    size--;
//    return data;
//}
//
//int Queue::getFront() const {
//    if (isEmpty()) {
//        // 可以选择抛出异常或返回特殊值  
//        return -1; // 这里返回-1表示队列为空  
//    }
//    return front->data;
//}
//
//int Queue::getRear() const {
//    if (isEmpty()) {
//        // 可以选择抛出异常或返回特殊值  
//        return -1; // 这里返回-1表示队列为空  
//    }
//    return rear->data;
//}
//
//// 主函数，用于测试队列  
//int main() {
//    Queue q;
//    q.enqueue(1);
//    q.enqueue(2);
//    q.enqueue(3);
//
//    std::cout << "Front: " << q.getFront() << std::endl; // 应输出 1  
//    std::cout << "Rear: " << q.getRear() << std::endl; // 应输出 3  
//
//    q.dequeue();
//
//    std::cout << "After dequeue, Front: " << q.getFront() << std::endl; // 应输出 2  
//    std::cout << "After dequeue, Rear: " << q.getRear() << std::endl; // 应输出 3  
//
//    return 0;
//}