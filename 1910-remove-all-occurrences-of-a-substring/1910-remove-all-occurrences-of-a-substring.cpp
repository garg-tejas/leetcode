class Solution {
public:
    string removeOccurrences(string s, string part) {
        string res;
        int startidx = s.find(part);
        if (startidx != string::npos) {
            s.erase(startidx, part.length());
        } else {
            return s;
        }
        return removeOccurrences(s, part);
    }
};