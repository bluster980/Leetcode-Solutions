class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> arr(n, 0);
        if (k == 0) {
            return arr;
        }
        if (k > 0) {
            for (int i = 0; i < n; i++) {
                int sum = 0;
                for (int j = i + 1; j <= (i + k); j++) {
                    sum += code[j % n];
                }
                arr[i] = sum;
            }
            return arr;
        }

        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i - 1; j >= (i + k); j--) {
                sum += code[(n + j) % n];
            }
            arr[i] = sum;
        }
        return arr;
    }
};