#include "map.h"

Map::Map()
{
	map = NULL;
	map_data = NULL;
}

Map::~Map()
{
	if(map_data != NULL)
	{
		delete map_data;
	}
	
}

bool Map::load_map(char *map_file)
{
	if (!file_helper.read_file(map_file))
	{
		return false;
	}

	map_data = file_helper.get_last_read_data();
	sscanf(map_data, "%[^\n]s", title);
}
