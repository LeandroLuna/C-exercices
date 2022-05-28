int busca_sequencial_exaustiva(struct reg bd[], int num, int chave,
                               struct reg encontrados[])
{
    int i, ne = 0;
    for (i = 0; i < num; i++)
    {
        if (bd[i].chave == chave)
        {
            encontrado[ne] = bd[i]; /*armazena registro da posição em que a chave foi encontrada */
            ne++;
        }
    }
    return (ne); /* qtd de registros com a chave procurada*/
}
