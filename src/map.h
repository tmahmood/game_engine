#ifndef MAP_H_

#define MAP_H_

#include "string_helper.h"
#include "file_helper.h"
#include "string_tokenizer.h"

class Map
{
	public:
		Map ();
		bool load_map(char *map_file);
		void clean_up();
		~Map();

	private:
		File_helper file_helper;
		String_helper string_helper;

		char *map;
		char *map_data;

		char *map_title;
};



#endif /* MAP_H_ */

