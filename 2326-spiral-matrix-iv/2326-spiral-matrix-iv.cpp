/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int left = 0, right = n - 1, top = 0, bottom = m - 1;

        vector<vector<int>> ans(m, vector<int>(n, -1));

        while (head != NULL) {
            for (int i = left; i <= right && head != NULL; ++i) {
                ans[top][i] = head->val;
                head = head->next;
            }
            ++top;

            for (int i = top; i <= bottom && head != NULL; ++i) {
                ans[i][right] = head->val;
                head = head->next;
            }
            --right;

            for (int i = right; i >= left && head != NULL; --i) {
                ans[bottom][i] = head->val;
                head = head->next;
            }
            --bottom;

            for (int i = bottom; i >= top && head != NULL; --i) {
                ans[i][left] = head->val;
                head = head->next;
            }
            ++left;
        }
        return ans;
    }
};