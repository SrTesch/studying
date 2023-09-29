package eusoulindo;
import java.util.Scanner;
public class hypotenuse {

	public static void main(String[] args) {
		double x, y, z;
		Scanner scanner = new Scanner(System.in);
		System.out.print("Enter side x: ");
		x = scanner.nextDouble();
		System.out.print("Enter side y: ");
		y = scanner.nextDouble();
		
		z = Math.sqrt((x*x)+(y*y));
		System.out.println("The hypotenuse is %f".formatted(z));
		scanner.close(); 
	}

}
