class Solution {
public:
    string reverseWords(string s) {
          int n = s.size();
        int write = 0;
        int read = 0;

        while (read < n && s[read] == ' ') read++;

        while (read < n) {
            if (s[read] != ' ') {
                s[write++] = s[read++];
            } else {
                s[write++] = ' ';
                while (read < n && s[read] == ' ') read++;
            }
        }

        if (write > 0 && s[write - 1] == ' ') write--;

        s.resize(write);

        reverse(s.begin(), s.end());

        int k = 0;
        bool wordFound = false;

        for (int i = 0; i < s.size(); i++) {
            if (!wordFound) {
                wordFound = true;
                k = i;

            } else if (wordFound && s[i] == ' ') {
                reverse(s.begin() + k, s.begin() + i);
                wordFound = false;
            }
        }
        if (wordFound) {
            reverse(s.begin() + k, s.end());
        }

        return s;
    }
};