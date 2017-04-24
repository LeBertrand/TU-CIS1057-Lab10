#include <stdlib.h>
#include <stdio.h>
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

	selection_sort_title(playlist, 3);
	FILE* output = fopen("sort_driver_output.txt", "w");
	fprintf(output, playlist[0].title, playlist[1].title, playlist[2].title);
	fclose(output);
}
