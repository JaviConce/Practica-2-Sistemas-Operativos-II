#ifndef WORD_H
#define WORD_H

#include <string>

class Word {
public:
    //void saludar();

private:
        class Fragment {
        public:
            int thread_number = 0;
            int line_i = 0;
            int line_f = 0;
        };

        Fragment fragment;
        int line;
        std::string previous_word;
        std::string later_word;
    
};

#endif
