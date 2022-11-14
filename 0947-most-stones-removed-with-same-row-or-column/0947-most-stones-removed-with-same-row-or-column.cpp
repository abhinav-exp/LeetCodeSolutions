class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int> V(n);
        for(int i=0; i<n; i++)
        {
            V[i] = i;
        }
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
                {
                    int p = i;
                    int q = j;
                    while(V[p] != p)
                    {
                        p = V[p];
                    }
                    while(V[q] != q)
                    {
                        q = V[q];
                    }
                    if(stones[p][0] > stones[q][0])
                    {
                        V[q] = p;
                    }
                    else if(stones[p][0] < stones[q][0])
                    {
                        V[p] = q;
                    }
                    else if(stones[p][1] > stones[q][1])
                    {
                        V[q] = p;
                    }
                    else
                    {
                        V[p] = q;
                    }
                }
            }
        }
        int count = 0;
        for(int i=0; i<n; i++)
        {
            if(V[i] == i)
            {
                count++;
            }
        }
        return n - count;
    }
};