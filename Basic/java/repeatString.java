import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
/* 
   2675
   문자열 반복
 */

public class Main{
	public static void main(String[] args) throws Exception{
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());
		
		while(t-->0) {
			
			StringTokenizer st = new StringTokenizer(br.readLine());
			
			int n = Integer.parseInt(st.nextToken());
			String str = st.nextToken();
			
			for(int i=0;i<str.length();i++) {
				for(int j=0;j<n;j++) {
					System.out.print(str.charAt(i));
				}
			}
			System.out.println();
		}
	}
}
