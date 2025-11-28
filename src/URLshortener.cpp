#include "URLshortener.h"

std::string URLshortener::generateCode()
{
    static const std::string chars =
        "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    static std::mt19937 generator(std::random_device{}());
    static std::uniform_int_distribution<int> dist(0, chars.size() - 1);
  
    std::string code;
    for (int i = 0; i < 6; i++)
    {
        code += chars[dist(generator)];
    }

    return code;
}

std::string URLshortener::shorten(const std::string &longUrl)
{
    if (urlToCode.count(longUrl)) // Shortened URL already exists
        return urlToCode[longUrl];

    std::string code;
    do
    {
        code = generateCode();
    } while (codeToUrl.count(code)); // Avoid using repeated code to avoid collision

    codeToUrl[code] = longUrl;
    urlToCode[longUrl] = code;

    return code;
}

std::string URLshortener::retrieve(const std::string &shortCode)
{
    if (codeToUrl.find(shortCode) != codeToUrl.end())
    {
        return codeToUrl.find(shortCode)->second;
    }

    return "";
}

void URLshortener::saveToFile(const std::string &fileName)
{
    std::ofstream out(fileName);

    if (!out.is_open())
        return;
    
    for (const auto &pair : codeToUrl)
    {
        out << pair.first << "," << pair.second << "\n";
    }

    out.close();
}

void URLshortener::loadFromFile(const std::string &fileName)
{
    std::ifstream in(fileName);

    if (!in.is_open())
        return;

    std::string line;
    while (std::getline(in, line))
    {
        std::stringstream ss(line);
        std::string code, url;

        if (std::getline(ss, code, ',') && std::getline(ss, url)) 
        {
            codeToUrl[code] = url;
            urlToCode[url] = code;
        }
    }

    in.close();
}