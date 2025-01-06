class Solution {
public:
    vector<int> minOperations(string boxes) {
        int l = boxes.size();
        vector<int> sums;
        sums.reserve(l); 
        int balls = 0;
        int cum = 0;
        for (const auto &box : boxes) {
            cum += box == '1' ? balls++ : balls;
            sums.push_back(cum);
        }
        balls = 0;
        cum = 0;
        for (int i = l - 1; i >= 0; i--) {
            cum += boxes[i] == '1' ? balls++ : balls;
            sums[i] += cum;
        }
        return sums;
    }
};