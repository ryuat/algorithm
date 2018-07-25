import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

/* 
  10866 
  덱
 */
public class Main{
	public static void main(String[] args) throws Exception{
		MyDeque dq = new MyDeque();
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		
		while(n-->0) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			String op = st.nextToken();
			
			int input;
			switch (op) {
			case "push_back":
				input = Integer.parseInt(st.nextToken());
				 dq.push_back(input);
				break;
			case "push_front":
				input = Integer.parseInt(st.nextToken());
				 dq.push_front(input);
				break;
			case "pop_front":
				System.out.println(dq.pop_front());
				break;
			case "pop_back":
				System.out.println(dq.pop_back());
				break;
			case "size":
				System.out.println(dq.size());
				break;
			case "empty":
				System.out.println(dq.empty());
				break;
			case "front":
				System.out.println(dq.front());
				break;
			case "back":
				System.out.println(dq.back());
				break;
			default:
				break;
			}
		}
		
			
		
	}
}



class MyDeque {
//	private int front; // 가장 앞의 인덱스
	private int nextFront = 20002/2;  // 다음 입력될 앞쪽 인덱스
	private int nextBack = 20002/2+1;
	private int size = 0;
//	private int nextBack;  // 다음 입력될 뒷쪽 인덱스
	private int [] arr = new int[20002];
	
	
	// 노말 메서드
	public void push_front(int x) {
		arr[nextFront--] = x;
		size++;
	}
	public void push_back(int x) {
		arr[nextBack++] = x;
		size++;
	}
	public int front() {
		if(size==0) return -1;
		return arr[nextFront+1]; 
	}
	public int back() {
		if(size==0) return -1;
		return arr[nextBack-1];
	}
	public int pop_front() {
		if(size==0) return -1;
		int tmp = arr[nextFront+1];
		nextFront++;
		size--;
		return tmp;		
	}
	public int pop_back() {
		if(size==0) return -1;
		int tmp = arr[nextBack-1];	
		nextBack--;
		size--;
		return tmp;
	}
	public int size() {
		return size;
	}
	public int empty() {
		return size > 0 ? 0:1;
	}
	
}
