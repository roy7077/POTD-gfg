//STACK || T - O(N) || S - O(N)
// Time complexity - O(N)
// Space complexity- O(N)
class Solution {
    public:
    string removeKdigits(string S, int k) {
        stack<char> ch;
        for(auto it:S)
        {
            while(k and !ch.empty() and ch.top()>it)
            {
                ch.pop();
                k--;
            }
            
            if(ch.empty() and it=='0')
            continue;
        
            ch.push(it);
        }
        
        //k is not zero, 
        while(!ch.empty() and k)
        {
            ch.pop();
            k--;
        }
        
        //making ans string
        string ans="";
        while(!ch.empty())
        {
            ans+=ch.top();
            ch.pop();
        }
        
        if(ans.size()==0)
        return "0";
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};