class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<char>> rowTable(9, set<char>());
        vector<set<char>> colTable(9, set<char>());
        vector<set<char>> boxTable(9, set<char>());
        for(int row = 0; row < 9; ++row){
            for(int col = 0; col < 9; ++col){
                char num = board[row][col];
                if(num == '.') continue;
                int box = (row / 3) * 3 + (col / 3);
                if(rowTable[row].count(num) == 1 ||
                   colTable[col].count(num) == 1 ||
                   boxTable[box].count(num) == 1) return false;
                
                rowTable[row].insert(num);
                colTable[col].insert(num);
                boxTable[box].insert(num);
            }
        }
        return true;
    }
};