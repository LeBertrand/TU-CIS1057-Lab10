#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SONG_TITLE 100
#define MAX_ALBUM_ARTIST 100


//song structure holds info of one song
typedef struct
{
    char title[MAX_SONG_TITLE], artist[MAX_ALBUM_ARTIST];
    int seconds;
} song_t;

int read_listing(FILE*, song_t[], int);

int
main()
{
    
    song_t songs[5];
    
    FILE* output = fopen("output.txt", "w");
    fclose(output);
    FILE* input = fopen("output.txt", "r");
    
    int lines = 1;
    char letter = ' ';
    
    while(letter != EOF){
        letter = getc(input);
        if(letter == '\n'){
            lines++;
        }
    }
    
    /* read_listing(input, songs, lines);
    
    int index;
    
    for(index = 0; index < 3; index++){
        puts(songs[index].title);
        puts(" | ");
    } */
    
    //printf("%d lines in document.\n", lines);
    
    char next_line[MAX_ALBUM_ARTIST];
    fgets(next_line, MAX_ALBUM_ARTIST, input);
    printf("%s\n", next_line);
    
    return EXIT_SUCCESS;
}

/*
 * Function:	read_listing
 * Programmer:	Shmuel Jacobs
 * Date:	April 26
 * Input:	input - path to file
 * Outputs:	song_list - array to fill with song_t structures
 * Returns: number of songs read in
 * Globals:	none
 * Description:	Given a pointer to a file of track listings, read in data
                and store in a list of song_t structs.
 */
int read_listing(FILE *input, song_t song_list[], int lines)
{
    //keep track of what track reached in the listings
    int song_number = 1;

    //last album name read in
    char current_album[MAX_ALBUM_ARTIST];

    //store next line for decision making
    char next_line[MAX_ALBUM_ARTIST];
    char* done = fgets(next_line, MAX_ALBUM_ARTIST, input) ;
    int lines_read = 0;
    
    do
    {
        if(next_line[0] != '*')
        {
            song_t track_builder;
            
            //get title
            next_line[strlen(next_line) - 1] = '\0';
            strcpy(track_builder.title, next_line);
            lines_read++;
            
            //get artist
            fgets(next_line, MAX_ALBUM_ARTIST, input);
            next_line[strlen(next_line) - 1] = '\0';
            strcpy(track_builder.artist, next_line);
            lines_read++;
            
            //get time
            fgets(next_line, MAX_ALBUM_ARTIST, input);
            int time = atoi(next_line);
            track_builder.seconds = time;
            lines_read++;
            
            //put into list
            song_list[song_number - 1] = track_builder;
                
            //done with this song--advance index by one
            song_number++;
            }
        done = fgets(next_line, MAX_ALBUM_ARTIST, input) ;
    }while(lines_read < lines);
    return song_number;
}