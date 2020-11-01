class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> um;
        for (int val : arr) {
            um[val]++;
        }
        set<int> uset;
        for (const auto& p : um) {
            if (uset.find(p.second) != uset.end()) {
                return false;
            }
            uset.insert(p.second);
        }
        return true;
    }
};
