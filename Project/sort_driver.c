#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "album_data.h"

int
main()
{
	song_t layla, mr_jones, john_henry;

	strcpy(layla.artist, "Eric Clapton");
	strcpy(layla.title, "Layla");
	layla.seconds = 428;

	strcpy(mr_jones.artist, "Counting Crows");
	strcpy(mr_jones.title, "Mr. Jones");
	mr_jones.seconds = 272;

	strcpy(john_henry.artist, "Joe Bonamassa");
	strcpy(john_henry.title, "The Ballad of John Henry");
	john_henry.seconds = 386;

	song_t playlist[] = {layla, mr_jones, john_henry};

	selection_sort_title_ascending(playlist, 3);
	FILE* output = fopen("sort_driver_output.txt", "w");
	
	fprintf(output, "%s | ", playlist[0].title);
	fprintf(output, "%s | ", playlist[1].title);
	fprintf(output, "%s | \n", playlist[2].title);

	selection_sort_artist_ascending(playlist, 3);
	
	fprintf(output, "%s | ", playlist[0].artist);
	fprintf(output, "%s | ", playlist[1].artist);
	fprintf(output, "%s | \n", playlist[2].artist);
	
	selection_sort_seconds_ascending(playlist, 3);
	
	fprintf(output, "%d | ", playlist[0].seconds);
	fprintf(output, "%d | ", playlist[1].seconds);
	fprintf(output, "%d | \n", playlist[2].seconds);
	
	fclose(output);
}
