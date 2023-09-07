
#include <algorithm>
#include <cstring>
class Solution {
  public:
    vector<string> CamelCase(int n, vector<string> d, string p) {
       //hello
       vector<string> ans;
       
       for(auto it:d)
       {
           int i=0;
           bool flag=1;
           for(auto x:it)
           {
               if(i>=p.size())
               break;
               
               if(x>='A' and x<='Z')
               {
                   if(x!=p[i])
                   {
                       flag=0;
                       break;
                   }
                   else
                   i++;
               }
           }
           
           if(flag and i>=p.size())
           ans.push_back(it);
       }
       
       if(ans.size()>=1)
       sort(ans.begin(),ans.end());
       else
       ans.push_back("-1");
       
       return ans;
    }
};
/* time complexity - O(n*S)
   space complexity - O(n*S)
   
   where n is size of a string aaray
         S is a size of a string 
*/