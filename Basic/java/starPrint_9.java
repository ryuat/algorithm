import java.util.Scanner;

/*
  2446
  별찍기 - 9
 */
public class Main {
	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
	
		for(int i=1;i<=n;i++) {
			for(int j=1;j<i;j++) 
				System.out.print(" ");
			
			for(int j=1;j<=2*(n-i)+1;j++)
				System.out.print("*");
			System.out.println();
		}
		
		for(int i=2;i<=n;i++) {
			for(int j=1;j<=n-i;j++) {
				System.out.print(" ");
			}
			for(int j=1;j<=2*i-1;j++) {
				System.out.print("*");
			}
			System.out.println();
		}
	}
}
/*n 5 5 5 5 5
 *i 1 2 3 4 5
 *  9 7 5 3 1 
 *  3 5 7 9
	5 6
  4 5 6 7
 *  */
