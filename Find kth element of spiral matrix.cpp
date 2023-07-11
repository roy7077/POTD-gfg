class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX],int m,int n,int find)
    {
 		
 		 int i, k = 0, l = 0;
 
        /* k - starting row index
            m - ending row index
            l - starting column index
            n - ending column index
            i - iterator
        */
 
        while (k < m && l < n) 
        {
            /* Print the first row from
                the remaining rows */
            for (i = l; i < n; ++i) 
            {
                if(find==1)
                return a[k][i];
            
                find--;
            }
            k++;
     
            /* Print the last column
             from the remaining columns */
            for (i = k; i < m; ++i) {
                
                if(find==1)
                return a[i][n-1];
                
                find--;
            }
            n--;
     
            /* Print the last row from
                    the remaining rows */
            if (k < m) {
                for (i = n - 1; i >= l; --i) {
                    
                    if(find==1)
                    return a[m-1][i];
                
                    find--;
                }
                m--;
            }
     
            /* Print the first column from
                       the remaining columns */
            if (l < n) {
                for (i = m - 1; i >= k; --i) {
                    
                    
                    if(find==1)
                    return a[i][l];
                    
                    
                    find--;
                }
                l++;
            }
        }
    }
};
