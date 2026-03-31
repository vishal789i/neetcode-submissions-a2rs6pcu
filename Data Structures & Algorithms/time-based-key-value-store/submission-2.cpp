class TimeMap {
    unordered_map<string, vector<pair<int, string>>> m_Key2TimestampValuePairVec;
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        m_Key2TimestampValuePairVec[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto& timestampValuePairVec = m_Key2TimestampValuePairVec[key];
        int l = 0, r = timestampValuePairVec.size() - 1;
        string result = "";
        while (l <= r) {
            int mid = l + (r - l)/2;
            if (timestampValuePairVec[mid].first <= timestamp) {
                result = timestampValuePairVec[mid].second;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return result;
    }
};
