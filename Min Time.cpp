#define ll long long
class Solution {
  public:
 
    vector<int> v;
    unordered_map<int,int> mn,mx;
    long long dp(int idx,int d,int m,vector<vector<long long>> &memo)
    {
        //base case
        if(idx>=m) 
        return 0;
        
        //memo check
        if(memo[idx][d]!=-1) 
        return memo[idx][d];
        
        //recurive calls
        //small calculation
        
        int left=0,right=0;
        if(idx!=0)
        {
            left=mn[v[idx-1]];
            right=mx[v[idx-1]];
        }
        if(d==1) 
        swap(left,right);
        
        long long ans=1e18;
        int ret1=0,ret2=0;
        if(idx==v.size()-1)
        {
            ret1=abs(mn[v[idx]]);
            ret2=abs(mx[v[idx]]);
        }
        ans=min(ans,dp(idx+1,0,m,memo)+abs(mx[v[idx]]-left)+(mx[v[idx]]-mn[v[idx]])+ret1);
        ans=min(ans,dp(idx+1,1,m,memo)+abs(mn[v[idx]]-left)+(mx[v[idx]]-mn[v[idx]])+ret2);
        return memo[idx][d]=ans;
    }  
    long long minTime(int n, vector<int> &locations, vector<int> &types) 
    {
        for(int i=0;i<n;i++)
        {
            if(mn.count(types[i])==0){
                mn[types[i]]=mx[types[i]]=locations[i];
                v.push_back(types[i]);
            }
            else
            {
                mn[types[i]]=min(mn[types[i]],locations[i]);
                mx[types[i]]=max(mx[types[i]],locations[i]);
            }
        }
        
        int m=v.size();
        sort(v.begin(),v.end());
        vector<vector<long long>> memo(m+5,vector<long long>(2,-1));
        return dp(0,0,m,memo);
    }
};