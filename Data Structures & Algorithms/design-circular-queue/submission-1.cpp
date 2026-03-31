class MyCircularQueue {
    struct Node {
        int val = -1;
        Node* next = nullptr;
    };

    Node* head = nullptr, *tail = nullptr;
    int size = 0;
    int capacity;

public:
    MyCircularQueue(int k) : capacity(k) {}
    
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }

        auto newNode = new Node(value);
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

        tail->next = head;
        size++;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }

        auto tmp = head;
        if (size == 1) {
            head = tail = nullptr;
        } else {
            head = head->next;
            tail->next = head;
        }

        delete tmp;
        size--;
        return true;
    }
    
    int Front() {
        return isEmpty() ? -1 : head->val;
    }
    
    int Rear() {
        return isEmpty() ? -1 : tail->val;
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == capacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */