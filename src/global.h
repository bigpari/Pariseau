#pragma once

#include <set>
#include <string>

namespace Pariseau
{
	class Global {
	public:
		inline static const std::set<std::string> keyword =
		{
			{ "echo" },
			{ "exit" }
		};

		enum class Type
		{
			None,
			Text,
			Keyword
		};

		static bool matchKeyword(std::string value)
		{
			if (value.size() < 4)
			{
				return false;
			}

			return Global::keyword.find(value) != Global::keyword.end();
		}
	};
}
