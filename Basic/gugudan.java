import java.io.BufferedReader;
import java.io.InputStreamReader;

/*
 2739
 구구단
 */
public class Main{
	public static void main(String[] args) throws Exception{
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	
		int n = Integer.parseInt(br.readLine());
		
		for(int i=1;i<=9;i++) {
			System.out.println(n + " * " + i + " = " + 2*i);
		}
	}
}