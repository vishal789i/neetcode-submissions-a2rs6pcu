class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int> hand2Freq;
        for (auto h : hand) {
            hand2Freq[h]++;
        }

        priority_queue<int, vector<int>, greater<>> minHeap;
        for (auto it : hand2Freq) {
            minHeap.push(it.first);
        }

        int cardNum = 0;
        while (not minHeap.empty()) {
            int first = minHeap.top();
            
            for (int i = first; i < first + groupSize; ++i) {
                if (not hand2Freq.count(i)) {
                    return false;
                }

                hand2Freq[i]--;
                if (hand2Freq[i] == 0) {
                    if (minHeap.top() != i) {
                        return false;
                    }
                    minHeap.pop();
                }
            }
        }

        return true;
    }
};
