#pragma once
#include <stdio.h>
#include <iostream>
#include <print>
#include <list>
#include <Windows.h>
class CommandReader
{
	std::string prompt;
	void SetPrompt(const std::string& s) { prompt = s; }
	std::string ReadCommand()
	{

	}
	void PrintHistory()
	{}
};

