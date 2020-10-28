# Mini Sudoku 
# https://edabit.com/challenge/JevwpdjTnoJT5t29F

def isMiniSudoku(square:list)->bool:
    ct = [None for i in range(len(square))]
    
    for i in range(len(square)):
        for j in range(len(square)):
            if(square[i][j]<1 or square[i][j]>9):
                return False
            ct.append(square.count(square[i][j]))
    
    for x in ct:
        if(x!=1):
            return True
            
if __name__=='__main__':
    arr = [[1,3,2],[9,7,8],[4,5,6]] # True
    print(isMiniSudoku(arr),end="\n")
