#ifndef ALBUM_DATA_H
#define ALBUM_DATA_H

const int MAX_FIELD = 40;

typedef struct{
    char[] title, album, seconds;
} song_t;

void selection_sort_category(song_t[] listing, int category, int length)
{
    //The sublist containing all indices less than this number is sorted
    int sorted_until;

    //inner counting loop will use this
    int index;
	
	for( sorted_until = 0; sorted_until < length; sorted_until++){
		
	}
}

int read_listing(FILE* input, song_t[])
{
	int song_number = 0;
	char current_read;
	int finished = 0;
	while(!finished){
		 current_read = fgets(input
	}
}
#endif ALBUM_DATA_H
