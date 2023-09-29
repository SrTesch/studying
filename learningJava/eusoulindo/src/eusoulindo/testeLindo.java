package eusoulindo;

import java.util.Scanner;

public class testeLindo {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		System.out.println("What is your name? ");
		String name = scanner.nextLine();
		System.out.println("How old are you? ");
		int age = scanner.nextInt();
		scanner.nextLine();
		System.out.println("What is your favorite food? ");
		String food = scanner.nextLine();
		
		
		System.out.println("Hello, %s".formatted(name));
		System.out.println("You're %d years old!".formatted(age));
		System.out.println("You really like %s".formatted(food));
		scanner.close();
	}

}
