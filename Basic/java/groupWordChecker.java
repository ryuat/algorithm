import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
/* 
   1316
   그룹단어 체커
 */

public class Main{
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.parseInt(br.readLine());
		// 122~97 => 26개

		
		int resCnt = 0; // 그룹문자 개수
		while(n-->0) {
			int [] arr = new int[26];
			
			// 배열을 -1로 초기화, 아직 한 번도 나타나지 않음을 의미
			for(int i=0;i<arr.length;i++) {
				arr[i] = -1;
			}
			
			String str = br.readLine();
			boolean status = true;
			for(int i=0;i<str.length();i++) {
				int charN = str.charAt(i) - 'a'; // 현재 문자를 숫자로 변환
				if(arr[charN] ==-1){ // 문자 charN이 아직 나타나지 않았다면
					arr[charN] = i; // 현재 문자 charN의 위치 입력
				}else if (i - arr[charN] > 1){ // 현재 문자 charN의 위치 i와 최근 위치 arr[charN]의 거리가 2이상일 경우
					status = false;
					break;
				}else { 
					arr[charN] = i; // 문자 charN의 현재 위치 i를 입력
				}
			}
//			System.out.println(status);
//			resCnt = status ? resCnt=+1:resCnt; // 그룹단어이면 개수 추가
			if(status) {
				resCnt++;
			}
		}
		System.out.println(resCnt);
	}
}
