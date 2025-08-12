#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* topNode;

public:
    Stack() {
        topNode = nullptr;
    }

    void push(int val) {
        Node* newNode = new Node{val, topNode};
        topNode = newNode;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return;
        }
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
    }

    int top() {
        if (isEmpty()) {
            throw runtime_error("Stack is empty");
        }
        return topNode->data;
    }

    bool isEmpty() {
        return topNode == nullptr;
    }

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};
int main() {
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Top element: " << stack.top() << endl; // Should print 30

    stack.pop();
    cout << "Top element after pop: " << stack.top() << endl; // Should print 20

    stack.pop();
    stack.pop();

    if (stack.isEmpty()) {
        cout << "Stack is empty now." << endl;
    }

    return 0;
}