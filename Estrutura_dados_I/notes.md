<style>    
    img{
        width: 600px;
        object-fit: cover;
    };
</style>

# Estrutura de Dados I Resumo

## Professor's code

[replit](https://replit.com/@jeffersonpaizano)

## Lista Duplamente Encadeada

- possui dois ponteiros, um aponta para o próximo e o outro aponta para o elemento anterior

![lista duplamente encadeada](https://saulo.arisa.com.br/wiki/images/c/c4/Lista_duplamente_encadeada.png)

```c
struct lista {
    int info;
    struct lista *ant;
    struct lista *prox;
}typedef struct lista Lista;


Lista* insere(Lista *lista, int v){
    Lista novo = (Lista*)Malloc(sizeof(Lista));
    novo->info = v;
    novo->prox = lista ;
    novo->ant = NULL;
    if (lista!=NULL){
        lista->ant=novo;
    }
    return novo;
}

Lista *remove (Lista *lista, int v){
    Lista *p = busca(lista, v);
    if(p==NULL){
        return lista;
    }
    if(lista==p){
        p->prox->ant = p->ant;
    }
    if (p->prox == NULL){
        p->ant->prox = p->prox;
    }
    free(p);
    return lista;
}
```

