#ifndef STRING_TOKENIZER_H_

#define STRING_TOKENIZER_H_
#include "string_helper.h"

class String_tokenizer
{
	public:
		String_tokenizer ( );
		virtual ~String_tokenizer();
		int split(char*, char);
		char *get(int);
		char *get_token(int);
		void clean_up();
		int get_token_count();

	private:
		int token_count;
		char *tokenized_str;
		String_helper string_helper;
		int *token_positions;

};



#endif /* SRC/STRING_TOKENIZER_H_ */

