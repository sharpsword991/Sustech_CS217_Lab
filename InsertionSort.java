import java.util.Scanner;

public class InsertionSort {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int[] a =  new int[n+1];
        for(int i=1; i<=n; i++){
            a[i] = in.nextInt();
        }
        for(int j=1; j<=n; j++){
            int key = a[j];
            int i=j-1;
            while(i>0 && key < a[i]){
                a[i+1] = a[i];
                i--;
            }
            a[i+1] = key;
        }
        for(int i=1; i<=n; i++){
            System.out.printf(a[i] + " ");
        }
    }
}