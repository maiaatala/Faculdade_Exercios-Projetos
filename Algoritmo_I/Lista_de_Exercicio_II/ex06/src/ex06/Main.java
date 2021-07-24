package ex06;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in); //scanner para ler entrada pelo console
		
		float input;
		double resultado;
		boolean positive;
		
		System.out.println("Programa para manipular um número, dependnedo do seu valor");
		System.out.println("----------------------------------------------------------\n");
		
		System.out.print("Insira qualquer numero desejado: ");
		input = scanner.nextFloat();
		scanner.nextLine();
		scanner.close();
		
		positive = (input >= 0) ? true : false;
		
		if (positive) {
			resultado = Math.sqrt(input);
			System.out.println("A raiz quadrada do número " + input + " é: " + resultado);
		}else {
			resultado = Math.pow(input, 2);
			System.out.println("O quadrado do número " + input + " é: " + resultado);
		}
		
	}
}
