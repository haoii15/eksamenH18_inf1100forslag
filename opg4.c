
typedef struct kontrollelement kontrollelement_t;
struct kontrollelement {
    int kode;
    double strekktid;
};


int kontroll(list_t *spor, list_t *fasit)
{
    listiter_t* sporiter = list_createiter(spor);
    listiter_t* fasititer = list_createiter(fasit);
    kontrollelement_t* spor, *fasit;
    fasit = list_next(fasititer);

    while (fasit != NULL)
    {
        spor = list_next(sporiter);
        if (spor == NULL)
            return 0;

        if (fasit->kode != spor->kode)
            return 0;
    }

    return 1;
}