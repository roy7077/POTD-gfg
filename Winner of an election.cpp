
/*-------------UNORDERED MAP-----------------*/
//Time complexity - O(N)
//Space complexity- O(1)
class Solution{
    public:
    vector<string> winner(string arr[],int n)
    {
        unordered_map<string,int> mp;
        int maxi=-1;
        string ans="";
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
            if(mp[arr[i]]>maxi)
            {
                maxi=mp[arr[i]];
                ans=arr[i];
            }
        }
    
        for(auto it:mp)
        {
            if(it.second==maxi and it.first<ans)
            ans=it.first;
        }
    
        string s1=to_string(maxi);
        
        return {ans,s1};
    }
};

/*---------UNORDERED MAP  &  SORTING  (BAKWAS APPROACH)----------*/
//Time complexity - O(NlogN)
//Space complexity- O(N+N+N)
class Solution{
    public:
    static bool cmp(pair<string,int>& a,pair<string,int>& b)
    {
        if(a.second>b.second)
        return 1;
        else if(a.second==b.second)
        return a.first<b.first;
        
        return 0;
    }
    vector<string> winner(string arr[],int n)
    {
        unordered_map<string,int> mp;
        for(int i=0;i<n;i++)
        mp[arr[i]]++;
        
        vector<pair<string,int>> p;
        for(auto it:mp)
        p.push_back({it.first,it.second});
        
        sort(p.begin(),p.end(),cmp);
        
        string s1=p[0].first;
        string s2=to_string(p[0].second);
        
        return {s1,s2};
    }
};