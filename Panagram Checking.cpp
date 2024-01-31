/*
 unordered map
 Time complexity - O(N)
 Space complexity- O(N)
 */
 
class Solution
{
    public:
    bool checkPangram (string s) {
        unordered_map<char,int> mp;
        for(auto it:s)
        {
            //if current character is not English Alphabet then ignore
            int temp=int(it);
            if((temp<65 or temp>90) and (temp<97 or temp>122))
            continue;
            
            if(it>='A' and it<='Z')
            it=it+32;
            
            mp[it]++;
        }
        
        return mp.size()==26 ? 1:0;
    }
};