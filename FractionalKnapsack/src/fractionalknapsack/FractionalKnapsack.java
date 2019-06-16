
package fractionalknapsack;

import java.util.Scanner;

public class FractionalKnapsack {

    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        System.out.print("Enter how many items:");
        int n=in.nextInt();
        System.out.print("Enter total capacity:");
        float c=in.nextInt();
        Item item[]=new Item[n];
        System.out.println("Enter weights & values:");
        for(int i=0;i<n;i++){
            float a=in.nextFloat();
            float b=in.nextFloat();
            item[i]=new Item(a,b);
        }
        getMaxProfit(item,c);
    }

    public static void getMaxProfit(Item[] item, float c) {
        sortValPerWtRatio(item);
        double maxProfit=0;
        for(int i=0;i<item.length;i++){
            if(c-item[i].wt >=0){
                c=c-item[i].wt;
                maxProfit+=item[i].val;
            }
            else{
                maxProfit+=(c/item[i].wt)*item[i].val;
                c=c-((c/item[i].wt)*item[i].wt);
            }
        }
        System.out.println("Max Profit:"+maxProfit);
    }

    public static void sortValPerWtRatio(Item[] item) {
        int j;
        for(int i=1;i<item.length;i++){
            Item key=item[i];
            j=i-1;
            while(j>=0 && item[j].ratio < key.ratio){
                item[j+1]=item[j];
                j=j-1;
            }
            item[j+1]=key;
        }
    }
    
}
class Item{
    float wt,val,ratio;
    Item(float wt,float val){
        this.wt=wt;
        this.val=val;
        ratio=val/wt;
    }
}