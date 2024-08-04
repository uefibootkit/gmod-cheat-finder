/*
*
*   Simple GMOD Cheat Finder
*   Made by roka | discord: rokadontmiss
*
*/

#include "workspace/includes.h"
#include "workspace/console/color_framework.hpp"

std::vector<std::wstring> get_available_drives( )
{
    std::vector<std::wstring> drives;
    wchar_t buffer[ 256 ];
    DWORD result = GetLogicalDriveStrings( 256, buffer );

    if ( result > 0 && result <= 256 )
    {
        wchar_t* drive = buffer;
        while ( *drive ) 
        {
            drives.push_back( drive );
            drive += wcslen( drive ) + 1;
        }
    }

    return drives;
}

auto main( ) -> int 
{
    SetConsoleTitle( TEXT( " " ) );

    std::vector<std::wstring> drives = get_available_drives( );
    std::wstring garrys_mod_path;
    bool garrys_mod_found_omg = false;
    bool memoriaaaaaamfouund = false;

    std::cout << dye::light_aqua( "[CHECKER] " ) << "Analyse en cours..." << std::endl;

    for ( const auto& steamPath : common_steam_paths )
    {
        if ( findfolder::find_folder( steamPath, L"GarrysMod", garrys_mod_path ) )
        {
            garrys_mod_found_omg = true; // vraiment pas le couteau le plus affuté du tiroir
            std::wstring memoriam_path;
            if ( findfolder::find_folder( garrys_mod_path, L"memoriam", memoriam_path ) )
            {
                std::cout << dye::light_green( "[CHECKER] " ) << "Le cheat 'Memoriam' as ete trouve, path: "; std::wcout << memoriam_path << std::endl;
                memoriaaaaaamfouund = true;
                break;
            }
        }
    }

    if ( !garrys_mod_found_omg )
        std::cout << dye::light_red( "[ERREUR] " ) << "Le dossier de garry's mod n'a pas pu être trouvé." << std::endl;

    else if ( !memoriaaaaaamfouund )
        std::cout << dye::light_aqua( "[CHECKER] " ) << "Aucun resultat #72." << std::endl;

    std::wstring target1 = L"memoriam";
    std::wstring target2 = L"unknowncheats.me";

    std::cout << dye::light_aqua( "[CHECKER] " ) << "Recherche avancee des fichiers en cours..." << std::endl;
    for ( const auto& drive : drives )
    {
        searchfile::search_files( drive, target1, target2 );
    }

    std::cout << dye::light_aqua( "[CHECKER] " ) << "Recherche terminee." << std::endl;
    std::vector<DWORD> sizes = { 706560, 14069760, 946688, 4066304 }; // la size des modules (Actuellement: Memoriam, FriendlyHack, SDK, Cranium) ehh merci moi même pour l'idée de génieeee
    
    std::cout << dye::light_aqua( "[CHECKER] " ) << "Recherche 2 des DLLs en cours..." << std::endl;
    for ( const auto& drive : drives )
    {
        searchdllsbysize::search_dlls_by_size( drive, sizes );
    }

    std::cout << dye::light_aqua( "[CHECKER] " ) << "Recherche terminee." << std::endl;
    std::cin.get( );
    return true;
}