package persistence;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;

import controller.MainController;

public class Serializer {
	private static String fileName = "data.bin";

	public static MainController readFile() {
		MainController mainController = null;

		try {
			ObjectInputStream input = new ObjectInputStream(new FileInputStream(fileName));
			mainController = (MainController) input.readObject();

			input.close();

		} catch (FileNotFoundException e) {
			System.out.printf("Arquivo %s não encontrado...%n", fileName);

		} catch (IOException e) {
			System.err.printf("Erro na leitura do arquivo %s!%n", fileName);
			
		} catch (Exception e) {
			e.printStackTrace();
		}

		return mainController;
	}

	public static void writeFile(MainController mainController) {

		try {
			ObjectOutputStream output = new ObjectOutputStream(new FileOutputStream(fileName));

			output.writeObject(mainController);
			output.flush();

			output.close();

		} catch (IOException e) {
			System.err.println(String.format("Erro na gravação do arquivo %s!", fileName));
			
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
