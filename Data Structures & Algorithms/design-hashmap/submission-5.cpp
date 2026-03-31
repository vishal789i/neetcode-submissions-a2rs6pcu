class MyHashMap {
    struct Node {
        Node(int key=-1, int val=-1, Node* next=nullptr) : key(key), val(val), next(next) {}
        int key;
        int val;
        Node* next;
    };

    vector<Node*> map;
    
    int hash(int key) {
        return key % map.size();
    }

public:
    MyHashMap() {
        map.resize(10000);
        for (auto& bucket : map) {
            bucket = new Node(0);
        }
    }
    
    void put(int key, int value) {
        auto cur = map[hash(key)];
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
        auto cur = map[hash(key)]->next; // skip dummy
        while (cur) {
            if (cur->key == key) {
                return cur->val;
            }

            cur = cur->next;
        }

        return -1;
    }
    
    void remove(int key) {
        auto cur = map[hash(key)];
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