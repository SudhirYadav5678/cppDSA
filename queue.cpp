#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue {
private:
    Node* frontNode;
    Node* rearNode;

public:
    Queue() {
        frontNode = rearNode = nullptr;
    }

    void enqueue(int val) {
        Node* newNode = new Node{val, nullptr};

        if (rearNode == nullptr) {
            frontNode = rearNode = newNode;
        } else {
            rearNode->next = newNode;
            rearNode = newNode;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }

        Node* temp = frontNode;
        frontNode = frontNode->next;

        if (frontNode == nullptr) rearNode = nullptr;

        delete temp;
    }

    int front() {
        if (isEmpty()) throw runtime_error("Queue is empty");
        return frontNode->data;
    }

    bool isEmpty() {
        return frontNode == nullptr;
    }

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};
int main() {
    Queue queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    cout << "Front element: " << queue.front() << endl; // Should print 10

    queue.dequeue();
    cout << "Front element after dequeue: " << queue.front() << endl; // Should print 20

    return 0;
}