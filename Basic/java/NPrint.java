import java.io.BufferedReader;
import java.io.InputStreamReader;

/*
 2742
 기찍N
 */
public class Main{
	public static void main(String[] args) throws Exception{
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	
		int n = Integer.parseInt(br.readLine());
		
		for(int i=n;i>=1;i--) {
			System.out.println(i);
		}
	}
}