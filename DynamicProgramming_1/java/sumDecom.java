import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
	public static void main(String args[]) throws Exception{
	
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String ss = br.readLine();
		
		StringTokenizer st = new StringTokenizer(ss," ");
		
		int n = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		
		long [][] d = new long[n+1][201];
		
		d[0][0] = 1;
	
		for(int i=0;i<=n;i++) {
			for(int j=1;j<=k;j++) {
				d[i][j] = 0;
				for(int c=0;c<=i;c++) {
					//System.out.println("d["+i +"][" +j +"]+= d[" +c +"][" + (j-1) +"] = " + d[c][j-1]);
					d[i][j] = d[i][j]%1000000000 + d[c][j-1]%1000000000; 
				}
				
			}
		}
		System.out.println(d[n][k]%1000000000);
	}
}