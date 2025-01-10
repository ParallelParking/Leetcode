# 916. Word Subsets

You are given two string arrays words1 and words2.

A string b is a subset of string a if every letter in b occurs in a including multiplicity.

    For example, "wrr" is a subset of "warrior" but is not a subset of "world".

A string a from words1 is universal if for every string b in words2, b is a subset of a.

Return an array of all the universal strings in words1. You may return the answer in any order.

Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["e","o"]

Output: ["facebook","google","leetcode"]

## Solution

### The Basic Idea

For all words in words2, calculate the frequency hash map for individual characters. Update the frequency for any character in the main hash map to the current word hash map in the event that the frequency of that character in that word is larger than the frequency stored in the main one. The reasoning for this is simply that if any word satisfies the subset condition for the character in its maximum occurrence, it must necessarily satisfy it for all others. Thus, it is prudent to only store the most frequent occurrence.

From there, fairly straightforward, iterate through all words in words1, check if universal. 

### Explanation for Code Explanation

```cpp
for (const auto& [k, v] : f)
```

This is the for loop to iterate through key value pairs for a hash map.

### Stuff I learned:

1. For each loop for a hash map

### Sources

1. https://stackoverflow.com/questions/14070940/how-can-i-print-out-c-map-values