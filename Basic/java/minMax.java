import java.util.Scanner;

/*
 8393번
 합
 */
public class Main {
	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		int num, min= 1000000, max= -1000000;
		while(n-->0) {
			num = sc.nextInt();
			if(num < min) min = num;
			if(num > max) max = num;
		}
		System.out.println(min + " " + max);
	}
}