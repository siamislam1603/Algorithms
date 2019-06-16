
package lcs;

import java.util.Scanner;

public class LCS {

    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        String x,y;
        x=in.nextLine();
        y=in.nextLine();
        longestCommonSubsequence(x,y);
    }

    public static void longestCommonSubsequence(String x, String y) {
       int l[][]=new int[x.length()+1][y.length()+1];
       for(int i=0;i<=x.length();i++){
           for(int j=0;j<=y.length();j++){
               if(i==0 || j==0){
                   l[i][j]=0;
               }
               else if(x.charAt(i-1)==y.charAt(j-1)){
                   l[i][j]=l[i-1][j-1]+1;
               }
               else{
                   l[i][j]=Max(l[i][j-1],l[i-1][j]);
               }
           }
       }
        System.out.println("length of longest common subsequence:"+l[x.length()][y.length()]);
        int len=l[x.length()][y.length()];
        char lcs[]=new char[len+1];
        int i=x.length();
        int j=y.length();
        while(i>0 && j>0){
            if(x.charAt(i-1)==y.charAt(j-1)){
                lcs[len--]=x.charAt(i-1);
                i--;
                j--;
            }
            else if(l[i][j-1]>l[i-1][j]){
                j--;
            }
            else
                i--;
        }
        System.out.println(lcs);
    }

    public static int Max(int a, int b) {
        if(a>b)
            return a;
        else 
            return b;
    }
    
}
