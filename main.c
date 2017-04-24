#include <stdio.h>
#include <stdlib.h>
#include "album_data.h"

int main()
{
    song_t songs[100];
    FILE* list = fopen("album.txt", "r");
    
    read_listing(list, songs);
    
    
    return EXIT_SUCCESS;
}
