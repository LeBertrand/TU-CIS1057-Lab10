#include <stdio.h>
#include <stdlib.h>
#include "album_data.h"

int main()
{
    song_t songs[200];
    FILE* list;
    
    list = fopen("album.txt", "r");
    
    int num_songs = read_listing(list, songs);
    
    int sort_code = prompt_sort();
    
    printTable(songs, num_songs, sort_code);
    
    return EXIT_SUCCESS;
}
