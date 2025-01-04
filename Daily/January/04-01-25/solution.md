# 1930. Unique Length-3 Palindromic Substrings

Given a string s, return the number of unique palindromes of length three that are a subsequence of s.

Note that even if there are multiple ways to obtain the same subsequence, it is still only counted once.

A palindrome is a string that reads the same forwards and backwards.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

    For example, "ace" is a subsequence of "abcde".

Input: s = "aabca"

Output: 3

Explanation: The 3 palindromic subsequences of length 3 are:

- "aba" (subsequence of "aabca")
- "aaa" (subsequence of "aabca")
- "aca" (subsequence of "aabca")

## Solution

### The basic idea:

A length-3 palindrome must consist of identical terminal characters with one single middle character. Thus, all possible palindromes for a given terminal character can be found by counting the letters in between the first and last occurrence of the terminal character. For example, in "aabca" the first and last occurrence of a is 0 and 4. We can ignore the 3rd occurrence of a at index 1, as any palindrome formed by an a in between the first and last indices will also form a palindrome with them. Due to this enveloping nature of the first and last indices, we can simplify our calculations.

### Explanation for code implementation:

Unordered sets are used to keep track of unique elements to ensure we neither double count a character we've already come across for our terminal ends or double count a character for the middle in the loop.

### Stuff I learned

1. unordered sets are faster than unordered maps for keeping track of unique objects
2. the string find_last_of function
3. the unordered set reserve function

## Sources
1. https://www.geeksforgeeks.org/unordered_set-reserve-function-in-c-stl/
2. https://www.codecademy.com/resources/docs/cpp/strings/find
3. https://www.geeksforgeeks.org/stdstringfind_last_of-in-c-with-examples/
4. https://www.geeksforgeeks.org/unordered_set-insert-function-in-c-stl/

NOTE: I did take help from the leetcode editorial for the basic idea for today's solution. I should avoid doing that but what to do.