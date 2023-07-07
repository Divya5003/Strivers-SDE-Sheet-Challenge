class Solution {
private:
    void subsets(int index, vector<int> &nums, vector<vector<int> > &ans, vector<int> &v){
        ans.push_back(v);
        for(int i=index; i<nums.size(); i++){
            if(i != index && nums[i] == nums[i - 1])
                continue;
            v.push_back(nums[i]);
            subsets(i + 1, nums, ans, v);
            v.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int> > ans;
        vector<int> v;
        sort(nums.begin(), nums.end());
        subsets(0, nums, ans, v);
        return ans;
    }
};