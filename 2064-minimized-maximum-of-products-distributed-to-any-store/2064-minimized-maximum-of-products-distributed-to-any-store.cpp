class Solution {
    int maxStores;

    bool isDistributionPossible(vector<int>& quantities, int assumptedQuantity) {
        int storesNeeded = 0;

        for(int x : quantities) {
            storesNeeded += x / assumptedQuantity;
            if(x % assumptedQuantity) storesNeeded++;
            if(storesNeeded > maxStores) return false;
        }

        return (storesNeeded <= maxStores); 
    }

public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        maxStores = n;
        int low = 1, high = *max_element(std::begin(quantities), std::end(quantities));
        int answer = -1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(isDistributionPossible(quantities, mid)) {
                answer = mid;
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }

        return answer;
    }
};