//2020.09.27_#-1_自己套泛式递归
//注意：
//for (int i = start + 1; i <= MAX_N; i++) {
//vector<int> newOne = vector<int>(combination);
//newOne.push_back(i);
//recursion(newOne, i, level + 1);
//}
//不能写成
//for (int i = start + 1; i <= MAX_N; i++) {
//combination.push_back(i);
//recursion(combination, i, level + 1);
//}
//会导致类似引用的更改,怀疑vector的传递是浅拷贝

class Solution {
private:
    vector<vector<int>> list;
    int MAX_N;
    int MAX_LEVEL;
    
    void recursion(vector<int> combination, int start, int level) {
        if (level == MAX_LEVEL) {
            list.push_back(combination);
            return;
        }
        
        for (int i = start + 1; i <= MAX_N; i++) {
            vector<int> newOne = vector<int>(combination);
            newOne.push_back(i);
            recursion(newOne, i, level + 1);
        }
        
    }
    
    
public:
    vector<vector<int>> combine(int n, int k) {
        MAX_N = n;
        MAX_LEVEL = k;
        vector<int> empty = vector<int>();
        
        recursion(empty, 0, 0);
        
        return list;
    }
};
