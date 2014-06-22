#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "main.h"

int main(int argc, char const *argv[])
{

	int endGame = 0;
	char reponse[9];
	int comPrecedent;
	int me, com;
	int scoreMe=0, scoreCom=0;
	//int lastFourA[] = {0,0,0,0};
	int nbCoups = 0;
	int i;

	weapon type[5];

	type[0].name = "rock";
	type[0].winTable[0] = 2, type[0].winTable[1] = 0, type[0].winTable[2] = 1, type[0].winTable[3] = 1, type[0].winTable[4] = 0;
	type[0].verbs[0] = "crushes";
	type[0].verbs[1] = "crushes";
	
	type[1].name = "paper";
	type[1].winTable[0] = 1, type[1].winTable[1] = 2, type[1].winTable[2] = 0, type[1].winTable[3] = 0, type[1].winTable[4] = 1;
	type[1].verbs[0] = "covers";
	type[1].verbs[1] = "disproves";
	
	type[2].name = "scissors";
	type[2].winTable[0] = 0, type[2].winTable[1] = 1, type[2].winTable[2] = 2, type[2].winTable[3] = 1, type[2].winTable[4] = 0;
	type[2].verbs[0] = "cut";
	type[2].verbs[1] = "decapitate";
	
	type[3].name = "lizard";
	type[3].winTable[0] = 0, type[3].winTable[1] = 1, type[3].winTable[2] = 0, type[3].winTable[3] = 2, type[3].winTable[4] = 1;
	type[3].verbs[0] = "eats";
	type[3].verbs[1] = "poisons";
	
	type[4].name = "spock";
	type[4].winTable[0] = 1, type[4].winTable[1] = 0, type[4].winTable[2] = 1, type[4].winTable[3] = 0, type[4].winTable[4] = 2;
	type[4].verbs[0] = "smashes";
	type[4].verbs[1] = "vaporizes";


	
	system("clear");
	printf("====================================\n");
	printf("| ROCK PAPER SCISSORS LIZARD SPOCK |\n");
	printf("====================================\n");
	printf("\nScissors cut paper.\nPaper covers rock.\nRock crushes lizard.\nLizard poisons Spock.\nSpock smashes scissors.\nScissors decapitate lizard.\nLizard eats paper.\nPaper disproves Spock.\nSpock vaporizes rock.\nRock crushes scissors.\n\n");

	while(!endGame)
	{
		do
		{
			printf("\nYour choice : ");
			scanf("%s", reponse);

			for(i=0;i<strlen(reponse);i++)
				reponse[i] = tolower(reponse[i]);

		} while(!checkAnswer(reponse, type));

		system("clear");

		me = checkAnswer(reponse, type) - 1;
		do
		{
			com = randomInt(0, 5);
		}while(com==comPrecedent);
		comPrecedent = com;
		nbCoups++;

		printBattle(me, com, type, &scoreCom, &scoreMe);
		printf("\n> COM : %d You : %d\n", scoreCom, scoreMe);

	}

	return 0;
}

int randomInt(int from, int to)
{
	to = to - from;
	srand(time(NULL));
	return rand()% to + from;
}

int checkAnswer(char *answer, weapon *type)
{
	int i;
	for(i=0;i<5;i++)
	{
		if(strcmp(answer, type[i].name) == 0)
			return i+1;
	}
	return 0;
}

void generateVerb(int winner, int looser, weapon *type)
{
	int i;
	int rangWin1;
	for(i=0;i<5;i++)
	{
		if(type[winner].winTable[i] == 1)
		{
			rangWin1 = i;
		}
	}
	i=0;
	if(rangWin1 == looser)
	{
		printf("%s",type[winner].verbs[0]);
	}
	else
	{
		printf("%s",type[winner].verbs[1]);
	}
}

void printBattle(int me, int com, weapon *type, int *scoreCom, int *scoreMe)
{
	int battle;

	printf("> You chose %s. Computer chose %s\n", type[me].name, type[com].name);

	battle = type[me].winTable[com];

	if(battle == 1)
	{
		printf("\n> %s ", type[me].name);
		generateVerb(me, com, type);
		printf(" %s.\n", type[com].name);
		printf("\n> You win this round.");
		*scoreMe += 1;
	}
	else if(battle == 0)
	{
		printf("\n> %s ", type[com].name);
		generateVerb(com, me, type);
		printf(" %s.\n", type[me].name);
		printf("\n> You lost this round.");
		*scoreCom += 1;
	}
	else if(battle == 2)
	{
		printf("\n> It's a tie.\n");
	}
}
