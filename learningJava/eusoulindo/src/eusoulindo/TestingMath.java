package eusoulindo;

public class TestingMath {
	public static void main(String[] args) {
		double x = 3.14;
		double y = -10;
		double z = Math.max(x, y);
		System.out.println("The biggest number is %f".formatted(z));
		z = Math.abs(y);
		System.out.println(z);
		z = Math.round(x);
		System.out.println(z);
	}
}
