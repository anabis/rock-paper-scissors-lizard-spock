typedef struct weapon weapon;
struct weapon
{
    char *name;
    int winTable[5];
    char *verbs[2];
};

int randomInt(int from, int to);
void generateVerb(int winner, int looser, weapon *type);
int checkAnswer(char *answer, weapon *type);
int tolower(int c);
time_t time(time_t *t);
void printBattle(int me, int com, weapon *type, int *scoreMe, int *scoreCom);
