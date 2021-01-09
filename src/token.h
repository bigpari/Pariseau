#pragma once

#include "global.h"
#include <string>


namespace Pariseau
{

	class Token
	{
	private:
		Global::Type id;
		std::string value;

	public:
		Token(Global::Type id, std::string value);
		~Token();

		Global::Type getId();
		void setId(Global::Type id);
		std::string getValue();
		void setValue(std::string value);
	};
}