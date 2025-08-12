#include <iostream>
using namespace std;

struct Node { // Node structure for linked list
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head; // Pointer to the head of the linked list

public:
    LinkedList() {
        head = nullptr; // Initialize head to nullptr
    }

    // Insert at end
    void insert(int val) {
        Node* newNode = new Node{val, nullptr};

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Insert at beginning
    void insertAtBeginning(int val) {
        Node* newNode = new Node{val, head};
        head = newNode;
    }

    // Delete first occurrence of a value
    void deleteValue(int val) {
        if (!head) return;

        if (head->data == val) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
            return;
        }

        Node* current = head;
        while (current->next && current->next->data != val) {
            current = current->next;
        }

        if (current->next) {
            Node* toDelete = current->next;
            current->next = current->next->next;
            delete toDelete;
        }
    }

    // Traverse list
    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    // Destructor to clean memory
    ~LinkedList() {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};
int main() {
    LinkedList list;
    list.insert(10);
    list.insert(20);
    list.insertAtBeginning(5);
    list.print(); // Output: 5 -> 10 -> 20 -> NULL

    list.deleteValue(10);
    list.print(); // Output: 5 -> 20 -> NULL

    return 0;
}