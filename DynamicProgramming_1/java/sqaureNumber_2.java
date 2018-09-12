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
			d[i] = i; // d[1] + d[1] + ... + d[1] = d[i] 가정
			for(int j=1;j*j<=i;j++) { // i에서 i보다 작은 제곱수를 뺀다.
				//System.out.println("i: " + i + " " + "j*j: " + j*j);
				if(d[i] > d[i-j*j] + 1) // 제곱수를 뺀값의 최소항 + 제곱수 한개의 min 값 찾기
					d[i] = d[i-j*j] + 1;
			}

		}
		System.out.println(d[n]);
	}
	
}