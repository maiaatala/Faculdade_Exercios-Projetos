package ex22;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		
		Scanner scanner = new Scanner(System.in);
		
		float saldo_m, credito;
		
		System.out.println("Programa para calcular o valor de credito");
		System.out.println("-----------------------------------------\n");
		System.out.print("Insira o saldo médio do cliente no ultimo ano: ");
		saldo_m = scanner.nextFloat();
		scanner.nextLine();
		scanner.close();
		
		if (saldo_m <= 500) {
			credito = 0;
			System.out.println("com saldo médio de R$ "+ saldo_m +" valor do crédito é de: R$ "+ credito);
		}else if (saldo_m <= 1000) {
			credito = (float) (0.30*saldo_m);
			System.out.println("com saldo médio de R$ "+ saldo_m +" valor do crédito é de: R$ "+ credito);
		}else if (saldo_m <= 3000) {
			credito = (float) (0.40*saldo_m);
			System.out.println("com saldo médio de R$ "+ saldo_m +" valor do crédito é de: R$ "+ credito);
		}else {
			credito = (float) (0.50*saldo_m);
			System.out.println("com saldo médio de R$ "+ saldo_m +" valor do crédito é de: R$ "+ credito);
		}

	}

}
