static auto init = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return nullptr;
}();

class Solution {
public:
    bool isVowel(char c){
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
        return false;
    }

    bool check(vector<int> freq){
        return freq[0] > 0 && freq['e' - 'a'] > 0 && freq['i' - 'a'] > 0 && freq['o' - 'a'] > 0 && freq['u' - 'a'] > 0;
    }

    long long countOfSubstrings(string word, int k) {
        vector<int> freq(26, 0);
        int cont = 0, ptr1 = 0, ptr2 = 0;
        long long validSubs = 0;
        for(int i = 0; i < word.size(); i++){
            if(isVowel(word[i])) freq[word[i] - 'a']++;
            else cont++;

            if(k < cont){
                while(isVowel(word[ptr2])) freq[word[ptr2++] - 'a']--;
                freq[word[ptr2++] - 'a']--;
                cont--;
                ptr1 = ptr2;
            }

            if(check(freq) && k == cont){
                while(isVowel(word[ptr2]) && freq[word[ptr2] - 'a'] != 1) freq[word[ptr2++] - 'a']--;
                validSubs += ptr2 - ptr1 + 1;
            }
            
        }
        return validSubs;
    }
};