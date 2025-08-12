#include <iostream>
#include <memory>
using namespace std;

class MyVector {
private:
    int* data; // Pointer to the array that holds the elements
    int capacity;
    int length;

    void resize() {
        capacity *= 2; // Double the capacity
        int* newData = new int[capacity]; // Create a new array with the updated capacity
        //std::unique_ptr<int[]> data = std::make_unique<int[]>(capacity); // Alternative using smart pointers
        for (int i = 0; i < length; ++i) {
            newData[i] = data[i]; // Copy the old elements to the new array
        }
        delete[] data; // Free the old array
        data = newData; // Point to the new array
    }

public:
    MyVector() {
        capacity = 4;
        length = 0;
        data = new int[capacity];
    }

    ~MyVector() {
        delete[] data; // Free the allocated memory
    }

    void push_back(int val) {
        if (length == capacity) {
            resize();
        }
        data[length++] = val;
    }

    void pop_back() {
        if (length > 0) {
            length--;
        }
    }

    int size() const {
        return length;
    }

    int& operator[](int index) { // Overloaded subscript operator for non-const access
        if (index < 0 || index >= length) {
            throw out_of_range("Index out of range");
        }
        return data[index];
    }

    bool empty() const {
        return length == 0;
    }

    void print() {
        for (int i = 0; i < length; ++i)
            cout << data[i] << " ";
        cout << endl;
    }
};
