// Time complexity - O(NlogN)
// Space complexity- O(N+logN)
typedef pair<int,int> pi;
class Solution {
    public:
    void mergeSort(vector<pi>& arr,int s,int e,vector<int>& ans)
    {
        vector<pi> temp;
        int mid=(s+e)/2;
        int i=s;
        int j=mid+1;
        
        while(i<=mid and j<=e)
        {
            if(arr[i].first>arr[j].first)
            {
                ans[arr[i].second]+=(e-j+1);
                temp.push_back(arr[i]);
                i++;
            }
            else
            {
                temp.push_back(arr[j]);
                j++;
            }
        }
        
        while(i<=mid)
        {
            temp.push_back(arr[i]);
            i++;
        }
        
        while(j<=e)
        {
            temp.push_back(arr[j]);
            j++;
        }
        
        i=s;
        for(auto& it:temp)
        arr[i++]=it;
    }
    void merge(vector<pi>& arr,int s,int e,vector<int>& ans)
    {
        if(s>=e)
        return ;
        
        int mid=(s+e)/2;
        merge(arr,s,mid,ans);
        merge(arr,mid+1,e,ans);
        mergeSort(arr,s,e,ans);
    }
    vector<int> constructLowerArray(vector<int> &arr) {
        int n=arr.size();
        vector<pi> temp;
        for(int i=0;i<arr.size();i++)
        temp.push_back({arr[i],i});
        
       
        vector<int> ans(arr.size(),0);
        merge(temp,0,n-1,ans);
        return ans;
    }
};
