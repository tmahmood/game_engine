#include "helpers/file_helper.h"
#include "helpers/string_tokenizer.h"
#include "helpers/string_helper.h"
#include "map.h"

void test_tokenizer(char *test, char split_by=' ')
{
	String_tokenizer st;
	int count = st.split(test, split_by);
	printf("%s\n", test);
	printf ("%d\n", count);

	for( int i = 0; i < count; i++)
	{
		char *text = st.get(i);
		printf("[%s]\n", text);
		delete text;
	}

}

void test_file_helper()
{
	File_helper fh;
	fh.read_file((char*)"test_file");
	char *data = fh.get_last_read_data();
	long  size = fh.get_last_file_size();
	printf ("%ld\n%s\n", size, data);
	test_tokenizer(data, '@');
	delete data;
}

void test_map()
{
	Map map;
	map.load_map((char*)"test_file");
	map.display_map_info();
}

void test_tokenizer_w_data()
{
	test_tokenizer((char*)"This  is  a  test");
	test_tokenizer((char*)"This is a test");
	test_tokenizer((char*)"   This is a test");
}

void test_string_trimmer()
{
	String_helper st;
	char test[] = "   this is a test string!     ";
	char *res;

	st.copy_string(res, test);

	st.trim_left(res ,' ');
	printf("[%s]\n", test);
	printf("[%s]\n", res);

	st.copy_string(res, test);

	st.trim_right(res ,' ');
	printf("[%s]\n", test);
	printf("[%s]\n", res);


	st.copy_string(res, test);
	printf("[%s]\n", test);
	st.trim(res, ' ');
	printf("[%s]\n", res);
	delete res;

}

int main (int argc, char const* argv[])
{
	//test_tokenizer_w_data();
	//test_file_helper();
	test_map();
	
	test_string_trimmer();
	return 0;
}

