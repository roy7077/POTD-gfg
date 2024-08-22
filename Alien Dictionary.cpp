class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        
        vector<int> adj[K];
        for(int i=0;i<N-1;i++)
        {
            for(int j=0;j<min(dict[i].length(),dict[i+1].length());j++)
            {
                if(dict[i][j]!=dict[i+1][j])
                {
                    adj[dict[i][j]-'a'].push_back(dict[i+1][j]-'a');
                    break;
                }
            }
        }
        
        vector<int> indegree(K,0);
        for(int i=0;i<K;i++)
        {
            for(auto it:adj[i])
            indegree[it]++;
        }
        
        queue<int> q;
        for(int i=0;i<K;i++)
        {
            if(indegree[i]==0)
            q.push(i);
        }
        
        string ans="";
        while(!q.empty())
        {
            int front=q.front();
            ans+=char((front+97));
            
            q.pop();
            
            for(auto it:adj[front])
            {
                indegree[it]--;
                if(indegree[it]==0)
                q.push(it);
            }
        }
        
        return ans;
    }
};
