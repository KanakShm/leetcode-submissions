class Solution {
public:

    string encode(vector<string>& strs) {
        /*
            know where words start and end
            concatenate all strings together
            at the start have a number that denotes the length of each word
            
            hello world
            hello[5]world[5]
            5-5-5-2-4-2-6-#[strs hello world my name is kanak]
        */
        std::string number = "";
        std::string combined = "";

        for (int i = 0; i < strs.size(); ++i) {
            number += std::to_string(strs[i].size()) + "-";
            combined += strs[i];
        }

        number += "#";
        return number + combined;
    }

    vector<string> decode(string s) {
        std::string raw_numbers = "";
        int idx = 0;
        while (s[idx] != '#') {
            raw_numbers += s[idx];
            idx++;
        }

        std::vector<int> processed_numbers;
        std::string number = "";
        int size = 0;
        for (int i = 0; i < raw_numbers.size(); ++i) {
            if (raw_numbers[i] == '-') {
                processed_numbers.push_back(std::stoi(number));
                number = "";
            } else {
                number += raw_numbers[i];
            }
            idx = i;
            size++;
        }
        idx += 2;

        std::cout << s << std::endl;
        // std::cout << idx << " "  << size << std::endl;

        // for (int i = 0; i < processed_numbers.size(); ++i) {
        //    std::cout << processed_numbers[i] << std::endl;
        // }

        std::vector<std::string> output;
        int it = 0;
        while (it < processed_numbers.size()) {
            int word_size = processed_numbers[it];
            // std::cout << word_size << " " << s[idx] << std::endl;
            std::string word = "";
            for (int i = 0; i < word_size; ++i) {
                word += s[idx];
                idx++;
            }
            output.push_back(word);
            it++;
        }

        if (output.empty()) {
            for (int i = 0; i < processed_numbers.size(); ++i) {
                output.push_back("");
            }
        }
        return output;
    }
};
