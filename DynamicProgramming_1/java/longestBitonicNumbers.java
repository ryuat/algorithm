import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.StringTokenizer;

import javax.swing.plaf.basic.BasicInternalFrameTitlePane.MaximizeAction;

/* 
11054
가장 긴 바이토닉 수열
 */

public class Main{
	public static void main(String [] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.parseInt(br.readLine());
		
		int[] a = new int[n+1];
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(int i=1;i<=n;i++) {
			a[i] = Integer.parseInt(st.nextToken());
		}
		
		
		// 증가수열 구하기
		int [] inD = new int[n+1]; //inD[i]: i번째 수를 마지막 수로 하는 증가수열의 최대 길이
		
		
		inD[1] = 1;
		for(int i=1;i<=n;i++) {
			int max = 1; // a[i]가 수열의 시작일 경우, 길이 1
			for(int j=1;j<i;j++) {
				if(a[j] < a[i]) { // 붙일 수 있을 경우
					if(max < inD[j] + 1) { // 최대값 찾기
						max = inD[j] + 1;
					}
				}
			}
			inD[i] = max;
		}
		
		int result = inD[1];
		for(int i=2;i<=n;i++) {
			if(inD[i] > result) {
				result = inD[i];
			}
		}
		
		// 감소 수열 구하기
		
		int [] deD = new int[n+1]; // deD[i]: i번째 수를 시작으로 하는 감소수열
		
		for(int i=n;i>=1;i--) {
			deD[i] = 1;
			for(int j=i+1;j<=n;j++) { // i의 우측 인덱스로 순회
				if(a[j] < a[i] && deD[j]+1 > deD[i]) { // 붙일 수 있고 (붙이고자 하는 수가 더 클 경우), 최대값보다 클 경우 갱신
					deD[i] = deD[j]+1;
				}
			}
		}
		int res=deD[1] + inD[1] - 1;
		for(int i=2;i<=n;i++) {
			if(deD[i] + inD[i] - 1 > res)
				res = deD[i] + inD[i] - 1; // 자신으로 끝나는 증가수열의 최대길이 + 자신으로 시작하는 감소수열의 최대길이 - 1(자신)
		}
		System.out.println(res);
	}
}