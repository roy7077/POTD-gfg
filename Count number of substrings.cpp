#define ll long long
class Solution
{
    public:
    
    ll help(string& s,int k)
    {
        int i=0;
        int j=0;
        
        int mp[26]={0};
        ll dist=0;
        ll cnt=0;
        
        while(j<s.length())
        {
           if(mp[s[j]-'a']==0)
           dist++;
           
           mp[s[j]-'a']++;
           while(dist>k)
           {
               mp[s[i]-'a']--;
               if(mp[s[i]-'a']==0)
               dist--;
               
               i++;
           }
           cnt=cnt+j-i;
           j++;
        }
        
        return cnt;
    }
    
    long long int substrCount (string s, int k) {
    	
    	return help(s,k)-help(s,k-1);
    }
};