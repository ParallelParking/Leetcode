class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<char> terminals;
        int count = 0;
        terminals.reserve(s.size());
        for (const auto & c : s) {
            if (terminals.find(c) != terminals.end()) continue;
            terminals.insert(c);
            int first = s.find(c);
            int last = s.find_last_of(c);
            if (last == first) continue;
            unordered_set<char> middle;
            middle.reserve(last - first - 1);
            for (int i = first + 1; i < last; i++) {
                if (middle.find(s[i]) != middle.end()) continue;
                middle.insert(s[i]);
                count++;
            }
        }
        return count;
    }
};