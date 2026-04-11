#include <iostream>
#include <stack>
using namespace std;

class QueueUsingStacks {
private:
    stack<int> s1, s2;

public:
    void enqueue(int x) {
        s1.push(x);
    }

    int dequeue() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is Empty\n";
            return -1;
        }
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int val = s2.top();
        s2.pop();
        return val;
    }

    int front() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is Empty\n";
            return -1;
        }
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }

    void display() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is Empty\n";
            return;
        }

        stack<int> temp1 = s1, temp2 = s2;
        stack<int> result;

        while (!temp2.empty()) {
            result.push(temp2.top());
            temp2.pop();
        }

        while (!temp1.empty()) {
            result.push(temp1.top());
            temp1.pop();
        }

        while (!result.empty()) {
            cout << result.top() << " ";
            result.pop();
        }
        cout << endl;
    }
};

int main() {
    QueueUsingStacks q;
    int choice, value;

    do {
        cout << "\n1.Enqueue 2.Dequeue 3.Front 4.Display 5.Exit\n";
        cin >> choice;

        switch (choice) {
        case 1:
            cin >> value;
            q.enqueue(value);
            break;
        case 2:
            cout << q.dequeue() << endl;
            break;
        case 3:
            cout << q.front() << endl;
            break;
        case 4:
            q.display();
            break;
        }
    } while (choice != 5);

    return 0;
}
