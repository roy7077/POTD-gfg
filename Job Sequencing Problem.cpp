// Time complexity - O(NlogN)
// Space complexity- O(1)
class Solution 
{
    public:
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // sorting an array based on 
        // some condition
        sort(arr, arr + n, [](const Job& a, const Job& b) {
            return a.profit > b.profit;
        });

        
       // actual calculation
       vector<bool> vis(n,false); 
       int jobcnt=0;
       int maxprofit=0;
       for (int i=0; i< n; i++)
       {
           for (int j=arr[i].dead-1; j>= 0; j--)
           {
                if (vis[j]) 
                continue;
                else
                {
                    vis[j]=true;
                    maxprofit+=arr[i].profit;
                    jobcnt++;
                    break;
                }
           }
        }
        return {jobcnt,maxprofit};
    } 
};


/*
[4,1,25],
[2,1,19],
[5,1,15],
[1,2,100],
[3,2,27],
*/
