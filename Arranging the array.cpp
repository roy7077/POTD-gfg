
class Solution
{
    public:
        void Rearrange(int arr[], int n)
        {
            int ind=0;
            vector<int> pos;
            
            //inserting all positive numbers into pos vector
            for(int i=0;i<n;i++)
            {
                if(arr[i]>=0)
                pos.push_back(arr[i]);
            }
            
            //making all negative numbers in start
            for(int i=0;i<n;i++)
            {
                if(arr[i]<0)
                {
                    arr[ind]=arr[i];
                    ind++;
                }
            }
            
            //arranging elements
            int j=0;
            for(int i=ind;i<n;i++)
            {
                arr[i]=pos[j];
                j++;
            }
        }
};
// time complexity - O(N)
// space complexity - O(N)