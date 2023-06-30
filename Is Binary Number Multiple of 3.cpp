//User function template for C++

class Solution{
public:	
		
	int isDivisible(string s)
	{
	    long long num=0;
	    int power=1;
	    
	    for(int i=s.length()-1;i>=0;i--)
	    {
	        if(s[i]=='1')
	        num+=power;
	        
	        
	        power*=2;
	        if(power==16)
	        power=1;
	    }
	    
	    if(num%3==0)
	    return 1;
	    else
	    return 0;
	}

};
