/*
*
*   Simple GMOD Cheat Finder
*   Made by roka | discord: rokadontmiss
*
*/

#include "searchdllsbysize.h"

auto searchdllsbysize::search_dlls_by_size( const std::wstring& directory, const std::vector<DWORD>& sizes ) -> void
{
    WIN32_FIND_DATA find_file_data;
    HANDLE hFind = FindFirstFile( ( directory + L"\\*" ).c_str( ), &find_file_data );

    if ( hFind == INVALID_HANDLE_VALUE ) return;
    do 
    {
        const std::wstring file_or_dir = find_file_data.cFileName;
        const std::wstring fullPath = directory + L"\\" + file_or_dir;

        if ( file_or_dir == L"." || file_or_dir == L".." ) continue;
        if ( find_file_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY )
            searchdllsbysize::search_dlls_by_size( fullPath, sizes );

        else if ( file_or_dir.length( ) > 4 && file_or_dir.substr( file_or_dir.length( ) - 4 ) == L".dll" ) // je cause des unhandled exception psk je sais pas coder :nerd: 
        {
            DWORD file_size_low = find_file_data.nFileSizeLow;
            DWORD file_size_high = find_file_data.nFileSizeHigh;
            ULONGLONG file_size = ( static_cast< ULONGLONG >( file_size_high ) << 32 ) + file_size_low;

            for ( const auto& size : sizes ) 
            {
                if ( file_size == size ) std::wcout << L"DLL found: " << fullPath << L" Size: " << file_size << L" bytes" << std::endl;
            }
        }
    } while ( FindNextFile( hFind, &find_file_data ) != 0 );
    FindClose( hFind );
}