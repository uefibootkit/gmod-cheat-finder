/*
*
*   Simple GMOD Cheat Finder
*   Made by roka | discord: rokadontmiss
*
*/

#pragma once
#include "../includes.h"

class searchfile
{
public:
	static auto search_files( const std::wstring& directory, const std::wstring& target1, const std::wstring& target2 ) -> void;
};