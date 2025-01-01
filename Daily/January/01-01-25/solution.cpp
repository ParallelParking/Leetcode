class Solution {
public:
    int maxScore(string str) {
        deque<int> prefix_sum;
        int cumulative_sum = 0;
        for (auto ch = str.rbegin(); ch != str.rend(); ch++) {
            cumulative_sum += *ch - '0';
            prefix_sum.push_front(cumulative_sum);
        }

        int str_length = str.size();
        if (str_length == 2) {
            return (str[0] == '0') + prefix_sum[1];
        }

        int max_score = 0;
        int zero_count = 0;
        for (int i = 0; i < str_length; i++) {
            if (str[i] == '0') zero_count++;
            if (i == 0 || i == str_length - 1) continue;
            int score = zero_count + prefix_sum[i];
            if (score > max_score) max_score = score;
        }
        return max_score;
    }
};