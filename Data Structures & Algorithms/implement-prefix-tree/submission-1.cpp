class PrefixTree {
    struct Node {
        bool isEnd = false;
        map<char, Node*> ch2Node;
    };

    Node* root = nullptr;

public:
    PrefixTree() {
        root = new Node();
    }
    
    void insert(string word) {
        auto cur = root;
        for (auto ch : word) {
            if (not cur->ch2Node.contains(ch)) {
                cur->ch2Node.emplace(ch, new Node());
            }

            cur = cur->ch2Node.at(ch);
        }

        cur->isEnd = true;
    }
    
    bool search(string word) {
        auto cur = root;
        for (auto ch : word) {
            if (not cur->ch2Node.contains(ch)) {
                return false;
            }

            cur = cur->ch2Node.at(ch);
        }

        return cur->isEnd;
    }
    
    bool startsWith(string prefix) {
        auto cur = root;
        for (auto ch : prefix) {
            if (not cur->ch2Node.contains(ch)) {
                return false;
            }

            cur = cur->ch2Node.at(ch);
        }

        return true;
    }
};
