class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> nums2Freq;
        for (auto num: nums) {
            nums2Freq[num]++;
        }
        struct myComp {
            constexpr bool operator()(pair<int, int> const& a, pair<int, int> const& b) const noexcept
            {
                return a.second < b.second;
            }
        };


        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, myComp> pq;
        for (auto [num, freq]: nums2Freq) {
            pq.push(std::make_pair(num, freq));
        }
        
        std::vector<int> ans;
        while (k--) {
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};
