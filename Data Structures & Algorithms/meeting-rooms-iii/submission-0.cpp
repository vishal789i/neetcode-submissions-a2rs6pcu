class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        vector<int> roomUsedCount(n);
        vector<long long> lastAvailableAt(n);
        for (auto& meeting : meetings) {
            auto start = meeting[0], end = meeting[1], duration = end - start;
            bool found = false;
            long long timeOfEarliestEndingRoom = LLONG_MAX;
            int earliestEndingRoom = -1;
            for (auto room = 0; room < n; ++room) {
                if (lastAvailableAt[room] <= start) {
                    lastAvailableAt[room] = end;
                    roomUsedCount[room]++;
                    found = true;
                    break;
                }

                if (lastAvailableAt[room] < timeOfEarliestEndingRoom) {
                    timeOfEarliestEndingRoom = lastAvailableAt[room];
                    earliestEndingRoom = room;
                }
            }

            if (not found) {
                lastAvailableAt[earliestEndingRoom] += duration;
                roomUsedCount[earliestEndingRoom]++;
            }
        }

        return max_element(roomUsedCount.begin(), roomUsedCount.end()) - roomUsedCount.begin();
    }
};