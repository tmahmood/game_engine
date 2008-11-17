#include "file_helper.h"
#include "string_tokenizer.h"

void test_tokenizer(char *test)
{
	String_tokenizer st;
	int count = st.split(test, ' ');
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
	delete data;
}

int main (int argc, char const* argv[])
{
	test_tokenizer((char*)"This is a test string");
	test_tokenizer((char*)"Thisisateststring");
	test_tokenizer((char*)"   This  is  at e stst ring");
	test_tokenizer((char*)"");
	return 0;
}

