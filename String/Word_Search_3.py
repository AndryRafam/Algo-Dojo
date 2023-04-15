"""
Given a 2D grid of characters and a list of words, find all the words that can be formed by traversing 
the grid in any of the 8 possible directions (up, down, left, right, and diagonals).

Time Complexity: O(W * M * N * L), where W is the number of words, M and N are the dimensions of the grid,
and L is the maximum length of a word.
"""

from typing import List

def dfs(grid:List[List[str]], word:str, i:int, j:int, pos:int)->bool:
    if pos==len(word):
        return True
    if i < 0 or i >= len(grid) or j < 0 or j >= len(grid[0]) or grid[i][j]!=word[pos]:
        return False
    else:
        directions = [(-1, 0), (1, 0), (0, -1), (0, 1), (-1, -1), (-1, 1), (1, -1), (1, 1)]
        temp = grid[i][j]
        grid[i][j] = '$'
        found = False
        for x,y in directions:
            if dfs(grid,word,i+x,j+y,pos+1):
                found = True
                break
        grid[i][j] = temp
        return found

def wordSearch(grid:List[List[str]], words:List[str])->List[str]:
    found_words = set()
    for word in words:
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == word[0] and dfs(grid,word,i,j,0):
                    found_words.add(word)
    return list(found_words)

if __name__=="__main__":
    grid = [['A', 'B', 'C', 'E'],['S', 'F', 'C', 'S'],['A', 'D', 'E', 'E']]
    words = ["ABCCED", "SEE"]
    print(wordSearch(grid,words),end=" ")
