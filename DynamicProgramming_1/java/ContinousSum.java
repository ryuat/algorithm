import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.StringTokenizer;

import javax.swing.plaf.basic.BasicInternalFrameTitlePane.MaximizeAction;

/* 
1912
연속합
 */

public class Main{
	public static void main(String [] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	
		int n = Integer.parseInt(br.readLine());
		int [] a = new int[n+1];
		int [] d = new int[n+1]; // d[i]: i번째 수를 마지막으로 하는 연속합 최대 
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		
		for(int i=1;i<=n;i++) {
			a[i] = Integer.parseInt(st.nextToken());
		}
		
		d[1] = a[1];
		for(int i=2;i<=n;i++) {
			d[i] = (d[i-1] >= 0)? d[i-1]+a[i]:a[i]; // 이전 수열의 합이 0보다 작으면 붙이지 않음
			//System.out.println("d[i]:" + d[i]);
		}
		int res = d[1];
		for(int i=2;i<=n;i++) {
			if(d[i] > res) {
				res = d[i];
			}
		}
		System.out.println(res);
	}
}