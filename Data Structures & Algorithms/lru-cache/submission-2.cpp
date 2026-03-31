class LRUCache {
    struct Node {
        Node(int key=-1, int val=-1) 
            : key(key), val(val), prev(nullptr), next(nullptr) {}
        int key;
        int val;
        Node* prev;
        Node* next;
    };

    Node* head;
    Node* tail;

    unordered_map<int, Node*> key2NodePtr;
    int cap;

    void insert(Node* newNode) {
        auto lastNode = tail->prev;
        lastNode->next = newNode;
        newNode->prev = lastNode;

        newNode->next = tail;
        tail->prev = newNode;
    }

    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

public:
    LRUCache(int capacity) 
        : cap(capacity), head(new Node()), tail(new Node()) {
        key2NodePtr.clear();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (not key2NodePtr.count(key)) {
            return -1;
        }

        auto nodePtr = key2NodePtr[key];
        remove(nodePtr);
        insert(nodePtr);
        return nodePtr->val;
    }
    
    void put(int key, int value) {
        if (key2NodePtr.count(key)) {
            remove(key2NodePtr[key]);
        }

        auto newNode = new Node(key, value);
        key2NodePtr[key] = newNode;
        insert(newNode);
        if (key2NodePtr.size() > cap) {
            auto lruNode = head->next;
            remove(lruNode);
            key2NodePtr.erase(lruNode->key);
            delete lruNode;
        }
    }
};
