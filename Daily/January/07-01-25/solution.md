# 1408. String Matching in an Array

Given an array of string words, return all strings in words that is a substring of another word. You can return the answer in any order.

A substring is a contiguous sequence of characters within a string

Input: words = ["mass","as","hero","superhero"]

Output: ["as","hero"]

Explanation: "as" is substring of "mass" and "hero" is substring of "superhero". ["hero","as"] is also a valid answer.

## Solution:

### The basic idea

The Knuth-Morris-Prat Algorithm: (See https://www.youtube.com/watch?v=JoF0Z7nVSrA / https://en.wikipedia.org/wiki/Knuth–Morris–Pratt_algorithm)

The basic idea lies in analysing what's wrong with the naive approach. When trying to find existence of a substring in a string (colloquially the 'needle' in the 'haystack'), we begin by looking for an instance of the first character of the needle in the haystack. On finding that, we look for the a consecutive second character, and so on. On the instance that some nth character does not match, we increment the index in the haystack by 1, then reset the needle index to 0, and restart the same search. This is... okay? But say for example the haystack "aaaaaaaaaab" and the needle "aaab". Every search, it takes 4 iterations at each character of the haystack before the algorithm realises something is wrong. KMP looks to resolve this.

KMP is broadly composed of two steps, the precompute (LPS) and the search. The LPS step, or 'Longest Prefix Suffix' precomputes an array of numbers indicating the longest proper prefix that can also act as a suffix. (NOTE: a 'proper prefix' is any prefix of a string that is not the string itself). Each index of the LPS array corresponds to the prefix of the needle that is of that index length + 1 (i.e. 0th index of LPS array indicates the prefix of needle composed of only 1 (the first) character). Then, the number stored in the LPS refers to the longest prefix of this substring (the needle prefix) that can also act as a suffix.

For example: Needle = "AAAXAAAA":
- 'A' : Has no proper prefixes, so LPS is 0 (This is always true)
- 'AA' : 'A' is a proper prefix that is also a suffix, thus LPS is 1
- 'AAA' : 'AA', thus LPS is 2
- 'AAAX' - There is no prefix that is also a suffix, thus LPS is 0
- On continuing this pattern, the final LPS array computed is [0,1,2,0,1,2,3,3]

Now that the LPS for the needle is calculated, it can be used to efficiently find needle in haystack. Again, the problem we are looking to combat by this is to avoid having to reset to first index of needle when finding a non matching character in the haystack. Thus, taking a suitable example: 
- Say haystack is "AAAXAAAA" and needle is "AAAA"
- LPS is computed to be [0,1,2,3]
- we proceed as normal, 0th index matches, then 1st, and so on.
- At the 3rd index, haystack is 'X' and needle is 'A'. Now, here if we check the the LPS length for the last matching index, that is 2, we will see the number provided is the number of indices of the needle that do *not* need to be rechecked, as they must already match.
- Thus, by doing this, we've saved ourselves from recomputing all equality checks. This process of either using the index specified by the LPS or otherwise shifting the start point of the haystack's search is continued until the full substring is found.

This is a confusing method that I still don't have great intuition for, but hopefully similar problems in coming days clarify issues for me. To practice it, I did problem 28. Find First Occurrence of Substring in String. The solution is given below, a fully manual implementation of the KMP algorithm.

```cpp
class Solution {
public:
    int strStr(string haystack, string needle) {
        int ln = needle.size();
        if (ln == 0) return 0;
        vector<int> lps;
        lps.reserve(ln);
        lps.push_back(0);
        int p = 0;
        int i = 1;
        while (i < ln) {
            if (needle[i] == needle[p]) {
                lps.push_back(++p);
                i++;
            } else {
                if (p == 0) {
                    lps.push_back(p);
                    i++;
                } else {
                    p = lps[p - 1];
                }
            }
        }
        int h = 0;
        int n = 0;
        int lh = haystack.size();
        while (h < lh) {
            if (haystack[h] == needle[n]) {
                h++;
                n++;
            } else {
                if (n == 0) h++;
                else n = lps[n - 1];
            }
            if (n == ln) return h - ln;
        }
        return -1;
    }
};
```
The first while loop here is LPS computing, and the second is pattern matching to see if the substring exists in the string. From here, the solution to our problem is fairly obvious, we simply follow this same schema for every possible needle and haystack in our String array.

### Explanation for code implementation:

Why use a goto? The problem only asks for unique entries. If I allow the needle to continue searching haystacks, it might encounter another string it is a substring of, and will be doubly entered. A break does not fix this due to the degree of nesting in my code (Might be worth fixing, tbf), So instead the solution was to use a goto to directly force the next iteration of needle.

### Stuff I learned:

1. The Knutt-Morris-Pratt Algorithm

## Sources:

1. https://en.wikipedia.org/wiki/String-searching_algorithm
2. https://en.wikipedia.org/wiki/Knuth–Morris–Pratt_algorithm
3. https://www.youtube.com/watch?v=JoF0Z7nVSrA
4. https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
5. https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/
6. https://www.geeksforgeeks.org/longest-prefix-also-suffix/