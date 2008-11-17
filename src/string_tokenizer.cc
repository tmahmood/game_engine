#include "string_tokenizer.h"
#include "string_helper.h"
#include <string.h>

String_tokenizer::String_tokenizer()
{
	token_count = 0;
	tokenized_str = NULL;
}

String_tokenizer::~String_tokenizer()
{
	if (tokenized_str != NULL)
	{
		delete tokenized_str;
	}
}

int String_tokenizer::split(char *string, char split_by=' ')
{
	string_helper.copy_string(tokenized_str, string);
	token_positions = new int[strlen(string)];

	token_count = 0;
	token_positions[0] = 0;

	int len = strlen(tokenized_str);

	for(int i = 0; i<=len; i++)	
	{
		if(tokenized_str[i]==split_by || 
			tokenized_str[i]=='\0')
		{
			tokenized_str[i]='\0';
			token_count++;
			token_positions[token_count] = i+1;
		}
	}

	return token_count;	
}

char *String_tokenizer::get(int token_no)
{
	char *ret_value ;
	char *target = &tokenized_str[token_positions[token_no]];
	string_helper.copy_string(ret_value, target);
	return ret_value;
}

