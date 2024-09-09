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
        vector<vector<int>> vec(m, vector<int>(n, -1));
        int i = 0;
        int j = 0;
        int leftM = 0;
        int leftN = 1;

        while (1) {
            bool check = false;
            while (j < n) {
                if (!head) {
                    check = true;
                    break;
                }
                vec[i][j] = head->val;
                head = head->next;
                j++;
            }

            if (check || !head)
                break;
            j--;
            i = i + 1;
            while (i < m) {
                if (!head) {
                    check = true;
                    break;
                }

                vec[i][j] = head->val;
                head = head->next;
                i++;
            }
            if (check || !head)
                break;

            i--;
            j = j - 1;
            while (j >= leftM) {
                if (!head) {
                    check = true;
                    break;
                }

                vec[i][j] = head->val;
                head = head->next;
                j--;
            }
            if (check || !head)
                break;

            j++;
            i = i - 1;
            while (i >= leftN) {
                if (!head) {
                    check = true;
                    break;
                }

                vec[i][j] = head->val;
                head = head->next;
                i--;
            }
            if (check || !head)
                break;

            i++;
            j++;
            m--;
            n--;
            leftN++;
            leftM++;
        }
        return vec;
    }
};
