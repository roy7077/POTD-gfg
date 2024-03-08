// Time complexity - O(N)
// Space complexity- O(2)
typedef pair<int,int> pr;
class Solution{
    public:	
	bool sameFreq(string s)
	{
	   unordered_map<char,int> mp;
	   for(auto it:s)
	   mp[it]++;
	   
	   unordered_map<int,int> mp2;
	   for(auto it:mp)
	   {
	       mp2[it.second]++;
	       if(mp2.size()>2)
	       return 0;
	   }
	   
	   if(mp2.size()<=1)
	   return 1;
	   
	   pr a={0,0};
	   pr b={0,0};
	   for(auto it:mp2)
	   {
	       if(a.first==0)
	       {
	           a.first=it.first;
	           a.second=it.second;
	       }
	       else
	       {
	           b.first=it.first;
	           b.second=it.second;
	       }
	   }
	   
	   if(a.second!=1 and b.second!=1)
	   return 0;
	   else if(a.first==1 or b.first==1)
	   return 1;
	   else
	   {
	       if(a.second>1)
	       {
	           if(b.first-a.first<0)
	           return 0;
	           else if(b.first-a.first<=1)
	           return 1;
	           else
	           return 0;
	       }
	       else
	       {
	           if(a.first-b.first<0)
	           return 0;
	           else if(a.first-b.first<=1)
	           return 1;
	           else
	           return 0;
	       }
	   }
	  
	   return 1;
	}
};