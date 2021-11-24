
typedef struct kontrollelement kontrollelement_t;
struct kontrollelement {
    int kode;
    double strekktid;
};

// Oppgave A
int kontroll(list_t *spor, list_t *fasit)
{
    // Deklarerer iteratorer for hver liste og kontrollelement-pekere for hver liste
    listiter_t* sporiter = list_createiter(spor);
    listiter_t* fasititer = list_createiter(fasit);
    kontrollelement_t* spor, *fasit;

    // henter ut første item fra fasit
    fasit = list_next(fasititer);

    // Loopen itererer gjennom fasit 
    while (fasit != NULL)
    {
        // Henter et og et item fra spor lista
        spor = list_next(sporiter);

        // Dersom spor er null, har ikke deltakeren hvert innom alle postene
        if (spor == NULL)
            return 0;

        // Dersom kodene ikke er like, har deltakeren ikke hvert innom i korrekt rekkefølge
        if (fasit->kode != spor->kode)
            return 0;
    
        fasit = list_next(fasititer);
    }

    return 1;
}

// Oppgave B
double tid(list_t *spor)
{
    // Deklarer iterator og kontrollelement-peker
    listiter_t* iter = list_createiter(spor);
    kontrollelement_t* elem = list_next(iter);

    // Lager en variabel til å lagre totaltiden
    double totaltid = 0;

    // Itererer lista
    while (elem != NULL)
    {
        // Legger til hver strekktid på totaltid
        totaltid += elem->strekktid;

        // henter ut neste item
        elem = list_next(iter);
    }

    // Returnerer den totale tiden
    return totaltid;
}

double bestetid(list_t *godkjente)
{
    // Deklarerer variabler som brukes i funksjonen
    double best = 0;
    double current;

    // Lager iterator og listepeker
    listiter_t* iter = list_createiter(godkjente);
    list_t* deltaker = list_next(iter);

    // Itererer den ytterste lista
    while (deltaker != NULL)
    {
        // Bruker tid funksjonen til å regne ut den totale tida for hver deltaker
        current = tid(deltaker);

        // Setter best til å være current tiden når best er 0, dvs første iterasjon
        if (best = 0)
            best = current;

        // Deretter endres kun best hvis current er mindre enn best
        else if (current < best)
            best = current;
    }

    // Returnerer best, som er den laveste totaltiden
    return best;
}