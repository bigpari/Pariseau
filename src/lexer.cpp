#include "lexer.h"
#include "global.h"
#include <iostream>

namespace Pariseau
{
	Lexer::Lexer()
	{
		this->tokens = new std::list<Token*>;
	}

	Lexer::~Lexer()
	{
		std::list<Token*>::iterator iterator;
		
		for (iterator = this->tokens->begin(); iterator != this->tokens->end(); iterator++)
		{
			delete *iterator;
		}
		
		this->tokens->clear();
	}

	/*
		[  
			{id = "keyword", "echo"},
			{id = "text", "Hello Worlds"}
			{id = "keyword", "exit"}
		]
	*/
	void Lexer::tokenizer(std::list<std::string>* file_text)
	{
		std::list<std::string>::const_iterator list_iterator;

		for (list_iterator = file_text->cbegin(); list_iterator != file_text->cend(); ++list_iterator)
		{
			std::string previous_character = "";
			Global::Type current_type = Global::Type::None;

			std::string::const_iterator string_iterator;
			std::string line = *list_iterator;

			std::cout << line << std::endl;

			for (string_iterator = line.cbegin(); string_iterator != line.cend(); ++string_iterator)
			{
				char character = *string_iterator;
				std::cout << character;

				if (character == '"' && current_type == Global::Type::None)
				{
					current_type = Global::Type::Text;
				}
				else if (character == '"' && current_type == Global::Type::Text)
				{
					tokens->push_back(new Token(Global::Type::Text, previous_character));

					current_type = Global::Type::None;
					previous_character = "";
				}
				else if (Global::matchKeyword(previous_character + character) && current_type != Global::Type::Text)
				{
					tokens->push_back(new Token(Global::Type::Keyword, previous_character + character));

					current_type = Global::Type::None;
					previous_character = "";
				}
				else if(character == ' ' && current_type != Global::Type::Text)
				{
					continue;
				}
				else
				{
					previous_character += character;
				}
			}

			std::cout << std::endl;
		}
	}

	std::list<Token*>* Lexer::getTokens()
	{
		return this->tokens;
	}
}
