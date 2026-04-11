#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Package {
    int id;
    string address;
    int startTime;
    int endTime;
};

class DeliveryQueue {
private:
    queue<Package> packages;
public:
    void enqueue(Package p) { packages.push(p); }
    void dequeue(int currentTime) {
        if (packages.empty()) return;
        Package p = packages.front();
        if (currentTime > p.endTime) { packages.pop(); return; }
        packages.pop();
    }
    void front() {
        if (packages.empty()) return;
        Package p = packages.front();
        cout << "ID:" << p.id << " Address:" << p.address
            << " Window:" << p.startTime << "-" << p.endTime << endl;
    }
    void display() {
        if (packages.empty()) return;
        queue<Package> temp = packages;
        while (!temp.empty()) {
            Package p = temp.front();
            cout << "ID:" << p.id << " Address:" << p.address
                << " Window:" << p.startTime << "-" << p.endTime << endl;
            temp.pop();
        }
    }
    void timeToDeliver(int currentTime) {
        while (!packages.empty() && currentTime > packages.front().endTime)
            packages.pop();
    }
};

int main() {
    DeliveryQueue dq;
    int choice, currentTime;
    do {
        cin >> choice;
        switch (choice) {
        case 1: {
            Package p;
            cin >> p.id;
            cin.ignore();
            getline(cin, p.address);
            cin >> p.startTime >> p.endTime;
            dq.enqueue(p);
            break;
        }
        case 2:
            cin >> currentTime;
            dq.dequeue(currentTime);
            break;
        case 3:
            dq.front();
            break;
        case 4:
            dq.display();
            break;
        case 5:
            cin >> currentTime;
            dq.timeToDeliver(currentTime);
            break;
        }
    } while (choice != 6);
    return 0;
}
