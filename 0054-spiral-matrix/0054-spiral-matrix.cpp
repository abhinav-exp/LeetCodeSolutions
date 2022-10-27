class Solution {
    vector<vector<int>> M;
    int m, n;
    vector<int> ans;
    void solve(int u, int d, int l, int r)
    {
        if(u > d || l > r)
            return;
        if(u == d)
        {
            for(int i=l; i<=r; i++)
            {
                ans.push_back(M[u][i]);
            }
            return;
        }
        if(l == r)
        {
            for(int i=u; i<=d; i++)
            {
                ans.push_back(M[i][l]);
            }
            return;
        }
        // cout<<u<<d<<l<<r<<endl;
        for(int i=l; i<=r; i++)
        {
            ans.push_back(M[u][i]);
        }
        for(int i=u+1; i<=d; i++)
        {
            ans.push_back(M[i][r]);
        }
        for(int i=r-1; i>=l; i--)
        {
            ans.push_back(M[d][i]);
        }
        for(int i=d-1; i>=u+1; i--)
        {
            ans.push_back(M[i][l]);
        }
        solve(u+1, d-1, l+1, r-1);
    }
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        M = matrix;
        m = M.size();
        n = M[0].size();
        solve(0, m-1, 0, n-1);
        return ans;
    }
};