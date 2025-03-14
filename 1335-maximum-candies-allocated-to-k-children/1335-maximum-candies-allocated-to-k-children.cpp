class Solution {
public:
    bool check(vector<int>& candies, long long k, int candy){
        long long count = 0;
        for(auto const & i : candies) count += i / candy;
        return count >= k;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        int low = 1, high = 0, last = 0;

            long long sum = 0;
            for(auto const& i : candies) sum += i;
            if(sum < k) return 0;

            high = sum / k;
            
        while(low <= high){
            int mid = (low + high) >> 1;
            if(check(candies, k, mid)){
                last = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }    
        return last;
    }
};