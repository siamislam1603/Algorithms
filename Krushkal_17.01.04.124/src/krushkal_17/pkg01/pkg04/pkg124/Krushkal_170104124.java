package krushkal_17.pkg01.pkg04.pkg124;
import java.util.*;
public class Krushkal_170104124 {
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        int nodeNo,edgeNo;
        nodeNo=in.nextInt();
        edgeNo=in.nextInt();
        Graph g=new Graph(nodeNo,edgeNo);
        g.krushkalMST();
    }

}
class Graph{
    int v,e,mstCost=0;
    Scanner in=new Scanner(System.in);
    Edge edge[];
    Subset subset[];
    Graph(int nodeNo,int edgeNo){
        v=nodeNo;
        e=edgeNo;
        edge=new Edge[e];
        for(int i=0;i<e;i++){
            edge[i]=new Edge();
            edge[i].source=in.nextInt();
            edge[i].dest=in.nextInt();
            edge[i].wt=in.nextInt();
        }
    }
    class Edge{
        int source,dest,wt;
    }
    class Subset{
        int parent,rank;
    }
    int findRoot(Subset subset[],int u){
        if(u!=subset[u].parent){
            return findRoot(subset,subset[u].parent);
        }
        return subset[u].parent;
    }
    void krushkalMST(){
        sort();
        subset=new Subset[v];
        for(int i=0;i<v;i++){
            subset[i]=new Subset();
            subset[i].parent=i;
            subset[i].rank=0;
        }
        System.out.println("MST::::\n");
        for(int i=0;i<e;i++){
            int xRoot=findRoot(subset,edge[i].source);
            int yRoot=findRoot(subset,edge[i].dest);
            if(xRoot!=yRoot){
                union(xRoot,yRoot,subset);
                System.out.println(edge[i].source+" "+edge[i].dest+" "+edge[i].wt);
                mstCost+=edge[i].wt;
            }
        }
        System.out.println("\nMST COST:"+mstCost);
    }
    void union(int xRoot,int yRoot,Subset subset[]){
        xRoot=findRoot(subset,xRoot);
        yRoot=findRoot(subset,yRoot);
        if(subset[xRoot].rank>subset[yRoot].rank){
            subset[yRoot].parent=xRoot;
        }
        else if(subset[xRoot].rank<subset[yRoot].rank){
            subset[xRoot].parent=yRoot;
        }
        else{
            subset[yRoot].parent=xRoot;
            subset[xRoot].rank++;
        }
    }
    void sort(){
        for (int i=1; i<e; ++i)
        {
            Edge temp=edge[i];
            int j = i-1;
            while (j>=0 && edge[j].wt > temp.wt)
            {
                edge[j+1] = edge[j];
                j = j-1;
            }
            edge[j+1] = temp;
        }
        System.out.println("Sort according to weight:");
        for(int i=0;i<e;i++){
            System.out.println(edge[i].wt+" "+edge[i].source+" "+edge[i].dest);
        }
    }
}

