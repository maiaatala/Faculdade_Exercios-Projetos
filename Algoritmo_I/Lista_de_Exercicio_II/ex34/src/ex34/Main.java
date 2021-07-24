package ex34;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in);
		
		float x, fx;
		
		System.out.println("Programa para calcular a F(x) da função:");
		System.out.println("F(x) = 8/(2-x)");
		System.out.println("----------------------------------------\n");
		
		System.out.print("Insira o valor de x:  ");
		x = scanner.nextFloat();
		scanner.nextLine();
		
		while (x == 2) {
			System.out.println("A função é indeterminada para x = 2");
			System.out.print("Por favor insira outro valor para x: ");
			x = scanner.nextFloat();
			scanner.nextLine();
		}
		scanner.close();
		
		fx = 8 / (2-x);
		
		System.out.println("O valor de F("+x+") = " + fx);

	}

}
