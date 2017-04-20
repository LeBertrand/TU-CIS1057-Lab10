#include <stdio.h>
#include <stdlib.h>

#ifndef ALBUM_DATA_H
#define ALBUM_DATA_H
#define MAX_ALBUM_ARTIST  70
#define MAX_SONG_TITLE  25

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
