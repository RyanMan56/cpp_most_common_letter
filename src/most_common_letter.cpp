#include <iostream>

struct MostCommon
{
    int occurrences {};
    std::vector<char> letters {};
};

int main()
{
    std::cout << "Enter a word or sentence: ";

    std::string input_string {};
    std::getline(std::cin >> std::ws, input_string);

    // Stores each letter against how many times it has occurred so far
    std::unordered_map<char, int> letters_map {};

    // A struct to store the current most-common letter(s) and how many occurrences they have had
    MostCommon most_common {};

    for (char& c : input_string)
    {
        // Increment the value in letters_map for the key of the current letter
        letters_map[c]++;

        // If this letter has now occurred more than the previous most common letter, then overwrite most_common
        if (letters_map[c] > most_common.occurrences)
        {
            most_common = { letters_map[c], { c } };
            continue;
        }

        // If this letter matches the most occurrences for a different letter, then add it to the vector of letters
        if (letters_map[c] == most_common.occurrences && std::find(most_common.letters.begin(), most_common.letters.end(), c) == most_common.letters.end()) 
        {
            most_common.letters.push_back(c);
        }
    }

    std::string_view letters_sv { most_common.letters.data(), most_common.letters.size() };
    std::cout << "Most common letter(s) are \"" << letters_sv << "\" which occurred " << most_common.occurrences << " times!\n";
    
    return 0;
}
