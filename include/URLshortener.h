#pragma once

#include <string>
#include <unordered_map>
#include <random>
#include <fstream>
#include <sstream>

class URLshortener
{
private:
    // Map short code to the original URL
    std::unordered_map<std::string, std::string> codeToUrl;

    // Map original URL to short code
    std::unordered_map<std::string, std::string> urlToCode;

    /**
     * @brief Generate a random code consisting of 6 characters
     *
     * @return A random std::string
     */
    std::string generateCode();

public:
    /**
     * @brief Shorten a long URL to a random short code
     *
     * @param longUrl The full URL that will be shortened
     * @return std::string code
     */
    std::string shorten(const std::string &longUrl);

    /**
     * @brief Retrieve the original URL from its short code
     *
     * @param shortCode The code that is mapped to orignal URL
     * @return std::string of Original URL or empty string if code was not found
     */
    std::string retrieve(const std::string &shortCode);

    /**
     * @brief Writes to a csv file, saves all shortened URL's
     * 
     * @param fileName Name of file to write to
     */
    void saveToFile(const std::string &fileName);

    /**
     * @brief 
     * 
     * @param fileName 
     */
    void loadFromFile(const std::string &fileName);
};