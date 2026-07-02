class Solution {
    public String mergeAlternately(String word1, String word2) {
        String ans="";
        int minLen=Math.min(word1.length(),word2.length());
        int i=0;
        while(i<minLen){
            if(i>=word1.length()) break;
            else ans+=word1.charAt(i);
            if(i>=word2.length()) {
            break;
            }
            else ans+=word2.charAt(i);
            i++;
        }
        if(i<word1.length()) ans+=word1.substring(i,word1.length());
        if(i<word2.length()) ans+=word2.substring(i,word2.length());
        return ans;
    }
}