#ifndef ALBUM_DATA_H
#define ALBUM_DATA_H

typedef struct{
    String title;
    String artist;
    String album;
    int seconds;
} song_t;

void selection_sort_category(song_t[] listing, int category, int length)
{
    //The sublist containing all indices less than this number is sorted
    int sorted_until;

    //inner counting loop will use this
    int index;
}

#endif ALBUM_DATA_H