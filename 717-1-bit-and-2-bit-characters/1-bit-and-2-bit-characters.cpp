class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
    int counter=0;
        while(counter<bits.size()-1){
            if(bits[counter]==1){
                counter+=2;
            }
            else counter++;
            if(counter>bits.size()-1) return false;
        }
    return true;
    }
};