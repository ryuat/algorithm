import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

/* 
 11656
 접미사 배열
 */
public class Main{
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str = br.readLine();
	
		String [] arr = new String[str.length()];
		
		StringBuilder sb = new StringBuilder();
		
		for(int i=0;i<str.length();i++) {
			arr[i] = str.substring(i, str.length());
		}
		
		for(int i=0;i<str.length();i++) { // 버블정렬
			for(int j=0;j<str.length()-1-i;j++) {
				if(arr[j].compareTo(arr[j+1]) > 0) {
					String tmp = arr[j];
					arr[j] = arr[j+1];
					arr[j+1]  = tmp;
				}
			}
		}
	
		for(int i=0;i<arr.length;i++) {
			System.out.println(arr[i]);
		}
	}
}


