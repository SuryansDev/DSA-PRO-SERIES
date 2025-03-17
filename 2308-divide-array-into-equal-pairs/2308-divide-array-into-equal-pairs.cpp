class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<int> freq(501, 0);
        for(auto const & i : nums) freq[i]++;
        for(int i = 0; i < 501; i++){
            if((freq[i] & 1) != 0) return false;
        }
        return true;
    }
};