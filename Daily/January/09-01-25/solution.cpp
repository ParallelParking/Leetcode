class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int pl = pref.size();
        int soln = 0;
        for (const auto &word : words) {
            int l = word.size();
            if (pl > l) continue;
            int j = 0;
            for (int i = 0; i < l; i++) {
                if (word[i] == pref[j]) {
                    j++;
                    if (j == pl) {
                        soln++;
                        break;
                    }
                } else break;
            }
        }
        return soln;
    }
};