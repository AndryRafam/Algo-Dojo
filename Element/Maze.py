# Can you exit the Maze
# https://edabit.com/challenge/PzyssSgqopkBjzTY2

def dfs(maze,i,j)->bool:
	N = len(maze)
	M = len(maze[0])
	row = [-1,0,0,1]
	col = [0,-1,1,0]
	if(i<0 or i>=N or j<0 or j>=M or maze[i][j]!=0):
		return False
	if(maze[i][j]==0):
		maze[i][j]=1
		if(i==N-1 and j==M-1):
			return True
		for k in range(4):
			if(dfs(maze,i+row[k],j+col[k])):
				return True
	return False

def can_exit(maze)->bool:
	if(dfs(maze,0,0)==False):
		return False
	return True


if __name__=='__main__':
	maze = [[0, 1, 1, 1, 1, 1, 1],
  			[0, 0, 1, 1, 0, 1, 1],
  			[1, 0, 0, 0, 0, 1, 1],
  			[1, 1, 1, 1, 0, 0, 1],
  			[1, 1, 1, 1, 1, 0, 0]]
	print(can_exit(maze),end="\n")
