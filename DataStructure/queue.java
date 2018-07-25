import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

/* 
  10845 
  큐
 */
public class Main{
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int [] arr = new int[10000];
		int push_idx=0, front=0; // push될 인덱스, 가장 앞 인덱스
		int n = Integer.parseInt(br.readLine());
		StringTokenizer st ;
		String op;
		while(n-->0) {
			st = new StringTokenizer(br.readLine());
			op = st.nextToken();
			
			if(op.equals("push")) {
				int input = Integer.parseInt(st.nextToken());
				arr[push_idx++] = input;// push_idx에 push 후 우측 한칸 이동
			}else if(op.equals("empty")) {
				if(push_idx == front) System.out.println(1);
				else System.out.println(0);
			}else if (op.equals("front")) {
				if(push_idx == front) System.out.println(-1);
				else System.out.println(arr[front]); // 가장 앞 출력 
			}else if (op.equals("back")) { //***
				if(front == push_idx) System.out.println(-1); // 빈 경우
				else System.out.println(arr[push_idx-1]); // 다음 push 해야할 인덱스 바로 앞
			}else if(op.equals("pop")) {
				if(front == push_idx) System.out.println(-1); // 빈 경우
				else {
					System.out.println(arr[front++]); // 가장 앞의 값 출력 후 우측 한 칸 이동
				}
			}else if(op.equals("size")) { // 수정 필요
				System.out.println(push_idx-front);
			}
			
			
		}		
	}
}
