import java.util.Scanner;

/*
  2444
  별찍기 - 7
 */
public class Main {
	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=n-i;j++) {
				System.out.print(" ");
			}
			for(int j=1;j<=2*i-1;j++) {
				System.out.print("*");
			}
			System.out.println();
		}
		
		for(int i=1;i<=n-1;i++) {
			for(int j=1;j<=i;j++) {
				System.out.print(" ");
			}
			for(int j=2*(n-i)-1;j>=1;j--) {
				System.out.print("*");
			}
			System.out.println();
		}
	}
}
/*
 * 
 *  *  "" 
 *  7  1
 *  5  2
 *  3  3
 *  1  4
 *  */


/*4 3 2 1 0 n-1

2n-1

1 3 5 7 9*/