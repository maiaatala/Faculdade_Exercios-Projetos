package ex42;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in);
		
		int mes_atual, placa, mes_venc;
		String mes_venc_nome = null;
		
		System.out.println("Programa para determinar qual mes o IPVA vence, e se vence no mês atual");
		System.out.println("-----------------------------------------------------------------------\n");
		
		System.out.print("Informe os números da placa: ");
		placa = scanner.nextInt();
		scanner.nextLine();
		
		System.out.print("Informe o número do mês atual: ");
		mes_atual = scanner.nextInt();
		scanner.nextLine();

		scanner.close(); //fecha o scanner

		mes_venc = placa % 10;
		
		switch (mes_venc) {
		case 1:
			mes_venc_nome = "Janeiro";
			break;
		case 2:
			mes_venc_nome = "Fevereiro";
			break;
		case 3: 
			mes_venc_nome = "Março";
			break;
		case 4:
			mes_venc_nome = "Abril";
			break;
		case 5: 
			mes_venc_nome = "Maio";
			break;
		case 6: 
			mes_venc_nome = "Junho";
			break;
		case 7:
			mes_venc_nome = "Julho";
			break;
		case 8:
			mes_venc_nome = "Agosto";
			break;
		case 9: 
			mes_venc_nome = "Setembro";
			break;
		case 0: 
			mes_venc_nome = "Outubro";
			break;
		}

		System.out.println(mes_venc);
		if (mes_venc == 0) {
			mes_venc = 10;
		}
		
		if (mes_venc == mes_atual) {
			System.out.println("O IPVA do veículo vence no mês "+ mes_venc_nome +" e portanto VENCE no mês corrente");
		}else {
			System.out.println("O IPVA do veículo vence no mês "+ mes_venc_nome +" e portanto NÃO vence no mes corrente");
		}
		
		
	}

}
