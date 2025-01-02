# 1422. Maximum score after splitting a string

Given a string s of zeros and ones, return the maximum score after splitting the string into two non-empty substrings (i.e. left substring and right substring).

The score after splitting a string is the number of zeros in the left substring plus the number of ones in the right substring.

Input: s = "011101"

Output: 5 

Explanation: 

All possible ways of splitting s into two non-empty substrings are:

1. left = "0" and right = "11101", score = 1 + 4 = 5 
2. left = "01" and right = "1101", score = 1 + 3 = 4 
3. left = "011" and right = "101", score = 1 + 2 = 3 
4. left = "0111" and right = "01", score = 1 + 1 = 2 
5. left = "01110" and right = "1", score = 2 + 1 = 3

## SOLUTION:

### The basic idea:

Precompute a prefix sum (see: https://en.wikipedia.org/wiki/Prefix_sum) from right to left of the string, storing prefix sum of Nth position of string at Nth position of prefix sum array (this is accomplished with push front).

Then, traverse array from left to right counting the number of zeroes. For every iteration of this loop, calculate the score using current zero count, and corresponding prefix sum array index. Store max score.

The intuition for why this works is fairly simple. The prefix sum for any given index maintains a count of 1s to the right of that index, and the count of zeroes traversing left to right maintains the number of zeroes left of that index. Thus, when they're added, the score according to the question is obtained.

Got the idea after looking at the leetcode hint.

### Explanation for code implementation:

Why use a deque? See: https://stackoverflow.com/questions/15524475/deque-how-come-reserve-doesnt-exist

Essentially boils down to two things as far as this problem is concerned: std::vector does not have a push_front function, and deques are relatively inexpensive to add more memory to.

What is this?
```cpp
if (str_length == 2) {
    return (str[0] == '0') + prefix_sum[1];
}
```

Further down in the code, this line can be seen:
```cpp
if (i == 0 || i == str_length - 1) continue;
```
This handles the cases where the score is calculated for the furthest left and furthest right elements. These scores are invalid because both the right and left substrings must be non-empty. However, in the case that the string is 2 characters long, due to this if check, the score will always come out to zero. To handle this edge case, an if condition is placed above to return the correct result for the 2-length string.

### Stuff I learned:

1. the Deque container
2. how to use the auto keyword
3. reverse iterators
4. prefix sum arrays

## The better solution:

```cpp
class Solution {
public:
    int maxScore(string s) {
        int ones = count(s.begin(), s.end(), '1');
        
        int ans = 0;
        int zeros = 0;
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == '1') {
                ones--;
            } else {
                zeros++;
            }
            
            ans = max(ans, zeros + ones);
        }
        
        return ans;
    }
};
```

See how instead of spending time calculating the entire prefix sum in the weird right to left traversal method I used, it just calculates the total cumulative sum, and subtracts ones as it needs to? Very clever.

Also pay heed to the max function used, much more readable than my if condition. Further, the count function seems more useful than the for loop I used.

## Sources:

1. https://en.wikipedia.org/wiki/Prefix_sum
2. https://www.geeksforgeeks.org/5-different-methods-to-find-length-of-a-string-in-cpp/
3. https://www.geeksforgeeks.org/list-push_front-function-in-c-stl/
4. https://stackoverflow.com/questions/15524475/deque-how-come-reserve-doesnt-exist