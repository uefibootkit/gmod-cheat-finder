/*
*
*   Simple GMOD Cheat Finder
*   Made by roka | discord: rokadontmiss
*
*/

#pragma once
#include "../includes.h"

class findfolder
{
public:
	static auto find_folder( const std::wstring& startDir, const std::wstring& targetFolder, std::wstring& foundPath ) -> bool;
};