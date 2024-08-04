/*
*
*   Simple GMOD Cheat Finder
*   Made by roka | discord: rokadontmiss
*
*/

#include "findfolder.h"

bool findfolder::find_folder( const std::wstring& startDir, const std::wstring& targetFolder, std::wstring& foundPath )
{
    WIN32_FIND_DATA find_file_data;
    HANDLE hFind = FindFirstFile( ( startDir + L"\\*" ).c_str( ), &find_file_data );

    if ( hFind == INVALID_HANDLE_VALUE ) return false;
    do
    {
        const std::wstring file_or_dir = find_file_data.cFileName;
        const std::wstring full_path = startDir + L"\\" + file_or_dir;

        if ( file_or_dir == L"." || file_or_dir == L".." ) continue;
        if ( find_file_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY )
        {
            if ( file_or_dir == targetFolder )
            {
                foundPath = full_path;
                FindClose( hFind );
                return true;
            }

            if ( findfolder::find_folder( full_path, targetFolder, foundPath ) )
            {
                FindClose( hFind );
                return true;
            }
        }

    } while ( FindNextFile( hFind, &find_file_data ) != 0 );
    FindClose( hFind );
    return false;
}