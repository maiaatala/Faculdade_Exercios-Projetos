package ex30;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		
		Scanner scanner = new Scanner(System.in);
		
		float ladoA, ladoB, ladoC;
		
		System.out.println("Programa para calcular verificar se os lados percetem a um triangulo e qual o tipo do triangulo");
		System.out.println("-----------------------------------------------------------------------------------------------\n");
		
		//lado A
		System.out.print("Informe a primeira medida: ");
		ladoA = scanner.nextFloat();
		scanner.nextLine();
		
		while (ladoA < 0) {
			System.out.println("Comprimentos de formas geometricas não podem menor que zero");
			System.out.print("Informe o valor correto: ");
			ladoA = scanner.nextFloat();
			scanner.nextLine();
		}
		
		//lado B
		System.out.print("Informe a segunda medida: ");
		ladoB = scanner.nextFloat();
		scanner.nextLine();
		
		while (ladoB < 0) {
			System.out.println("Comprimentos de formas geometricas não podem menor que zero");
			System.out.print("Informe o valor correto: ");
			ladoB = scanner.nextFloat();
			scanner.nextLine();
		}
		
		//lado C
		System.out.print("Informe a terceira medida: ");
		ladoC = scanner.nextFloat();
		scanner.nextLine();
		
		while (ladoC < 0) {
			System.out.println("Comprimentos de formas geometricas não podem menor que zero");
			System.out.print("Informe o valor correto: ");
			ladoC = scanner.nextFloat();
			scanner.nextLine();
		}
		scanner.close();
		
		if ((ladoA == 0 || ladoB == 0 || ladoC ==0)||(ladoA + ladoB < ladoC || ladoA + ladoC < ladoB || ladoB + ladoC < ladoA)||(Math.abs(ladoB-ladoC) > ladoA || Math.abs(ladoA-ladoC) > ladoB || Math.abs(ladoA-ladoB) > ladoC)){
			System.out.println("Os valores inseridos não pertecem a um triangulo;");
		} else {
			if((ladoA == ladoB) && (ladoA == ladoC)) {
				System.out.println("Os valores inseridos resultam em um triangulo equilátero");
			}else if (ladoA == ladoB || ladoB == ladoC || ladoC == ladoA) {
				System.out.println("Os valores inseridos resultam em um triangulo isósceles");
			}else {
				System.out.println("Os valores inseridos resultam em um triangulo escaleno");
			}
		}

	}

}
