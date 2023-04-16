"""
Given an m x n grid of characters board and a string word, return true if word exists in the grid.
The word can be constructed from letters of sequentially adjacent cells, where adjacent cells
are horizontally or vertically neighboring. The same letter cell may not be used more than once.
"""

def exist(board,word):
    for i in range(len(board)):
        for j in range(len(board[i])):
            if dfs(board,word,i,j,0):
                return True
    return False

def dfs(board,word,i,j,k)->bool:
    if(k==len(board)):
        return True
    if(i < 0 or i >= len(board) or j < 0 or j >= len(board[i]) or board[i][j]!=word[k]):
        return False
    
    temp = board[i][j]
    board[i][j] = '$' # mark as visited
    found = dfs(board,word,i+1,j,k+1) or dfs(board,word,i-1,j,k+1) or dfs(board,word,i,j+1,k+1) or dfs(board,word,i,j-1,k+1)
    board[i][j]=temp
    return found

if __name__ == "__main__":
    board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
    word = "ABCCED"
    print(exist(board,word), end=" ") 
