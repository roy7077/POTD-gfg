class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
		
    void lower_bound(int* a,int s,int e,int x,int& ind)
    {
        if(s>e)
        return ;
        
        int mid=(s+e)/2;
        if(a[mid]>=x)
        {
            ind=mid;
            lower_bound(a,s,mid-1,x,ind);
        }
        else
        lower_bound(a,mid+1,e,x,ind);
    }
    
    void upper_bound(int* a,int s,int e,int x,int& ind)
    {
        if(s>e)
        return ;
        
        int mid=(s+e)/2;
        if(a[mid]<=x)
        {
            ind=mid;
            upper_bound(a,mid+1,e,x,ind);
        }
        else
        upper_bound(a,s,mid-1,x,ind);
    }
    
	int count(int a[], int n, int x) {
	    
	    int ind1=-1;
	    int ind2=-1;
	    
	    lower_bound(a,0,n-1,x,ind1);
	    upper_bound(a,0,n-1,x,ind2);
	    
	    if(ind1==-1)
	    return 0;
	   
	    return ind2-ind1+1;
	}
};