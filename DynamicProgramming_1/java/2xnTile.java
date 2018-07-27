import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.StringTokenizer;

/* 
 11726
 2×n 타일링 
 */
public class Main{
	
	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		int[] d = new int[1001];
		
		d[1] = 1;
		d[2] = 2;
		for(int i=3;i<=1000;i++) {
			d[i] = (d[i-1] + d[i-2])%10007;
		}
		
		System.out.println(d[n]);
	}
}


