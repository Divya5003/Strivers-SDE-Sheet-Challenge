class Solution {
private:
    void combination(int index, vector<int> &candidates, int target, vector<vector<int> > &ans, vector<int> v){
        if(target == 0)
            ans.push_back(v);
        
        for(int i=index; i<candidates.size(); i++){
            if(i > index && candidates[i] == candidates[i - 1])
                continue;
            if(candidates[i] > target)
                break;
            v.push_back(candidates[i]);
            combination(i + 1, candidates, target - candidates[i], ans, v);
            v.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > ans;
        vector<int> v;
        combination(0, candidates, target, ans, v);
        return ans;
    }
};