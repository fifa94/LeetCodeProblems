#include <string>
#include <random>
#include <iostream>
#include <unordered_map>

class Solution
{
    std::unordered_map<std::string, std::string> storedData;
    std::string tinyUrlPrefix = "http://tinyurl.com/";

public:
    // Encodes a URL to a shortened URL.
    std::string encode(std::string longUrl)
    {
        const std::hash<std::string> hasher;
        const auto hashResult = hasher(longUrl);
        std::string tinyUrl = tinyUrlPrefix + std::to_string(hashResult % 100000000);
        storedData[std::to_string(hashResult % 100000000)] = longUrl;
        return tinyUrl;
    }

    // Decodes a shortened URL to its original URL.
    std::string decode(std::string shortUrl)
    {
        const auto it = storedData.find(shortUrl.substr(tinyUrlPrefix.size()));
        return it->second;
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

int main()
{
    std::string longUrl = "https://leetcode.com/problems/design-tinyurl";
    Solution solutionObj;
    std::cout << "encoded long url: " << solutionObj.encode(longUrl) << std::endl;
    std::cout << "tiny url: " << solutionObj.decode(solutionObj.encode(longUrl)) << std::endl;
    return 0;
}