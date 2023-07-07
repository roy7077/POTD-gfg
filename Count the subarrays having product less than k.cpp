
class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
          //sliding window approach
          long long int p=1;
          int count=0;
          int i=0,j=0;
          while(j<n){
              p=p*a[j];
              if(p<k) count=count+j-i+1;
              else {
                  while(p>=k && i<=j){
                      p=p/a[i];
                      i++;
                  }
                  if(p<k) count=count+j-i+1;
              }
              j++;
          }
          return count;
    }
};