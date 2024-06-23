class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> ascending;
        deque<int> descending ;
        int max_len = 0;
        int left = 0;

        for (int right = 0; right < nums.size(); right++) {
            while (!ascending.empty() && nums[right] < ascending.back()) {
                ascending.pop_back();
            }
            ascending.push_back(nums[right]);

            while (!descending.empty() && nums[right] > descending.back()) {
                descending.pop_back();
            }
            descending.push_back(nums[right]);

            while (descending.front() - ascending.front() > limit) {
                if (nums[left] == descending.front()) {
                    descending.pop_front();
                }
                if (nums[left] == ascending.front()) {
                    ascending.pop_front();
                }
                ++left;
            }

            max_len = max(max_len, right - left + 1);
        }

        return max_len;
    }
};