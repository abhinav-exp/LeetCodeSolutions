class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> M;
        for(auto s:strs)
        {
            string t = s;
            sort(t.begin(), t.end());
            M[t].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto m:M)
        {
            ans.push_back(m.second);
        }
        return ans;
    }
};