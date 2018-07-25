import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/* 
  2908 
  상수
 */
public class Main{
	public static void main(String[] args) throws Exception{

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
											   
		StringTokenizer st = new StringTokenizer(br.readLine());
		String str1 = st.nextToken();
		String str2 = st.nextToken();
		
		int s1=0, s2=0;
		for(int i=2;i>=0;i--) {	
			s1 = s1*10 + (int)(str1.charAt(i) - '0');
			s2 = s2*10 + (int)(str2.charAt(i) - '0');
		}
		System.out.println((s1 > s2) ? s1:s2);
		
		
	}
}
