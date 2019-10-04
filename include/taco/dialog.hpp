#pragma once

#include <string>
#include <vector>
#include <functional>

namespace taco
{
class dialog
{
public:
    struct answer
    {
        std::string content;
        std::function<void()> callback;
    };

private:
    std::vector<answer> possibilities;

    size_t position = 0;

public:
    std::string question;

public:
    dialog(std::string question_) : question(question_){};

    inline void add_possibility(std::string value, const std::function<void()> &callback)
    {
        possibilities.push_back({value, callback});
    }

    void up(size_t n = 1);
    void down(size_t n = 1);

    inline void execute_selected()
    {
        this->possibilities[this->position].callback();
    }

    void display();
};
} // namespace taco
