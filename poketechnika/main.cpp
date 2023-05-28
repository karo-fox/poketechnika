#include "Game.h"
#include <iostream>
//#include <pugixml.hpp>

using namespace std;

int main()
{
    //pugi::xml_document doc;
    //pugi::xml_parse_result result = doc.load_file("data/tree.xml");
    //std::cout << "Load result: " << result.description() << '\n';
    //std::cout << doc.child("mesh").attribute("name").value() << '\n';

    // Default resolution: 1280x720

    cout << "Wybierz rozdzielczosc: " << endl;
    cout << "1. Fullscreen " << endl;
    cout << "2. 1280x720" << endl;
    cout << "3. 1920x1080" << endl;
    int wybor, w, h;
    bool fs = false;
    cout << "Wybor: ";
    cin >> wybor;
    switch (wybor)
    {
    case 1:
        fs = true;
        w = 1280;
        h = 720;
        break;
    case 2:
        w = 1280;
        h = 720;
        break;
    case 3:
        w = 1920;
        h = 1080;
        break;
    default:
        w = 1280;
        h = 720;
        break;
    }
    Game game(w, h, fs);
    game.initGameLoop();
    return 0;
}