package ex18;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in); //scanner para ler entrada pelo console
		
		float num1;
		
		System.out.println("Programa para indicar se um número esta entre 20 e 90");
		System.out.println("-------------------------------------------------------------\n");
		System.out.print("Insira qualquer número desejado: ");
		num1 = scanner.nextFloat();
		scanner.nextLine(); //O nextInt não lê o /n, então usa um scanner next line para limpar isso.
		scanner.close();

		if ((num1 > 20) & (num1 < 90)) {
			System.out.println("O valor inserido, "+num1+", está entre 20 e 90.");
		}else {
			System.out.println("O valor inserido, "+num1+", não está entre 20 e 90");
		}
	}

}
