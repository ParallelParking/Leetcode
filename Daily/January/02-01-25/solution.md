# 2559. Count vowel strings in ranges

You are given a 0-indexed array of strings words and a 2D array of integers queries.

Each query queries[i] = [li, ri] asks us to find the number of strings present in the range li to ri (both inclusive) of words that start and end with a vowel.

Return an array ans of size queries.length, where ans[i] is the answer to the ith query.

Note that the vowel letters are 'a', 'e', 'i', 'o', and 'u'.

Input: words = ["aba","bcb","ece","aa","e"], queries = [[0,2],[1,4],[1,1]]

Output: [2,3,0]

Explanation: The strings starting and ending with a vowel are "aba", "ece", "aa" and "e". The answer to the query [0,2] is 2 (strings "aba" and "ece"). to query [1,4] is 3 (strings "ece", "aa", "e"). to query [1,1] is 0. We return [2,3,0].

## SOLUTION:

### The basic idea:

Remember the problem from 01-01-25, where the prefix sum was computed for a string of form "1011001011" etc. Similarly, strings in this problem that satisfy the condition of starting and ending with a vowel are '1' and those that don't are '0'.

THE ONE KEY DIFFERENCE: Prior to calculating prefix sum, I am pushing a 0 into the vector. This is because the query is inclusive both on the left and the right.

Finally, once the full prefix sum is calculated, I simply subtract the sum at query left from the sum at query right.

### Explanation for code implementation:

Why use an unordered set? Because it has an O(1) lookup time due to the hashing storage, as opposed to a vector's O(n) linear search, and vowels are unordered & unique, hence an unordered set is a suitable data structure to store them in.

Explaining the lambda function (See: https://www.geeksforgeeks.org/lambda-expression-in-c/) the [&vowels] captures the vowels set from the outside scope.

Further explaining the initial 0 push in the prefix sum: This same effect could also have been obtained by simply subtracting 1 from the query left index, but then I would have to write additional handling code for the case where query left is 0 (to avoid invalid index). This just seemed easier, as the only handling necessary is to subtract the query left index by 1 to account for the offset.

Different kinds of for each loops: (See: https://stackoverflow.com/questions/29859796/c-auto-vs-auto) essentially, the types are:

1. auto var -- local copy created
2. auto & var -- reference of var created
3. auto const & var -- read only reference of var created
4. auto && var -- don't really understand this, asked on GC.
5. auto const var -- exists but not really useful. Don't generally need read only access to something you already own.

### Stuff I learned:

1. unordered_set container
2. lambda functions
3. different kinds of for each loops
4. the special C++ pass by reference call
5. string.front() and string.back()

## Sources

1. https://stackoverflow.com/questions/52088430/type-vs-type-in-c-function-definitions
2. https://stackoverflow.com/questions/32391036/how-to-get-last-character-of-string-in-c
3. https://www.geeksforgeeks.org/unordered_set-find-function-in-c-stl/
4. https://stackoverflow.com/questions/29859796/c-auto-vs-auto
5. https://www.geeksforgeeks.org/stdstringfront-in-cwith-examples/
6. https://www.geeksforgeeks.org/lambda-expression-in-c/