#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#ifndef ALBUM_DATA_H
#define ALBUM_DATA_H

#define MAX_ALBUM_ARTIST  80
#define MAX_SONG_TITLE  80
#define MAX_TIME 5


//song structure holds info of one song
typedef struct
{
    char title[MAX_SONG_TITLE], artist[MAX_ALBUM_ARTIST];
    int seconds;
} song_t;

//array holds all song structures
//song_t all_songs[100];
/* This would all be a lot easier with a linked list.
Just move the nodes */

void swap_songs(song_t*, song_t*);

//string makes space for Track, pad, Title, pad, Artist, pad, minutes, seconds
const char* TITLE_FORMAT_STRING = "\t%-5d%-30s%-50s%d:%2.2d\n";

const char* ARTIST_FORMAT_STRING = "\t%-5d%-50s%-30s%d:%2.2d\n";
//Track, pad, minutes, seconds, pad, Title, pad, Artist
const char* TIME_FORMAT_STRING = "\t%-5d%d:%-40.2d%-40s%5s\n";

/*
typedef enum
{
    title, artist, time
} cgry; */

/*
void selection_sort_category(song_t listing[], int category, int length)
{
    //The sublist containing all indices less than this number is sorted
    int sorted_until;

    //inner counting loop will use this
    int index;

    //visit every element in the list once
    for( sorted_until = 0; sorted_until < length; sorted_until++)
    {
        //check all items after the current one, looking for smallest
        int loc_smallest = sorted_until;
        for( index = sorted_until; index < length; index++)
        {
            //case: we found a new smallest
            if(listing[index] < listing[loc_smallest])
            {
                loc_smallest = index;
            }
        }//loop ends--we found smallest
        swap_songs(&listing[loc_smallest], &listing[sorted_until]);
    }
}
*/

/*
 * Function:	selection_sort_title_ascending
 * Programmer:	Shmuel Jacobs
 * Date:	April 26
 * Input:	listing - array of songs to sort by title
            length - number of songs in the listing
 * Outputs:	listing - songs, now sorted
 * Returns: none
 * Globals:	none
 * Description:	Given an array of song_t structures, sort by value.
 */
void selection_sort_title_ascending(song_t listing[], int length)
{
    //The sublist containing all indices less than this number is sorted
    int sorted_until;

    //inner counting loop will use this
    int index;

    //visit every element in the list once
    for( sorted_until = 0; sorted_until < length; sorted_until++)
    {
        //check all items after the current one, looking for smallest
        int loc_smallest = sorted_until;
        for( index = sorted_until; index < length; index++)
        {
            //compare current song title to earliest title so far
            int comp = strcmp(listing[index].title, listing[loc_smallest].title);
            //case: title at index should come first
            if(comp < 0)
            {
                loc_smallest = index;
            }
        }//loop ends--we found smallest
        swap_songs(&listing[loc_smallest], &listing[sorted_until]);
    }
}

/*
 * Function:	selection_sort_artist_ascending
 * Programmer:	Shmuel Jacobs
 * Date:	April 26
 * Input:	listing - array of songs to sort by artist
            length - number of songs in the listing
 * Outputs:	listing - songs, now sorted
 * Returns: none
 * Globals:	none
 * Description:	Given an array of song_t structures, sort by value.
 */
void selection_sort_artist_ascending(song_t listing[], int length)
{
    //The sublist containing all indices less than this number is sorted
    int sorted_until;

    //inner counting loop will use this
    int index;

    //visit every element in the list once
    for( sorted_until = 0; sorted_until < length; sorted_until++)
    {
        //check all items after the current one, looking for smallest
        int loc_smallest = sorted_until;
        for( index = sorted_until; index < length; index++)
        {
            //compare current song artist to earliest artist so far
            int comp = strcmp(listing[index].artist, listing[loc_smallest].artist);
            //case: artist at index should come first
            if(comp < 0)
            {
                loc_smallest = index;
            }
        }//loop ends--we found smallest
        swap_songs(&listing[loc_smallest], &listing[sorted_until]);
    }
}

/*
 * Function:	selection_sort_seconds_ascending
 * Programmer:	Shmuel Jacobs
 * Date:	April 26
 * Input:	listing - array of songs to sort by song length
            length - number of songs in the listing
 * Outputs:	listing - songs, now sorted
 * Returns: none
 * Globals:	none
 * Description:	Given an array of song_t structures, sort by value.
 */
void selection_sort_seconds_ascending(song_t listing[], int length)
{
    //The sublist containing all indices less than this number is sorted
    int sorted_until;

    //inner counting loop will use this
    int index;

    //visit every element in the list once
    for( sorted_until = 0; sorted_until < length; sorted_until++)
    {
        //check all items after the current one, looking for smallest
        int loc_smallest = sorted_until;
        for( index = sorted_until; index < length; index++)
        {
            //compare current song length to least length so far
            int comp = listing[index].seconds - listing[loc_smallest].seconds;
            //case: title at index should come first
            if(comp < 0)
            {
                loc_smallest = index;
            }
        }//loop ends--we found smallest
        swap_songs(&listing[loc_smallest], &listing[sorted_until]);
    }
}

/*
 * Function:	swap_songs
 * Programmer:	Shmuel Jacobs
 * Date:	April 26
 * Input:	first_listing, second_listing - locations of songs to swap
 * Outputs:	none
 * Returns: none
 * Globals:	none
 * Description:	Given locations of two song_t structures, swap them.
 */
