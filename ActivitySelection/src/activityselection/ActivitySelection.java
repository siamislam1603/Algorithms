package activityselection;

import java.util.Scanner;

public class ActivitySelection {
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        System.out.print("Total no of activities:");
        int n=in.nextInt();
        Activity a[]=new Activity[n];
        System.out.println("Enter starting & finishing time of activity:");
        for(int i=0;i<n;i++){
            int s=in.nextInt();
            int f=in.nextInt();
            a[i]=new Activity(s,f);
        }
        maxActivities(a);
    }

    public static void maxActivities(Activity[] a) {
        sortBasedOnFinishing(a);
        System.out.println("Selecting activities:");
        int i=0;
        System.out.println(a[i].start+" "+a[i].finish);
        for(int j=1;j<a.length;j++){
            if(a[j].start>=a[i].finish){
                System.out.println(a[j].start+" "+a[j].finish);
                i=j;
            }
        }
    }

    public static void sortBasedOnFinishing(Activity[] a) {
        for(int i=1;i<a.length;i++){
            Activity key=a[i];
            int j=i-1;
            while(j>=0 && a[j].finish>key.finish){
                a[j+1]=a[j];
                j=j-1;
            }
            a[j+1]=key;
        }
    }
    
}
class Activity{
    int start,finish;
    Activity(int start,int finish){
        this.start=start;
        this.finish=finish;
    }
}