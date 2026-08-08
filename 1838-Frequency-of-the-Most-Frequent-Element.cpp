class Solution {
public:
    
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int maxfreq = 0;
        int left=0,right=0;
        long long currsum=0;
        while(right<n){
            currsum+=nums[right];

            while(1LL*(right-left+1)*nums[right] - currsum>k){
                currsum-=nums[left];
                left++;
            }
            maxfreq=max(maxfreq,right-left+1);
            right++;
        }
        return maxfreq;
    }
};
/*
//binary search
class Solution {
public:
    int bsearch(int target_idx, vector<int>& nums,vector<long long> &prefix, int k) {
        int l = 0, r = target_idx;
        int possible_idx = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int count = target_idx - mid + 1;
            long long windowsum = 1LL*nums[target_idx] * count;
            long long originalsum = prefix[target_idx+1]-prefix[mid];
            long long operations = windowsum - originalsum;
            if (operations > k)
                l = mid + 1;
            else {
                possible_idx = mid;
                r = mid - 1;
            }
        }
        return target_idx - possible_idx + 1;
    }
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int result = 0;
        vector<long long> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        for (int i = 0; i < n; i++) {
            int freq = bsearch(i, nums,prefix, k);
            result = max(result, freq);
        }
        return result;
    }
};
*/