package knapsack_01_17.pkg01.pkg04.pkg124;

import java.util.Scanner;

public class Knapsack_01_170104124 {
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        int n,cap;
        n=in.nextInt();
        cap=in.nextInt();
        int p[]=new int[n];
        int w[]=new int[n];
        for(int i=0;i<n;i++){
            p[i]=in.nextInt();
            w[i]=in.nextInt();
        }
        int memo[][]=new int[n][cap+1];
        for(int i=0;i<n;i++){
            memo[i][cap]=-1;
        }
        int profit=knapSack(0,p,w,cap,n,memo);
        System.out.println(profit);
    }

    public static int knapSack(int pos, int[] p, int[] w, int cap,int n,int memo[][]) {
        if(pos==n)
            return 0;
        int p1=0;
        int p2=0;
        if(w[pos]<=cap){
            p1=p[pos]+knapSack(pos+1,p,w,cap-w[pos],n,memo);//take
        }
        p2=knapSack(pos+1,p,w,cap,n,memo);//if not take then
        int m;
        if(p1>p2)
            m=p1;
        else 
            m=p2;
        if(memo[pos][cap]!=-1){
            memo[pos][cap]=m;
            return memo[pos][cap];
        }
        return m;
    }
    
}