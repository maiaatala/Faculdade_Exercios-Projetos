# Lista de Exercicios I <!-- omit in toc -->

[//]: # "<!-- omit in toc --> makes the TOC not count that heading as part of the formatation"

Codigos realizados para solucionar problemas da primeira lista da matéria de algoritmo I

***

## 1. Sumário

- [1. Sumário](#1-sumário)
- [2. Introdução](#2-introdução)
- [3. Metodologia](#3-metodologia)
- [4. Exercícios](#4-exercícios)
  - [4.1. Exercício 03](#41-exercício-03)
  - [4.2. Exercício 08](#42-exercício-08)
  - [4.3. Exercício 13](#43-exercício-13)
  - [4.4. Exercício 18](#44-exercício-18)
  - [4.5. Exercício 23](#45-exercício-23)
  - [4.6. Exercício 28](#46-exercício-28)
  - [4.7. Exercício 33](#47-exercício-33)

***

## 2. Introdução

Os programas desse reposítorio são soluções de um conjunto de problemas propostos na primeira lista de Algorimo I :notebook:

Linguagem Utilizada: C

Data dos programas: Maio 2021.

Autora: Ana C Maia Atala. :e-mail: @ ana.atala@unemat.br

Faculdade: Unemat :school:

***

## 3. Metodologia

De uma [lista com 35 exercicios](https://drive.google.com/file/d/1VYxFBJM3nKkg7gUh232tjwbwHbBe35Np/view?usp=sharing), foram selecionados 7 exercicios para cada aluno da turma pelo professor.

Podiamos escolher entra as seguintes linguagens de programação: Visualg, C, C++ e Java.
A linguagem escolhida foi `C` e a IDE utilizada foi `VS code`

***

## 4. Exercícios

Todos os exercicios dessa lista possuem a inclusão da biblioteca do windows, esta foi utilizada para mudar a codificação de texto do CMD, com o intuito de mostrar os acentos e caracteres especiais usados em Portugês. Portanto, todos os programas desta lista possuem a seguinte estrutura chave:

```C
#include <windows.h>  //biblioteca do windows para que o apareca acentos do printf na cmd.

void preparacao_acentos(){          //Processo de preparação do sistema para acentos
    UINT CPAGE_UTF8 = 65001;        //Define a codificação do cmd com UFT-8
    SetConsoleOutputCP(CPAGE_UTF8);     //muda a codificação do sistema para UFT-8
    system("cls");      //comando para limpar a tela do cmd
}

int main(){
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();  //armazena a codificação padrao do windows
    preparacao_acentos(0);  //chama o processo que prepara o sistema para mostrar acentos


    SetConsoleOutputCP(CPAGE_DEFAULT);   //comando para voltar à codificação padrão do windows.
    system  ("pause");   //comando para fazer o arquivo .exe nao fechar automaticamente
    return (0);
}
```

***

### 4.1. Exercício 03

Enunciado da questão 03:
> Dada a razão de uma P.A. (progressão aritmética) e um termo qualquer, k (![ak](https://latex.codecogs.com/gif.latex?%5Cbg_white%20%5Clarge%20a_%7Bk%7D)). Escreva um algoritmo em PORTUGOL para calcular qualquer outro termo, n, (![an](https://latex.codecogs.com/gif.latex?%5Cbg_white%20%5Clarge%20a_%7Bn%7D))
> 
> ![pa eq](https://latex.codecogs.com/gif.latex?%5Cbg_white%20%5Clarge%20a_%7Bn%7D%20%3D%20a_%7Bk%7D%20&plus;%20%28n%20-%20k%29*r)


Além disso, O código deste programa utiliza loops `Do {...} While()` para permitir a reutilização do mesmo, de acordo com [este fluxograma](03_PA_fluxograma.pdf)

***

### 4.2. Exercício 08

Enunciado da questão 08:
> Considere que o número de uma placa de veículo é composto por **quatro algarismos**. Construa um algoritmo em PORTUGOL que leia este número e apresente o algarismo correspondente à casa das centenas.

A lógica matemática para calcular o algarismo corespondente a casa das centenas utilizado foi:
![centena formula](https://latex.codecogs.com/png.latex?%5Cbg_white%20%5Clarge%20Centena%20%3D%20%28Placa%20%5Cmod%201000%29%5Cmathbf%7Bdiv%7D100)

A implementação da formula foi feita em uma função do tipo int de acordo com o seguinte codigo:

```C
int calculocentena(int valorp){
    div_t centena; //declaração das variaveis

    /*calculo da centena
    usamos o modulo (%) para calcular o resto da divisao de milhar, 'retirando' a parte do milhar do calculo
    e div(int numerador, int denominador) para calcular a centena
    onde centena.quot é o quociente e centena.rem é o resto*/
    centena = div((valorp%1000), 100);

    return (centena.quot);
}
```

Além disso, o programa confere o valor de entrada para aceitar *apenas* números de 4 algarismos através do seguinte loop:

```C
while   ((placa >= 10000)||(placa < 1000)){
    printf  ("Valor incorreto, por favor inserir uma placa de valor positivo e de 4 algarismos\n");
    printf  ("escreva o número da placa:  ");
    scanf   ("%i", &placa);
}
```

Ademais, o programa possui um loop `While{...}` para permitir a reutilização do mesmo. Dessa forma, o programa repete ate que o usuário responda com `n`

***

### 4.3. Exercício 13

Enunciado da questão 13:
> Escreva um algoritmo em PORTUGOL que leia um número real e imprima a terça parte deste número.

Um programa de divisão bem simples que possui um loop `while{...}` para possibilitar a reutilização do mesmo

***

### 4.4. Exercício 18

Enunciado da questão 18:
>  Seja uma seqüência A,B,C, ... determinando um Progressão Geométrica (P.G.), o termo médio (B) de uma P.G. é determinado pela média geométrica de seus termos, sucessor (C) e antecessor (B). Com base neste enunciado construa um algoritmo em PORTUGOL que calcule o termo médio (B) através de A, C.
> 
> ![B² = A x C](https://latex.codecogs.com/gif.latex?%5Cbg_white%20B%5E%7B2%7D%20%3D%20A%20*%20C)

O programa calcula o seguinte codigo usando o módulo do valor A e o módulo do valor B, o resultado é, portanto, calculado como `± sqrt(|A|*|B|)`

Ademais, O programa possui um loop `while{...}` para possibilitar a reutilização do mesmo.

***

### 4.5. Exercício 23

Enunciado da questão 23:
> Escreva um algoritmo em PORTUGOL que leia uma temperatura em gruas centígrados e apresente a temperatura convertida em graus Fahrenheit. A fórmula de conversão é:
> 
> ![F = 1.8C + 32](https://latex.codecogs.com/gif.latex?%5Cbg_white%20F%20%3D%20%5Cfrac%7B9*C&plus;160%7D%7B5%7D%20%3D%201.8*C&plus;32)

O programa calcula a conversão para Fahrenheit através da seguinte função float:

```C
float conversor_para_fah(float temp){
    //simplificado a equação fica F = 1.8C + 32
    return (1.8*temp + 32);
}
```
Ademais, O programa possui um loop `while{...}` para possibilitar a reutilização do mesmo.

***

### 4.6. Exercício 28

Enunciado da questão 28:
> Todo restaurante, embora por lei não possa obrigar o cliente a pagar, cobra 10% de comissão para o garçom. Crie um algoritmo em PORTUGOL que leia o valor gasto com despesas realizadas em um restaurante e imprima o valor da gorjeta e o valor total com a gorjeta.

Um programa simples de multiplicação que possui um loop `while{...}` para possibilitar a reutilização do mesmo.

***

### 4.7. Exercício 33

Enunciado da questão 33:
> Criar um algoritmo em PORTUGOL que efetue o cálculo da quantidade de litros de combustível gastos em uma viagem sabendo-se que o carro faz 12 km com um litro. Deverão ser fornecidos o tempo gasto na viagem e a velocidade média
> ![d = t*v](https://latex.codecogs.com/gif.latex?%5Cbg_white%20Distancia%20%3D%20Tempo*Velocidade)
> 
> ![l = d/12](https://latex.codecogs.com/gif.latex?%5Cbg_white%20Litros%20%3D%20%5Cfrac%7BDistancia%7D%7B12%7D)
> 
> Portanto: ![l = (t*v)/12](https://latex.codecogs.com/gif.latex?%5Cbg_white%20Litros%20%3D%20%5Cfrac%7BTempo*Velocidade%7D%7B12%7D)

Um programa matemático simples que possui um loop `do{...}while()` para possibilitar a reutilização do mesmo.

***
