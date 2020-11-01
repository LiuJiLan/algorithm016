class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> front {beginWord};
        set<string> back {endWord};
        set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end()) return 0;
        int level = 0;
        while (!front.empty()) {
            level++;
            set<string> newset;
            for (const auto& word : front) {
                for (int i = 0; i < word.size(); i++) {
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == word[i]) continue;
                        string val = word.substr(0, i) + c + word.substr(i + 1, word.size() - i - 1);
                        if (back.find(val) != back.end()) {
                            return level + 1;
                        }
                        if (wordSet.find(val) != wordSet.end()) {
                            newset.insert(val);
                            wordSet.erase(val);
                        }
                    }
                }
            }
            front = newset;
            if (front.size() > back.size()) {
                swap(front, back);
            }
        }
        return 0;
    }
};
