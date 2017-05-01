#include <stdio.h>
#include <stdlib.h>
#include "album_data.h"

int
main()
{
    FILE* output = fopen("swap_driver_output.txt", "w");
	song_t layla;
	strcpy(layla.title, "Layla");
	strcpy(layla.artist, "Eric Clapton");
	layla.seconds = 360;

	song_t maggies_farm;
	strcpy(maggies_farm.title, "Maggies Farm");
	strcpy(maggies_farm.artist, "Bob Dylan");
	maggies_farm.seconds = 300;

	swap_songs(&layla, &maggies_farm);
	fprintf(output, "Maggies Farm new title: %s\n", maggies_farm.title);
	if(maggies_farm.title[0] == 'L'){
		fprintf(output, "Swap worked apparently\n");
	}
}
