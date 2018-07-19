import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

/*
 1924번
 2007년
 */
public class Main {
	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner(System.in);
	
		int arr[] = {31, 28, 31, 30, 31, 30 , 31 , 31 , 30 ,31 , 30 ,31};
		String[] day = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
		
		int x = sc.nextInt();
		int y = sc.nextInt();
		// 총 몇일이 지났는지
		// 7일 지났다면, 일요일

			
		int cnt=0; 				 // 12월 가정
		for(int i=x-1;i>0;i--) { // x-1(11)월부터 1월까지 날의 수
			cnt += arr[i-1]; // i월의 날수를 더한다.
		}
		
		cnt += y; // 12월의 일수를 더한다.
		
		System.out.println(day[cnt%7]);
	}
}