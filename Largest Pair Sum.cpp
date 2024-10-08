class Solution {
  public:
    int pairsum(vector<int> &arr) {
        int largest=-1e9;
        int secondLargest=-1e9;
        
        for(auto& it:arr)
        {
            if(it>largest)
            {
                secondLargest=largest;
                largest=it;
            }
            else if(it>secondLargest)
            secondLargest=it;
        }
        return largest+secondLargest;
    }
};
