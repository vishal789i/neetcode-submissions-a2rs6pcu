class LRUCache {
    std::list<pair<int, int>> m_KeyValueList;
    unordered_map<int, std::list<pair<int, int>>::iterator> m_KeyToListIteratorMap;
    int m_Capacity;

public:
    LRUCache(int capacity) : m_Capacity(capacity) {}

    int get(int key) {
        if (not m_KeyToListIteratorMap.count(key)) {
            return - 1;
        }

        auto it = m_KeyToListIteratorMap[key];
        m_KeyValueList.splice(m_KeyValueList.begin(), m_KeyValueList, it);
        return it->second;
    }
    
    void put(int key, int value) {
        if (m_KeyToListIteratorMap.count(key)) {
            auto it = m_KeyToListIteratorMap.at(key);
            it->second = value;
            m_KeyValueList.splice(m_KeyValueList.begin(), m_KeyValueList, it);
            return;
        }

        m_KeyValueList.emplace_front(key, value);
        m_KeyToListIteratorMap[key] = m_KeyValueList.begin();

        if (m_KeyValueList.size() > m_Capacity) {
            auto lruIt = m_KeyValueList.back();
            m_KeyToListIteratorMap.erase(lruIt.first);
            m_KeyValueList.pop_back();
        }
    }
};
