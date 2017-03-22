class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > matrix(n, vector<int>(n));
        int layerMax = n/2 + n%2;
        int num = 1; 
        
        for (int layer = 0; layer < layerMax; layer++ ) {
            if (layer == n - 1 - layer) //single item
                matrix[layer][layer] = num++;
                
            for ( int i = layer; i < n - 1 - layer; i++ ) 
                matrix[layer][i] = num++;
                
            for ( int j = layer; j < n - 1 - layer; j++ ) 
                matrix[j][n - 1 - layer] = num++;
                
            for ( int i = n - 1 - layer; i > layer; i-- )
                matrix[n - 1 - layer][i] = num++;
                
            for ( int j = n - 1 - layer; j > layer; j-- )
                matrix[j][layer] = num++;  
        }
        
        return matrix;
    }
};
