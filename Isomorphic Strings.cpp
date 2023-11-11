//Time complexity - O(N)
//Space complexity- O(N)
class Solution
{
    public:
    bool areIsomorphic(string str1, string str2)
    {
        
        if(str1.length()!=str2.length())
        return 0;
        
        //maping string 1 -> string 2
        unordered_map<char,char> mp;
        for(int i=0;i<str1.length();i++)
        {
            if(mp.count(str1[i]))
            {
                if(mp[str1[ihttps://auth.geeksforgeeks.org/user/roy_707]]!=str2[i])
                return 0;
            }
            else
            mp[str1[i]]=str2[i];
        }
        
        mp.clear();
        //maping string 2 -> string 1
        for(int i=0;i<str1.length();i++)
        {
            if(mp.count(str2[i]))
            {
                if(mp[str2[i]]!=str1[i])
                return 0;
            }
            else
            mp[str2[i]]=str1[i];
        }
        return 1;
    }
};
