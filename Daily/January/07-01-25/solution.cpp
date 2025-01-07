class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> substrings;
        int ws = words.size();
        substrings.reserve(ws);
        for (int i = 0; i < ws; i++) {
            string needle = words[i];
            vector<int> lps;
            int ns = needle.size();
            lps.reserve(ns);
            lps.push_back(0);
            int p = 0;
            int k = 1;
            while (k < ns) {
                if (needle[k] == needle[p]) {
                    lps.push_back(++p);
                    k++;
                } else {
                    if (p == 0) {
                        lps.push_back(p);
                        k++;
                    } else {
                        p = lps[p - 1];
                    }
                }
            }
            for (int j = 0; j < ws; j++) {
                if (i == j) continue;
                string haystack = words[j];
                int hs = haystack.size();
                if  (hs < ns) continue;
                int h = 0;
                int n = 0;
                while (h < hs) {
                    if (haystack[h] == needle[n]) {
                        h++;
                        n++;
                    } else {
                        if (n == 0) h++;
                        else n = lps[n - 1];
                    }
                    if (n == ns) {
                        substrings.push_back(needle);
                        goto outer;
                    }
                }
            }
            outer:
        }
        return substrings;
    }
};