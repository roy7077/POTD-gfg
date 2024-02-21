// Memoization
#define ll long long
class Solution{
    public:
    ll help(string& s,int i,int j,bool istrue,vector<vector<vector<int>>>& memo)
    {
        //base case
        if(i>j)
        return 0;
        
        //memo check
        if(memo[i][j][int(istrue)]!=-1)
        return memo[i][j][int(istrue)];
        
        if(i==j)
        {
            if(istrue)
            return s[i]=='T';
            else
            return s[i]=='F';
        }
        
        //recursive calls
        //and small calculation
        ll ways=0;
        for(int ind=i+1;ind<=j-1;ind+=2)
        {
            ll lt=help(s,i,ind-1,1,memo);
            ll lf=help(s,i,ind-1,0,memo);
            ll rt=help(s,ind+1,j,1,memo);
            ll rf=help(s,ind+1,j,0,memo);
            
            if(s[ind]=='&')
            {
                if(istrue)
                ways+=(rt*lt);
                else
                ways+=(lf*rf)+(lf*rt)+(lt*rf);
            }
            else if(s[ind]=='|')
            {
                if(istrue)
                ways+=(lt*rt)+(lt*rf)+(lf*rt);
                else
                ways+=lf*rf;
            }
            else
            {
                if(istrue)
                ways+=(lt*rf)+(lf*rt);
                else
                ways+=(lt*rt)+(lf*rf);
            }
        }
        return memo[i][j][int(istrue)]=ways%1003;
    }
    int countWays(int n, string s)
    {
        vector<vector<vector<int>>> memo(n,vector<vector<int>>(n,vector<int>(2,-1)));
        return help(s,0,n-1,1,memo);
    }
};
