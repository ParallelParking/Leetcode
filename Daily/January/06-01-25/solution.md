# 1769. Minimum Number of Operations to Move All Balls to Each Box

You have n boxes. You are given a binary string boxes of length n, where boxes[i] is '0' if the ith box is empty, and '1' if it contains one ball.

In one operation, you can move one ball from a box to an adjacent box. Box i is adjacent to box j if abs(i - j) == 1. Note that after doing so, there may be more than one ball in some boxes.

Return an array answer of size n, where answer[i] is the minimum number of operations needed to move all the balls to the ith box.

Each answer[i] is calculated considering the initial state of the boxes.

Input: boxes = "110"

Output: [1,1,3]

Explanation: The answer for each box is as follows:
1) First box: you will have to move one ball from the second box to the first box in one operation.
2) Second box: you will have to move one ball from the first box to the second box in one operation.
3) Third box: you will have to move one ball from the first box to the third box in two operations, and move one ball from the second box to the third box in one operation.

## Solution

### The basic idea:

For every ball, moving n adjacent spaces to some box will take n operations. Thus, using this property, we can calculate how many operations it will take for any jth ball to move to any ith box. To avoid using brute force here, a modified, odd version of the prefix sum calculation is used, where instead of simply summing up the contents of the string, we instead track the number of found balls, and for every box traversed we added the total operation count to the prefix sum array.

```cpp
cum += box == '1' ? balls++ : balls;
sums.push_back(cum);
```

that's what these statements in the for loop do.

Thus, by calculating the total cost using these sums in both the right direction and the left direction (this is because the ith ball and jth box, where i > j, the ball will have to move left instead of right, and so a different sum calculation in the opposite direction is required), and adding them together, we can obtain the total operation cost for every box.

NOTE: No stuff I learned, code explanation or sources for this one because I didn't use any, only prior knowledge and code I fully understand!! VV happy :)