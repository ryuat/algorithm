import java.util.Scanner;
import java.util.Vector;

/*
 스택
 */
public class Main {
	public static void main(String[] args) throws Exception{
		Main m = new Main();
		
		stackTest lst = new stackTest();
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		
		while(n-->0) {
			String op = sc.next();
			switch(op) {
			case "push":
				int input = sc.nextInt();
				lst.push(input);
				break;
			case "top":
				lst.top();
				break;
			case "size":
				lst.size();
				break;
			case "empty":
				lst.empty();
				break;
			case "pop":
				lst.pop();
				break;
				
			}
		}
	}
}

class stackTest{
	private int top;
	private int [] arr;

	public stackTest() {
		this.top = -1;
		this.arr = new int[10001];
	}
	
	public boolean isEmpty() {
		if(top == -1) { // -1이면 들어온 데이터가 없는 상태
			return true;
		}
		return false;
	}
	public void push(int input) {
		arr[++top] = input; // list 에 input을 넣는다.
	}
	public void pop() {
		if(isEmpty()) {
			System.out.println(-1);
			return;
		}
		System.out.println(arr[top--]); // top위치의 값을 출력하고, 좌측으로 이동
	}
	public void top() {
		if(isEmpty()) {
			System.out.println(-1);
			return;
		}
		System.out.println(arr[top]); // top위치의 값을 출력
	}
	public void size() {
		System.out.println(top+1);
	}
	public void empty() {
		if(isEmpty()) {
			System.out.println(1);
		}else {
			System.out.println(0);
		}
	}
} 
