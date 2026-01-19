class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int totalLength=word1.size()+word2.size();
        string newS(totalLength,' ');
        int i=0;
        int j=0;
        int k=0;
        while(i<totalLength){
            if(j<word1.size()){
                newS[i]=word1[j];
                j++;
                i++;
            }
            if(k<word2.size()){
                newS[i]=word2[k];
                k++;
                i++;
            }
        }
        return newS;
    }
};