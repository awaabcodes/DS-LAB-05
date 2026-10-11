#include <iostream>
#include <queue>
#include <stack>
#include <string>
using namespace std;

using Queue = queue<string>;

void reverseFirstK(Queue &q, int k) {
    int n = (int)q.size();
    if (k <= 0 || k > n) return;

    stack<string> st;
    for (int i = 0; i < k; i++) {
        st.push(q.front());
        q.pop();
    }
    while (!st.empty()) {
        q.push(st.top());
        st.pop();
    }
    for (int i = 0; i < n - k; i++) {
        q.push(q.front());
        q.pop();
    }
}

void printQueue(Queue q) {
    while (!q.empty()) {
        cout << q.front();
        q.pop();
        if (!q.empty()) cout << ", ";
    }
    cout << endl;
}

int main() {
    Queue q;
    for (int i = 1; i <= 7; i++) q.push("J" + to_string(i));

    cout << "Before: ";
    printQueue(q);

    reverseFirstK(q, 3);

    cout << "After:  ";
    printQueue(q);

    return 0;
}
