#include <iostream>
using namespace std;

class Deque {
private:
    int* arr;
    int front, rear, size, capacity;

public:
    Deque(int cap) {
        capacity = cap;
        arr = new int[cap];
        front = -1;
        rear = 0;
        size = 0;
    }

    bool isFull() { return size == capacity; }
    bool isEmpty() { return size == 0; }

    void push_front(int val) {
        if (isFull()) {
            cout << "Deque is full\n";
            return;
        }
        front = (front == -1) ? 0 : (front - 1 + capacity) % capacity;
        arr[front] = val;
        size++;
    }

    void push_back(int val) {
        if (isFull()) {
            cout << "Deque is full\n";
            return;
        }
        if (isEmpty()) front = 0;
        rear = (rear + 1) % capacity;
        arr[rear] = val;
        size++;
    }

    void pop_front() {
        if (isEmpty()) {
            cout << "Deque is empty\n";
            return;
        }
        front = (front + 1) % capacity;
        size--;
    }

    void pop_back() {
        if (isEmpty()) {
            cout << "Deque is empty\n";
            return;
        }
        rear = (rear - 1 + capacity) % capacity;
        size--;
    }

    int getFront() {
        if (isEmpty()) throw runtime_error("Empty deque");
        return arr[front];
    }

    int getBack() {
        if (isEmpty()) throw runtime_error("Empty deque");
        return arr[rear];
    }

    ~Deque() {
        delete[] arr;
    }
};
int main() {
    Deque deque(5);
    deque.push_back(10);
    deque.push_back(20);
    deque.push_front(5);
    
    cout << "Front: " << deque.getFront() << endl; // Should print 5
    cout << "Back: " << deque.getBack() << endl;   // Should print 20

    deque.pop_front();
    cout << "Front after pop: " << deque.getFront() << endl; // Should print 10

    deque.pop_back();
    cout << "Back after pop: " << deque.getBack() << endl; // Should print 10

    return 0;
}