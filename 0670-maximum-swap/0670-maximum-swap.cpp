class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.size();
        int rightMaxIndex = n - 1;
        int maxIndex = -1, leftIndex = -1, rightIndex = -1;

        for (int i = n - 2; i >= 0; --i) {
            if (s[i] < s[rightMaxIndex]) {
                leftIndex = i;
                rightIndex = rightMaxIndex;
            } else if (s[i] > s[rightMaxIndex]) {
                rightMaxIndex = i;
            }
        }

        if (leftIndex != -1) {
            swap(s[leftIndex], s[rightIndex]);
        }

        return stoi(s);
    }
};