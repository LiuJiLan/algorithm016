class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int fmin = nums[0], fmax = nums[0], result = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int oldfmin = fmin;
            fmin = min(fmin * nums[i], min(fmax * nums[i], nums[i]));
            fmax = max(fmax * nums[i], max(oldfmin * nums[i], nums[i]));
            result = max(result, max(fmin, fmax));
        }
        return result;
    }
};
