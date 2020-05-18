// Mini project on rock,paper,scissors game

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int rand_i(int n)
{
	int rand_max = RAND_MAX - (RAND_MAX % n);
	int ret;
	while ((ret = rand()) >= rand_max);
	return ret/(rand_max / n);
}

int weighed_rand(int *tbl, int len)
{
	int i, sum, r;
	for (i = 0, sum = 0; i < len; sum += tbl[i++]);
	if (!sum) return rand_i(len);

	r = rand_i(sum) + 1;
	for (i = 0; i < len && (r -= tbl[i]) > 0; i++);
	return i;
}



int main(int argc, const char *argv[])
{
	char usermove[10], compmove[10], line[155];
	int user, comp;
	int tbl[]={0,0,0};
	int tbllen=3;
	printf("\tHello, Welcome to rock-paper-scissors game\n\t\tBy The BB's Pro\n");
mainloop:
	while(1)
	{
		printf("\n\nPlease type in 1 for Rock, 2 For Paper, 3 for Scissors, 4 for Quit\n");
		srand(time(NULL));
		comp = (weighed_rand(tbl, tbllen) + 1) % 3;
		fgets(line, sizeof(line), stdin);
		while(sscanf(line, "%d", &user) != 1)
		{
  			printf("You have not entered an integer.\n");
			fgets(line, sizeof(line), stdin);
		}
		if( (user > 4) || (user < 1) )
		{
			printf("Please enter a valid number!\n");
			continue;
		}
		switch (comp)
		{
			case 1 :
				strcpy(compmove, "Rock");
				break;
			case 2 :
				strcpy(compmove, "Paper");
				break;
			case 3 :
				strcpy(compmove, "Scissors");
				break;
			default :
				printf("Computer Error, set comp=1\n");
				comp=1;
				strcpy(compmove, "Rock");
				break;
		}
		switch (user)
		{
			case 1 :
				strcpy(usermove, "Rock");
				break;
			case 2 :
				strcpy(usermove, "Paper");
				break;
			case 3 :
				strcpy(usermove, "Scissors");
				break;
			case 4 :
				printf("Goodbye! Thanks for playing!\n");
				return 0;
			default :
				printf("Error, use number not between 1-4 exiting...");
				goto mainloop;
		}
		if( (user+1)%3 == comp )
		{
			printf("Comp Played: %s\nYou Played: %s\nSorry, You Lost!\n", compmove, usermove);
		}
		else if(comp == user)
		{
			printf("Comp Played: %s\nYou Played: %s\nMatch Tied !\n", compmove, usermove);
		}
		else
		{
			printf("Comp Played: %s\nYou Played: %s\nHurray, You Won!:)\n", compmove, usermove);
		}

	}
	return 0;
}
