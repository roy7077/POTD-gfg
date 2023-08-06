class Solution{
    public:
    //Complete this function
    
    void permute(string s, vector<string>&v, int i=0)
    {
        if(i == s.length()-1)
            v.push_back(s);
            
        for(int j = i; j<s.length(); j++)
        {
            swap(s[i], s[j]);
            permute(s, v, i+1);
            swap(s[j],s[i]);
        }
        
    }
    
    vector<string> permutation(string S)
    {
        //Your code here
        vector<string>v;
        permute(S, v);
        sort(v.begin(), v.end());
        return v;
    }
};