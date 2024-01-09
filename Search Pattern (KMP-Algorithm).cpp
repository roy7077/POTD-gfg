/*---------TWO APPROACHES-----------*/

//BRUTE FORCE
// Time complexity - O(N*M)
// Space complexity- O(1)
class Solution
{
    public:
    vector<int> search(string pat, string txt)
    {
        vector<int> ans;
        int n=txt.size();
        int m=pat.size();
        for(int i=0;i<(n-m+1);i++)
        {
            bool flag=1;
            int k=0;
            for(int j=i;j<(i+m);j++)
            {
                if(txt[j]==pat[k])
                k++;
                else
                {
                    flag=0;
                    break;
                }
            }
            if(flag)
            ans.push_back(i+1);
        }
        return ans;
    }
     
};


//KMP - ALGORITHM
// Time complexity - O(M+N)
// Space complexity- O(N)
class Solution
{
    public:
    vector <int> search(string pat, string txt)
    {
        //lps array
        vector<int> arr(pat.size(),0);
        int i=0;
        int j=1;
        while(j<pat.size())
        {
            while(i>0 and pat[i]!=pat[j])
            {
                i--;
            }
            
            if(pat[i]==pat[j])
            {
                arr[j]=i+1;
                i++;
            }
            else
            arr[j]=0;
            
            j++;
        }
        
        //matching pattern
        j=0;
        i=0;
        vector<int> ans;
        while(i<txt.size())
        {
            if(txt[i]==pat[j])
            {
                i++;
                j++;
            }
            
            if(j==pat.size())
            {
                ans.push_back(i-j+1);
                j=arr[j-1];
            }
            else if(i<txt.size() && txt[i] != pat[j])
            {
                if(j==0)
                i++;
                else
                j = arr[j-1];
            }
            
        }
        return ans;
    }
     
};