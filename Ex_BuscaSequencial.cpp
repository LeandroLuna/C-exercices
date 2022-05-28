int busca_sequencial(struct reg vet[], int num, int chave)
{
    int i, pos = -1;
    int achou = 0;
    for (i = 0; i < num && achou == 0; i++)
    {
        if (vet[i].dado == chave)
        {
            achou = 1;
            pos = i;
        }
    }
    return (pos);
}
