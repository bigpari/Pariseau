#pragma once

#include "global.h"
#include "token.h"

#include <list>

namespace Pariseau
{
	class Lexer
	{
	private:
		std::list<Token*>* tokens;

	public:
		Lexer();
		~Lexer();
		
		void tokenizer(std::list<std::string>* file_text);
		std::list<Token*>* getTokens();
	};

}