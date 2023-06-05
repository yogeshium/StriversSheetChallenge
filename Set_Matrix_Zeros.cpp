   //Solution 1: 
    /*Time Complexity: O(m*n)   Space Complexity: O(m*n)*/
  void setZeroes(vector<vector<int>>& mat) 
    {
        vector<pair<int,int>> zero;
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[i].size();j++)
            {
                if(mat[i][j]==0)
                    zero.push_back({i,j});
            }
        }

        for(auto x:zero)
        {
            for(int i=0;i<mat.size();i++)
                mat[i][x.second]=0;
            for(int j=0;j<mat[0].size();j++)
                mat[x.first][j]=0;
        }
    }

//Solution 2: 
/* space: O(m+n) */
 void setZeroes(vector<vector<int>>& mat) 
    {
        vector<int> row, col;
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[i].size();j++)
            {
                if(mat[i][j]==0)
                {
                    row.push_back(i);
                    break;
                }
            }
        }
        for(int j=0;j<mat[0].size();j++)
        {
            for(int i=0;i<mat.size();i++)
            {
                if(mat[i][j]==0)
                {
                    col.push_back(j);
                    break;
                }
            }
        }

        for(auto r:row)
        {
            for(int j=0;j<mat[0].size();j++)
                mat[r][j]=0;
        }
        for(auto c:col)
        {
            for(int i=0;i<mat.size();i++)
                mat[i][c]=0;
        }
    }

//Solution 3:( Not mine : taken help from other submissions)
/* Constant space complexity */
/* My idea is simple: store states of each row in the first of 
  that row, and store states of each column in the first of that 
  column. Because the state of row0 and the state of column0 would 
  occupy the same cell, I let it be the state of row0, and use another 
  variable "col0" for column0. In the first phase, use matrix elements
  to set states in a top-down way. In the second phase, use states to 
  set matrix elements in a bottom-up way.
 */

 void setZeroes(vector<vector<int>>& mat) 
    {
        int row0 = -1, col0=-1;
        for(int i=0;i<mat.size();i++)
            if(mat[i][0]==0)
            {    col0=0;break;}

        for(int j=0;j<mat[0].size();j++)
            if(mat[0][j]==0)
            {    row0=0;break;}
        

        for(int i=1;i<mat.size();i++)
        {
            for(int j=1;j<mat[0].size();j++)
            {
                if(mat[i][j]==0)
                {
                    mat[i][0]=0;
                    mat[0][j]=0;
                }
            }
        }
        //column
        for(int i=1;i<mat.size();i++)
        {
            if(mat[i][0]==0)
            {
                for(int j=1;j<mat[0].size();j++)
                    mat[i][j]=0;
            }
        }
        //row
        for(int j=1;j<mat[0].size();j++)
        {
            if(mat[0][j]==0)
            {
                for(int i=1;i<mat.size();i++)
                    mat[i][j]=0;
            }
        }

        if(row0==0)
        {
            for(int j=0;j<mat[0].size();j++)
                mat[0][j]=0;
        }
        if(col0==0)
        {
            for(int i=0;i<mat.size();i++)
                mat[i][0]=0;
        }
    }
