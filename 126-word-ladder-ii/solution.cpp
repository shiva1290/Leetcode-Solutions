class Solution {
   public:
    void dfs(string word, string &startWord, vector<string> &seq,
             unordered_map<string, int> &dist, vector<vector<string>> &ans) {
        if (word == startWord) {
            vector<string> path = seq;
            reverse(path.begin(), path.end());
            ans.push_back(path);
            return;
        }
        int val = dist[word];
        for (int i = 0; i < word.size(); i++) {
            string newWord = word;
            for (char c = 'a'; c <= 'z'; c++) {
                if (word[i] == c) continue;
                newWord[i] = c;
                if (dist.find(newWord) != dist.end() &&
                    dist[newWord] + 1 == val) {
                    seq.push_back(newWord);
                    dfs(newWord, startWord, seq, dist, ans);
                    seq.pop_back();
                }
            }
        }
    }

    vector<vector<string>> findLadders(string startWord, string targetWord,
                                         vector<string> &wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        unordered_map<string, int> dist;
        queue<string> q;
        q.push(startWord);
        dist[startWord] = 0;
        st.erase(startWord);
        while (!q.empty()) {
            string word = q.front();
            q.pop();
            for (int i = 0; i < word.size(); i++) {
                string newWord = word;
                for (char c = 'a'; c <= 'z'; c++) {
                    if (word[i] == c) continue;
                    newWord[i] = c;
                    if (st.count(newWord)) {
                        dist[newWord] = dist[word] + 1;
                        q.push(newWord);
                        st.erase(newWord);
                    }
                }
            }
        }
        if (dist.find(targetWord) == dist.end()) return {};
        vector<vector<string>> ans;
        vector<string> seq;
        seq.push_back(targetWord);
        dfs(targetWord, startWord, seq, dist, ans);
        return ans;
    }
};
