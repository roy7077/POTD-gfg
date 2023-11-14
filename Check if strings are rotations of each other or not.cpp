/*----------TWO  APPROACHES--------------*/ 

/*-----------MAKING  SUBSTRINGS----------*/
class Solution
{
    public:
    //Function to check if two strings are rotations of each other or not.
    bool areRotations(string s1,string s2)
    {
       int n1=s1.size();
       int n2=s2.size();
       
       if(n1!=n2) 
       return 0;
       
       string s3=s1+s1;
       for(int i=0;i<s3.size();i++)
       {
           if(s3.substr(i,n1)==s2) 
           return 1;
       }
       return 0;
    }
};

/*--------------USING INBUILT FIND FUNCTION------------*/
class Solution
{
    public:
    //Function to check if two strings are rotations of each other or not.
    bool areRotations(string s1,string s2)
    {
        if(s1.length()!=s2.length())
        return false;
        
        s1+=s1;
        if(s1.find(s2)!=-1)
        return true;
        else
        return false;
    }
};