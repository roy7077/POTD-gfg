
/* Method 1
Time complexity - O(NlogN)
Space complexity- O(1)
*/

class Solution
{
    public:
    static bool cmp(Item& a,Item& b)
    {
        double pro1=((double)a.value)/a.weight;
        double pro2=((double)b.value)/b.weight;
        
        return pro1>pro2;
    }
    
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr,arr+n,cmp);
        double ans=0.0;
        for(int i=0;i<n;i++)
        {
            int val=arr[i].value;
            int wei=arr[i].weight;
            
            if(wei<=W)
            {
                ans+=val;
                W-=wei;
            }
            else
            {
                double last=((double)W/wei)*val;
                ans+=last;
                W=0;
            }
        }
        return ans;
    }
};

/* Method 2
Time complexity - O(NlogN)
Space complexity- O(2*N)
*/

typedef pair<double,int> pi;
class Solution
{
    public:
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        vector<pi> v;
        for(int i=0;i<n;i++)
        {
            int val=arr[i].value;
            int wei=arr[i].weight;
            
            // profte/weight
            double pro=((double)val)/wei;
            v.push_back({pro,i});
        }
        
        sort(v.begin(),v.end(),greater<pi>());
        double ans=0.0;
        for(auto it:v)
        {
            int i=it.second;
            int val=arr[i].value;
            int wei=arr[i].weight;
            
            if(wei<=W)
            {
                ans+=val;
                W-=wei;
            }
            else
            {
                double last=((double)W/wei)*val;
                ans+=last;
                W=0;
            }
        }
        return ans;
    }
        
};