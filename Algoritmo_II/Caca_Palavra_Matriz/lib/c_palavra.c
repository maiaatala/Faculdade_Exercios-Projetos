#include "./c_palavra.h"

Jogo init_struct(Jogo M, char op){
    if  (op == 1){
        M.m_exists = false;
    }else if (op == 2){
        M.caca.w_exists = false;
    }else if(op == 3){
        M.m_exists = false;
        M.caca.w_exists = false;
    }
    return(M);
}

Jogo generate(Jogo M){
    int r, i, j;
    srand(time(NULL));
    // M = init_struct(M, 1);
    // generates random matrix by using ascii values, lowercase from 97 to 122 
    for (i = 0; i < 10; i++){
        for (j = 0; j < 10; j++){
            r = rand() % 26;
            M.m[i][j] = 97+ r;
        }
    }
    M.m_exists = true;
    return M;
}

Jogo input_Jogo(Jogo M){
    int i, j;
    char temp_w[c_max];
    // M = init_struct(M, 1);
    printf("OBS: INSIRA A LINHA INTEIRA\n");
    // generates random matrix by using ascii values, lowercase from 97 to 122 
    for (i = 0; i < c_max; i++){
        printf(">>> Insira linha %i: ", i+1);
        fflush(stdin);
        fgets(temp_w, c_max+1,stdin);
        fflush(stdin);
        for (j = 0; j < c_max; j++){
            M.m[i][j] = temp_w[j];
        }

    }
    M.m_exists = true;
    return M;
}

Jogo nova_palavra(Jogo M){
    // M = init_struct(M, 2);
    if (M.m_exists){
        show(M);
    }
    printf("Escreva a palavra a procurar (max 10 char): ");
    fflush(stdin);
    fgets(M.caca.word, c_max+1, stdin);
    fflush(stdin);

    M.caca.word[strlen(M.caca.word)-1] = '\0';
    // printf("%i", strlen(M.caca.word));
    M.caca.w_exists = true;
    // printf ("%s", M.caca.word);
    return M;
}

void show(Jogo M){
    int i, j;
    printf("\n");
    for (i = 0; i < 10; i++){
        printf("\t");
        for (j = 0; j < 10; j++){
            printf("%c  ", M.m[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void esqdir(Jogo M){
    int i, j, k, w_length;
    bool found = false;

    w_length = strlen(M.caca.word);

    for (i = 0; i < c_max; i++){
        for (j = 0; j < c_max; j++){
            // printf("m: %c \n", M.m[i][j]);
            if ((j + w_length) > c_max){
                break;
            }
            if (M.m[i][j] == M.caca.word[0]){
                found = true;
                for (k = 0; k < w_length; k++){
                    // printf("w: %c | m: %c \n", M.caca.word[k], M.m[i][j+k]);
                    if (M.caca.word[k] != M.m[i][j+k]){
                        found = false;
                        break;
                    }
                }
                if (found){
                    printf("\n\t Esquerda -> Direita:  "
                            ">> Linha: %i, Coluna: %i",
                            i+1, j+1
                        );
                    found = false;
                }
            }
            
        }
    }
}

void diresq(Jogo M){
    int i, j, k, w_length;
    bool found = false;

    w_length = strlen(M.caca.word);

    for (i = 0; i < c_max; i++){
        for (j = c_max - 1; j >= 0; j--){
            // printf("m: %c \n", M.m[i][j]);
            if ((j + 1 - w_length) < 0){
                break;
            }
            if (M.m[i][j] == M.caca.word[0]){
                found = true;
                for (k = 0; k < w_length; k++){
                    // printf("w: %c | m: %c \n", M.caca.word[k], M.m[i][j+k]);
                    if (M.caca.word[k] != M.m[i][j-k]){
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

void cimabaixo(Jogo M){
    int i, j, k, w_length;
    bool found = false;

    w_length = strlen(M.caca.word);

    for (j = 0; j < c_max; j++){
        for (i = 0; i < c_max; i++){
            // printf("m: %c \n", M.m[i][j]);
            if ((i + w_length) > c_max){
                break;
            }
            if (M.m[i][j] == M.caca.word[0]){
                found = true;
                for (k = 0; k < w_length; k++){
                    // printf("w: %c | m: %c \n", M.caca.word[k], M.m[i][j+k]);
                    if (M.caca.word[k] != M.m[i+k][j]){
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
    int i, j, k, w_length;
    bool found = false;

    w_length = strlen(M.caca.word);

    for (j = 0; j < c_max; j++){
        for (i = c_max -1; i >= 0; i--){
            // printf("m: %c \n", M.m[i][j]);
            if ((i + 1 - w_length) < 0){
                break;
            }
            if (M.m[i][j] == M.caca.word[0]){
                found = true;
                for (k = 0; k < w_length; k++){
                    // printf("w: %c | m: %c \n", M.caca.word[k], M.m[i][j+k]);
                    if (M.caca.word[k] != M.m[i-k][j]){
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

void diagsupdir(Jogo M){
    int i, j, k, w_length;
    bool found = false;

    w_length = strlen(M.caca.word);

    for (i = 0; i < c_max; i++){
        for (j = 0; j < c_max; j++){
            // printf("m: %c \n", M.m[i][j]);
            if (((j + w_length) > c_max )||((i+1 - w_length) < 0 )){
                continue;
            }
            if (M.m[i][j] == M.caca.word[0]){
                found = true;
                for (k = 0; k < w_length; k++){
                    // printf("w: %c | m: %c \n", M.caca.word[k], M.m[i][j+k]);
                    if (M.caca.word[k] != M.m[i-k][j+k]){
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

void diagsupesq(Jogo M){
    int i, j, k, w_length;
    bool found = false;

    w_length = strlen(M.caca.word);

    for (i = 0; i < c_max; i++){
        for (j = 0; j < c_max; j++){
            // printf("m: %c \n", M.m[i][j]);
            if (((j+1 - w_length) < 0)||((i+1 - w_length) < 0 )){
                continue;
            }
            if (M.m[i][j] == M.caca.word[0]){
                found = true;
                for (k = 0; k < w_length; k++){
                    // printf("w: %c | m: %c \n", M.caca.word[k], M.m[i-k][j-k]);
                    if (M.caca.word[k] != M.m[i-k][j-k]){
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
    int i, j, k, w_length;
    bool found = false;

    w_length = strlen(M.caca.word);

    for (i = 0; i < c_max; i++){
        for (j = 0; j < c_max; j++){
            // printf("m: %c \n", M.m[i][j]);
            if (((j+1 - w_length) < 0)||((i + w_length) > c_max )){
                continue;
            }
            if (M.m[i][j] == M.caca.word[0]){
                found = true;
                for (k = 0; k < w_length; k++){
                    // printf("w: %c | m: %c \n", M.caca.word[k], M.m[i-k][j-k]);
                    if (M.caca.word[k] != M.m[i+k][j-k]){
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

void diaginfdir(Jogo M){
    int i, j, k, w_length;
    bool found = false;

    w_length = strlen(M.caca.word);

    for (i = 0; i < c_max; i++){
        for (j = 0; j < c_max; j++){
            // printf("m: %c \n", M.m[i][j]);
            if (((j + w_length) > c_max)||((i + w_length) > c_max )){
                continue;
            }
            if (M.m[i][j] == M.caca.word[0]){
                found = true;
                for (k = 0; k < w_length; k++){
                    // printf("w: %c | m: %c \n", M.caca.word[k], M.m[i-k][j-k]);
                    if (M.caca.word[k] != M.m[i+k][j+k]){
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

void pesquisa(Jogo M){
    show(M);
    printf("Palavra \"%s\": ", M.caca.word);
    esqdir(M);
    diresq(M);
    cimabaixo(M);
    baixocima(M);
    diagsupdir(M);
    diagsupesq(M);
    diaginfesq(M);
    diaginfdir(M);
    printf("\n");
}