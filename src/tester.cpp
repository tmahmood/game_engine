#include "file_helper.h"
#include "string_tokenizer.h"
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
}

int main (int argc, char const* argv[])
{
	//test_file_helper();
	//test_tokenizer((char*)"This  is  a  test");
	//test_tokenizer((char*)"This is a test");
	//test_tokenizer((char*)"   This is a test");

	//test_file_helper();
	//
	
	test_map();
	return 0;
}

