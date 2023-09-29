package eusoulindo;
import java.util.Scanner;
public class IfStatements {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);		
		int age = scanner.nextInt();
		if(age >= 18) {
			System.out.println("You're an adult and can drink some alcoholic drinks");
		}else {
			System.out.println("You are not an adult and can't become a alcoholic!");
		}
		
		scanner.close();
	}

}
