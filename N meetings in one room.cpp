// Time complexity - O(NlogN)
// Space complexity- O(2*N)
typedef pair<int,int> pi;
class Solution {
    public:
    static bool cmp(pi& a,pi& b)
    {
        if(a.second==b.second)
        return a.first<=b.first;
        
        return a.second<=b.second;
    }
    int maxMeetings(int n, int start[], int end[]) {
        
        vector<pi> v;
        for(int i=0;i<n;i++)
        v.push_back({start[i],end[i]});
        
        sort(v.begin(),v.end(),cmp);
        

        int cnt=1;
        int s=v[0].first;
        int e=v[0].second;
        for(auto& it:v)
        {
            if(it.first>e)
            {
                cnt++;
                s=it.first;
                e=it.second;
            }
        }
        
        return cnt;
    }
};

