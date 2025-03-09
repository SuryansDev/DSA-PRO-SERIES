class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int match = 0, n = colors.size();
        int validGroups = 0;
        for(int i = 0; i < k - 2; i++){
            if(colors[i] == colors[i + 1]) match++;
        }

        for(int i = k - 2; i < n + k - 2; i++){
            if(colors[i % n] == colors[(i + 1) % n]) match++;
            if(match == 0) validGroups++;
            if(colors[(i - k + 2) % n] == colors[(i - k + 2 + 1) % n]) match--;
        }

        return validGroups;
    }
};