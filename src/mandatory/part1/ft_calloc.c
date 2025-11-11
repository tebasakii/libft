void *calloc(size_t count, size_t size)
{
    void *ptr = malloc(count * size);
    unsigned char *p;

    p = (unsigned char *)ptr;
    size_t i;
    i = 0;
    while(i < count * size)
    {
        p[i++] = 0;
    }

    free(ptr);
    return (ptr);
}