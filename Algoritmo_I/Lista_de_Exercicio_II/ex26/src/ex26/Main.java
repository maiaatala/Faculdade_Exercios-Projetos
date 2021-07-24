package ex26;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in);
		
		int idade, valor;
		
		System.out.println("Programa para calcular o valor dos planos de saúde de acordo com a idade");
		System.out.println("------------------------------------------------------------------------\n");
		System.out.print("Insira a idade do cidadão: ");
		idade = scanner.nextInt();
		scanner.nextLine();
		scanner.close();

		if (idade <= 10) {
			valor = 30;
			System.out.println("Com "+ idade +" anos o valor da mensalidade do plano de saúde é de: R$ "+ valor);
		}else if (idade <= 29) {
			valor = 60;
			System.out.println("Com "+ idade +" anos o valor da mensalidade do plano de saúde é de: R$ "+ valor);
		}else if (idade <= 45) {
			valor = 120;
			System.out.println("Com "+ idade +" anos o valor da mensalidade do plano de saúde é de: R$ "+ valor);
		}else if (idade <= 59) {
			valor = 150;
			System.out.println("Com "+ idade +" anos o valor da mensalidade do plano de saúde é de: R$ "+ valor);
		}else if (idade <= 65) {
			valor = 250;
			System.out.println("Com "+ idade +" anos o valor da mensalidade do plano de saúde é de: R$ "+ valor);
		}else {
			valor = 400;
			System.out.println("Com "+ idade +" anos o valor da mensalidade do plano de saúde é de: R$ "+ valor);
		}
		
	}

}
