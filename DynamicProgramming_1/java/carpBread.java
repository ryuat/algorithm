import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.StringTokenizer;

/* 
 11052
 붕어빵 판매하기
 */
public class Main{
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.parseInt(br.readLine());
		int[] p = new int[n+1]; // p[i]: i개 세트 가격
		int [] d = new int[n+1];  // d[i]: i개 최대수익
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		for(int i=1;i<=n;i++) {
			p[i] = (int)Integer.parseInt(st.nextToken());
		}
		
		d[0] = 0;
		for(int i=1;i<=n;i++) {
//			System.out.println("**d[" + i + "] 구하기 **");
			int max =0;
			for(int k=0;k<=i-1;k++) {
				if(d[k] + p[i-k] > max){
					max = d[k] + p[i-k];	
				}
//				System.out.println("d[" + k + "]" + "p[" + (i-k) +"]");
				d[i] = max;
			}
		}
		
		System.out.println(d[n]);
		
	}
}


