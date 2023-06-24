class Solution{   
public:
    int klengthpref(string arr[], int n, int K, string str){    
        
        int cnt=0;
        str=str.substr(0,K); //getting substring from index 0 to k-1
        for(int i=0;i<n;i++)
        {
            string temp=arr[i];
            if(temp.length()>=K and temp.substr(0,K)==str)
            cnt++;
        }
        
        return cnt;
    }
};

//time _Complexity -  O(n*k)
//space _Complexity - O(k)