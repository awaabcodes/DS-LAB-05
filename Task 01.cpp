#include <iostream>
using namespace std;

const int CAPACITY = 8;

class UndoStack {
    int data[CAPACITY];
    int topIdx;
public:
    UndoStack() : topIdx(-1) {}
    bool isEmpty() const { return topIdx == -1; }
    bool isFull() const { return topIdx == CAPACITY - 1; }
    bool push(int code) {
        if (isFull()) return false;
        data[++topIdx] = code;
        return true;
    }
    bool pop(int &code) {
        if (isEmpty()) return false;
        code = data[topIdx--];
        return true;
    }
    void showTop() const {
        if (isEmpty()) cout << "Current top: none (stack empty)" << endl;
        else cout << "Current top: " << data[topIdx] << endl;
    }
    void showAll() const {
        for (int i = topIdx; i >= 0; i--) cout << data[i] << " ";
        cout << endl;
    }
};

void doOperation(UndoStack &s, int code) {
    if (s.push(code)) cout << "Operation " << code << " performed. ";
    else cout << "Stack full, operation " << code << " not stored. ";
    s.showTop();
}

void doUndo(UndoStack &s) {
    int removed;
    if (s.pop(removed)) cout << "Undo removed " << removed << ". ";
    else cout << "Undo failed: nothing to undo. ";
    s.showTop();
}

int main() {
    UndoStack s;
    int ops[] = {12, 25, 17, 31, 44, 19};
    for (int i = 0; i < 6; i++) doOperation(s, ops[i]);
    for (int i = 0; i < 3; i++) doUndo(s);
    doOperation(s, 52);
    for (int i = 0; i < 2; i++) doUndo(s);
    cout << "Remaining (top to bottom): ";
    s.showAll();

    cout << "Undo on empty stack:" << endl;
    UndoStack empty;
    doUndo(empty);
    return 0;
}
