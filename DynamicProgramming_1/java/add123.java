import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.StringTokenizer;

/* 
 9095
 1, 2, 3 더하기
 */
public class Main{
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int t = Integer.parseInt(br.readLine());
		
		while(t-->0) {
			int n = Integer.parseInt(br.readLine());
			
			int[] d = new int[n+5];
		
			d[1] = 1;
			d[2] = 2;
			d[3] = 4;
			
			for(int i=4;i<=n;i++) {
				d[i] = (d[i-1] + d[i-2] + d[i-3])%10007;
				
			}
			System.out.println(d[n]);
		}
	}
}


