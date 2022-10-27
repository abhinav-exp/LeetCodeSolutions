class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int ans = 0;
        int n = img1.size();
        for(int i= -1*(n-1); i<n; i++)
        {
            for(int j = -1*(n-1); j<n; j++)
            {
                int t = 0;
                int a1 = max(-1*i, 0);
                int b1 = max(-1*j, 0);
                // cout<<a1<<b1<<" "<<min(n, n-i)<<min(n, n-j)<<endl;
                for(int p=a1; p<n && p+i<n; p++)
                {
                    for(int q=b1; q<n && q+j<n; q++)
                    {
                        if(img1[p][q] == img2[p+i][q+j] && img1[p][q] == 1)
                        {
                            t++;
                        }
                    }
                }
                ans = max(ans, t);
            }
        }
        return ans;
    }
};