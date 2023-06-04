
#define ll long long
class Solution{
public:
    int maxEqualSum(int N1,int N2,int N3,vector<int> &S1,vector<int> &S2,vector<int> &S3){
        
        ll sum1,sum2,sum3;
        sum1=sum2=sum3=0;
        
        for(auto it:S1)
        sum1+=it;
        
        for(auto it:S2)
        sum2+=it;
        
        for(auto it:S3)
        sum3+=it;
        
        int i=0,j=0,k=0;
        while(i<N1 and j<N2 and k<N3)
        {
            if(sum1==sum2 and sum2==sum3)
            return sum1;
            
            else if(sum1<=sum2 and sum1<=sum3)
            {
                if(sum1<sum2){
                    sum2-=S2[j];
                    j++;
                }
                if(sum1<sum3)
                {
                    sum3-=S3[k];
                    k++;
                }
            }
            else if(sum2<=sum1 and sum2<=sum3)
            {
                if(sum2<sum1)
                {
                    sum1-=S1[i];
                    i++;
                }
                if(sum2<sum3)
                {
                    sum3-=S3[k];
                    k++;
                }
            }
            else{
                if(sum3<sum2)
                {
                    sum2-=S2[j];
                    j++;
                }
                if(sum3<sum1)
                {
                    sum1-=S1[i];
                    i++;
                }
            }
        }
        return 0;
    }
};

// time complexity - O(N1+N2+N3)
// space complexity - O(1)