class Solution{
    static int splitArray(int[]arr,int N,int K){
        long low= Arrays.stream(arr).max().getAsInt();
        long high= Arrays.stream(arr).sum();
        while(low<high){
            long mid = low +(high - low) /2;
            int count= getCount(arr, N, mid);
            
            if(count > K){
                low =mid+1;
            }else{
                high=mid;
            }
        }
        return (int)low;
    }
    static int getCount(int arr[], int N, long maxSum){
        int count =1;
         long currentSum = 0;
        
        for (int num : arr) {
            currentSum += num;
            if (currentSum > maxSum) {
                count++;
                currentSum = num;
            }
        }
        
        return count;
    }
        
     
}