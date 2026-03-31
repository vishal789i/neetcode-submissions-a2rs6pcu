class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for (auto stone: stones) {
            pq.push(stone);
        }

        while (pq.size() >= 2) {
            auto stone1 = pq.top();
            pq.pop();
            auto stone2 = pq.top();
            pq.pop();

            auto wtDiff = abs(stone1 - stone2);
            pq.push(wtDiff);
            // if (wtDiff > 0) {
            // }
        }

        // pq.size() is < 2

        return pq.top();
    }
};
