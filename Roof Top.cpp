class Solution {
    public:
    int maxStep(vector<int>& arr) {
        int maxi=0;
        int cnt=0;
        for(int i=0;i<arr.size()-1;i++)
        {
            if(arr[i+1]>arr[i])
            cnt++;
            else
            {
                maxi=max(maxi,cnt);
                cnt=0;
            }
        }
        maxi=max(maxi,cnt);
        return maxi;
    }
};
