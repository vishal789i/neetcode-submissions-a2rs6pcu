class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives = 0, tens = 0;
        for (auto b : bills) {
            auto rem = b - 5;
            if (rem == 0) {
                fives++;
            } else if (rem == 5) {
                tens++;
                if (fives > 0) {
                    fives--;
                } else {
                    return false;
                }
            } else if (rem == 15) {
                if (fives > 0 and tens > 0) {
                    fives--;
                    tens--;
                } else if (fives >= 3) {
                    fives -= 3;
                } else {
                    return false;
                }
            }
        }

        return true;
    }
};


// fives 0 tens 0 
// fives 1 tens 0 
// fives 0 tens 1
// fives 1 tens 1
// fives 2 tens 1
// fives 2 tens 1
