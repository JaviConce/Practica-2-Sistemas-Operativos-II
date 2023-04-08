#ifndef WORD_H
#define WORD_H

#include <string>

class Word {
private:
        class Fragment {
        public:
            int thread_number = 0;
            int line_i = 0;
            int line_f = 0;
        };

        Fragment fragment;
        int line;
        int pos;
        std::string previous_word;
        std::string later_word;

public:
    //void saludar();

    //Para ordenar al revés, cambiar < por >
    bool operator<(const Word& other) const{
        if (fragment.thread_number != other.fragment.thread_number)
            return fragment.thread_number < other.fragment.thread_number;

        else if (line != other.line)
            return line < other.line;
        else
            return pos < other.pos;
                 
    }

    Word(int thread_number, int line_i, int line_f, int line, std::string previous_word, std::string later_word, int pos)
    {
        this->fragment.thread_number = thread_number;
        this->fragment.line_i = line_i;
        this->fragment.line_f = line_f;
        this->line = line;
        this->previous_word = previous_word;
        this->later_word = later_word;
        this->pos = pos;
    }

    friend std::ostream& operator<<(std::ostream& os, const Word& p) {
        os << "[Hilo: " << p.fragment.thread_number << " inicio: " << p.fragment.line_i << " final: " << p.fragment.line_f <<
         "] :: línea " << p.line << " :: Anterior: " << p.previous_word << " :: Posterior: " << p.later_word << "\n";
        return os;
    }

};

#endif
