class twoStacks
{
    int *arr;
    int size;
    int i,j;
    public:
    
    twoStacks(int n=200)
    {
        size = n; 
        arr = new int[n]; 
        i=0;
        j=100;
    }
 
    //Function to push an integer into the stack1.
    void push1(int x)
    {
        arr[i]=x;
        i++;
    }
    
    //Function to push an integer into the stack2.
    void push2(int x)
    {
       arr[j]=x;
       j++;
    }
    
    //Function to remove an element from top of the stack1.
    int pop1()
    {
        if(i==0)
        return -1;
        
        i--;
        return arr[i];
    }
    
    //Function to remove an element from top of the stack2.
    int pop2()
    {
       if(j==100)
        return -1;
        
        j--;
        return arr[j];
    }
};
