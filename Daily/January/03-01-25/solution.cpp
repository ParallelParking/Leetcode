class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long int left_sum = 0;
        // int right_sum = reduce(nums.begin(), nums.end());
        long int right_sum = 0;
        for (auto const & num : nums) {
            right_sum += (long int) num;
        }
        nums.pop_back();
        int ways = 0;
        for (auto const & num : nums) {
            left_sum += num;
            right_sum -= num;
            if (left_sum >= right_sum) 
                ways++;
        }
        return ways;
    }
};