class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int l = 0, r = people.size() - 1;
        // 1, 2, 4, 5
        int res = 0;
        while (l <= r) {
            res++;
            int rem = limit - people[r--];
            if (people[l] <= rem) {
                l++;
            }
        }

        return res;
    }
};