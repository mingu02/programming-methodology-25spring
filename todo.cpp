#include "todo.h"
#include <stdexcept>

void TodoList::init() {
    // TODO: set size to 0 and all task pointers to nullptr
    //tasks는 포인터를 담고 있는 배열임
    for(int i = 0; i < MAX_TASKS; i++)
    {
        tasks[i] = nullptr;
    }
    size = 0;
}

void TodoList::destroy() {
    // TODO: delete all tasks and reset pointers
    for(int i = 0; i < size; i++)
    {
        delete[] tasks[i];
        tasks[i] = nullptr;
    }
    size = 0;
}

int TodoList::string_length(const char* str) const {
    // TODO: return the number of characters before '\0'
    int i = 0;
    int length = 0;
    while(str[i] != '\0')
    {
        length++;
        i++;
    }
    return length;
}

void TodoList::string_copy(char* dest, const char* src) const {
    // TODO: copy characters from src to dest
    int length = string_length(src);
    for(int i = 0; i < length; i++)
    {
        dest[i] = src[i];
    }
    dest[length] = '\0';
}

void TodoList::add_task(const char* task) {
    // TODO: if full, throw. otherwise allocate and copy new task
    if(size > 31)
    {
        throw std::length_error("Task is full.");
    }
    tasks[size] = new char[string_length(task) + 1];
    string_copy(tasks[size], task);
    size++; 
}

void TodoList::remove_task(int index) {
    // TODO: check bounds, delete task, shift left
    if(index >= size || index < 0)
    {
        throw std::out_of_range("Index out of range");
    }
    delete[] tasks[index];
    for(int i = index; i < size - 1; i++)
    {
        tasks[i] = tasks[i + 1];
    }
    size--;
}

const char** TodoList::get_pending_tasks(int& count) const {
    // TODO: set count and return task array
    count = size;
    const char** copy;
    for(int i = 0; i < size; i++)
    {
        copy[i] = tasks[i];
    }
    return copy;
}