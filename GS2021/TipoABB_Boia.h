struct noInt
{
  TipoBoia dado;
  struct noInt *esq, *dir;
};

typedef struct noInt *TipoArvore;

void insere(TipoArvore *p, TipoBoia info)
{
  TipoArvore novo;
  if (*p == NULL)
  {
    novo = (TipoArvore)malloc(sizeof(struct noInt));
    if (novo != NULL)
    {
      novo->dado.hashcode = info.hashcode;
      strcpy(novo->dado.coordenada, info.coordenada);
      novo->dado.salinidade = info.salinidade;
      novo->dado.temperatura = info.temperatura;
      novo->dado.alerta = info.alerta;
      novo->dir = NULL;
      novo->esq = NULL;
      *p = novo;
    }
  }
  else
  {
    if (info.hashcode < (*p)->dado.hashcode)
    {
      insere(&(*p)->esq, info);
    }
    else
    {
      insere(&(*p)->dir, info);
    }
  }
}

void lista_em_ordemD(TipoArvore p)
{
  if (p != NULL)
  {
    if (p->dir != NULL)
    {
      lista_em_ordemD(p->dir);
    }
    cout << "Hashcode: " << p->dado.hashcode << " || Coordenada: " << p->dado.coordenada << endl;
    if (p->esq != NULL)
    {
      lista_em_ordemD(p->esq);
    }
  }
}

void atualizaMedidas(TipoArvore p)
{
  float antes;
  if (p != NULL)
  {
    if (p->esq != NULL)
    {
      atualizaMedidas(p->esq);
    }
    cout << "\natualiza medida do sensor com coordenadas: " << p->dado.coordenada << endl;
    antes = p->dado.salinidade;
    cout << "Medida de salinidade (atual e' '" << p->dado.salinidade << "'): ";
    cin >> p->dado.salinidade;
    if ((p->dado.salinidade - antes) / antes > 0.2)
    {
      p->dado.alerta = 1;
    }
    antes = p->dado.temperatura;
    cout << "Medida de temperatura (atual e' '" << p->dado.temperatura << "'): ";
    cin >> p->dado.temperatura;
    if ((p->dado.temperatura - antes) / antes > 0.2)
    {
      p->dado.alerta = 1;
    }
    if (p->dir != NULL)
    {
      atualizaMedidas(p->dir);
    }
  }
}

int consulta(TipoArvore p, int info)
{
  if (p != NULL)
  {
    if (p->dado.hashcode == info)
      cout << "Salinidade: " << p->dado.salinidade << " || Temperatura: " << p->dado.temperatura << endl;
    else if (info < p->dado.hashcode)
      return consulta(p->esq, info);
    else
      return consulta(p->dir, info);
  }
  else
    return 0;
}
