#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
    stack<int> inStack;
    stack<int> outStack;
public:
    void enqueue(int item) {
        inStack.push(item);
    }
    int dequeue() {
        if (outStack.empty()) {
            while (!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
        if (outStack.empty()) return -1;
        int item = outStack.top();
        outStack.pop();
        return item;
    }
};

int main() {
    MyQueue q;

    q.enqueue('A');
    q.enqueue('B');
    cout << "dequeue() -> " << (char)q.dequeue() << endl;
    q.enqueue('C');
    cout << "dequeue() -> " << (char)q.dequeue() << endl;
    cout << "dequeue() -> " << (char)q.dequeue() << endl;

    return 0;
}
