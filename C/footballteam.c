// This program loads football team data from a file, displays it,
// calculates average points, counts how many teams played 33 or 34 games,
// and lists teams with 3 consecutive wins based on recent form.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct teams
{
    int played;
    int points;
    char name[20];
    char form[6];
};

typedef struct teams *team;

team load_data(char *, int *);
void display_data(team, int *);
void process_data(team, int *, char *);

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    int size;
    team teams = load_data(argv[1], &size);

    if (teams == NULL) {
        return 1;
    }

    display_data(teams, &size);
    process_data(teams, &size, argv[1]);

    free(teams);
    return 0;
}

team load_data(char *file, int *size)
{
    FILE *infile;
    int count = 0;
    struct teams temp;
    team team_info;
    int i;

    infile = fopen(file, "r");
    if (infile == NULL)
    {
        printf("A problem occurred when processing the file.\n");
        return NULL;
    }

    /* Count valid records */
    while (fscanf(infile, "%d %d %19s %5s",
                  &temp.played, &temp.points, temp.name, temp.form) == 4)
    {
        count++;
    }

    if (count == 0)
    {
        fclose(infile);
        *size = 0;
        return NULL;
    }

    rewind(infile);
    *size = count;

    team_info = malloc(sizeof(struct teams) * count);
    if (team_info == NULL)
    {
        printf("Memory allocation failed.\n");
        fclose(infile);
        return NULL;
    }

    for (i = 0; i < *size; i++)
    {
        if (fscanf(infile, "%d %d %19s %5s",
                   &team_info[i].played, &team_info[i].points,
                   team_info[i].name, team_info[i].form) != 4)
        {
            printf("Invalid data format in file.\n");
            free(team_info);
            fclose(infile);
            return NULL;
        }
    }

    fclose(infile);
    return team_info;
}

void display_data(team team_info, int *size)
{
    int i;
    printf("Your data is successfully processed and looks as follows:\n");
    printf("Team\tPlayed\tPoints\tForm\n");

    for (i = 0; i < *size; i++)
    {
        printf("%s\t%d\t%d\t%s\n",
               team_info[i].name,
               team_info[i].played,
               team_info[i].points,
               team_info[i].form);
    }
}

void process_data(team teams_info, int *size, char *file)
{
    int i;
    float avg_points = 0, total = 0;
    int check33 = 0, check34 = 0;

    for (i = 0; i < *size; i++)
    {
        total += teams_info[i].points;

        if (teams_info[i].played == 33)
            check33++;
        if (teams_info[i].played == 34)
            check34++;
    }

    if (*size > 0)
        avg_points = total / (*size);

    printf("\nAverage points: %.2f\n", avg_points);
    printf("%d teams played 33 games and %d teams played 34 games\n", check33, check34);

    printf("These teams have three consecutive wins:\n");
    for (i = 0; i < *size; i++)
    {
        if (strstr(teams_info[i].form, "WWW") != NULL)
        {
            printf("%s\n", teams_info[i].name);
        }
    }
}
