// Longest commons subsequence

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/param.h>

const int LIM = 100000;

int LCS(char *s, char *t) {
    int m = strlen(s);
    int n = strlen(t);
    int dp[m+1][n+1];
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            if(i==0 || j==0) {
                dp[i+1][j+1]=0;
            }
            else if(*(s+i)==*(t+j)) {
                dp[i+1][j+1]=dp[i][j]+1;
            }
            else {
                *(*(dp+i+1)+j+1)=MAX(dp[i][j+1],dp[i+1][j]);
            }
        }
    }
    return dp[m][n];
}

int main() {
    char *s = malloc(LIM*sizeof(char));
    char *t = malloc(LIM*sizeof(char));
    fgets(s,LIM,stdin);
    fgets(t,LIM,stdin);
    printf("%d\n",LCS(s,t));
    free(s);
    free(t);
    return 0;
}
