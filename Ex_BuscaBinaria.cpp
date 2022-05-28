int busca_binaria(struct reg vet[], int num, int chave)
{
    int i_baixo = 0, i_alto = num - 1, i_medio;
    int achou = 0;
    int pos = -1;
    while (achou != 1 && i_baixo <= i_alto)
    {
        i_medio = (i_baixo + i_alto) / 2;
        if (chave == vet[i_medio].dado)
        {
            pos = i_medio;
            achou = 1;
        }
        else
        {
            if (chave < vet[i_medio].dado)
                i_alto = i_medio - 1;
            else
                i_baixo = i_medio + 1;
        }
    }
    return (pos);
}
