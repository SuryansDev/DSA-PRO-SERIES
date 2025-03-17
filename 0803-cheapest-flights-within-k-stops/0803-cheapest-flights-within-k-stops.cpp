class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> price(n, INT_MAX);
        price[src] = 0;
        vector<int> newPrice(price);
        for(int i = 0; i <= k; i++){
            for(auto & flight : flights){
                if(price[flight[0]] != INT_MAX && newPrice[flight[1]] > price[flight[0]] + flight[2])
                    newPrice[flight[1]] = price[flight[0]] + flight[2];
            }
            price = newPrice;
        }
        if(price[dst] == INT_MAX) return -1;
        else return price[dst];
    }
};