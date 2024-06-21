// Time complexity - O(N)
// Space complexity- O(1)
class Solution {
    public:
    string compareFrac(string str) {
        vector<int> v;
        int num=0;
        for(auto& it:str)
        {
            if(it=='/' or it==',')
            {
                v.push_back(num);
                num=0;
            }
            else if(it==' ')
            num=0;
            else
            {
                num*=10;
                num+=(it-'0');
            }
        }
        
        v.push_back(num);
        
        double a=(double(v[0]))/v[1];
        double b=(double(v[2]))/v[3];
        
        if(a>b)
        {
            string temp1=to_string(v[0]);
            string temp2=to_string(v[1]);
            string ans="";
            ans+=temp1;
            ans+="/";
            ans+=temp2;
            return ans;
        }
        else if(b>a)
        {
            string temp1=to_string(v[2]);
            string temp2=to_string(v[3]);
            string ans="";
            ans+=temp1;
            ans+="/";
            ans+=temp2;
            return ans;
        }
        
        return "equal";
    }
};
