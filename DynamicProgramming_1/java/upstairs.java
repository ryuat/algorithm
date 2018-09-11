import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.StringTokenizer;

import javax.swing.plaf.basic.BasicInternalFrameTitlePane.MaximizeAction;

/* 
2579
계단 오르기
 */

public class Main{
	
	public static void main(String [] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.parseInt(br.readLine());

		int [][] d= new int[301][3];
		int [] a = new int[301];
		
		
		for(int i=1;i<=n;i++) {
			a[i] = Integer.parseInt(br.readLine());
		}
		
		d[1][0] = 0;
		d[1][1] = a[1];
		d[1][2] = a[1];
		d[2][0] = 0;
		d[2][1] = a[2];
		d[2][2] = a[1]+a[2];
		
		for(int i=3;i<=n;i++) {
			d[i][0] = Math.max(d[i-1][2] , d[n-1][1]); // 이전에 두번 연속 or, 한번 연속
			d[i][1] = Math.max(d[i-2][1] , d[i-2][2]) + a[i]; // 두 칸 전 계단을 한번연속 or 두번연속 + 현재 칸
			d[i][2] = d[i-1][1] + a[i]; // 이전에 1번, 자신 1번
			
			//System.out.println(a[i]);
		}
	
		System.out.println(Math.max(d[n][1],d[n][2])); // 마지막 계단은 반드시 밟아야 하므로
	}
	
}