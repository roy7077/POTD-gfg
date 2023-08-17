class Solution{
    public:
    string make_pali(string str)
    {
        int n=str.length();
        int i=0;
        int j=n-1;
        while(i<j)
        {
            str[j]=str[i];
            i++;
            j--;
        }
        
        return str;
    }
    
    string help(string& str)
    {
        string temp=make_pali(str);
        if(temp>str)
        return temp;
        
        int c=1;
        int n=str.length();
        int i=(n-1)/2;
        while(i>=0)
        {
            int num=(str[i]-'0')+c;
            str[i]=char((num%10)+48);
            c=num/10;
            i--;
        }
        
        string ans="";
        if(c)
        ans+='1';
        
        ans+=str;
        ans=make_pali(ans);
        return ans;
    }
    
    
	vector<int> generateNextPalindrome(int num[], int n) {
	    
	   string str="";
	   for(int i=0;i<n;i++)
	   str+=char(num[i]+48);
	   
	   string ans=help(str);
	   
	   vector<int> v;
	   for(auto it:ans)
	   v.push_back(it-'0');
	   
	   return v;
	}

};