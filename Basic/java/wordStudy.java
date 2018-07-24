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
		char maxChar='A';
		boolean q = false;
		int maxCnt = -1;
		for(int i=0;i<arr.length;i++) {
			if (arr[i] > maxCnt) {
				maxCnt = arr[i];
				maxChar = (char)(i + 'A');
			}
		}
		int cnt = 0; // 최대값의 개수
		for(int i=0;i<arr.length;i++) {
			if(maxCnt == arr[i])
				cnt++;
		}
		if(cnt>1) {
			System.out.println('?');
		}else {
			System.out.println(maxChar);
		}
		
	}
}
