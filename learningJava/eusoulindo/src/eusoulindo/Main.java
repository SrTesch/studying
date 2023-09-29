package eusoulindo;

import java.util.Scanner;

// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
public class Main {
    public static void main(String[] args) {
        Cliente cliente = new Cliente(17142035730L, "Rafael Costa", "rafacdomin@gmail.com");
        Produto p1 = new Produto(1000, "Produto 1", 100.0);
        Produto p2 = new Produto(1000, "Produto 2", 200.0);
        Produto p3 = new Produto(1000, "Produto 3", 300.0);

        Pedido pedido = new Pedido(cliente);

        pedido.addItem(p1, 1);
        pedido.addItem(p2, 2);

        System.out.println("Total: " + pedido.getTotal());
        System.out.println(pedido.listar());
    }

    public static void AnalisaTriangulo() {
        int l1, l2, l3;

        Scanner input = new Scanner(System.in);

        System.out.println("Insira os lados do triangulo: ");

        System.out.print("Lado 1: ");
        l1 = input.nextInt();
        System.out.print("Lado 2: ");
        l2 = input.nextInt();
        System.out.print("Lado 3: ");
        l3 = input.nextInt();

        if (!(l1 + l2 > l3 && l1 +l3 > l2 && l2 + l3 > l1)) {
            System.out.println("Não é triangulo");
            return;
        }

        if (l1 == l2 && l1 == l3) {
            System.out.println("Triangulo Equilátero");
        } else if(l1 == l2 && l1 != l3) {
            System.out.println("Triangulo Isósceles");
        } else {
            System.out.println("Triangulo Escaleno");
        }

        input.close();
    }

    public static void MediaNotas() {
        final int length = 10;
        Scanner input = new Scanner(System.in);

        String[] alunos = new String[length];
        float[] notas = new float[length];
        float media = 0;
        for(int i = 0; i < alunos.length; i++) {
            System.out.print("Nome do Aluno: ");
            alunos[i] = input.nextLine();
            System.out.print("Nota: ");
            notas[i] = input.nextInt();

            input.nextLine();
            media += notas[i] / notas.length;
        }

        System.out.println("Media das notas:" + media);
        System.out.println("Aprovados:");
        for (int i = 0; i < alunos.length; i++) {
            if (notas[i] >= 7) {
                System.out.println("Aluno: " + alunos[i] + "\t Nota: " + notas[i]);
            }
        }

        input.close();
    }
}