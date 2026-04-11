 
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reverseK(queue<int>& q, int k) {
    if (k <= 1 || q.empty() || k > q.size()) return;

    stack<int> s;

    for (int i = 0; i < k; i++) {
        s.push(q.front());
        q.pop();
    }

    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    int rem = q.size() - k;

    for (int i = 0; i < rem; i++) {
        q.push(q.front());
        q.pop();
    }
}

void display(queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {
    queue<int> q;
    int n, val, k;

    cout << "Enter number of elements: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> val;
        q.push(val);
    }

    cout << "Enter K: ";
    cin >> k;

    reverseK(q, k);

    cout << "Queue after reversing first K elements: ";
    display(q);

    return 0;
}

