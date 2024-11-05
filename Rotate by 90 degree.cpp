// User function template for C++

/* matrix : given input matrix, you are require
 to change it in place without using extra space */
 
 
void rotate(vector<vector<int> >& mat) {
    vector<vector<int>> temp(mat.size(),vector<int>(mat[0].size()));
    int k=mat[0].size()-1;
    for(int i=0;i<mat.size();i++)
    {
        for(int j=0;j<mat[0].size();j++)
        temp[j][k]=mat[i][j];
        
        k--;
    }
    
    // copying back
    for(int i=0;i<mat.size();i++)
    {
        for(int j=0;j<mat[0].size();j++)
        mat[i][j]=temp[i][j];
    }
}

// [1 2 3], 
// [4 5 6], 
// [7 8 9]


// 7 4 1
// 8 5 2
// 9 6 3
