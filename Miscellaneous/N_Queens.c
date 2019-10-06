/* N Queen problem.*/

#include <stdio.h>
#include <stdlib.h>

#define attack(i,j) (board[j] == i || abs(board[j] - i) == column - j) // Macro use to check if a queen attack a column, line or a diagonal on the chessboard

int count = 0; // Count is the number of all possible solution of the problem
void Solve_NQ (int n, int column, int *board)
{
	if (column == n) {
		printf("\nSolution No. %d\n\n", ++count);
		for (int i = 0; i < n; i++, putchar('\n'), putchar('\n'))
			for (int j = 0; j < n; j++) {
				putchar(j == board[i] ? 'Q' : ((i+j) & 1) ? 'x' : 'x');
				putchar(' ');
			}
		return;
	}

	
	for (int i = 0, j = 0; i < n; i++) {
		for (j = 0; j < column && !attack(i,j); j++);
		if (j < column) continue;

		board[column] = i;
		Solve_NQ(n,column + 1, board);
		
	}
}


int main ()
{
	int n; // n represents the number of queen on the board and also the length of the edge
	printf("\nPlease enter the length of edge.\n\n");
	printf(">> ");
	scanf("%d", &n);
	
	if (n < 4) {
		printf("\nNo solution.\n");
		return -1;
	}
	printf("\nThe size of bord is %d\n ", n*n);
	int board[n];

	Solve_NQ(n,0,board); // Start at the leftmost column
	
	putchar('\n');
	return 0;

}

