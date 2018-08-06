import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.StringTokenizer;

/* 
 2193
 이친수
 */

public class Main{
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));


		int n = Integer.parseInt(br.readLine());
		long [][] dp = new long[n+1][2];
		
		dp[1][0] = 0;
		dp[1][1] = 1;

		for(int i = 2;i<=n;i++) {
			dp[i][0] += dp[i-1][0] + dp[i-1][1];
			dp[i][1]  = dp[i-1][0];
		}
		
		System.out.println(dp[n][0] + dp[n][1]);
	}
}


