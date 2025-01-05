# 2381. Shifting Letters II

You are given a string s of lowercase English letters and a 2D integer array shifts where shifts[i] = [starti, endi, directioni]. For every i, shift the characters in s from the index starti to the index endi (inclusive) forward if directioni = 1, or shift the characters backward if directioni = 0.

Shifting a character forward means replacing it with the next letter in the alphabet (wrapping around so that 'z' becomes 'a'). Similarly, shifting a character backward means replacing it with the previous letter in the alphabet (wrapping around so that 'a' becomes 'z').

Return the final string after all such shifts to s are applied.

Input: s = "abc", shifts = [[0,1,0],[1,2,1],[0,2,1]]

Output: "ace"

Explanation: 
- Firstly, shift the characters from index 0 to index 1 backward. Now s = "zac".
- Secondly, shift the characters from index 1 to index 2 forward. Now s = "zbd".
- Finally, shift the characters from index 0 to index 2 forward. Now s = "ace".

## Solution

### The basic idea:

Instead of individually computing the total shift for each individual character, we can instead compute a 'difference array' (See: https://codeforces.com/blog/entry/78762). This difference array allows easy calculation of the total shift for characters upon calculating the prefix sum of this array.

### Explanation for code implementation:

What is a difference array? See: https://codeforces.com/blog/entry/78762

Essentially, When given any problem in which there are 'Q' ranges [L, R], we can construct a difference array such that for every range, we increment the Lth index of the array by 1 to indicate start of range and decrement the (R+1)th index by 1 to indicate the end of range. Upon doing this for all Q ranges, the net effect of all ranges is obtained. Further, on taking the prefix sum of the difference array, the effect of these ranges on each element of the original array can be found.

In this specific case, where there is a third element in each range determining whether to shift forward or backward, in the event that a certain range necessitates backward shifting, instead of doing L++ and (R-1)--, we reverse it, and do L-- and (R+1)++.

The specifics of difference array construction also explains why the size of the array is one greater than the length of the string (due to accessing the R+1 element in situations where R is the last character of string).

```cpp
int n = s[i] + t[i];
n = (n - 'a') % 26; 
if (n < 0) n += 26; 
s[i] = 'a' + n;
```
What's with this weird stuff in the for loop? Handles circling back in case of moving past a or z. There was some other code there earlier:

```cpp
for (int i = 0; i < l; i++) {
    int n = s[i] + t[i];
    if (n > 122) n -= 26;
    else if (n < 97) n += 26;
    s[i] = (char) n;
}
```
But this for some reason threw a runtime error:
> Line 74: Char 16: runtime error: index -128 out of bounds for type 'string[256]' (aka 'basic_string<char>[256]') (_Serializer_.cpp)
one day, find out why.

### Stuff I learned

1. pre-initializing all elements of vector with value
2. Difference array and uses

## Sources

1. https://codeforces.com/blog/entry/78762
2. https://en.wikipedia.org/wiki/ASCII#Character_set
3. https://www.geeksforgeeks.org/initialize-a-vector-in-cpp-different-ways/