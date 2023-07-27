class Solution
{
    public:
    //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)  
    {
      int largest=i;
      int l=2*i+1;
      int r=2*i+2;
      
      if(r<n and arr[r]>arr[largest])
      largest=r;
      
      if(l<n and arr[l]>arr[largest])
      largest=l;
      
      if(largest!=i)
      {
          swap(arr[largest],arr[i]);
          heapify(arr,n,largest);
      }
    }

    public:
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    { 
        for(int i=(n/2)-1;i>=0;i--)
        heapify(arr,n,i);
        
        for(int i=n-1;i>=0;i--)
        {
            swap(arr[i],arr[0]);
            heapify(arr,i,0);
        }
    }

    
    public:
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        buildHeap(arr,n);
        return ;
    }
};