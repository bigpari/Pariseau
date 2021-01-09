#pragma once

#include <string>
#include <list>

namespace Pariseau {
	class FileExtractor
	{
	private:
		std::list<std::string>* file_text;

	public:
		FileExtractor();
		~FileExtractor();
		void readFile(std::string file_name);
		std::list<std::string>* getFileText();
	};
}


