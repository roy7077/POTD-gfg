class Solution {
    public:
    vector<int> findSplit(vector<int>& arr) {
        int sum=0;
        for(auto& it:arr)
        sum+=it;
        
        if(sum==0)
        return {0,1};
        
        int s=0;
        int e=sum;
        while(s<=e)
        {
            int mid=(s+e)/2;
            //cout<<"mid -> "<<mid<<endl;
            vector<int> index;
            int currSum=arr[0];
            bool flag=1;
            for(int i=1;i<arr.size();i++)
            {
                //if(currSum)
                if(currSum+arr[i]>mid)
                {
                    if(currSum!=mid)
                    flag=0;
                    
                    index.push_back(i-1);
                    currSum=arr[i];
                }
                else
                currSum+=arr[i];
            }
            
            if(currSum and currSum!=mid)
            flag=0;
            
            if(flag and index.size()==2)
            {
                //cout<<"yes"<<endl;
                return index;
            }
            
            //cout<<"mid -> "<<mid<<" size "<<index.size()<<endl;
            if(index.size()==2)
            {
                if(currSum<mid)
                e=mid-1;
                else
                s=mid+1;
            }
            else if(index.size()>2)
            s=mid+1;
            else
            e=mid-1;
        }
        
        return {-1,-1};
    }
};
