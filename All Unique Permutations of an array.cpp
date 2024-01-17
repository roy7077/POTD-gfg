/*-------ALL POSSIBLE APPROACHES---------*/


//MAP  &&  SET
class Solution {
    public:
    void help(map<int,int>& mp,set<vector<int>>& st,vector<int>& v,int& n)
    {
        //base case
        if(v.size()==n)
        {
            st.insert(v);
            return ;
        }
        
        //recursive calls
        //small calculation
        for(auto it:mp)
        {
            int k=it.second;
            while(k--)
            {
                mp[it.first]--;
                v.push_back(it.first);
                help(mp,st,v,n);
                
                mp[it.first]++;
                v.pop_back();
            }
        }
    }
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        map<int,int> mp;
        for(auto it:arr)
        mp[it]++;
        
        set<vector<int>> st;
        vector<int> v;
        help(mp,st,v,n);
        
        vector<vector<int>> ans;
        for(auto it:st)
        ans.push_back(it);
        
        return ans;
    }
};

//SWAPPING  &&  SET
class Solution {
    public:
    void help(set<vector<int>>& st,vector<int>& arr,int& n,int curr)
    {
        //base case
        if(curr==n)
        {
            st.insert(arr);
            return ;
        }
        
        //recursive calls
        //small calculation
        for(int i=curr;i<n;i++)
        {
            swap(arr[curr],arr[i]);     
            help(st,arr,n,curr+1);  
            swap(arr[curr],arr[i]); 
        }
    }
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        
        set<vector<int>> st;
        vector<int> v;
        help(st,arr,n,0);
        
        
        vector<vector<int>> ans;
        
        for(auto it:st)
        ans.push_back(it);
        
        return ans;
    }
};

//STL
class Solution {
    public:
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        
        vector<vector<int>> ans;
        sort(arr.begin(),arr.end());
        
        do{
            ans.push_back(arr);
        }
        while(
            next_permutation(arr.begin(),arr.end())
        );
        
        return ans;
    }
};