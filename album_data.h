#include <stdio.h>
#include <stdlib.h>

#ifndef ALBUM_DATA_H
#define ALBUM_DATA_H

#define MAX_ALBUM_ARTIST  71
#define MAX_SONG_TITLE  26
#define MAX_TIME 5

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

int read_listing(FILE *input, song_t song_list[])
{
	//keep track of what track reached in the listings
	int song_number = 0;

	//last album name read in
	char current_album[MAX_ALBUM_ARTIST];

	//store next line for descision making
	char next_line[MAX_ALBUM_ARTIST];
	while(1){
		//read in next line
		char* done = fgets(next_line, MAX_SONG_TITLE, input);
		//case: reached end of file
		if(done == NULL){
			break;
		}
		//case: line doesn't hold a title
		if(next_line[0] != '*'){
			strcpy(song_list[song_number].title, next_line);
			//get artist
			fgets(next_line, MAX_ALBUM_ARTIST, input);
			strcpy(song_list[song_number].artist, next_line);
			//get time
			fgets(next_line, MAX_ALBUM_ARTIST, input);
			strcpy(song_list[song_number], input);

			//done with this song--advance index by one
			song_number++
		}		
	}
}
#endif ALBUM_DATA_H
