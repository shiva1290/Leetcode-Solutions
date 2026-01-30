class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> pairs;
        for(int i=0;i<nums1.size();i++){
            pairs.push_back({nums2[i],nums1[i]});
        }
        sort(pairs.begin(),pairs.end(),[](auto& a,auto &b){
            return (a.first>b.first);
        });
        priority_queue<int,vector<int>,greater<int>> pq;
        long long sum=0;
        long long answer=0;
        for(auto it: pairs){
            int num1=it.second;
            int num2=it.first;
            pq.push(num1);
            sum+=num1;
            if(pq.size()>k){
                int num=pq.top();
                pq.pop();
                sum-=num;
            }
            if(pq.size()==k){
                long long score=sum*num2;
                answer=max(answer,score);
            }
        }
        return answer;
    }
};