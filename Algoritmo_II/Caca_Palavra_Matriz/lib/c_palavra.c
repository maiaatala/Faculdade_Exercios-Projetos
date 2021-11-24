#include "./c_palavra.h"

// fflush nao funciona no linux, essa é a minha versão
void clean_stdin(){
    int c;
    // limpa os \n e EOF do console, para que o fgets e pause funcionem corretamente
    while((c = getchar() != '\n' && c != EOF))
    {    }
}

// linux também nao tem um system("pause"), essa é a minha versão
void pause(){
    printf("\n...Press Enter to continue...\n");
    int c = getchar();
    // o programa fica "parado" esperando um enter.
}

// minha versão do strlen() da biblioteca string.h
unsigned int str_len(const char *s){
    unsigned int len = 0;

    //\0 é o EOF character
    while (*s != '\0' && *s != '\n') 
    {
        s++; // avança para o proximo bloco da memoria
        len++; // incrementa a len
    }
    return (len);  // retorna o mesmo que a strlen() da string.h
}

/*Gera matriz aleatoria utilizando valores ascii, lowercase de 97 a 122*/
Jogo generate(Jogo M){
    int r, i, j;
    srand(time(NULL));
    for (i = 0; i < 10; i++){
        for (j = 0; j < 10; j++){
            r = rand() % 26;  // % 26 vai gerar valores entre 0 e 25
            M.m[i][j] = 97+ r; // soma com 97, posicao do 'a'
        }
    }
    M.m_exists = true;
    return M;
}

/*le uma linha inteira, e itera pelos primeiros 10 chars dela para preencher a linha da matriz*/
Jogo input_Jogo(Jogo M){
    int i, j;
    char temp_w[c_max];
    printf("OBS: INSIRA A LINHA INTEIRA\n");
    M.m_exists = true;
    for (i = 0; i < c_max; i++){
        printf(">>> Insira a linha %i: ", i+1);
        clean_stdin();
        fgets(temp_w, c_max+1,stdin);
        // verifica se a linha inserida tem pelo menos 10 chars
        if (str_len(temp_w) < c_max){
            printf("...Error! A linha nao tem pelo menos %i characteres...\n", c_max);
            M.m_exists = false;
            break;
        }
        // bloco que preenche a linha da matriz
        for (j = 0; j < c_max; j++){
            M.m[i][j] = temp_w[j];
        }
    }
    return M;
}

/*Lê do stdin a string a ser procurada na matriz*/
Jogo nova_palavra(Jogo M){
    clean_stdin();
    printf("Escreva a palavra a procurar (max 10 char): ");
    fgets(M.word, c_max+1, stdin);
    //muda o fim da string para EOF char ao inves do padrao \n do fgets
    M.word[str_len(M.word)] = '\0';  
    return M;
}

/*mostra a matriz*/
void show(Jogo M){
    int i, j;
    printf("\n");
    printf("\t    ");
    /*numero da coluna*/
    for (i = 0; i < 10; i++){
        printf("%d  ", i+1);
    }
    printf("\n");
    /*itera a matriz*/
    for (i = 0; i < 10; i++){
        printf("\t%-2d  ", i+1);  // numero da linha
        for (j = 0; j < 10; j++){
            printf("%c  ", M.m[i][j]);  // char da matriz
        }
        printf("\n");
    }
    printf("\n");
}

/*Chama todas as funções de procura*/
void pesquisa(Jogo M){
    show(M);
    printf("Palavra \"%s\": ", M.word);
    /*há 3 possibilidades para as a colunas e linhas da matriz,
    ponto de referencia: M[1][1]
    1: nao muda []
    2: crescente [++]
    3: descrescente [--]
    fazendo a combinação dessas 3 possibilidades, 
    e excludindo a que ambas e linahs e colunas nao mudam
        (pois ficariamos parados no mesmo item)
    Chegamos nas 8 formas de procurar palavras na matriz: */
    esqdir(M); //M[][++]
    diresq(M); //M[][--]
    cimabaixo(M); //M[++][]
    baixocima(M); //M[--][]
    diagsupdir(M); //M[--][++]
    diaginfdir(M); //M[++][++]
    diagsupesq(M); //M[--][--]
    diaginfesq(M); //M[++][--]
}

/*Abaixo são as funções relacionadas a busca no caça palavras*/

/*--- busca nas horizontais ---*/
/*linha fica constante, coluna muda*/

void esqdir(Jogo M){
    int i, j, k, w_length;
    bool found = false;

    w_length = str_len(M.word);

    for (i = 0; i < c_max; i++){
        for (j = 0; j < c_max; j++){
            // checa apra ver se a palavra caberia a partir da posicao atual
            if ((j + w_length) > c_max){
                break; //sai do loop atual caso nao seja possivel ter a palavra na linha atual
            }
            /*se o char atual é igual ao primeio char da palavra,
            entra em um loop diferente para verificar se a palavra inteira esta na sequencia*/
            if (M.m[i][j] == M.word[0]){
                found = true;
                /*checa char por char da palavra,
                caso um seja diferente da sequencia, sai do loop com condiçao falsa*/
                for (k = 0; k < w_length; k++){ 
                    if (M.word[k] != M.m[i][j+k]){ // j + k pois diresq é M[][++]
                        found = false;
                        break;
                    }
                }
                if (found){
                    // escreve a localização do primeiro char da palavra na matriz, e o sentido para encontra-la
                    printf("\n\t Esquerda -> Direita:  "
                            ">> Linha: %i, Coluna: %i",
                            i+1, j+1
                        );
                    found = false; //reseta a variavel para o prox loop
                }
            }
            
        }
    }
}

void diresq(Jogo M){
    // mesma logica de esqdir, apenas muda a linha com a variavel k
    int i, j, k, w_length;
    bool found = false;

    w_length = str_len(M.word);

    for (i = 0; i < c_max; i++){
        for (j = c_max - 1; j >= 0; j--){
            if ((j + 1 - w_length) < 0){
                break;
            }
            if (M.m[i][j] == M.word[0]){
                found = true;
                for (k = 0; k < w_length; k++){
                    if (M.word[k] != M.m[i][j-k]){ // j - k pois diresq é M[][--]
                        found = false;
                        break;
                    }
                }
                if (found){
                    printf("\n\t Direita -> Esquerda:  "
                            ">> Linha: %i, Coluna: %i",
                            i+1, j+1
                        );
                    found = false;
                }
            }
            
        }
    }
}

/*--- busca nas verticais ---*/
/*linha muda, coluna fica constante*/

void cimabaixo(Jogo M){
    // mesma logica de esqdir, apenas muda a linha com a variavel k
    int i, j, k, w_length;
    bool found = false;

    w_length = str_len(M.word);

    for (j = 0; j < c_max; j++){
        for (i = 0; i < c_max; i++){
            if ((i + w_length) > c_max){
                break;
            }
            if (M.m[i][j] == M.word[0]){
                found = true;
                for (k = 0; k < w_length; k++){
                    if (M.word[k] != M.m[i+k][j]){ // i + k pois cimabaixo é M[++][]
                        found = false;
                        break;
                    }
                }
                if (found){
                    printf("\n\t Cima -> Baixo:  "
                            ">> Linha: %i, Coluna: %i",
                            i+1, j+1
                        );
                    found = false;
                }
            }
            
        }
    }
}

void baixocima(Jogo M){
    // mesma logica de esqdir, apenas muda a linha com a variavel k
    int i, j, k, w_length;
    bool found = false;

    w_length = str_len(M.word);

    for (j = 0; j < c_max; j++){
        for (i = c_max -1; i >= 0; i--){
            if ((i + 1 - w_length) < 0){
                break;
            }
            if (M.m[i][j] == M.word[0]){
                found = true;
                for (k = 0; k < w_length; k++){ // i - k pois baixocima é M[++][]
                    if (M.word[k] != M.m[i-k][j]){
                        found = false;
                        break;
                    }
                }
                if (found){
                    printf("\n\t Baixo -> Cima:  "
                            ">> Linha: %i, Coluna: %i",
                            i+1, j+1
                        );
                    found = false;
                }
            }
            
        }
    }
}

/*--- busca na diagonal p/ esquerda ---*/
/*linha altra entre ++ e --. coluna fica --*/


void diagsupesq(Jogo M){
    /* mesma logica de esqdir, apenas muda a linha com a variavel k
    e o bloco que checa a palavra caberia a partir da posicao atual da matriz*/
    int i, j, k, w_length;
    bool found = false;

    w_length = str_len(M.word);

    for (i = 0; i < c_max; i++){
        for (j = 0; j < c_max; j++){
            // checa para ver se a palavra pode caber na posicao atual da matriz
            if (((j+1 - w_length) < 0)||((i+1 - w_length) < 0 )){
                continue; /*continue porque devido a ser na diagonal,
                tem posições que a prox interação pode funcionar*/
            }
            if (M.m[i][j] == M.word[0]){
                found = true;
                for (k = 0; k < w_length; k++){
                    // i - k & j - k pois diagsupesq é M[--][--]
                    if (M.word[k] != M.m[i-k][j-k]){
                        found = false;
                        break;
                    }
                }
                if (found){
                    printf("\n\t Diagonal Superior Esquerda:  "
                            ">> Linha: %i, Coluna: %i",
                            i+1, j+1
                        );
                    found = false;
                }
            }
            
        }
    }
}

void diaginfesq(Jogo M){
    // mesma logica de diagsupesq, apenas muda a linha com a variavel k
    int i, j, k, w_length;
    bool found = false;

    w_length = str_len(M.word);

    for (i = 0; i < c_max; i++){
        for (j = 0; j < c_max; j++){
            if (((j+1 - w_length) < 0)||((i + w_length) > c_max )){
                continue;
            }
            if (M.m[i][j] == M.word[0]){
                found = true;
                for (k = 0; k < w_length; k++){
                    // i + k & j - k pois diaginfesq é M[++][--]
                    if (M.word[k] != M.m[i+k][j-k]){
                        found = false;
                        break;
                    }
                }
                if (found){
                    printf("\n\t Diagonal Inferior Esquerda:  "
                            ">> Linha: %i, Coluna: %i",
                            i+1, j+1
                        );
                    found = false;
                }
            }
            
        }
    }
}

/*--- busca na diagonal p/ direita ---*/
/*linha altra entre ++ e --. coluna fica ++*/

void diagsupdir(Jogo M){
    // mesma logica de diagsupesq, apenas muda a linha com a variavel k
    int i, j, k, w_length;
    bool found = false;

    w_length = str_len(M.word);

    for (i = 0; i < c_max; i++){
        for (j = 0; j < c_max; j++){
            if (((j + w_length) > c_max )||((i+1 - w_length) < 0 )){
                continue;
            }
            if (M.m[i][j] == M.word[0]){
                found = true;
                for (k = 0; k < w_length; k++){
                    // i + k & j - k pois diagsupdir é M[--][++]
                    if (M.word[k] != M.m[i-k][j+k]){
                        found = false;
                        break;
                    }
                }
                if (found){
                    printf("\n\t Diagonal Superior Direita:  "
                            ">> Linha: %i, Coluna: %i",
                            i+1, j+1
                        );
                    found = false;
                }
            }
        }
    }
}

void diaginfdir(Jogo M){
    // mesma logica de diagsupesq, apenas muda a linha com a variavel k
    int i, j, k, w_length;
    bool found = false;

    w_length = str_len(M.word);

    for (i = 0; i < c_max; i++){
        for (j = 0; j < c_max; j++){
            if (((j + w_length) > c_max)||((i + w_length) > c_max )){
                continue;
            }
            if (M.m[i][j] == M.word[0]){
                found = true;
                for (k = 0; k < w_length; k++){
                    // i + k & j - k pois diagsupdir é M[++][++]
                    if (M.word[k] != M.m[i+k][j+k]){
                        found = false;
                        break;
                    }
                }
                if (found){
                    printf("\n\t Diagonal Inferior Direita:  "
                            ">> Linha: %i, Coluna: %i",
                            i+1, j+1
                        );
                    found = false;
                }
            }
            
        }
    }
}