#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int main() {
    srand((unsigned int)time(NULL));

    char *boys[] = {"pronoy", "suvadeep", "soumayraj", "spandhan", "ankur", "chandra"};

    char *team1[3];
    char *team2[3];

    int isNameInTeam(char **team, int teamSize, char *name) {
        for (int i = 0; i < teamSize; i++) {
            if (team[i] != NULL && strcmp(team[i], name) == 0) {
                return 1; 
            }
        }
        return 0;  
    }

    for (int i = 0; i < 3; i++) {
        int randomNumber;
        do {
            randomNumber = rand() % 6;  
        } while (isNameInTeam(team1, i, boys[randomNumber]));

        team1[i] = boys[randomNumber];
    }

    for (int i = 0; i < 3; i++) {
        int randomNumber;
        do {
            randomNumber = rand() % 6; 
        } while (isNameInTeam(team1, 3, boys[randomNumber]) || isNameInTeam(team2, i, boys[randomNumber]));

        team2[i] = boys[randomNumber];
    }

    printf("Team 1 has:\n");
    for (int i = 0; i < 3; i++) {
        printf("Team member %d: %s\n", i, team1[i]);
    }

    printf("\nTeam 2 has:\n");
    for (int i = 0; i < 3; i++) {
        printf("Team member %d: %s\n", i, team2[i]);
        
    }

    return 0;
}
