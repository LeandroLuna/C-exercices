#include <cstring>
struct noFila
{
	TipoBoia dado;
	struct noFila *prox;
};

typedef struct noFila *TipoFilaCoordenadas;

void init(TipoFilaCoordenadas *ini, TipoFilaCoordenadas *fim)
{
	*ini = NULL;
	*fim = NULL;
}

int isEmpty(TipoFilaCoordenadas ini, TipoFilaCoordenadas fim)
{
	if ((ini == NULL) && (fim == NULL))
		return (1);
	else
		return (0);
}

void enqueue(TipoFilaCoordenadas *ini, TipoFilaCoordenadas *fim, char *v)
{
	TipoFilaCoordenadas novo;
	novo = (TipoFilaCoordenadas)malloc(sizeof(struct noFila));
	if (novo == NULL)
		cout << "Fila Cheia \n";
	else
	{
		strcpy(novo->dado.coordenada, v);
		novo->prox = NULL;
		if (isEmpty(*ini, *fim))
			*ini = novo;
		else
			(*fim)->prox = novo;

		*fim = novo;
	}
}

int dequeue(TipoFilaCoordenadas *ini, TipoFilaCoordenadas *fim, char *v)
{
	TipoFilaCoordenadas aux = *ini;
	if (isEmpty(*ini, *fim))
	{
		return 0;
	}
	else
	{
		strcpy(v, aux->dado.coordenada);
		*ini = aux->prox;
		if (*ini == NULL)
			*fim = NULL;
		free(aux);
		return 1;
	}
}
