//给定一个整数数组nums和一个整数目标值target，请你在该数组中找出和为目标值target的那两个整数，并返回它们的数组下标。
//你可以假设每种输入只会对应一个答案，并且你不能使用两次相同的元素。
//你可以按任意顺序返回答案。

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        for (int i = 0; const auto& num : nums) {
            auto it = hash.find(target - num);
            if(it != hash.end()) return {it->second, i};
            hash[num] = i++;
        }
        return {};
    }
};