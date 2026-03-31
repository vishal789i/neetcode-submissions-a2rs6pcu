#include <iostream>
#include <vector>
#include <cstring>

class MyHashSet {
    int* m_ArrPtr;
    bool* m_Flags; // Flags indicating if a slot is occupied
    int m_Capacity;
    int m_Size;

    int getHash(int key) const {
        return key % m_Capacity;
    }

    void resize() {
        int oldCapacity = m_Capacity;
        int* oldArr = m_ArrPtr;
        bool* oldFlags = m_Flags;

        m_Capacity *= 2;
        m_ArrPtr = new int[m_Capacity];
        m_Flags = new bool[m_Capacity];
        m_Size = 0;

        std::memset(m_Flags, false, m_Capacity * sizeof(bool));

        for (int i = 0; i < oldCapacity; ++i) {
            if (oldFlags[i]) {
                add(oldArr[i]);
            }
        }

        delete[] oldArr;
        delete[] oldFlags;
    }

public:
    MyHashSet() {
        m_Capacity = 8;
        m_Size = 0;
        m_ArrPtr = new int[m_Capacity];
        m_Flags = new bool[m_Capacity];
        std::memset(m_Flags, false, m_Capacity * sizeof(bool));
    }

    ~MyHashSet() {
        delete[] m_ArrPtr;
        delete[] m_Flags;
    }

    void add(int key) {
        if (contains(key)) return;  // Prevent duplicates

        if (m_Size * 2 >= m_Capacity) {  // Load factor > 0.5
            resize();
        }

        int idx = getHash(key);
        while (m_Flags[idx]) {
            idx = (idx + 1) % m_Capacity;
        }

        m_ArrPtr[idx] = key;
        m_Flags[idx] = true;
        ++m_Size;
    }

    void remove(int key) {
        int idx = getHash(key);
        int startIdx = idx;

        while (m_Flags[idx]) {
            if (m_ArrPtr[idx] == key) {
                m_Flags[idx] = false;
                --m_Size;
                return;
            }
            idx = (idx + 1) % m_Capacity;
            if (idx == startIdx) break;
        }
    }

    bool contains(int key) const {
        int idx = getHash(key);
        int startIdx = idx;

        while (m_Flags[idx]) {
            if (m_ArrPtr[idx] == key) {
                return true;
            }
            idx = (idx + 1) % m_Capacity;
            if (idx == startIdx) break;
        }

        return false;
    }
};
