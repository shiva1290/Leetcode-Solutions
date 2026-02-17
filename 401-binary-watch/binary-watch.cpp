class Solution {
public:
    void helper(int index, vector<int>& hours, vector<int>& minutes,
                vector<int>& bits, vector<string>& ans, int turnedOn, int hour,
                int minute) {
        if (turnedOn == 0) {
            if(hour>=12 || minute>59) return;
            string h, m;
            if (minute < 10)
                m += '0';
            h += to_string(hour);
            m += to_string(minute);
            string fin = h + ":" + m;
            ans.push_back(fin);
            return;
        }
        if (index == 6) {
            return;
        }
        int take = 0;
        if (turnedOn >= 1) {
            if (index < 4)
                helper(index + 1, hours, minutes, bits, ans, turnedOn - 1,
                       hour + bits[index], minute);
            helper(index + 1, hours, minutes, bits, ans, turnedOn - 1, hour,
                   minute + bits[index]);
            if (turnedOn >= 2 && index < 4)
                helper(index + 1, hours, minutes, bits, ans, turnedOn - 2,
                       hour + bits[index], minute + bits[index]);
        }
        helper(index + 1, hours, minutes, bits, ans, turnedOn, hour, minute);
    }
    vector<string> readBinaryWatch(int turnedOn) {
        vector<int> hours(4, 0);
        vector<int> minutes(6, 0);
        vector<string> ans;
        vector<int> bits;
        bits = {1, 2, 4, 8, 16, 32};
        helper(0, hours, minutes, bits, ans, turnedOn, 0, 0);
        return ans;
    }
};