#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class TextEditor {
    stack<string> undoStack;
    stack<string> redoStack;
public:
    void type(const string &word) {
        undoStack.push(word);
        while (!redoStack.empty()) redoStack.pop();
    }
    void undo() {
        if (undoStack.empty()) return;
        redoStack.push(undoStack.top());
        undoStack.pop();
    }
    void redo() {
        if (redoStack.empty()) return;
        undoStack.push(redoStack.top());
        redoStack.pop();
    }
    void print() const {
        stack<string> temp = undoStack;
        vector<string> words;
        while (!temp.empty()) {
            words.push_back(temp.top());
            temp.pop();
        }
        cout << "\"";
        for (int i = (int)words.size() - 1; i >= 0; i--) {
            cout << words[i];
            if (i > 0) cout << " ";
        }
        cout << "\"" << endl;
    }
};

int main() {
    TextEditor ed;

    cout << "type(\"Hello\")  -> ";
    ed.type("Hello");
    ed.print();

    cout << "type(\"World\")  -> ";
    ed.type("World");
    ed.print();

    cout << "undo()         -> ";
    ed.undo();
    ed.print();

    cout << "redo()         -> ";
    ed.redo();
    ed.print();

    cout << "undo()         -> ";
    ed.undo();
    ed.print();

    cout << "type(\"There\")  -> ";
    ed.type("There");
    ed.print();

    cout << "redo()         -> ";
    ed.redo();
    ed.print();

    return 0;
}
