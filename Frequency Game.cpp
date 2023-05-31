
#include <unordered_map>
#include <algorithm>
#include <vector>

class Solution{
public:
    int LargButMinFreq(int arr[], int n) {
        
        unordered_map<int,int> map;
        int freq=1e9;
        int num;
        for(int i=0;i<n;i++)
        map[arr[i]]++;
        
        for(auto it:map)
        {
            if(it.second<freq)
            {
                freq=it.second;
                num=it.first;
            }
        }
        
        for(auto it:map)
        {
            if(it.first>num and it.second<=freq)
            {
                freq=it.second;
                num=it.first;
            }
        }
        
        return num;
    }
};