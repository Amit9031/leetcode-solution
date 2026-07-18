class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        if (n == 1)
            return 1;

        int candies = 1;
        int up = 0, down = 0, peak = 0;

        for (int i = 1; i < n; i++) {

            if (ratings[i] > ratings[i - 1]) {
                up++;
                peak = up;
                down = 0;
                candies += 1 + up;
            }
            else if (ratings[i] == ratings[i - 1]) {
                up = down = peak = 0;
                candies += 1;
            }
            else {
                up = 0;
                down++;
                candies += 1 + down;

                if (peak >= down)
                    candies--;
            }
        }

        return candies;
    }
};