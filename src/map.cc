#include "map.h"

Map::Map()
{
	map = NULL;
	map_data = NULL;
	map_title = NULL;
}

Map::~Map()
{
	clean_up();
}

void Map::clean_up()
{
	if(map_data != NULL)
	{
		delete map_data;
	}

	if(map_title != NULL)
	{
		delete map_title;
	}
}

bool Map::load_map(char *map_file)
{
	clean_up();

	String_tokenizer stokenizer;
	char *map_info;
	

	if (!file_helper.read_file(map_file))
	{
		return false;
	}

	map_data = file_helper.get_last_read_data();
	stokenizer.split(map_data, '@');
	map = stokenizer.get(1);

	char *map_size;
	char *map_start_pos;
	char *map_end_pos;

	map_info = stokenizer.get(0);

	stokenizer.split(map_info, '\n');
	
	map_title = stokenizer.get(0);

	map_size = stokenizer.get(1);
	map_start_pos = stokenizer.get(2);
	map_end_pos = stokenizer.get(3);


	delete map_info;
	delete map_size;
	delete map_start_pos;
	delete map_end_pos;

}
