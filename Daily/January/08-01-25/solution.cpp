class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int pairs = 0;
        int ws = words.size();
        for (int i = 0; i < ws; i++) {
            string s = words[i];
            int ss = s.size();
            for (int j = i + 1; j < ws; j++) {
                string t = words[j];
                int ts = t.size();
                if (ts < ss) continue;
                if (t.find(s) == 0 && t.rfind(s) == ts - ss) pairs++;
            }
        }
        return pairs;
    }
};