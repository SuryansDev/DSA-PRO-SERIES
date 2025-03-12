class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> found(1e4 + 1, false);
        for(auto const & i : nums) found[i] += i;

        for(int i = 2; i <= 1e4; i++){
            found[i] = max(found[i] + found[i - 2], found[i -1]);
        }
        return found[1e4];
    }
};