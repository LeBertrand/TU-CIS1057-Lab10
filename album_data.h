#include <stdio.h>
#include <stdlib.h>

#ifndef ALBUM_DATA_H
#define ALBUM_DATA_H
<<<<<<< HEAD
#define MAX_ALBUM_ARTIST  70
#define MAX_SONG_TITLE  25
=======

#define MAX_ALBUM_ARTIST  71
#define MAX_SONG_TITLE  26
#define MAX_TIME 5
>>>>>>> stash

//song structure holds info of one song
typedef struct{
    char title[MAX_SONG_TITLE], album[MAX_ALBUM_ARTIST],
		seconds[MAX_ALBUM_ARTIST];
} song_t;

//array holds all song structures
song_t all_songs[100];

//explicit response coding makes passing category to sort function clearer
typedef enum{
	title, artist, time
} cgry;

void selection_sort_category(song_t listing[], int category, int length)
{
    //The sublist containing all indices less than this number is sorted
    int sorted_until;

    //inner counting loop will use this
    int index;
	
	//visit every element in the list once
	for( sorted_until = 0; sorted_until < length; sorted_until++){
		//check all items after the current one, looking for smallest
		int loc_smallest = sorted_until;
		for( index = sorted_until; index < length; index++){
			//case: we found a new smallest
			if(listing[index] < listing[loc_smallest]){
				loc_smallest = index;
			}
		}//loop ends--we found smallest
		//swaps go here
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
