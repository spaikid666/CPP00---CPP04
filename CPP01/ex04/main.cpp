#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

static std::string replaceAll(const std::string &input, const std::string &s1, const std::string &s2)
{
    if (s1.empty())
        return input;

    std::string result;
    std::size_t pos = 0;

    while (true)
    {
        std::size_t found = input.find(s1, pos);
        if (found == std::string::npos)
        {
            result.append(input, pos, std::string::npos);
            break;
        }

        result.append(input, pos, found - pos);
        result.append(s2);

        pos = found + s1.length();
    }
    return result;
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    if (filename.empty())
    {
        std::cerr << "Error: filename must not be empty." << std::endl;
        return 1;
    }

    if (s1.empty())
    {
        std::cerr << "Error: s1 must not be empty (would lead to infinite replacement)." << std::endl;
        return 1;
    }

    std::ifstream in(filename.c_str());
    if (!in.is_open())
    {
        std::cerr << "Error: could not open input file '" << filename << "'." << std::endl;
        return 1;
    }

    std::ostringstream buffer;
    buffer << in.rdbuf();
    if (!in.good() && !in.eof())
    {
        std::cerr << "Error: failed while reading input file." << std::endl;
        return 1;
    }

    std::string content = buffer.str();
    std::string replaced = replaceAll(content, s1, s2);

    std::string outName = filename + ".replace";
    std::ofstream out(outName.c_str());
    if (!out.is_open())
    {
        std::cerr << "Error: could not open output file '" << outName << "' for writing." << std::endl;
        return 1;
    }

    out << replaced;
    if (!out.good())
    {
        std::cerr << "Error: failed while writing to output file." << std::endl;
        return 1;
    }

    return 0;
}
