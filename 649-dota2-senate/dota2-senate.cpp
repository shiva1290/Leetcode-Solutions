class Solution {
public:
    string predictPartyVictory(string senate) {
       queue<int> rq, dq;
       int n=senate.size();
       for(int i=0;i<senate.size();i++){
        char c=senate[i];
            if(c=='R'){
                rq.push(i);
            }
            else dq.push(i);
       }
       while(!dq.empty() && !rq.empty()){
            int r=rq.front();
            int d=dq.front();
            rq.pop();
            dq.pop();
            if(r>d){
                dq.push(n+d);
            }
            else{
                rq.push(n+r);
            }
       }
       return (rq.empty()) ?  "Dire" : "Radiant";
    }
};