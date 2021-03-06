#include <iostream>
#include <string>
#include "AssetLoader.hpp"
#include "MemoryManager.hpp"
#include "HDR.hpp"

using namespace std;
using namespace My;

namespace My {
    IMemoryManager* g_pMemoryManager = new MemoryManager();
    AssetLoader*   g_pAssetLoader = new AssetLoader();
}

int main(int argc, const char** argv)
{
    g_pMemoryManager->Initialize();
    g_pAssetLoader->Initialize();

#ifdef __ORBIS__
    g_pAssetLoader->AddSearchPath("/app0");
#endif

    {
        Buffer buf;
        if (argc >= 2) {
            buf = g_pAssetLoader->SyncOpenAndReadBinary(argv[1]);
        } else {
            buf = g_pAssetLoader->SyncOpenAndReadBinary("Textures/hdr/PaperMill_E_3k.hdr");
        }

        HdrParser hdr_parser;

        Image image = hdr_parser.Parse(buf);

        cout << image;
    }

    g_pAssetLoader->Finalize();
    g_pMemoryManager->Finalize();

    delete g_pAssetLoader;
    delete g_pMemoryManager;

    return 0;
}