void swap_songs( song_t *first_listing, song_t *second_listing)
{
    if(first_listing != second_listing)
    {
        song_t holder = * first_listing;
        *first_listing = *second_listing;
        *second_listing = holder;
    }
}

void print_by_title(song_t song, int i);


/*
 * Function:	read_listing
 * Programmer:	Shmuel Jacobs
 * Date:	April 26
 * Input:	input - path to file
            lines - number of lines in fill
 * Outputs:	song_list - array to fill with song_t structures
 * Returns: number of songs read in
 * Globals:	none
 * Description:	Given a pointer to a file of track listings, read in data
                and store in a list of song_t structs.
 */
int read_listing(FILE *input, song_t song_list[], int lines)
{
    //keep track of what track reached in the listings
    int song_number = 1;

    //last album name read in
    char current_album[MAX_ALBUM_ARTIST];

    //store next line for decision making
    char next_line[MAX_ALBUM_ARTIST];
    char* done = fgets(next_line, MAX_ALBUM_ARTIST, input) ;
    int lines_read = 0;
    
    do
    {
        if(next_line[0] != '*')
        {
            song_t track_builder;
            
            //get title
            next_line[strlen(next_line) - 1] = '\0';
            strcpy(track_builder.title, next_line);
            lines_read++;
            
            //get artist
            fgets(next_line, MAX_ALBUM_ARTIST, input);
            next_line[strlen(next_line) - 1] = '\0';
            strcpy(track_builder.artist, next_line);
            lines_read++;
            
            //get time
            fgets(next_line, MAX_ALBUM_ARTIST, input);
            int time = atoi(next_line);
            track_builder.seconds = time;
            lines_read++;
            
            //put into list
            song_list[song_number - 1] = track_builder;
                
            //done with this song--advance index by one
            song_number++;
            }
        done = fgets(next_line, MAX_ALBUM_ARTIST, input) ;
    }while(lines_read < lines);
    return song_number;
}

/*
 * Function:	prompt_sort
 * Programmer:	Shmuel Jacobs
 * Date:	April 26
 * Input:	none
 * Outputs:	none
 * Returns: two digit code, in which first digit indicates category to sort -
            1: title, 2: artist, 3: length - and sort up or down -
            0: ascending, 1: descending
 * Globals:	none
 * Description:	Ask user for instructions for sorting, then return
                a two digit code indicating response
 */
int prompt_sort()
{
    printf("Choose how to sort listings.");
    printf("Type 1 to sort by title, 2 by artist, or 3 by track length.");
    int cat;
    scanf("%d", &cat);
    while( 3 < cat || cat < 0){
        printf("Invalid input.");
        printf("Type 1 to sort by title, 2 by artist, or 3 by track length.");
        scanf("%d", &cat);
    }
    cat *= 10;
    
    printf("Type 1 to sort ascending, or 2 to sort descending.");
    int up;
    scanf("%d", &up);
    while( up != 1 && up != 2){
        printf("Invalid input.");
        printf("Type 1 to sort ascending, or 2 to sort descending.");
        scanf("%d", &up);
    }
    
    //return is two digit code: first digit is category, second is up/down
    return up + cat - 1;
}

void print_by_title(song_t song, int i)
{
    printf(TITLE_FORMAT_STRING, i, song.title, song.artist, song.seconds/60, song.seconds%60);
}

void print_by_artist(song_t song, int i)
{
    printf(ARTIST_FORMAT_STRING, i, song.artist, song.title, song.seconds/60, song.seconds%60);
}

void print_by_time(song_t song, int i)
{
    printf(TIME_FORMAT_STRING, i, song.seconds/60, song.seconds%60, song.title, song.artist);
}

/*
 * Function:	programOperate
 * Programmer:	Shmuel Jacobs
 * Date:	April 26
 * Input:	songs - list of song
            length - number of songs in list
 * Outputs:	none
 * Returns: none
 * Globals:	none
 * Description:	Print out a table of all songs in the given list, sorted and formatted.
 * This essentially is the program logic. The only thing higher level is the main call.
 */
void programOperate(song_t songs[], int length, int cat_asc_code)
{
    //get category from first digit of cat_asc_code
    int cat = cat_asc_code/10;
    //char *format_string;
    void (*pf)(song_t, int);
    int down = cat_asc_code%10;
    int index;
    
    //sort array and choose format string
    switch(cat){
        case 1:
            selection_sort_title_ascending(songs, length);
            //format_string = TA_FORMAT_STRING;
            pf = print_by_title;
            //print appropriate heading
            printf("\t%-40s%-40s%s\n", "Title", "Artist", "Time");
            break;
        case 2:
            selection_sort_artist_ascending(songs, length);
            //format_string = TA_FORMAT_STRING;
            pf = print_by_artist;
            //print appropriate heading
            printf("\t%-40s%-40s%s\n", "Artist", "Title", "Time");
            break;
        case 3:
            selection_sort_seconds_ascending(songs, length);
            //format_string = TIME_FORMAT_STRING;
            pf = print_by_time;
            //print appropriate heading
            printf("\t%-40s%-40s%s\n", "Time", "Title", "Artist");
            break;
    }
        
        
    if(down){
        for(index = length - 1; index > 0; index--){
            pf(songs[index], length - index);
        }
    }
    else{
        for(index = 1; index < length; index++){
            pf(songs[index], index);
        }
    }
}


#endif
