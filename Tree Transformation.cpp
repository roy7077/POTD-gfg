//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
#include <unordered_map>
class Solution {
    public:
    int solve(int N, vector<int> p){
        
        unordered_map<int,int> map;
        for(int i=1;i<N;i++)
        {
            //making a conections
            map[i]++;
            map[p[i]]++;
        }
        
        int cnt=0;
        for(auto it:map)
        {
            if(it.second==1)
            cnt++;
        }
        
        /* total number of nodes - leaf nodes (including root node) */
        return N-1-(cnt);
    }
};


//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        vector<int> p(N);
        for(int i = 0; i < N; i++){
            cin >> p[i];
        }

        Solution obj;
        cout << obj.solve(N, p) << "\n";
    }
}   
// } Driver Code Ends