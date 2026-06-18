class LRUCache {
    struct Node {
        int key = -1, val = -1;
        Node *prev = nullptr, *next = nullptr;
    };

    Node *head = nullptr, *tail = nullptr;
    map<int, Node*> mp;
    int cap = -1;
    
    // head = mru, tail = lru
    void insertNode(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    void deleteNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

public:
    LRUCache(int capacity) : cap(capacity) {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (not mp.contains(key)) {
            return -1;
        }

        auto node = mp.at(key);
        deleteNode(node);
        insertNode(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if (mp.contains(key)) {
            auto node = mp.at(key);
            node->val = value;
            deleteNode(node);
            insertNode(node);
            return;
        }

        if (mp.size() == cap) {
            auto lruNode = tail->prev;
            deleteNode(lruNode);
            mp.erase(lruNode->key);
        }

        auto newNode = new Node(key, value);
        mp[key] = newNode;
        insertNode(newNode);
    }
};
