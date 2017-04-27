#include <stdio.h>
#include <stdlib.h>
#include "album_data.h"

song_t songs[5];

int
main()
{
    FILE* input = fopen("AbbridgedText.txt", "r");
    
    read_listing(input, songs);
    
    return EXIT_SUCCESS;
}