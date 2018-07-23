import java.util.Scanner;
import java.util.Stack;

public class Main{
	public static void  main(String[] args) {
		
		Stack<Character> st = new Stack<Character>();
		
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		
		String str;
		
		
		while(n-->0) {
			str = sc.next();
			st.clear();;
		
			boolean result = true;
			for(int i=0;i<str.length();i++) {
				char c = str.charAt(i); // 입력 받은 문자열 중 문자 하나
				if(c == '(') {  // 문자가 "(" 이면 push
					st.push(c);
				}else if(c==')') { // 문자가 ")" 이면 "(" 있는지 확인 후 pop
					if(st.isEmpty()) {
						result = false;
						break;
					}else {
						st.pop();
					}
				}			
			}
			// 모두 진행 후 stack에 "(" 가 남아있을 경우
			if(st.isEmpty() == false){
				result = false;
			}
			
			if(result) {
				System.out.println("YES");	
			}else {
				System.out.println("NO");
			}
		}
	}
}