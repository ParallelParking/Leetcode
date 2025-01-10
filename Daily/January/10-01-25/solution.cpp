class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> soln;
        int l2 = words2.size();
        soln.reserve(words1.size());
        unordered_map<char, int> s;
        for (const auto& word : words2) {
            unordered_map<char, int> f;
            for (const auto& ch : word) f[ch]++;
            for (const auto& [k, v] : f) if (s[k] < v) s[k] = v;
        }
        for (const auto& word : words1) {
            unordered_map<char, int> f;
            for (const auto& ch : word) f[ch]++;
            for (const auto& [k, v] : s) if (f[k] < v) goto nextWord;
            soln.push_back(word);
            nextWord:
        }
        return soln;
    }
};