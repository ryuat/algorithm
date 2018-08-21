import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.StringTokenizer;

import javax.swing.plaf.basic.BasicInternalFrameTitlePane.MaximizeAction;

/* 
 2165
 포도주
 */

public class Main{
	public static void main(String[] args) throws Exception{
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int [] a = new int[10001];
		int [][] d = new int[10001][3];
		
		
		for(int i=1;i<=n;i++) {
			a[i] = Integer.parseInt(br.readLine());
		}
		
		d[1][0] = 0;
		d[1][1] = a[1];
		d[1][2] = a[1];
		for(int i=2;i<=n;i++) {
			d[i][0] = Math.max(Math.max(d[i-1][1], d[i-1][2]), d[i-1][0]); // 이 부분 확인
			d[i][1] = d[i-1][0] + a[i];
			d[i][2] = d[i-1][1] + a[i];
		}
		
		int result = Math.max(d[n][0],Math.max(d[n][1], d[n][2]));
		System.out.println(result);
	}
}


