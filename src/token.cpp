#include "token.h"

namespace Pariseau
{
	Token::Token(Global::Type id, std::string value)
	{
		this->id = id;
		this->value = value;
	}

	Token::~Token()
	{
	}

	Global::Type Token::getId()
	{
		return this->id;
	}

	void Token::setId(Global::Type id)
	{
		this->id = id;
	}

	std::string Token::getValue()
	{
		return this->value;
	}

	void Token::setValue(std::string value)
	{
		this->value = value;
	}
}