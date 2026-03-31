class LRUCache {
    struct Node {
        Node(int key, int val) : key(key), val(val) {}
        int key, val;
        Node *next = nullptr, *prev = nullptr;
    };

    void deleteNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insertAtBeg(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }
    
    Node *head, *tail; // head = mru, tail = lru
    map<int, Node*> key2Node;
    int cap;

public:
    LRUCache(int capacity) : cap(capacity) {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;    
    }
    
    int get(int key) {
        auto it = key2Node.find(key);
        if (it == key2Node.end()) {
            return -1;
        }

        auto node = it->second;
        // key present, bring the key to the mru position
        deleteNode(node);
        insertAtBeg(node);
        return node->val;
    }
    
    void put(int key, int value) {
        auto it = key2Node.find(key);
        if (it == key2Node.end()) {
            if (key2Node.size() == cap) {
                auto lruNode = tail->prev;
                deleteNode(lruNode);
                key2Node.erase(lruNode->key);
                delete lruNode;
            }

            auto newNode = new Node(key, value);
            insertAtBeg(newNode);
            key2Node[key] = newNode;
        } else {
            auto node = it->second;
            node->val = value;
            deleteNode(node);
            insertAtBeg(node);
        }
    }
};
