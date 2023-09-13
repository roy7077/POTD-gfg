class Solution{
    public:
    string findLargest(int N, int S){
        
        if(ceil(S/9.0)>N or (N>=2 and S==0))
        return "-1";
        
        string temp="";
        
        while(S and N)
        {
            if(S<=9)
            {
                temp+=char(S+48);
                N--;
                break;
            }
            
            temp+=char(9+48);
            S-=9;
            N--;
        }
        
        while(N)
        {
            temp+='0';
            N--;
        }
        
        return temp;
    }
};