class Solution {
private:
    void combination(int index, vector<int>& candidates, int target, vector<vector<int> > &ans, vector<int> &v){
        if(index == candidates.size()){
            if(target == 0)
                ans.push_back(v);
            return;
        }
        if(candidates[index] <= target){
            v.push_back(candidates[index]);
            combination(index, candidates, target - candidates[index], ans, v);
            v.pop_back();
        }
        combination(index + 1, candidates, target, ans, v);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > ans;
        vector<int> v;
        combination(0, candidates, target, ans, v);
        return ans;
    }
};