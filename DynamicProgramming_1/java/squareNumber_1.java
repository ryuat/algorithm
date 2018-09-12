import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.StringTokenizer;

import javax.swing.plaf.basic.BasicInternalFrameTitlePane.MaximizeAction;

/* 
1699
제곱수의 합
 */

public class Main{
	
	public static void main(String [] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.parseInt(br.readLine());
		
		int [] d = new int [n+1];
		
		d[1] = 1;
		
		for(int i=2;i<=n;i++) {
			int min = Integer.MAX_VALUE;

			for(int j=1;j<=i/2;j++) {
				if(d[j] + d[i-j] < min) 
					min = d[j]+d[i-j];
			}
			double sqrtI = Math.sqrt(i);
			if(sqrtI == Math.floor(sqrtI)) // 제곱근이 정수이면
				d[i] = 1;
			else
				d[i] = min;

			//System.out.println("i: " +i + " d[i]: " + d[i] );
			//System.out.println("-----------------------");
		}
		System.out.println(d[n]);
	}
	
}