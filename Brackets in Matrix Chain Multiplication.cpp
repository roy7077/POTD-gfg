//Variation Of Matrix Chain Multiplication || Memoization
// MEMOIZATION
typedef pair<string,int> pi;
class Solution{
    public:
    pi help(int* p,int i,int j,vector<vector<pi>>& memo)
    {
        //base case
        if(i==j)
        {
            string s="";
            s+='A'+i-1;
            return {s,0};
        }
        
        //memo check
        if(memo[i][j].second!=-1)
        return memo[i][j];
        
        // recursive calls
        // and small calculation
        int mini=1e9;
        string st="";
        for(int ind=i;ind<j;ind++)
        {
            auto left=help(p,i,ind,memo);
            auto right=help(p,ind+1,j,memo);
            int cal=p[i-1]*p[ind]*p[j]+left.second+right.second;
            
            if(cal<mini)
            {
                mini=cal;
                string s="("+left.first+right.first+")";
                st=s;
            }
        }
        return memo[i][j]={st,mini};
    }
    string matrixChainOrder(int p[], int n){
        vector<vector<pi>> memo(n,vector<pi>(n,{"",-1}));
        return help(p,1,n-1,memo).first;
    }
};