import java.util.Scanner;

public class SelectionSort {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int[] a =  new int[n+1];
        for(int i=1; i<=n; i++){
            a[i] = in.nextInt();
        }
        for(int j=1; j<=n-1; j++){
            int min = j;
            for(int i=j+1; i<=n; i++){
                if(a[min] > a[i]){
                    min = i;
                }
            }
            int restore = a[j];
            a[j] = a[min];
            a[min] = restore;
        }
        for(int i=1; i<=n; i++){
            System.out.printf(a[i] + " ");
        }
    }

}