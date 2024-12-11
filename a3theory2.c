#include <stdio.h>
#include <string.h>

typedef struct {
    char playerName[50];
    int ballScores[12];
    int totalScore;
} Player;

int main() {
    Player player1,player2;
    
    printf("Enter Player name: ");
    scanf(" %s", player1.playerName);
    printf("Enter Player 2 name: ");
    scanf(" %s", player2.playerName);

    player1.totalScore = 0;
    player2.totalScore = 0;

    printf("\n%s, Enter your scores for 12 balls:\n", player1.playerName);
    for (int i=0; i<12; i++) {
        int score;
        printf("Ball %d:",i + 1);
        scanf("%d", &score);

        if (score >= 0 && score <= 6) {
            player1.ballScores[i] = score;
            player1.totalScore += score;
        } else {
            printf("Invalid score! Score disregarded.\n");
            player1.ballScores[i] = 0;
        }
    }
    printf("\n%s, Enter your scores for 12 balls:\n", player2.playerName);
    for (int i = 0; i < 12; i++) {
        int score;
        printf("Ball %d: ",i + 1);
        scanf("%d", &score);

        if (score >= 0 && score <= 6) {
            player2.ballScores[i] = score;
            player2.totalScore += score;
        } else {
            printf("Invalid score! Score disregarded.\n");
            player2.ballScores[i] = 0;
        }
    }

    printf("\nMatch Result:\n");
    if (player1.totalScore > player2.totalScore) {
        printf("%s wins with %d runs!\n", player1.playerName, player1.totalScore-player2.totalScore);
    } else if (player1.totalScore < player2.totalScore) {
        printf("%s wins with %d runs!\n", player2.playerName, player2.totalScore-player1.totalScore);
    } else {
        printf("The match is a tie with both scoring %d runs!\n", player1.totalScore);
    }

    printf("\nMatch Scoreboard:\n");
    for (int i = 0; i < 2; i++) {
        Player current = (i == 0) ? player1 : player2;
        printf("\n%s Performance:\n", current.playerName);
        printf("Scores: ");
        for (int j = 0; j < 12; j++) {
            printf("%d ", current.ballScores[j]);
        }
        printf("\nTotal Score: %d\n", current.totalScore);
        printf("Average Score: %.2f\n", current.totalScore / 12.0);
    }
    return 0;
}
