# 3042. Counting Prefix & Suffix Pairs I

You are given a 0-indexed string array words.

Let's define a boolean function isPrefixAndSuffix that takes two strings, str1 and str2:
- isPrefixAndSuffix(str1, str2) returns true if str1  is both a prefix and a suffix of str2, and false otherwise.

For example, isPrefixAndSuffix("aba", "ababa") is true because "aba" is a prefix of "ababa" and also a suffix, but isPrefixAndSuffix("abc", "abcd") is false.

Return an integer denoting the number of index pairs (i, j) such that i < j, and isPrefixAndSuffix(words[i], words[j]) is true.

Input: words = ["a","aba","ababa","aa"]

Output: 4

Explanation: In this example, the counted index pairs are:
- i = 0 and j = 1 because isPrefixAndSuffix("a", "aba") is true.
- i = 0 and j = 2 because isPrefixAndSuffix("a", "ababa") is true.
- i = 0 and j = 3 because isPrefixAndSuffix("a", "aa") is true.
- i = 1 and j = 2 because isPrefixAndSuffix("aba", "ababa") is true.
Therefore, the answer is 4.

## Solution

### The basic idea

I was very, very busy today, and thus only had time to implement the brute force solution. It works well, but I wish I could've learned something new today.

The idea is simple. Iterate through words. For every word, check it against every other word manually for if it forms both suffix and prefix. If it does, update count.

### Stuff I learned

1. The cpp string rfind function

## Sources

1. https://www.geeksforgeeks.org/stdstringrfind-in-c-with-examples/

NOTE: If I ever have time, I should come back and do the trie solution for this.