#pragma once
#include <iostream>
#include "Object.h"
#include "Event.h"
class Print:
	public Object
{
protected:
	std::string name;
	std::string author;
public:
	Print();
	Print(const Print&);
	Print(std::string, std::string);
	virtual ~Print();
	void Show();
	void Input();
	std::string get_name();
	std::string get_author();
	void set_name(std::string);
	void set_author(std::string);
	Print& operator=(const Print&);
	void HandleEvent(const TEvent& r);
};

