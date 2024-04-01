//Policy Based Data Structure 💀
//Go through this article - https://codeforces.com/blog/entry/11080

/* policy-based data structure that is like set, it can add/remove elements, 
   can find the number of elements less than x, kth smallest element etc in 
   O(logn) time
   
   Time complexity - O(N*logN)
   Space complexity- O(N)
*/
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
class Solution {
    public:
    void help(Node* root,vector<int>& v)
    {
        //base case
        if(!root)
        return ;
        
        //recursive calls
        //small calculation
        help(root->left,v);
        v.push_back(root->data);
        help(root->right,v);
    }
    int pairsViolatingBST(int n, Node *root) {
        vector<int> v;
        help(root,v);
      
        int count = 0;
        ordered_set st;
        for (int i = 0; i < n; i++)
        {
          int smaller = st.order_of_key(v[i]);
          count += (i - smaller);
          st.insert(v[i]);
        }
        return count;
    }
};