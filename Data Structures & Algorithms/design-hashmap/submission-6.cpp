class MyHashMap {
    struct Node {
        Node() = default;
        Node(int key, int val) : key(key), val(val) {}
        int key = -1;
        int val = -1;
        Node* next = nullptr;
    };

    const size_t NUM_BUCKETS = 10000;
    vector<Node*> buckets;

    int hash(int key) {
        return key % NUM_BUCKETS;
    }

public:
    MyHashMap() {
        buckets.resize(NUM_BUCKETS);
        for (auto& b : buckets) {
            b = new Node();
        }
    }
    
    void put(int key, int value) {
        auto cur = buckets[hash(key)];
        while (cur->next) {
            if (cur->next->key == key) {
                cur->next->val = value;
                return;
            }

            cur = cur->next;
        }

        cur->next = new Node(key, value);
    }
    
    int get(int key) {
        auto cur = buckets[hash(key)];
        cur = cur->next; // dummy node;
        while (cur) {
            if (cur->key == key) {
                return cur->val;
            }

            cur = cur->next;
        }

        return -1;
    }
    
    void remove(int key) {
        auto cur = buckets[hash(key)];
        while (cur->next) {
            if (cur->next->key == key) {
                auto tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
                return;
            }

            cur = cur->next;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */