package ex38;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		
		Scanner scanner = new Scanner(System.in);
		
		float presenca, nota;
		String nome;
		
		System.out.println("Programa para determianr a situação de um aluno com sua frequência e nota");
		System.out.println("-------------------------------------------------------------------------\n");
		
		System.out.print("Informe o nome do aluno(a): ");
		nome = scanner.nextLine();
		
		System.out.print("Informe a frequencia do aluno(a) (em %): ");
		presenca = scanner.nextFloat();
		scanner.nextLine();
		
		System.out.print("Informe a nota média do aluno(a): ");
		nota = scanner.nextFloat();
		scanner.nextLine();
		scanner.close();
		
		if (presenca >= 75) {
			if (nota < 3) {
				System.out.println("O aluno(a) "+ nome + " com frequencia "+ presenca+ "% e nota "+ nota + "\n\tReprovou por nota");
			}else if (nota < 7) {
				System.out.println("O aluno(a) "+ nome + " com frequencia "+ presenca+ "% e nota "+ nota + "\n\tPrecisa fazer a PF");
			}else {
				System.out.println("O aluno(a) "+ nome + " com frequencia "+ presenca+ "% e nota "+ nota + "\n\tFoi aprovado(a) na matéria");
			}
		}else {
			System.out.println("O aluno(a) "+ nome + " com frequencia "+ presenca+ "% e nota "+ nota + "\n\tReprovou por falta.");
		}

	}

}
