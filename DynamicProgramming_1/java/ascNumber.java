import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.StringTokenizer;

/* 
 11507
 오르막 수
 */

public class Main{
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	
	
		int n = Integer.parseInt(br.readLine());
		
		int[][] d  = new int[n+1][10]; // d[n][j]: n자리의 오르막 수 중 j로 끝나는 수의 개수
		
		for(int i=0;i<=9;i++) { // 1자리의 오르막 수 중 i로 끝나는 수의 개수는 1
			d[1][i] = 1; 
 		}
	
		// i자리의 오르막 수 각각에 대해 0으로 끝나는 수부터 9로 끝나는 수까지 개수 구하기
		for(int i=2;i<=n;i++) { // 2자리의 오르막 수부터 n자리의 오르막 수까지 
//			System.out.println("****d["+i+"] 구하기 ****" );
			for(int j=0;j<=9;j++) { 
//				System.out.println("----d["+i+"]["+j+"] 구하기 ----" );
				for(int k=0;k<=j;k++) { // j보다 작을 때 까지 더하기
					d[i][j]+=d[i-1][k]%10007;
					d[i][j]%=10007;
//					System.out.println("d["+(i-1)+"]["+k+"]");
				}
			}
		}
		int sum =0;
		for(int i=0;i<=9;i++) {
			sum += d[n][i]%10007;
			sum %= 10007;
		}
		System.out.println(sum);
	}
}


