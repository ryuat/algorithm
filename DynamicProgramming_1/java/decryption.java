import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
	public static void main(String args[]) throws Exception{
		int mod = 1000000;
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		char[] num = (" "+ br.readLine()).toCharArray();
		int n = num.length-1;
			
		int[] dp = new int[n+1]; // dp[i][j] : i번째 까지의 수를 해석하는 경우의 수

		if (n == 1 && Integer.parseInt(num[1]+"") == 0) { // 0 하나가 입력될 경우
			System.out.println(0);
			return;
		}
			
		dp[0] = 1; // 불가능한 경우이지만 점화식을 만족시키기 위해 1 입력
		dp[1] = 1;
		for(int i=2;i<=n;i++) {
			int curNum = Integer.parseInt(num[i]+"");
			
			if(1 <= curNum && curNum <= 9) { // 마지막 자리가 1~9일 경우 => 앞자리 수 까지의 경우의 수
				dp[i] = dp[i-1]%mod;
			}
			
			int curNum_two = Integer.parseInt(num[i-1] + "" + num[i]);
			if(10 <= curNum_two && curNum_two <= 26) { // 마지막 두 자리가 10~26일 경우 두자리 앞 자리 수 까지의 경우의 수
				dp[i] += dp[i-2]%mod;
			}
		}
		System.out.println(dp[n]%mod);
	}
}