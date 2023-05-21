//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
#include <cmath>
#define ll long long
class Solution {
  public:
    int findMoves(int n, vector<int> ch, vector<int> p) {
        
        //sorting an aarays
        sort(ch.begin(),ch.end());
        sort(p.begin(),p.end());
        
        ll cnt=0;
        for(int i=0;i<n;i++)
        cnt+=abs(ch[i]-p[i]);
        
        return cnt;
    }
};

//time complexity - O(nlogn)
//space complexity - O(1) (constant , not extra space used)

//{ Driver Code Starts.

int main() {
    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> chairs(n), passengers(n);
        for (auto &val : chairs) cin >> val;
        for (auto &val : passengers) cin >> val;
        int ans = sol.findMoves(n, chairs, passengers);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends