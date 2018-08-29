import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.StringTokenizer;

import javax.swing.plaf.basic.BasicInternalFrameTitlePane.MaximizeAction;

/* 
11055
가장 큰 증가하는 부분 수열
 */

public class Main{
	public static void main(String[] args) throws Exception{
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());

		int [] a = new int[n+1];
		int [] d = new int[n+1];
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		for(int i=1;i<=n;i++) {
			a[i] = Integer.parseInt(st.nextToken());
			//System.out.println(a[i] + " ");
		}

		d[1] = a[1];
		for(int i=2;i<=n;i++) {
			int max = a[i]; // 붙일 수 없을 경우 자신이 시작.
			for(int j=1;j<i;j++) {
				if(a[i] > a[j]) { // 붙일 수 있을 때
					if(d[j]+a[i] > max) { // 최대 찾기 
						max = d[j] + a[i];
					//	System.out.println(i+ "/" +j+"번째"+ "max: " + max);
					}
				}
			d[i] = max;
			}
		}
		
		int max=0;
		for(int i=1;i<=n;i++) {
			if(max < d[i]) {
				max = d[i];
			}
		}
		System.out.println(max);
		}
	}