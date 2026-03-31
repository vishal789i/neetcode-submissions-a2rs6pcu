/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        function<Node*(int, int, int)> dfs = [&] (int r, int c, int n) {
            auto allSame = true;
            for (int i = 0; i < n and allSame; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (grid[r][c] != grid[r + i][c + j]) {
                        allSame = false;
                        break;
                    }
                }

                if (not allSame) {
                    break;
                }
            }

            if (allSame) {
                return new Node(grid[r][c], true);
            }

            n /= 2;
            auto topLeft = dfs(r, c, n);
            auto topRight = dfs(r, c + n, n);
            auto bottomLeft = dfs(r + n, c, n);
            auto bottomRight = dfs(r + n, c + n, n);
            return new Node(grid[r][c], false, topLeft, topRight, bottomLeft, bottomRight);
        };

        return dfs(0, 0, grid.size());
    }
};