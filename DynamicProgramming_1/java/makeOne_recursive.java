import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

/* 
 1463
 1로 만들기 (재귀, 시간초과)
 */
public class Main{
	
	public static int dp(int i) {
//		System.out.println("i:" + i);
		if(i==3) return 1;
		else if(i==2) return 1;
		else if(i==1) return 0;
		
		if(i%6==0) {
			return Math.min(Math.min(Main.dp(i/3), Main.dp(i/2)), Main.dp(i-1)) + 1;
		}else if(i%2==0) {
			return Math.min(Main.dp(i-1), Main.dp(i/2)) + 1;
		}else if(i%3==0) {
			return Math.min(Main.dp(i-1), Main.dp(i/3)) + 1;
		}else {
			return Main.dp(i-1) + 1;
		}
	}
	
	
	public static void main(String[] args) throws Exception{
	
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		System.out.println(dp(n));
		
	}
}


