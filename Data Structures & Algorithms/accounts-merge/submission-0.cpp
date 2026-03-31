class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<int> parent(accounts.size());
        for (int i = 0; i < accounts.size(); ++i) {
            parent[i] = i;
        }

        auto find = [&] (int n) {
            while (n != parent[n]) {
                n = parent[n];
            }

            return n;
        };

        auto unionSets = [&] (int n1, int n2) {
            parent[find(n1)] = find(n2);
        };

        map<string, int> email2AccId;
        for (int i = 0; i < accounts.size(); ++i) {
            for (int j = 1; j < accounts[i].size(); ++j) { // idx 0 = name
                auto& email = accounts[i][j];
                if (email2AccId.contains(email)) {
                    auto& accId = email2AccId.at(email);
                    unionSets(accId, i);
                } else {
                    email2AccId[email] = i;
                }
            }
        }

        map<int, vector<string>> accId2Emails; // leader acc to list of all emails
        for (auto& [email, accId] : email2AccId) {
            accId2Emails[find(accId)].push_back(email);
        }

        vector<vector<string>> res;
        for (auto& [accId, emails] : accId2Emails) {
            sort(emails.begin(), emails.end());
            vector<string> mergedEmails;
            mergedEmails.push_back(accounts[accId][0]); // adding name to front
            mergedEmails.insert(mergedEmails.end(), emails.begin(), emails.end());
            res.push_back(mergedEmails);
        }

        return res;
    }
};