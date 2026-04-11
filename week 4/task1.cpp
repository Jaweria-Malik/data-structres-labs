#include <iostream>
using namespace std;


template <typename T>
class AbstractQueue {
public:
    virtual void enQueue(T value) = 0;
    virtual T deQueue() = 0;
    virtual T front() const = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;
    virtual ~AbstractQueue() {}
};


template <typename T>
class myQueue : public AbstractQueue<T> {
private:
    T* arr;
    int frontIndex;
    int rear;
    int size;
    int capacity;

public:
    
    myQueue(int cap) {
        capacity = cap;
        arr = new T[capacity];
        frontIndex = 0;
        rear = -1;
        size = 0;
    }

    
    ~myQueue() {
        delete[] arr;
    }

    
    void enQueue(T value) {
        if (isFull()) {
            cout << "Queue is Full!\n";
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = value;
        size++;
        cout << value << " inserted into queue.\n";
    }

    
    T deQueue() {
        if (isEmpty()) {
            cout << "Queue is Empty!\n";
            return T(); 
        }
        T val = arr[frontIndex];
        frontIndex = (frontIndex + 1) % capacity;
        size--;
        return val;
    }

    
    T front() const {
        if (isEmpty()) {
            cout << "Queue is Empty!\n";
            return T();
        }
        return arr[frontIndex];
    }

    
    bool isEmpty() const {
        return size == 0;
    }

    
    bool isFull() const {
        return size == capacity;
    }

    
    void display() const {
        if (isEmpty()) {
            cout << "Queue is Empty!\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = 0; i < size; i++) {
            cout << arr[(frontIndex + i) % capacity] << " ";
        }
        cout << endl;
    }
};

int main() {
    int cap;
    cout << "Enter queue capacity: ";
    cin >> cap;

    myQueue<int> q(cap);

    int choice, value;

    do {
        cout << "\n===== QUEUE MENU =====\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Front\n";
        cout << "4. Display\n";
        cout << "5. Check Empty\n";
        cout << "6. Check Full\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            q.enQueue(value);
            break;

        case 2:
            cout << "Removed: " << q.deQueue() << endl;
            break;

        case 3:
            cout << "Front element: " << q.front() << endl;
            break;

        case 4:
            q.display();
            break;

        case 5:
            if (q.isEmpty())
                cout << "Queue is Empty\n";
            else
                cout << "Queue is NOT Empty\n";
            break;

        case 6:
            if (q.isFull())
                cout << "Queue is Full\n";
            else
                cout << "Queue is NOT Full\n";
            break;

        case 7:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 7);

    return 0;
}

