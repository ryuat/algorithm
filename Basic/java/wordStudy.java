import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
/* 
   1157
   단어공부
 */

public class Main{
	public static void main(String[] args) throws Exception{
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String str = br.readLine();
		
		int arr[] = new int[26];
		
		str = str.toUpperCase();
		
		for(int i=0;i<str.length();i++) {
			arr[str.charAt(i) - 'A'] += 1;
		}
		char maxChar= 0 + 'A'; // 'A'
		
		int maxCnt = -1;
		
		boolean result = true;
		for(int i=0;i<arr.length;i++) {
			if (arr[i] > maxCnt) {
				maxCnt = arr[i];
				maxChar = (char)(i + 'A');
				result = false;
			}else if(arr[i] == maxCnt) {
				result = true;
			}
		}

		System.out.println(result ? "?":maxChar);
	}
}
