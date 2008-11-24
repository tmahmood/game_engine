#ifndef MAP_H_

#define MAP_H_

#include "helpers/string_helper.h"
#include "helpers/file_helper.h"
#include "helpers/string_tokenizer.h"
#include "point.h"

class Map
{
	public:
		Map ();
		bool load_map(char *map_file);
		void clean_up();
		void display_map_info();
		bool is_valid_position(Point);
		~Map();

	private:
		File_helper file_helper;
		String_helper string_helper;

		char *map;

		char *map_title;

		int map_width;
		int map_height;

		Point start_point;
		Point end_point;
};

#endif /* MAP_H_ */

