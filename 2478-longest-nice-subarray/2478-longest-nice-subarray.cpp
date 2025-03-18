class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int xor_ = 0;
        int j = 0;
        int max = 1;
        for(int i = 0; i < nums.size(); i++){
            while((nums[i] & xor_) != 0) xor_ ^= nums[j++];
            xor_ |= nums[i];
            if(max < i - j + 1) max = i - j + 1;
        }
        return max;
    }
};