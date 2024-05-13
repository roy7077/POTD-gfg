class Solution {
    public:
    int dfs(vector<int>* adj,int node,vector<int>& visited,int& num)
    {
        int numNode=1;
        visited[node]=num;
        for(auto& it:adj[node])
        {
            if(visited[it]==0)
            numNode+=dfs(adj,it,visited,num);
        }
        return numNode;
    }
    int findNumberOfGoodComponent(int e, int v, vector<vector<int>> &edges) {
        
        //making adj list
        vector<int> adj[v+1];
        for(auto& it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        //finding connected components
        vector<int> visited(v+1,0);
        unordered_map<int,int> nodeMap;
        int num=1;
        for(int i=1;i<=v;i++)
        {
            if(visited[i]==0)
            {
                int nodeCnt=dfs(adj,i,visited,num);
                nodeMap[num]=nodeCnt;
                num++;
            }
        }
       
        //calculating number of good components
        unordered_map<int,int> mp;
        int cnt=0;
        for(int i=1;i<=v;i++)
        {
            if(mp.count(visited[i])==0)
            {
                if((adj[i].size()+1)==nodeMap[visited[i]])
                {
                    cnt++;
                    mp[visited[i]]=adj[i].size();
                }
                else
                mp[visited[i]]=-1;
            }
            else
            {
                if(mp[visited[i]]==-1)
                continue;
                
                if((adj[i].size()+1)!=nodeMap[visited[i]])
                {
                    cnt--;
                    mp[visited[i]]=-1;
                }
            }
        }
        return cnt;
    }
};