import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Main {
	public static void main(String args[]) throws Exception{
	
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int T = Integer.parseInt(br.readLine());
		
		while(T-->0) {
			int n = Integer.parseInt(br.readLine());
			long[] d = new long[101];
			
			d[1] = 1;
			d[2] = 1;
			d[3] = 1;
			d[4] = 2;
			d[5] = 2;
			for(int i=6;i<=n;i++) {
				d[i] = d[i-1] + d[i-5];
			}
			System.out.println(d[n]);
		}
	}
}
