import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	public static void main(String [] args) throws Exception {
		

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	
		int n = Integer.parseInt(br.readLine());		
		int[] d = new int[n+1];
		
		if(n==1) {
			System.out.println(0);
			return;
		}
		d[1] = 0;
		d[2] = 3;
		for(int i=3;i<=n;i++) {
			d[i] = d[i-2];
			for(int c=1; 2*c<=i;c++) {
				if(2*c == i) {
					d[i] += 2;
				}else {
					d[i] += d[i-2*c]*2;
				}
			}
		}	
		System.out.println(d[n]);
	}
}
