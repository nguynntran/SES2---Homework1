#include <deque>
#include <stdexcept>
#include <iostream>

template <typename T>
class StackAdapter {
private:
    std::deque<T> con; // The underlying deque container

public:
    // Default constructor
    StackAdapter() = default;

    // Constructor that initializes the stack with an existing deque
    StackAdapter(const std::deque<T>& deq) : con(deq) {}

    // Push an item onto the stack
    void push(const T& item) {
        con.push_back(item);
    }

    // Push multiple items onto the stack from a range
    template <typename it>
    void push(it begin, it end) {
        con.insert(con.end(), begin, end);
    }

    // Pop an item from the stack and return it
    // Throws std::out_of_range if the stack is empty
    T pop() {
        if (con.empty()) {
            throw std::out_of_range("pop from empty stack");
        }
        T topElement = con.back();
        con.pop_back();
        return topElement;
    }

    // Return the item on top of the stack without removing it
    // Throws std::out_of_range if the stack is empty
    T& top() {
        if (con.empty()) {
            throw std::out_of_range("top from empty stack");
        }
        return con.back();
    }

    // Check if the stack is empty
    bool isEmpty() const {
        return con.empty();
    }

    // Return the size of the stack
    std::size_t size() const {
        return con.size();
    }

    // Method to print elements in the stack
    void print() const {
        std::cout << "Stack elements (top to bottom): ";
        for (auto it = con.rbegin(); it != con.rend(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    // Initialize a stack adapter
    std::deque<int> inDeque;
    inDeque.push_back(1);
    inDeque.push_back(13);
    inDeque.push_front(2);


    StackAdapter<int> stack(inDeque);

    // Push some elements onto the stack
    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout<< stack.top() << std::endl;

    // Print the elements in the stack
    stack.print(); // Output: Stack elements (top to bottom): 30 20 10 

    return 0;
}
