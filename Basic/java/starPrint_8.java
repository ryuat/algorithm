import java.util.Scanner;

/*
  2445
  별찍기 - 8
 */
public class Main {
	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
	
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=n*2;j++) {
				if(j<=i || j>2*n-i) System.out.print("*");
				else System.out.print(" ");
				
			}
			System.out.println();
		}
		
		for(int i=n-1;i>=1;i--) {
			for(int j=1;j<=2*n;j++) {
				if(j<=i || j>2*n-i) System.out.print("*");
				else System.out.print(" ");
			}
			System.out.println();
		}
	}
}
/*
 * 
	5 6
  4 5 6 7
 *  */


/*4 3 2 1 0 n-1

2n-1

1 3 5 7 9*/