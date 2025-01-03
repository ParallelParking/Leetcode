# 2270. Number of ways to split an array

You are given a 0-indexed integer array nums of length n.

nums contains a valid split at index i if the following are true:

1. The sum of the first i + 1 elements is greater than or equal to the sum of the last n - i - 1 elements.
2. There is at least one element to the right of i. That is, 0 <= i < n - 1.

Return the number of valid splits in nums.

Input: nums = [10,4,-8,7]

Output: 2

Explanation: 

There are three ways of splitting nums into two non-empty parts:

- Split nums at index 0. Then, the first part is [10], and its sum is 10. The second part is [4,-8,7], and its sum is 3. Since 10 >= 3, i = 0 is a valid split.
- Split nums at index 1. Then, the first part is [10,4], and its sum is 14. The second part is [-8,7], and its sum is -1. Since 14 >= -1, i = 1 is a valid split.
- Split nums at index 2. Then, the first part is [10,4,-8], and its sum is 6. The second part is [7], and its sum is 7. Since 6 < 7, i = 2 is not a valid split.

Thus, the number of valid splits in nums is 2.

## My initial attempt

This attempt worked, but has not been included in the code file as it performed poorly. However, I think there is some learning value here.

```cpp
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        vector<long int> sums;
        //inclusive_scan(nums.begin(), nums.end(), sums.begin());
        long int cumulative_sum = 0;
        for (auto const & num : nums) {
            cumulative_sum += (long int) num;
            sums.push_back(cumulative_sum);
        }
        int ways = 0;
        long int final_sum = sums.back();
        sums.pop_back();
        for (auto const & sum : sums) 
            if (sum >= final_sum - sum) ways++;
        return ways;
    }
};
```

I calculated prefix sum for the given nums array, then proceeded to iterate through the sums array, with each prefix sum representing the left split, and the difference between left split and total sum giving the right split. 

> To generalize, when a problem requires answering multiple queries, and each query involves some form of range aggregation where each aggregate builds on the previous one, the prefix sum is often a good fit, such as the sum of a subarray, the product of a range, counting from a range or finding averages.

This calculation and then traversal of the prefix sum is repetitive work that can be avoided.

### Explanations for this implementation

What is inclusive_scan? It was commented out when I realised the integer overflow would force me to use long int, but it is an STL function to calculate the prefix sum array. What I had been doing with for loops the last several days could have been optimized out.

## Solution

### The basic idea:

Instead of precalulating an entire array of sums, we can simply maintain a left sum and a right sum, and update both as we iterate through the array a single time.

### Explanation for code implementation:

Why long int? There were overflows with some of the test cases that I couldn't figure out how to deal with (is there a way that doesn't simply involve using a bigger int?)

why use pop_back? I don't want to perform a check with the last element of nums, because this would cause the right split to be empty and thus 0. This violates the constraint that there must be at least one integer to the right of i.

What is reduce? Again, it'd been commented out due to type constraints forcing my hand into using long int and thus writing the function manually, but it is an STL function that can calculate the sum of elements of array.

### Stuff I learned

1. The inclusive_scan function
2. The pop_back function
3. Intuition on when to use prefix sums
4. The reduce function
5. C++ iterators
6. long int, long long int data types

## Sources

1. https://en.cppreference.com/w/cpp/algorithm/inclusive_scan
2. https://stackoverflow.com/questions/3221812/how-to-sum-up-elements-of-a-stdvector
3. https://stackoverflow.com/questions/14373934/iterator-loop-vs-index-loop
4. https://cplusplus.com/reference/vector/vector/pop_back/
5. https://stackoverflow.com/questions/18971732/what-is-the-difference-between-long-long-long-long-int-and-long-long-i