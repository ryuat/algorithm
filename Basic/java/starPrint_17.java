import java.util.Scanner;

/*
  10992
  별찍기 - 17
 */
public class Main {
	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		for(int i=1;i<n;i++) {
			for(int j=1;j<=n-i;j++) { // 3 2 1 
				System.out.print(" ");
			}
			for(int j=1;j<=2*i-1;j++) {
				if(j==1 || j == 2*i-1) System.out.print("*");
				else System.out.print(" ");
			}
			System.out.println();
		}
		for(int i=1;i<=2*n-1;i++) {
			System.out.print("*");
		}
	}
}
