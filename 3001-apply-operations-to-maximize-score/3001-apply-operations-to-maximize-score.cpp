const int maxi = 100001;
int mod = 1e9 + 7;

vector<int> prime(maxi, true);
auto oneTime = [] {
    prime[0] = false;
    prime[1] = false;
    for (int i = 2; i * i <= maxi; i++) {
        if (prime[i]) {
            for (int j = i * i; j < maxi; j += i) {
                prime[j] = false;
            }
        }
    }
    return 0;
}();

class Solution {
public:
    int mod_mul(int a, int b){
        return (a%mod *1LL* b%mod) % mod;
    }

    int fastexp(int a, int b){
        if(b == 0) return 1;

        int div = fastexp(a,b/2);
        div = mod_mul(div,div);
        if(b&1){
            div = mod_mul(div,a);
        }

        return div;
    }

    vector<int> getSortedIndices(vector<int>& arr) {
        vector<int> indices(arr.size());
        for (int i = 0; i < arr.size(); ++i) {
            indices[i] = i;
        }

        sort(indices.begin(), indices.end(), [&arr](int i, int j) {
            return arr[i] > arr[j];
        });

        return indices;
    }

    int getScore(int x){
        int count = 0;
        if(prime[x]) return 1;
        for(int i = 2; i*i <= x; i++){
            if(prime[i] && x%i==0) count++;
            if(i*i != x && prime[x / i] && x%i==0) count++;
        }
        return count;
    }

    int maximumScore(vector<int>& nums, int k) {
        vector<int> score(nums.size(), 0);
        for(int i = 0; i < nums.size(); i++){
            score[i] = getScore(nums[i]);
        }        

        vector<long long> subCount(nums.size(), 0);

        stack<pair<int, int>> stck;
        stck.push({INT_MAX, -1});
        for(int i = 0; i < nums.size(); i++){
            while(score[i] > stck.top().first){
                int j = stck.top().second;
                stck.pop();
                int k = stck.top().second;
                subCount[j] = (i - j) * 1ll * (j - k);
            }
            stck.push({score[i], i});
        }

        int v = score.size();
        while(stck.size() > 1){
            int j = stck.top().second;
            stck.pop();
            int k = stck.top().second;
            subCount[j] = (v - j) * 1ll * (j - k);
        }

        // int mod = 1e9 + 7;
        int ans = 1;
        vector<int> sorted = getSortedIndices(nums);

        
        // for(int k : sorted) cout << k << " ";
        // cout << endl;
        // for(int j : subCount) cout << j << " ";
        // cout << endl;
        // for(int j : score) cout << j << " ";
        // cout << endl;


        int j = 0;
        // for(int i = 0; i < k; i++){
        //     if(subCount[sorted[j]] == 0) j++;
        //     ans = (ans * 1ll * nums[sorted[j]]) % mod;
        //     subCount[sorted[j]]--;
        // }

         while(k){
            int val = nums[sorted[j]];
            int power = k < subCount[sorted[j]] ? k : subCount[sorted[j]];
            k -= power;
            ans = mod_mul(ans, fastexp(val, power));
            j++;
        }

        return ans;
    }
};