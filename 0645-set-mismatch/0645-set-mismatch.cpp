class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_set<int> S(nums.begin(), nums.end());
        int n1 = 0;
        for(auto s:S)
        {
            n1 = n1^s;
        }
        int n2 = 0;
        for(int i=1; i<=nums.size(); i++)
        {
            n2 = n2^i;
        }
        int n3 = 0;
        for(int i=0; i<nums.size(); i++)
        {
            n3 = n3^nums[i];
        }
        // cout<<n1<<" "<<n2<<" "<<n3<<endl;
        return {n3^n1, n2^n1};
    }
};