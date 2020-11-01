class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<vector<string>>> layer({{beginWord, {{beginWord}}}});
        set<string> wordSet(wordList.begin(), wordList.end());

        while (!layer.empty()) {
            unordered_map<string, vector<vector<string>>> newlayer;
            for (const auto& p : layer) {
                if (p.first == endWord) {
                    return layer[p.first];
                }
                for (int i = 0; i < p.first.size(); i++) {
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == p.first[i]) continue;
                        string nword = p.first.substr(0, i) + c + p.first.substr(i + 1, p.first.size() - i - 1);
                        if (wordSet.find(nword) == wordSet.end()) continue;
                        vector<vector<string>> npaths = layer[p.first];
                        for (auto v : npaths) {
                            v.push_back(nword);
                            if (newlayer.find(nword) == newlayer.end()) {
                                newlayer[nword] = {v};
                            } else {
                                newlayer[nword].push_back(v);
                            }
                        }
                    }
                }
            }
            for (const auto& p : newlayer) {
                wordSet.erase(p.first);
            }
            layer = newlayer;
        }
        return vector<vector<string>>();
    }
};
