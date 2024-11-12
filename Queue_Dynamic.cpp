//#include <iostream>
//using namespace std;
//

//// �ڵ���  
//class Node {
//public:
//    int data;
//    Node* next;
//
//    Node(int val) : data(val), next(nullptr) {}
//};
//
//// ������  
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
//    int getRear() const; // ��������ȡ��βԪ��  
//
//private:
//    void clear();
//};
//
//// ��������  
//Queue::~Queue() {
//    clear();
//}
//
//// �����������������  
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
//// ���в���  
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
//        // ����ѡ���׳��쳣�򷵻�����ֵ  
//        return -1; // ���ﷵ��-1��ʾ����Ϊ��  
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
//        // ����ѡ���׳��쳣�򷵻�����ֵ  
//        return -1; // ���ﷵ��-1��ʾ����Ϊ��  
//    }
//    return front->data;
//}
//
//int Queue::getRear() const {
//    if (isEmpty()) {
//        // ����ѡ���׳��쳣�򷵻�����ֵ  
//        return -1; // ���ﷵ��-1��ʾ����Ϊ��  
//    }
//    return rear->data;
//}
//
//// �����������ڲ��Զ���  
//int main() {
//    Queue q;
//    q.enqueue(1);
//    q.enqueue(2);
//    q.enqueue(3);
//
//    std::cout << "Front: " << q.getFront() << std::endl; // Ӧ��� 1  
//    std::cout << "Rear: " << q.getRear() << std::endl; // Ӧ��� 3  
//
//    q.dequeue();
//
//    std::cout << "After dequeue, Front: " << q.getFront() << std::endl; // Ӧ��� 2  
//    std::cout << "After dequeue, Rear: " << q.getRear() << std::endl; // Ӧ��� 3  
//
//    return 0;
//}