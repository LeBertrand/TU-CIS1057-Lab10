#include <stdio.h>
#include <stdlib.h>

#ifndef ALBUM_DATA_H
#define ALBUM_DATA_H

#define MAX_ALBUM_ARTIST  70
#define MAX_SONG_TITLE  25

typedef struct{
    char title[MAX_SONG_TITLE], album[MAX_ALBUM_ARTIST],
		seconds[MAX_ALBUM_ARTIST];
} song_t;

void selection_sort_category(song_t listing[], int category, int length)
{
    //The sublist containing all indices less than this number is sorted
    int sorted_until;

    //inner counting loop will use this
    int index;
	
	for( sorted_until = 0; sorted_until < length; sorted_until++){
		
	}
}

int read_listing(FILE *input, song_t s[])
{
	int song_number = 0;
	char current_read;
	int finished = 0;
	while(!finished){
		 current_read = fgets(input);
	}
}
#endif ALBUM_DATA_H
