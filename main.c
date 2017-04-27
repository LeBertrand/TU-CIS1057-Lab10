#include <stdio.h>
#include <stdlib.h>
#include "album_data.h"

int main()
{
    song_t songs[100];
    FILE* list;
    
    list = fopen("album.txt", "r");
    
    int numSongs = read_listing(list, songs);
    
    printf("EXIT_SUCCESS");
    return EXIT_SUCCESS;
}
