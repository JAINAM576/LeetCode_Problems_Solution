class Solution {
public:
    bool check(int val, vector<int>& vec) {
        cout<<val<<endl;
         return (val>=1 && val <= 9 && vec[val] == 0); 
         }
    bool isMagicSqaure(int i, int j, int n, int m, vector<vector<int>> grid) {
        vector<int> vec(10, 0);
        cout<<i<<j<<n<<m<<endl;
        if ((i + 1) >= n || (i + 2) >= n || (j + 1) >= m || (j + 2) >= m)
            return false;
        if (check(grid[i][j], vec))
            vec[grid[i][j]]++;
        else
            return false;
        if (check(grid[i][j+1], vec))
            vec[grid[i][j+1]]++;
        else
            return false;
        if (check(grid[i][j+2], vec))
            vec[grid[i][j+2]]++;
        else
            return false;
        if (check(grid[i+1][j], vec))
            vec[grid[i+1][j]]++;
        else
            return false;
        if (check(grid[i+1][j+1], vec))
            vec[grid[i+1][j+1]]++;
        else
            return false;
        if (check(grid[i+1][j+2], vec))
            vec[grid[i+1][j+2]]++;
        else
            return false;
        if (check(grid[i+2][j], vec))
            vec[grid[i+2][j]]++;
        else
            return false;
        if (check(grid[i+2][j+1], vec))
            vec[grid[i+2][j+1]]++;
        else
            return false;
        if (check(grid[i+2][j+2], vec))
            vec[grid[i+2][j+2]]++;
        else
            return false;

            int rowSum=0;
            int prevSum=-1;
        for(int row=i;row<(i+3);row++){
            for(int col=j;col<(j+3);col++){
rowSum+=grid[row][col];
            }
            if(prevSum!=-1 && prevSum!=rowSum)return false;
            prevSum=rowSum;
            rowSum=0;
        }
            int colSum=0;
            int prevColSum=-1;
         for(int row=j;row<(j+3);row++){
            for(int col=i;col<(i+3);col++){
colSum+=grid[col][row];
            }
            if((prevColSum!=-1 && prevColSum!=colSum) || colSum!=prevSum)return false;
            prevColSum=colSum;
            colSum=0;
        }

        int diagnolsum=grid[i][j]+grid[i+1][j+1]+grid[i+2][j+2];
        int diagnoalInverseSum=grid[i][j+2]+grid[i+1][j+1]+grid[i+2][j];
        if((diagnolsum !=diagnoalInverseSum) || (diagnolsum!=prevSum) || (diagnolsum!=prevColSum))return false;
    
        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int count=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n-1;i++){
            for(int j=0;j<m-1;j++){
                if(isMagicSqaure(i,j,n,m,grid))count++;
            }
        }
        return count;
    }
};