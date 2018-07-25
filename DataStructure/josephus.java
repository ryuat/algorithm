import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.StringTokenizer;

/* 
   1158
   조세퍼스
 */
public class Main{
	public static void main(String[] args) throws Exception{
		Queue<Integer> q = new LinkedList<Integer>();
		
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		int m = sc.nextInt();
	
		System.out.print('<');
		for(int i=1;i<=n;i++) {
			q.add(i);
		}
		for(int i=1;i<=n*m;i++) {
			if(i%m == 0) {
				if(i==n*m) System.out.print(q.element());
				else System.out.print(q.element()+", ");
				q.remove();
			}else {
				q.add(q.element()); // 첫번째 값을 뒤쪽에 추가
				q.remove(); // 첫번째 값 제거
			}
		}
		System.out.print('>');		
	}
}
