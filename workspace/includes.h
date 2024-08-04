/*
*
*   Simple GMOD Cheat Finder
*   Made by roka | discord: rokadontmiss
*
*/

#pragma once
#pragma warning(disable : 4996)

#include <Windows.h>
#include <iostream>
#include <vector>
#include <string>

#include "engine/findfolder.h"
#include "engine/searchdllsbysize.h"
#include "engine/searchfiles.h"

static std::vector<std::wstring> common_steam_paths =
{
    L"C:\\Program Files (x86)\\Steam\\steamapps\\common",
    L"D:\\Steam\\steamapps\\common",
    L"D:\\SteamLibrary\\steamapps\\common",
    L"E:\\Steam\\steamapps\\common",
    L"E:\\SteamLibrary\\steamapps\\common",
};