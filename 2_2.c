int mgetline(char line[], int lim) 
{
    int i, c;
    for (i = 0; i < lim - 1; ++i) 
    {
        c = getchar();
        if (c == EOF)
            break;
        if (c == '\n')
            break;
        line[i] = c;
    }

    if (c == '\n') 
    {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}
