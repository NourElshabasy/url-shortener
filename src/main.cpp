#include <iostream>
#include <string>
#include "URLshortener.h"

int main()
{
    URLshortener shortener;
    shortener.loadFromFile("data.txt");

    std::string command;

    std::cout << "===== URL Shortener =====\n";
    std::cout << "Commands:\n";
    std::cout << "      shorten <url>\n";
    std::cout << "      retrieve <code>\n";
    std::cout << "      quit\n\n";

    while (true)
    {
        std::cout << "> ";
        std::cin >> command;

        // Quit
        if (command == "quit")
        {
            std::cout << "Program Exited\n";
            shortener.saveToFile("data.txt");
            break;
        }

        // Shorten URL
        else if (command == "shorten")
        {
            std::string url;
            std::cin >> url;

            std::string code = shortener.shorten(url);
            std::cout << "Short code: " << code << "\n";
        }

        // --- Retrieve URL ---
        else if (command == "retrieve")
        {
            std::string code;
            std::cin >> code;

            std::string url = shortener.retrieve(code);

            if (url.empty())
                std::cout << "Error: Code not found.\n";
            else
                std::cout << "Original URL: " << url << "\n";
        }

        else
        {
            std::cout << "Unknown command.\n";
        }
    }

    return 0;
}
