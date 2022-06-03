#include <iostream>
#include <stdexcept>
#include <utility>

struct Stack_underflow :std::exception {};

class Stack {
public:
    Stack() = default;
    Stack(const Stack&) = delete;
    Stack& operator=(const Stack&) = delete;
    ~Stack();

    void push(int value);
    void pop();
    void display() const;
    bool empty() const { return top == nullptr; }
private:
    struct Node {
        int data;
        Node* prev;
        Node* next;
    };
    Node* top = nullptr;
};

Stack::~Stack()
{
    while (!empty()) {
        pop();
    }
}

void Stack::push(int value)
{
    top = new Node{ value, top, nullptr };
    if (auto old = top->prev) {
        old->next = top;
    }
}

void Stack::pop()
{
    if (empty()) {
        throw Stack_underflow{};
    }
    delete std::exchange(top, top->prev);
}

void Stack::display() const
{
    for (auto it = top; it; it = it->prev) {
        std::cout << it->data << ' ';
    }
    std::cout << '\n';
}

int main()
{
    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);

    stack.pop();
    stack.display();
    stack.pop();
    stack.display();
}