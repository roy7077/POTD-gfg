class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            int maxi=1e9;
            int i=0;
            int j=0;
            int k=0;
            
            while(k<(n+m))
            {
                if(i<n and j<m)
                {
                    if(k<n)
                    {
                        if((arr1[i]%maxi)<(arr2[j]%maxi))
                        {
                            arr1[k]=((arr1[i]%maxi)*maxi)+(arr1[k]%maxi);
                            i++;
                        }
                        else
                        {
                            arr1[k]=((arr2[j]%maxi)*maxi)+(arr1[k]%maxi);
                            j++;
                        }
                    }
                    else
                    {
                        if((arr1[i]%maxi)<(arr2[j]%maxi))
                        {
                            arr2[k-n]=((arr1[i]%maxi)*maxi)+(arr2[k-n]%maxi);
                            i++;
                        }
                        else
                        {
                            arr2[k-n]=((arr2[j]%maxi)*maxi)+(arr2[k-n]%maxi);
                            j++;
                        }
                    }
                }
                else
                {
                    if(i<n)
                    {
                        if(k<n)
                        {
                            arr1[k]=((arr1[i]%maxi)*maxi)+(arr1[k]%maxi);
                            i++;
                        }
                        else
                        {
                            arr2[k-n]=((arr1[i]%maxi)*maxi)+(arr2[k-n]%maxi);
                            i++;
                        }
                    }
                    else
                    {
                        if(k<n)
                        {
                            arr1[k]=((arr2[j]%maxi)*maxi)+(arr1[k]%maxi);
                            j++;
                        }
                        else
                        {
                            arr2[k-n]=((arr2[j]%maxi)*maxi)+(arr2[k-n]%maxi);
                            j++;
                        }
                    }
                }
                
                k++;
            }
            
            for(int i=0;i<n;i++)
            arr1[i]=arr1[i]/maxi;
            
            for(int i=0;i<m;i++)
            arr2[i]=arr2[i]/maxi;
            
        } 
};