class Solution {
private:
    vector <int> generate_array(int n, int sum) {
        vector <int> ans(n);

        if (sum % n == 0) {
            int val = sum / n;
            for (int i = 0; i < n; i++) ans[i] = val;
        }

        else {
            int val = sum / n, 
                temp_sum = val * n;
            
            for (int i = 0; i < n; i++) ans[i] = val;

            int i = 0;
            while (sum - temp_sum != 0) {
                if (sum - temp_sum > 0 && ans[i] < 6) {
                    int increment = min(abs(sum - temp_sum), 6 - ans[i]);

                    ans[i] += increment;
                    temp_sum += increment;
                }

                else if (sum - temp_sum < 0 && ans[i] > 1) {
                    int decrement = min(abs(sum - temp_sum), ans[i] - 1);

                    ans[i] -= decrement;
                    temp_sum -= decrement;
                }

                i = (i + 1) % n; 
            }
        }

        return ans;
    }
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int total_sum = mean * (n + rolls.size()),
            partial_sum = 0;
        
        for (int obs: rolls) partial_sum += obs;
        int sum = total_sum - partial_sum;

        if (n > sum || 6 * n < sum) return {}; 
        return generate_array(n, sum);
    }
};