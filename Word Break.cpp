class Solution
{
    public:
    bool help(unordered_map<string,bool>& mp,string& s,string temp,int i)
    {
        //base case
        if(temp.length()>=s.length())
        return s==temp;
        
        //recursive calls
        //and small calculation
        string str="";
        for(int j=i;j<s.length();j++)
        {
            str+=s[j];
            if(mp.count(str))
            {
                bool ans=help(mp,s,temp+str,j+1);
                if(ans)
                return 1;
            }
        }
        return 0;
    }
    int wordBreak(int n, string s, vector<string> &dictionary) {
        unordered_map<string,bool> mp;
        for(auto it:dictionary)
        mp[it]=1;
        
        return help(mp,s,"",0);
    }
};