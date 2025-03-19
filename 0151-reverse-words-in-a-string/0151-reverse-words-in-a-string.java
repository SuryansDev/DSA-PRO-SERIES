class Solution {
    public String reverseWords(String s) {
        StringBuilder ans = new StringBuilder();
        String[] words = s.trim().split(" ");
        for(int i = words.length - 1; i >= 0; i--){
            String word = words[i];
            if(!word.equals("")) ans.append(word + " ");
        }
        ans.setLength(ans.length() - 1);
        return ans.toString();
    }
}