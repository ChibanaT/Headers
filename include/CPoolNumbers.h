class CPoolNumbers
{

    typedef struct xxx{
        int value;
        struct xxx *prox;
    } Elem;

    private:

        Elem *free;
        int *used;

    public:

        int qtdTotal;

        CPoolNumbers(int qtd){
            qtdTotal = qtd;
            free = Null;
            Elem *aux;
            for (int i = 0; i < qtd; i++){
                aux = (Elem*) malloc(sizeof(Elem));
                aux -> value = i;
                aux -> prox = free;
                free = aux;
            }
            used = (int*) calloc(sizeof(int), qtd);
        }

        ~CPoolNumbers(){
            Elem *aux, *ret;
            aux = free;
            while (aux){
                ret = aux -> prox;
                free(aux);
                aux = ret;
            }
            free(used);            
        }

        int RemoveFree(){
            Elem *aux = free;
            free = free -> prox;
            used [aux -> value] = 1;
            
            return aux -> value;
        }

        void ReturnUsed(int value){
            if (used[value] == 0){
                // printf ("Return error %d\n", value);
                
                return;
            }

            used[value] = 0;
            Elem* aux = (Elem*) malloc(sizeof(Elem));
            aux -> value = value;
            aux -> prox = free;
            free = aux;
        }

        void PrintFree(){
            for (int i = 0; i < qtdTotal; i++){
                if (used[i] == 0)
                    printf("%d\n", i);
            }
        }

        void PrintUsed(){
            for (int i = 0; i < qtdTotal; i++){
                if (used[i] == 0)
                    printf("%d\n", i);
            }
        }
};

typedef CPoolNumbers* PoolNumbers;