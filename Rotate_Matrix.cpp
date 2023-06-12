//Solution :-  TC: O(n*n)   SC: O(1)

void rotate(vector<vector<int>>& mat) 
    {
        //Transpose the matrix
        for(int i=0;i<mat.size();i++)
        {
            for(int j=i+1;j<mat[0].size();j++)
            {
                //swap
                int temp = mat[i][j];
                mat[i][j]=mat[j][i];
                mat[j][i]=temp;
            }
        }
        //Reverse the every row
        for(auto &v:mat)
        {
            int i=0, j=v.size()-1;
            while(i<j)
            {
                //swap
                int temp = v[i];
                v[i]=v[j];
                v[j]=temp;
                i++;j--;
            }
        }
    }
