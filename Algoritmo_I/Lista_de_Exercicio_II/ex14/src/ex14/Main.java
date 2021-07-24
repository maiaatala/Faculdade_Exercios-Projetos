package ex14;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in); //scanner para ler entrada pelo console
		
		float num1, num2, num3;
		
		System.out.println("Programa para ordenar 3 valores em ordem ascendente");
		System.out.println("---------------------------------------------------\n");
		System.out.print("Insira o primeiro número: ");
		num1 = scanner.nextFloat();
		scanner.nextLine(); //O nextInt não lê o /n, então usa um scanner next line para limpar isso.
		System.out.print("Insira o segundo número: ");
		num2 = scanner.nextFloat();
		scanner.nextLine();
		System.out.print("Insira o terceiro número: ");
		num3 = scanner.nextFloat();
		scanner.nextLine();
		scanner.close();
		
		if (num1 > num2){
			if (num3 > num1) {
				System.out.println("A ordem ascendente é: "+num2+", "+num1+", "+num1+";"); // B A C
			}else if (num3 > num2){
				System.out.println("A ordem ascendente é: "+num2+", "+num3+", "+num1+";"); // B C A
			}else {
				System.out.println("A ordem ascendente é: "+num3+", "+num2+", "+num1+";"); // C B A
			}
		}else{
			if (num3 > num2) {
				System.out.println("A ordem ascendente é: "+num1+", "+num2+", "+num3+";"); // A B C
			}else if (num3 > num1) {
				System.out.println("A ordem ascendente é: "+num1+", "+num3+", "+num2+";"); // A C B
			}else {
				System.out.println("A ordem ascendente é: "+num3+", "+num1+", "+num2+";"); // C A B
			}
		}
	}
}
