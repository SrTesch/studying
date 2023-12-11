package view;
import javax.swing.JOptionPane;

public class teste {
	public static void main(String[] args) {
		String name = JOptionPane.showInputDialog("Enter your name, please");
		JOptionPane.showMessageDialog(null, "Hello, %s".formatted(name));
		int age = Integer.parseInt(JOptionPane.showInputDialog("Enter your age, please"));
		JOptionPane.showMessageDialog(null, "You born in  %d! Is that correct?".formatted(2023 - age));
	}
}
