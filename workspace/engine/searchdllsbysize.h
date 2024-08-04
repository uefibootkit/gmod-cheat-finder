/*
*
*   Simple GMOD Cheat Finder
*   Made by roka | discord: rokadontmiss
*
*/

#pragma once
#include "../includes.h"

class searchdllsbysize
{
public:
	static auto search_dlls_by_size( const std::wstring& directory, const std::vector<DWORD>& sizes ) -> void;
};