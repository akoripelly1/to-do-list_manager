#include "TodoListManager.h"
#include <iostream>

int main() {
    TodoListManager manager;
    manager.loadTasks();

    std::string input;
    while (true) {
        std::cout << "ToDo List Application\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. Delete Task\n";
        std::cout << "3. Display Tasks\n";
        std::cout << "4. Exit\n";
        std::cout << "Select an option: ";
        std::getline(std::cin, input);
        int option = std::stoi(input);

        switch (option) {
            case 1: {
                std::cout << "Enter a task: ";
                std::getline(std::cin, input);
                manager.addTask(input);
                manager.saveTasks();
                break;
            }
            case 2: {
                manager.displayTasks();
                std::cout << "Enter task number to delete: ";
                std::getline(std::cin, input);
                int taskIndex = std::stoi(input) - 1;
                manager.deleteTask(taskIndex);
                manager.saveTasks();
                break;
            }
            case 3: {
                manager.displayTasks();
                break;
            }
            case 4: {
                return 0;
            }
            default:
                std::cout << "Invalid option. Please try again.\n";
        }
    }
}
