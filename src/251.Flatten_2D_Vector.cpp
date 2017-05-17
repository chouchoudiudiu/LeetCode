class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d) {
        data = vec2d;
        row = 0;
        col = 0;
    }

    int next() {
        return data[row][col++];
    }

    bool hasNext() {
        while (row < data.size() && col == data[row].size()) {//while not if
            ++row;
            col = 0;//starting a new row, use while to gurantee you reach a location with a valid number
        }
        return row < data.size();
    }
    
    int row, col;
    vector<vector<int>> data;
};
//[[1],[]]
/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
