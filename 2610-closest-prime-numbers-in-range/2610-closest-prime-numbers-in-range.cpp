class Solution {
public:
    vector<int> primes = [](){
        vector<int> ans;
        vector<bool> composite(1e6 + 1);
        for(int i = 2; i <= 1e6; i++){
            if(!composite[i]){ 
                ans.push_back(i);
                for(int j = 2; i * j <= 1e6; j++){
                    composite[i * j] = true;
                }
            }
        }
        return ans;
    }();

    vector<int> closestPrimes(int left, int right) {
        vector<int> ans = {-1, -1};
        int diff = INT_MAX;
        int low = lower_bound(primes.begin(), primes.end(), left) - primes.begin();
        while(low + 1 < primes.size() && primes[low + 1] <= right){
            if(primes[low + 1] - primes[low] < diff){
                ans[0] = primes[low];
                ans[1] = primes[low + 1];
                diff = primes[low + 1] - primes[low];
            }
            low++;
        }

        return ans;
    }
};