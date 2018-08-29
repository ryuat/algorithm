import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.StringTokenizer;

import javax.swing.plaf.basic.BasicInternalFrameTitlePane.MaximizeAction;

/* 
11722
가장 큰 감소하는 부분 수열
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
		}
		
		for(int i=1;i<=n;i++) {
			int max = 1;
			for(int j=1;j<i;j++) {
			
				if(a[j] > a[i]) {
					if(d[j] + 1 > max) {
						max = d[j]+1;
						
					}
				}
			}
			d[i] = max;
		}
	
		int res = d[1];
		for(int i=1;i<=n;i++) {
			if(d[i] > res) {
				res = d[i];
			}
		}
		System.out.println(res);
	}
	
}