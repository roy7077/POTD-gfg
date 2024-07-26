
// Method - 1
// sorting
// Time complexity - O(NlogN)
// Space complexity- O(1)
class Solution {
    public:
    bool kPangram(string str, int k) {
        sort(str.begin(),str.end());
        
        int j=0;
        int spaceCnt=0;
        while(j<str.length() and str[j]==' ')
        j++;
        
        spaceCnt=j;
        int distChar=1;
        
        j++;
        while(j<str.length())
        {
            if(str[j-1]!=str[j])
            distChar++;
            
            j++;
        }
        
        int need=26-distChar;
        // cout<<spaceCnt<<endl;
        // cout<<need<<endl;
        // cout<<(str.length()-spaceCnt-distChar)<<endl;
        if(need<=k and (str.length()-spaceCnt-distChar)>=need)
        return true;
        else
        return false;
    }
};




// Method - 2
// Time complexity - O(N)
// Space complexity- O(27)
class Solution {
    public:
    bool kPangram(string str, int k) {
        unordered_map<int,int> mp;
        for(auto& it:str)
        mp[it]++;
        
        int need;
        int distChar;
        if(mp.count(' '))
        {
            distChar=mp.size()-1;
            need=26-distChar;
        }
        else
        {
            distChar=mp.size();
            need=26-distChar;
        }
        
        if(need<=k and (str.length()-mp[' ']-distChar)>=need)
        return true;
        else
        return false;
    }
};
