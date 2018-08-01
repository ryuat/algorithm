import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.StringTokenizer;

/* 
 10844
 쉬운계단수
 */
public class Main{
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	
		int n = Integer.parseInt(br.readLine());
		
		int[][] d  = new int[n+1][10];
		
		d[1][0] = 0;
		for(int i=1;i<=9;i++) {
			d[1][i] = 1;
		}
		
		for(int i=2;i<=n;i++) { // 2자리 부터 n자리까지
			for(int j=0;j<=9;j++) { // 끝자리가 j(0~9)로 끝나는 경우
				d[i][j] = ((j-1>=0)? d[i-1][j-1]%1000000000:0) + ((j+1<=9) ? d[i-1][j+1]%1000000000:0);
			}
		}
		
		int sum = 0;
		for(int i=0;i<10;i++) {
			sum += d[n][i]%1000000000;
			sum %= 1000000000;
		}
		
		System.out.println(sum%1000000000);
	}
}


