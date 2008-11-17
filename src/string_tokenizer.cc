#include "string_tokenizer.h"
#include "string_helper.h"
#include <string.h>

String_tokenizer::String_tokenizer()
{
	token_count = 0;
	tokenized_str = NULL;
	token_positions = NULL;
}

String_tokenizer::~String_tokenizer()
{
	clean_up();
}

void String_tokenizer::clean_up()
{
	if (tokenized_str != NULL)
	{
		delete tokenized_str;
	}

	if(token_positions != NULL)
	{
		delete token_positions;
	}
}

int String_tokenizer::split(char *string, char split_by=' ')
{
	clean_up();
	string_helper.copy_string(tokenized_str, string);
	int *tpos = new int[strlen(string)];

	token_count = 0;
	tpos[0] = 0;

	int len = strlen(tokenized_str);
	int last_found = -1;

	for(int i = 0; i<=len; i++)	
	{
		if(tokenized_str[i]==split_by || tokenized_str[i]=='\0')
		{
			tokenized_str[i]='\0';
			if (last_found + 1 == i)
			{
				tpos[token_count] = i+1;
				last_found = i;
				continue;
			}
			
			last_found = i;
			token_count++;
			tpos[token_count] = i+1;
		}
	}

	token_positions = new int[token_count];
	for (int i=0;i<token_count; i++) 
	{
		token_positions[i] = tpos[i];
	}
	
	delete tpos;
	return token_count;	
}

char *String_tokenizer::get(int token_no)
{
	char *ret_value ;
	char *target = &tokenized_str[token_positions[token_no]];
	string_helper.copy_string(ret_value, target);
	return ret_value;
}

