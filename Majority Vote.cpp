class Solution {
    public:
    vector<int> findMajority(vector<int>& nums) {
        int ind1=-1;
        int ind2=-1;
        int cnt1=0;
        int cnt2=0;
        
        for(int i=0;i<nums.size();i++)
        {
            
            if(cnt1!=0 and nums[ind1]==nums[i])
            cnt1++;
            else if(cnt2!=0 and nums[ind2]==nums[i])
            cnt2++;
            else if(cnt1==0)
            {
                ind1=i;
                cnt1=1;
            }
            else if(cnt2==0)
            {
                ind2=i;
                cnt2=1;
            }
            else
            {
                cnt1--;
                cnt2--;
            }
        }
        

        cnt1=0;
        cnt2=0;
        int cnt3=0;
        int ele=-1;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==nums[ind1])
            cnt1++;
            else if(nums[i]==nums[ind2])
            cnt2++;
            else
            {
                if(nums[i]==ele)
                cnt3++;
                else
                {
                    cnt3=1;
                    ele=nums[i];
                }
            }
        }
        
    
        int size=nums.size()/3.0;
        vector<int> ans;
        if(cnt1>size and cnt2>size and cnt3>size)
        {
            ans.push_back(nums[ind1]);
            ans.push_back(nums[ind2]);
            ans.push_back(ele);
            
            sort(ans.begin(),ans.end(),greater<int>());
            return ans;
        }
        else if(cnt1>size and cnt2>size)
        {
            ans.push_back(nums[ind1]);
            ans.push_back(nums[ind2]);
            
            sort(ans.begin(),ans.end());
            return ans;
        }
        else if(cnt1>size)
        return {nums[ind1]};
        else if(cnt2>size)
        return {nums[ind2]};
        else
        return {-1};
    }
};
