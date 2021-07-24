package ex10;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in); //scanner para ler entrada pelo console
		
		float num1, num2;
		
		System.out.println("Programa para ordenar 2 valores");
		System.out.println("-------------------------------\n");
		System.out.print("Insira o primeiro número: ");
		num1 = scanner.nextFloat();
		scanner.nextLine(); //O nextInt não lê o /n, então usa um scanner next line para limpar isso.
		System.out.print("Insira o segundo número: ");
		num2 = scanner.nextFloat();
		scanner.nextLine();
		scanner.close();
			
		if (num1 > num2) {
			System.out.println("O primeiro numero inserido é maior que o segundo;");
			System.out.println("Menor número: " + num2);
			System.out.println("Maior número: " + num1);
		}else {
			System.out.println("O segundo numero inserido é maior que o primeiro;");
			System.out.println("Menor número: " + num1);
			System.out.println("Maior número: " + num2);
		}

	}

}
