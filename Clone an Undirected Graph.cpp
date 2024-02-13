// DFS

class Solution {
    public:
    Node* help(Node* node,vector<Node*>& visited)
    {
        Node* graph=new Node(node->val);
        visited[node->val]=graph;
        for(auto it:node->neighbors)
        {
            if(!visited[it->val])
            help(it,visited);
            
            graph->neighbors.push_back(visited[it->val]);
        }
        return graph;
    }
    Node* cloneGraph(Node* node) {
        vector<Node*> visited(10001,NULL);
        return help(node,visited);
    }
};

//BFS

class Solution {
    public:
    Node* cloneGraph(Node* node) {
        vector<Node*> visited(10001,NULL);
        queue<pair<Node*,Node*>> q;
        Node* start=NULL;
        
        q.push({node,NULL});
        while(!q.empty())
        {
            Node* n=q.front().first;
            Node* clone=q.front().second;
            q.pop();
            
            Node* graph=NULL;
            if(clone==NULL)
            graph=new Node(n->val);
            else
            graph=clone;
            
            if(start==NULL)
            start=graph;
            
            visited[n->val]=graph;
            for(auto it:n->neighbors)
            {
                if(visited[it->val]==0)
                {
                    Node* newnode=new Node(it->val);
                    q.push({it,newnode});
                    visited[it->val]=newnode;
                }
                graph->neighbors.push_back(visited[it->val]);
            }
        }
        return start;
    }
};