class MyCircularQueue {
    struct Node {
        int val = -1;
        Node* next = nullptr;
    };

    Node* head = nullptr, *tail = nullptr;
    int capacity;

public:
    MyCircularQueue(int k) : capacity(k) {
        head = new Node();
        tail = head;
    }
    
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }

        capacity--;
        auto newNode = new Node(value);
        tail->next = newNode;
        tail = newNode;
        tail->next = head;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }

        capacity++;
        auto tmp = head;
        head = head->next;
        tail->next = head;
        delete tmp;
        return true;
    }
    
    int Front() {
        return isEmpty() ? -1 : head->next->val;
    }
    
    int Rear() {
        return isEmpty() ? -1 : tail->val;
    }
    
    bool isEmpty() {
        return head == tail;
    }
    
    bool isFull() {
        return capacity == 0;
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