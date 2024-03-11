/* Method - 1
   Time complexity - O(N*N)
   Space complexity- O(1)
*/
class Solution{
    public:	
	int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int n, int x)
	{
	   int i=0;
	   int j=(n*n)-1;
	   int cnt=0;
	   while(i<(n*n) and j>=0)
	   {
	       while(i+1<(n*n) and mat1[i/n][i%n]==mat1[(i+1)/n][(i+1)%n])
	       i++;
	       
	       while(j-1>=0 and mat2[j/n][j%n]==mat2[(j-1)/n][(j-1)%n])
	       j--;
	       
	       int a=mat1[i/n][i%n];
	       int b=mat2[j/n][j%n];
	       if((a+b)==x)
	       {
	           cnt++;
	           i++;
	           j--;
	       }
	       else if((a+b)<x)
	       i++;
	       else
	       j--;
	   }
	   return cnt;
	}
};
