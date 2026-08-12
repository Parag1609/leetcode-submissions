class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        deque<int> maxi_monotonic;
        deque<int> mini_monotonic;
        int i = 0, j = 0, maxlen = 0;

        while (j < n) {
            while (!maxi_monotonic.empty() &&
                   nums[j] > nums[maxi_monotonic.back()]) {
                maxi_monotonic.pop_back();
            }
            maxi_monotonic.push_back(j);

            while (!mini_monotonic.empty() &&
                   nums[j] < nums[mini_monotonic.back()]) {
                mini_monotonic.pop_back();
            }
            mini_monotonic.push_back(j);

            while (!maxi_monotonic.empty() && !mini_monotonic.empty() &&
                   nums[maxi_monotonic.front()] - nums[mini_monotonic.front()] > limit) {
                if (i == maxi_monotonic.front()) {
                    maxi_monotonic.pop_front();
                }
                if (i == mini_monotonic.front()) {
                    mini_monotonic.pop_front();
                }
                i++;
            }
            maxlen = max(maxlen, j - i + 1);
            j++;
        }
        return maxlen;
    }
};