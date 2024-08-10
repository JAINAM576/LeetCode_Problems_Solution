class Solution {
public:
void dfs(int i ,int j,int rowSize,int colSize, vector<vector<int>> &gridMatrix){
    if(i<0 || j<0 || i>=rowSize || j>=colSize || gridMatrix[i][j]==1)return ;

    gridMatrix[i][j]=1;
    dfs(i+1,j,rowSize,colSize,gridMatrix);
    dfs(i-1,j,rowSize,colSize,gridMatrix);
    dfs(i,j+1,rowSize,colSize,gridMatrix);
    dfs(i,j-1,rowSize,colSize,gridMatrix);

}

    int regionsBySlashes(vector<string>& grid) {
     int count=0;
        int n=grid.size();
int rows=n*3;
int cols=n*3;
        vector<vector<int>> gridMatrix(n*3,vector<int>(n*3,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int row=i*3;
                int col=j*3;
                if(grid[i][j]=='/'){
                    gridMatrix[row][col+2]=1;
                    gridMatrix[row+1][col+1]=1;
                    gridMatrix[row+2][col]=1;


                }
                else if(grid[i][j]=='\\'){
                    gridMatrix[row][col]=1;
                    gridMatrix[row+1][col+1]=1;
                    gridMatrix[row+2][col+2]=1;

                }
            }
        }

        for(int i=0;i<n*3;i++){
            for(int j=0;j<n*3;j++){
                if(gridMatrix[i][j]==0){
                    dfs(i,j,rows,cols,gridMatrix);
                    count++;
                
                }
            }
        }


        return count;
    }
};