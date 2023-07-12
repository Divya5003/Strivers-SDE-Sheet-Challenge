#include <bits/stdc++.h> 

void helper(int index, string &s, string &temp, vector<string> &ans, unordered_map<string, bool> &mp){
    if(index == s.length()){
        ans.push_back(temp);
        return;
    }
    for(int i=index; i<s.length(); i++){
        int sz = temp.length();
        if(mp[s.substr(index, (i - index + 1))]){
            temp.append(s.substr(index, (i - index + 1)));
            temp.push_back(' ');
            helper(i + 1, s, temp, ans, mp);
            int szn = temp.length();
            while(szn != sz){
                temp.pop_back();
                szn--;
            }
        }
    }
}

vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    unordered_map<string, bool> mp;
    for(auto i : dictionary)
        mp[i] = true;
    vector<string> ans;
    string temp;
    helper(0, s, temp, ans, mp);
    return ans;

}