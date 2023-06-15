class Solution {
private:
    vector<int> generateRow(int row){
        vector<int> ans;
        long long num = 1;
        ans.push_back(1);
        for(int col=1; col<row; col++){
            num *= (row - col);
            num /= col;
            ans.push_back(num);
        }
        return ans;
    }
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > ans;
        for(int row=1; row<=numRows; row++){
            ans.push_back(generateRow(row));
        }
        return ans;
    }
};