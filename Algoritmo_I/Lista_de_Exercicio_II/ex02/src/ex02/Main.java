package ex02;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in); //scanner para ler entrada pelo console
		
		int num1, num2, soma;
		
		System.out.println("Programa para efetuar adição de dois números inteiros");
		System.out.println("-----------------------------------------------------\n");
		System.out.print("Insira o primeiro número: ");
		num1 = scanner.nextInt();
		scanner.nextLine(); //O nextInt não lê o /n, ent�o usa um scanner next line para limpar isso.
		System.out.print("Insira o segundo número: ");
		num2 = scanner.nextInt();
		scanner.nextLine();
		scanner.close();

		soma = num1 + num2;
		
		if (soma > 10) {
			System.out.println("A soma dos numeros " + num1 + " e " + num2 + " é: " + soma);
		}else {
			System.out.println("A soma é menor ou igual a 10.");
		}
	}

}
