
// Time complexity - O(N)
// Space complexity- O(1)
class Solution {
    public:
    int gameOfXor(int N , int A[]) {
        if(N&1)
        {
            int ans=0;
            int i=0;
            while(i<N)
            {
                ans^=A[i];
                i+=2;
            }
            return ans;
        }
        
        return 0;
    }
};

/*
For an array of even length N, let's consider the examples:

N=2, arr[]={1,2}

Subarrays:

[1]
[2]
[1,2]
XOR of subarrays:

[1] ^ [2] ^ [1,2] = 0 (as [1,2] ^ [1,2] cancels out)
N=4, arr[]={1,2,3,4}

Subarrays:

[1], [2], [3], [4]
[1,2], [2,3], [3,4]
[1,2,3]
[2,3,4]
[1,2,3,4]
XOR of subarrays:

[1] ^ [2] ^ [3] ^ [4] ^ [1,2] ^ [2,3] ^ [3,4] ^ [1,2,3] ^ [2,3,4] ^ [1,2,3,4] = 0
In simpler terms, for an array of even length, when you XOR all possible subarrays, the result is always 0.

For an array of odd length, consider the following example:

N=3, arr[]={1,2,3}

Take the XOR of alternate elements:
[1] ^ [3] = 2
This can be generalized for arrays with odd length as follows:

Given an array of odd length N, take the XOR of alternate elements.

For example:

N=5, arr[]={1,2,3,4,5}
XOR of alternate elements: [1] ^ [3] ^ [5] = 3
In summary, for arrays with odd length, you can obtain the XOR of alternate elements to get a specific result.
*/