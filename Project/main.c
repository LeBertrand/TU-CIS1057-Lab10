#include <stdio.h>
#include <stdlib.h>
#include "album_data.h"

int main()
{
    song_t songs[100];
    FILE* list;
    
    //open file of track listings
    list = fopen("album.txt", "r");
    
    //find out how many lines to read
    int lines = 1;
    char letter = ' ';
    
    while(!feof(list)){
        letter = getc(list);
        if(letter == '\n'){
            lines++;
        }
    }
    fclose(list);
    
    //re-open file to read into list of tracks
    list = fopen("album.txt", "r");
    int num_songs = read_listing(list, songs, lines);
    
    int sort_code = prompt_sort();
    programOperate(songs, num_songs, sort_code);
    
    fclose(list);
    return EXIT_SUCCESS;
}
