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
	
	printTable(playlist, 3, 31);
	puts("\n\n");
	printTable(playlist, 3, 22);
	
	return EXIT_SUCCESS;
}