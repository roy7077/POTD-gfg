// User function template for C++

// Time complexity - O(N*M)
// Space complexity- O(1002) - constant
class Solution {
    public:
    string longestCommonPrefix(vector<string> arr) {
        vector<char> pre(1002,'#');
        bool flag=0;
        for(auto& it:arr)
        {
            for(int i=0;i<it.length();i++)
            {
                if(!flag)
                {
                    pre[i]=it[i];
                    continue;
                }
                
                if(pre[i]!=it[i])
                {
                    pre[i]='#';
                    break;
                }
            }
            
            flag=1;
        }
        
        string ans="";
        for(int i=0;i<1002;i++)
        {
            if(pre[i]=='#')
            return ans.length() ? ans : "-1";
            
            ans+=pre[i];
        }
        
        return ans;
    }
};
