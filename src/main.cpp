#include "file_extractor.h"
#include "lexer.h"
#include "parser.h"
#include "type_checker.h"
#include "generator.h"

#include <iostream>

using namespace Pariseau;

int main(int argc, char** argv)
{
	if (argc < 2)
	{
		std::cout << "you need to atleast have one parameters";
		return 1;
	}

	FileExtractor* fileExtractor = new FileExtractor();

	fileExtractor->readFile(argv[1]);

	Lexer* lexer = new Lexer();

	lexer->tokenizer(fileExtractor->getFileText());

	auto token = lexer->getTokens();

	delete fileExtractor;
	delete lexer;

	return 0;
}