#include "file_extractor.h"
#include <fstream>
#include <algorithm>

namespace Pariseau
{
	FileExtractor::FileExtractor()
	{
		this->file_text = new std::list<std::string>;
	}

	FileExtractor::~FileExtractor()
	{
		this->file_text->clear();
	}

	void FileExtractor::readFile(std::string file_name)
	{
		std::ifstream file(file_name, std::ios::in|std::ios::binary);

		if (file.is_open())
		{
			std::string line;

			while (getline(file, line)) 
			{
				line.erase(std::remove(line.begin(), line.end(), '\n'), line.end());
				line.erase(std::remove(line.begin(), line.end(), '\r'), line.end());
				line.erase(std::remove(line.begin(), line.end(), '\t'), line.end());

				this->file_text->push_back(line);
			}
		}

		file.close();
	}

	std::list<std::string>* FileExtractor::getFileText()
	{
		return this->file_text;
	}
}

