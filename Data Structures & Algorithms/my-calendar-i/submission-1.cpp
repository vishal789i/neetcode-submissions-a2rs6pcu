class MyCalendar {
    vector<pair<int, int>> events;

public:
    MyCalendar() {}
    
    bool book(int startTime, int endTime) {
        for (auto [s, e] : events) {
            cout << (startTime < e) << " " << (endTime > s) << endl;
            if (startTime < e and endTime > s) {
                return false;
            } 
        }

        events.push_back({startTime, endTime});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */