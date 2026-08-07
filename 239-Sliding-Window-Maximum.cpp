class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        int n=nums.size();
        vector<int>result;
        int left=0,right=0;
        while(right<n){
            if(dq.empty())dq.push_back(right);
            else{
                while(!dq.empty() && nums[right]>=nums[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(right);
                
            }
            if(right-left+1==k){
                result.push_back(nums[dq.front()]);
                if(left==dq.front())dq.pop_front();
                left++;
            }
            right++;

        }
        return result;
    }
};