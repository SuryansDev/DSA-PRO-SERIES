class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int change = 0;
        for(int i = 0; i < k; i++) if(blocks[i] == 'W') change++;

        int min = change;
        for(int i = k; i < blocks.size(); i++){
            if(blocks[i] == 'W') change++;
            if(blocks[i - k] == 'W') change--;

            if(change < min) min = change;
        }
        return min;
    }
};