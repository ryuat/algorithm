import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

/* 
 1463
 1로 만들기 (for)
 */
public class Main{
	
	public static void main(String[] args) throws Exception{
	
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		
		int[] dp = new int[1000001]; 
	
		dp[1] = 0;
		
		for(int i=2;i<=n;i++) { // 2번부터 n번까지
			if(i%6==0) {
				dp[i] =  Math.min(Math.min(dp[i/3], dp[i/2]), dp[i-1]) + 1;
			}else if(i%2==0) {
				dp[i] = Math.min(dp[i-1], dp[i/2]) + 1;
			}else if(i%3==0) {
				dp[i] = Math.min(dp[i-1], dp[i/3]) + 1;
			}else {
				dp[i] = dp[i-1] + 1;
			}
		}
		
		System.out.println(dp[n]);
	}
}


