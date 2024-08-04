/*
*
*   Simple GMOD Cheat Finder
*   Made by roka | discord: rokadontmiss
*
*/

#include "searchfiles.h"

auto searchfile::search_files( const std::wstring& directory, const std::wstring& target1, const std::wstring& target2 ) -> void
{
    WIN32_FIND_DATA find_file_data;
    HANDLE hFind = FindFirstFile( ( directory + L"\\*" ).c_str( ), &find_file_data );

    if ( hFind == INVALID_HANDLE_VALUE ) return;
    do
    {
        const std::wstring file_or_dir = find_file_data.cFileName;
        const std::wstring full_path = directory + L"\\" + file_or_dir;

        if ( file_or_dir == L"." || file_or_dir == L".." ) continue;
        if ( find_file_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY )
            searchfile::search_files( full_path, target1, target2 );
        else
            if ( file_or_dir.find( target1 ) != std::wstring::npos || file_or_dir.find( target2 ) != std::wstring::npos )
                std::wcout << L"Fichier trouve: " << full_path << std::endl;

    } while ( FindNextFile( hFind, &find_file_data ) != 0 );
    FindClose( hFind );
}