#include <iostream>
#include <queue>
using namespace std;

queue<string> emergencyQ, passengerQ, cargoQ;

void enqueue(string type, string id) {
    if (type == "E")
        emergencyQ.push(id);
    else if (type == "P")
        passengerQ.push(id);
    else
        cargoQ.push(id);
}

void dequeue() {
    if (!emergencyQ.empty()) {
        cout << emergencyQ.front() << endl;
        emergencyQ.pop();
    }
    else if (!passengerQ.empty()) {
        cout << passengerQ.front() << endl;
        passengerQ.pop();
    }
    else if (!cargoQ.empty()) {
        cout << cargoQ.front() << endl;
        cargoQ.pop();
    }
}

int main() {
    enqueue("P", "P1");
    enqueue("C", "C1");
    enqueue("E", "E1");
    enqueue("P", "P2");
    enqueue("C", "C2");
    enqueue("E", "E2");

    cout << "Landing Order:\n";

    for (int i = 0; i < 6; i++)
        dequeue();
}
