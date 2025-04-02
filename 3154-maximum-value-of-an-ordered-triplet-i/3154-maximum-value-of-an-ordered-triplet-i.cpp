class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long res = 0;
        long long currMax = 0;
        int max = nums[0];
        for(auto& i : nums){
            long long curVal = currMax * i;
            if(res < curVal) res = curVal;

            if(currMax < max - i)  currMax = max - i;
            if(max < i) max = i;
        }
        return res;
    }
};