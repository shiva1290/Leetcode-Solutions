class Solution {
public:
    int ladderLength(string startWord, string targetWord,
                     vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;
        q.push({startWord, 1});
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            string word = node.first;
            int dist = node.second;
            if (targetWord == word)
                return dist;
            for (int i = 0; i < word.size(); i++) {
                for (int j = 0; j < 26; j++) {
                    string newWord = word;
                    newWord[i] = 'a' + j;
                    if (st.count(newWord)) {
                        q.push({newWord, dist + 1});
                        st.erase(newWord);
                    }
                }
            }
        }
        return 0;
    }
};