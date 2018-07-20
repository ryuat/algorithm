import java.util.Scanner;

/*
  10991
  별찍기 - 16
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
				if(j%2==1) System.out.print("*");
				else System.out.print(" ");
			}
			System.out.println();
		}
	}
}
/*
   n   4 4 4 4 
   i   1 2 3 4
 "*"   1 3 5 7
  " "  3 2 1 0
 */
