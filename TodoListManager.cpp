#include "TodoListManager.h"
#include <fstream>
#include <iostream>

void TodoListManager::addTask(const std::string& task) {
    tasks.push_back(task);
}

void TodoListManager::deleteTask(int taskIndex) {
    if (taskIndex >= 0 && taskIndex < tasks.size()) {
        tasks.erase(tasks.begin() + taskIndex);
    }
}

void TodoListManager::displayTasks() const {
    for (int i = 0; i < tasks.size(); ++i) {
        std::cout << i + 1 << ". " << tasks[i] << std::endl;
    }
}

void TodoListManager::loadTasks() {
    std::ifstream file("todos.txt");
    std::string line;
    while (std::getline(file, line)) {
        tasks.push_back(line);
    }
    file.close();
}

void TodoListManager::saveTasks() {
    std::ofstream file("todos.txt");
    for (const auto& task : tasks) {
        file << task << std::endl;
    }
    file.close();
}
