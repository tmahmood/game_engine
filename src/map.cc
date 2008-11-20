#include "map.h"

Map::Map()
{
	map = NULL;
	map_title = NULL;
}

Map::~Map()
{
	clean_up();
}

void Map::clean_up()
{
	if(map_title != NULL)
	{
		delete map_title;
	}

	if (map != NULL) 
	{
		delete map;
	}
}

bool Map::load_map(char *map_file)
{
	clean_up();

	String_tokenizer stokenizer;
	char *map_info;
	char *map_data;
	

	if (!file_helper.read_file(map_file))
	{
		return false;
	}

	map_data = file_helper.get_last_read_data();
	stokenizer.split(map_data, '@');

	map = stokenizer.get(1);
	map_info = stokenizer.get(0);

	char *map_size;

	stokenizer.split(map_info, '\n');
	
	map_title = stokenizer.get(0);
	map_size = stokenizer.get(1);

	sscanf(map_size, "%d %d", &map_width, &map_height);
	
	delete map_info;
	delete map_data;
	delete map_size;
}

bool Map::is_valid_position(Point p)
{
	int x = p.get_x();
	int y = p.get_y();

	if(x>map_width || x <0) 
	{
		return false;
	}

	if(y>map_height || y<0) 
	{
		return false;
	}

	return true;
}

void Map::display_map_info()
{
	printf("map size : %d %d\n", map_width, map_height);
	map[map_width * 2 + 5] = 'W';
	printf("map      :\n[%s]\n", map);
}
