//给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请你返回所有和为 0 且不重复的三元组。

//注意：答案中不可以包含重复的三元组。

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res = {};
        sort(nums.begin(), nums.end());
        int sz = (int)nums.size();
        int left = 0;
        int middle = 0;
        for(int num : nums) {
            if(num <= 0) {
                middle++;
            }
        }
        if(nums[left] > 0 || nums[sz - 1] < 0) {
            return res;
        }
        left--;
        while(++left < middle) {
            if (left > 0 && nums[left] == nums[left - 1]) continue;
            int sum = -nums[left];
            unordered_map<int, int> us;
            for(int i = left + 1; i < sz; i++) {
                auto pos = us.find(nums[i]);
                if(pos != us.end()) {
                    if (pos->second == 1) {
                        continue;
                    }
                    us[nums[i]] = 1;
                    us[sum - nums[i]] = 1;
                    res.emplace_back(vector<int>{-sum, nums[i], sum - nums[i]});
                }
                else {
                    us[sum - nums[i]] = 0;
                }
            }
        }
        return res;
    }
};