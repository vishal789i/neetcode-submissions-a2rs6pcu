class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int l = 0, r = people.size() - 1, res = 0;
        while (l <= r) {
            if (l == r) {
                if (people[l] <= limit) {
                    res++;
                    l++;
                }

                break;
            }

            if (people[r] + people[l] <= limit) {
                res++;
                r--;
                l++;
            } else {
                if (people[r] <= limit) {
                    res++;
                    r--;
                } else if (people[l] <= limit) {
                    res++;
                    l++;
                } else {
                    break;
                }
            }
        }

        return res;
    }

    // 1, 2, 4, 5
    //    r  l  lim = 3  res = 2
    //    lr
    // 
    //
    //
    // 
};
