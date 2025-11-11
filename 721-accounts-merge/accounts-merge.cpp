class DisjointSet {
   public:
    vector<int> size;
    vector<int> parent;

    DisjointSet(int N) {
        size.resize(N, 1);
        parent.resize(N);
        for (int i = 0; i < N; i++) {
            parent[i] = i;
        }
    }
    bool find(int u, int v) { return findUPar(u) == findUPar(v); }
    int findUPar(int i) {
        if (parent[i] == i) {
            return i;
        }
        return parent[i] = findUPar(parent[i]);
    }
    void unionBySize(int u, int v) {
        int ul_u = findUPar(u);
        int ul_v = findUPar(v);
        if (ul_u == ul_v) return;
        if (size[ul_u] < size[ul_v]) {
            parent[ul_u] = ul_v;
            size[ul_v] += size[ul_u];
        } else {
            parent[ul_v] = ul_u;
            size[ul_u] += size[ul_v];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        DisjointSet ds(n);
        map<string,int>mpp;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail=accounts[i][j];
                if(mpp.find(mail)==mpp.end()){
                    mpp[mail]=i;
                }
                else {
                    ds.unionBySize(i,mpp[mail]);
                }
            }
        }

        vector<vector<string>>mergedMails(n);
        for(auto it: mpp){
            string mail=it.first;
            int node=ds.findUPar(it.second);
            mergedMails[node].push_back(mail);
        }

        vector<vector<string>>ans;
        for(int i=0;i<n;i++){
            if(mergedMails[i].size()==0) continue;
            string name=accounts[i][0];
            vector<string>temp;
            sort(mergedMails[i].begin(),mergedMails[i].end());
            temp.push_back(name);
            for(auto it : mergedMails[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }

        sort(ans.begin(),ans.end());
        return ans;
    }
};