class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        auto is_vowel = [&vowels](char c) { 
            return vowels.find(c) != vowels.end(); 
        };
        
        vector<int> prefix_sum;
        prefix_sum.reserve(words.size() + 1);
        prefix_sum.push_back(0);
        int cumulative_sum = 0;
        for (auto const & word : words) {
            if (is_vowel(word.front()) && is_vowel(word.back())) {
                cumulative_sum++;
            }
            prefix_sum.push_back(cumulative_sum);
        }

        vector<int> soln;
        soln.reserve(queries.size());
        for (auto const & query : queries) { 
            soln.push_back(prefix_sum[query[1] + 1] - prefix_sum[query[0]]);
        }
        
        return soln;
    }
};