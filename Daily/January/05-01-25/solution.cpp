class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int l = s.size();
        vector<int> d(l + 1, 0); //difference array
        for (auto const & shift : shifts) {
            if (shift[2]) {
                d[shift[0]]++;
                d[shift[1] + 1]--;
            } else {
                d[shift[0]]--;
                d[shift[1] + 1]++;
            }
        }
        vector<int> t(d.size(), 0);
        inclusive_scan(d.begin(), d.end(), t.begin());
        for (int i = 0; i < l; i++) {
            int n = s[i] + t[i];
            n = (n - 'a') % 26; 
            if (n < 0) n += 26; 
            s[i] = 'a' + n;    
        }
        return s;
    }
};