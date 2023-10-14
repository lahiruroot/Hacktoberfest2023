class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& img, int sr, int sc, int color) {
        int orgColor = img[sr][sc];
        if (orgColor == color) {
            return img; 
        }
        
        fill(img, sr, sc, orgColor, color);
        return img;
    }

private:
    void fill(vector<vector<int>>& img, int r, int c, int orgColor, int newColor) {
        if (r < 0 || r >= img.size() || c < 0 || c >= img[0].size() || img[r][c] != orgColor) {
            return;
        }
        
        img[r][c] = newColor;
        
        fill(img, r + 1, c, orgColor, newColor);
        fill(img, r - 1, c, orgColor, newColor);
        fill(img, r, c + 1, orgColor, newColor);
        fill(img, r, c - 1, orgColor, newColor);
    }
};




//  Output


// image = [[1,1,1],[1,1,0],[1,0,1]]

// sr = 1

// sc = 1

// color=2
// Output [[2,2,2],[2,2,0],[2,0,1]]