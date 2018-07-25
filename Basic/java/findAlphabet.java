import java.io.BufferedReader;
import java.io.InputStreamReader;
/* 
   10809
   알파벳 찾기
 */

public class Main{
	public static void main(String[] args) throws Exception{
		
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String s = br.readLine();
		
		int [] arr = new int[26]; // 알파벳 배열 a~z까지의 위치 
		
		for(int i=0;i<arr.length;i++) {  // -1로 초기화
			arr[i] = -1;
		}
		
		// 97~122 97-122+1 26개 a = 97 (배열0), b=98(배열1)
	
		for(int i=0;i<s.length();i++) {
			int c = s.charAt(i) - 'a'; //a=0, b=1..z=25
			if(arr[c] == -1) {
				arr[c] = i;
			}
		}
		
		StringBuilder sb = new StringBuilder();
		for(int i=0;i<arr.length;i++) {
			sb.append(arr[i] +" ");			
		}
		System.out.println(sb);
	}
}
