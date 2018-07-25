import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.Stack;
import java.util.StringTokenizer;

/* 
  1406
  에디터
  */
public class Main {
	public static void main(String[] args) throws Exception {

		Stack<Character> stackR = new Stack<Character>();
		Stack<Character> stackL = new Stack<Character>();

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		String str = br.readLine();
		int n = Integer.parseInt(br.readLine());

		for (int i = 0; i < str.length(); i++) {
			stackL.push(str.charAt(i)); // 처음 커서는 맨 왼쪽에 있으므로, 전부 우측 스택에 push
		}

		while (n-- > 0) {
			StringTokenizer st = new StringTokenizer(br.readLine()); // P x

			String op = st.nextToken();
			if (op.equals("P")) {
				char input = st.nextToken().charAt(0);
				stackL.push(input);
			} else if (op.equals("L")) {
				if (stackL.isEmpty() == false) { // 왼쪽 스택이 비어있지 않은 경우

					stackR.push(stackL.pop()); // 왼쪽 스택의 첫번째 값을 오른쪽 스택에 push
				}
				;
			} else if (op.equals("D")) {
				if (stackR.isEmpty() == false) { // 오른쪽 스택이 비어있지 않은 경우
					stackL.push(stackR.pop()); // 오른쪽 스택의 첫번째 값을 왼쪽 스택에 push
				}
				;
			} else if (op.equals("B")) {
				if (stackL.isEmpty() == false) {
					stackL.pop();
				}
			}
		}

		while (stackL.isEmpty() == false) {
			stackR.push(stackL.pop());
		}

		StringBuilder sb = new StringBuilder();
		while (stackR.isEmpty() == false) {
			sb.append(stackR.pop());
		}

		System.out.println(sb);
		br.close();
	}
}