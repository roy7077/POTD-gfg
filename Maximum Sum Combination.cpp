class Solution {
  public:
    vector<int> maxCombinations(int n, int k, vector<int> &a, vector<int> &b) {
        
        //priority queue to implement max heap
        // it will have <sum, index_of_a>
        priority_queue<pair<int, int>> pq;
        //sort in non- increasing order
        sort(a.rbegin(), a.rend());
        sort(b.rbegin(), b.rend());
        
        vector<int> ans;
        //push all possible combinations for first vector a[0] -> b[0],b[1]...
        for(int i=0; i<n; i++){
            pq.push({(a[0]+b[i]), 0});
        }
        
        
        while(k--){
            auto x= pq.top();
            int i= x.first;
            int j= x.second;
            pq.pop();
            ans.push_back(i);
            
            pq.push({i - a[j]+a[j+1], j+1});
            
        }
        return ans;
    }
};