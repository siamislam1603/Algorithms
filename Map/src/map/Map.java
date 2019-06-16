
package map;
import java.util.*;
public class Map {

    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        Vector<Integer> v= new Vector<Integer>();
        int n=in.nextInt(),even=0,odd=0;
        for(int i=0;i<n;i++){
            v.add(in.nextInt());
            if(v.get(i)%2==0)
                even++;
            else
                odd++;
        }
        if(even>odd)
            System.out.println("YES");
        else
            System.out.println("NO");
    }
    
}
