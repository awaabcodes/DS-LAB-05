#include <iostream>
using namespace std;

const int CAPACITY = 6;

class CircularQueue {
    int data[CAPACITY];
    int front;
    int rear;
    int count;
public:
    CircularQueue() : front(0), rear(-1), count(0) {}
    bool isEmpty() const { return count == 0; }
    bool isFull() const { return count == CAPACITY; }
    bool enqueue(int id) {
        if (isFull()) return false;
        rear = (rear + 1) % CAPACITY;
        data[rear] = id;
        count++;
        return true;
    }
    bool dequeue(int &id) {
        if (isEmpty()) return false;
        id = data[front];
        front = (front + 1) % CAPACITY;
        count--;
        return true;
    }
    void display() const {
        cout << "Boarding order: ";
        for (int i = 0; i < count; i++)
            cout << data[(front + i) % CAPACITY] << " ";
        cout << endl;
        cout << "Front position: " << front << endl;
        cout << "Rear position: " << rear << endl;
    }
};

void arrive(CircularQueue &q, int id) {
    if (q.enqueue(id)) cout << "Passenger " << id << " arrived" << endl;
    else cout << "Queue full, passenger " << id << " cannot enter" << endl;
}

void board(CircularQueue &q) {
    int id;
    if (q.dequeue(id)) cout << "Passenger " << id << " boarded" << endl;
    else cout << "Queue empty, no passenger to board" << endl;
}

int main() {
    CircularQueue q;

    for (int id = 101; id <= 106; id++) arrive(q, id);
    for (int i = 0; i < 3; i++) board(q);
    for (int id = 107; id <= 109; id++) arrive(q, id);
    for (int i = 0; i < 2; i++) board(q);
    arrive(q, 110);
    board(q);
    arrive(q, 111);
    arrive(q, 112);

    cout << endl;
    q.display();
    return 0;
}
