import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.StringTokenizer;

import javax.swing.plaf.basic.BasicInternalFrameTitlePane.MaximizeAction;

/* 
 9465
 스티커
 */

public class Main{
	
	public static void main(String[] args) throws Exception{
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int t = Integer.parseInt(br.readLine());
		
		while(t-->0) {
			int n =   Integer.parseInt(br.readLine());
//			System.out.println("n: "+n) ;
			int a[][] = new int[n+1][2]; // a[i][j]: i열 j번째 점수
			int d[][] = new int[n+1][3]; // d[i][j]: i열 j번째(0은 선택x) 스티커를 선택했을 경우의 최대 점수
			
			for(int i=0;i<=1;i++){
				StringTokenizer st = new StringTokenizer(br.readLine());
				for(int j=1;j<=n;j++) {
					a[j][i] = Integer.parseInt(st.nextToken());
				}
			}
			
			d[1][0] = 0;
			d[1][1] = a[1][0];
			d[1][2] = a[1][1];
			for(int i=2;i<=n;i++) {
				d[i][0] = Math.max(Math.max(d[i-1][0], d[i-1][1]), d[i-1][2]);
				d[i][1] = Math.max(d[i-1][0], d[i-1][2]) + a[i][0];
				d[i][2] = Math.max(d[i-1][0], d[i-1][1]) + a[i][1];
			}
			
			int max = Math.max(Math.max(d[n][0], d[n][1]), d[n][2]);
			System.out.println(max);
		}
		
	}
}


