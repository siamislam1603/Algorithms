
package nqueens_17.pkg01.pkg04.pkg124;

import java.util.Scanner;


public class NQueens_170104124 {

    static int n;
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        n=in.nextInt();
        int board[][]=new int[n+1][n+1];
        for(int i=1;i<=n;i++){
            nQueens(board,1,i);
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                System.out.print(board[i][j]+" ");
            }
            System.out.println();
        }
    }

    static boolean nQueens(int[][] board, int row, int col) {
        if(row==n){
            board[row][col]=1;
            return true;
        }
        board[row][col]=1;
        for(int c=1;c<=n;c++){
            if(isSafe(board,row+1,c)){
                if(nQueens(board,row+1,c))
                    return true;
            }
        }
        board[row][col]=0;
        return false;
    }
    static boolean isSafe(int board[][],int row,int col){
        for(int r=row-1,c=col-1;r>=1 && c>=1;r--,c--){
            if(board[r][c]==1)
                return false;
        }
        for(int r=row-1,c=col+1;r>=1 && c<=n;r--,c++){
            if(board[r][c]==1)
                return false;
        }
        for(int r=row-1,c=col;r>=1;r--){
            if(board[r][c]==1)
                return false;
        }
        return true;
    }
    
}
