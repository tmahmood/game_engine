#ifndef FILE_HELPER_H_

#define FILE_HELPER_H_
#include "string_helper.h"
#include <stdio.h>

class File_helper
{
	public:
		File_helper ();
		virtual ~File_helper();

		bool read_file(char *);
		long get_file_size(char *);

		char *get_last_read_data();
		long get_last_file_size();

		void clean_up();
	private:
		long get_file_size(FILE *);

		char *last_read_data;
		long file_size;
		String_helper string_helper;
};
#endif /* SRC/FILE_HELPER_H_ */

