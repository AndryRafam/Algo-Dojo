"""
Given an m x n board of characters and a list of strings words, return all words on the board.
Each word must be constructed from letters of sequentially adjacent cells, 
where adjacent cells are horizontally or vertically neighboring. 
The same letter cell may not be used more than once in a word.

Brute force approach.
"""

class Solution:
    def findWords(self,board,words):
        ust = set() # to ensure that there is no duplicate in the final solution
        result = []

        def dfs(board,word,i,j,pos):
            if pos==len(word):
                return True
            if i < 0 or i >= len(board) or j < 0 or j >= len(board[i]) or board[i][j]!=word[pos]:
                return False
            else:
                temp = board[i][j]
                board[i][j] = '$'
                found = dfs(board,word,i+1,j,pos+1) or dfs(board,word,i-1,j,pos+1) or dfs(board,word,i,j+1,pos+1) or dfs(board,word,i,j-1,pos+1)
                board[i][j] = temp
                return found

        for i in range(len(board)):
            for j in range(len(board[0])):
                for k in range(len(words)):
                    if dfs(board,words[k],i,j,0):
                        ust.add(words[k])
        for x in ust:
            result.append(x)
        return result

if __name__=="__main__":
    board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]]
    words = ["oath","pea","eat","rain"]
    print(Solution().findWords(board,words),end = " ")
