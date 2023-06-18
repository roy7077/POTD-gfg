class Solution{
    public:
    // Function to insert element into the queue
    map<int,int> m;
    void insert(queue<int> &q, int k){
        // Your code here
        q.push(k);
        m[k]++;
    }
    
    // Function to find frequency of an element
    // return the frequency of k
    int findFrequency(queue<int> &q, int k){
        
        return m[k];
    }
    
};