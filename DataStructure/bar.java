import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.Stack;

/* 
  10799
  쇠막대기
  */ 
public class Main{
	public static void  main(String[] args) throws Exception{
		
		Stack<Character> stack = new Stack<Character>();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		//int n = Integer.parseInt(br.readLine());
		
		String str = br.readLine();
		
		char before_c= '-'; // 임의의 문자
		int result = 0;
		for(int i=0;i<str.length();i++) {
			char c = str.charAt(i);
			
			if(c == '(') { // 3번 경우 무조건 push
				stack.push(c);
			}else { // ')' 일 경우
				if(before_c == ')') { // 연속으로 ')'가 나올 경우
					stack.pop();
					result += 1;
				}else { // '(' , ')' 가 만났을 경우
					stack.pop(); // '('를 pop한 후
					result += stack.size();  // '('의 개수만큼 쇳조각 추가
				}
			}
			before_c = c;
		}
		System.out.println(result);
	}
}