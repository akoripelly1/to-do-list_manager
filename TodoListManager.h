#include <vector>
#include <string>

class TodoListManager {
public:
    void addTask(const std::string& task);
    void deleteTask(int taskIndex);
    void displayTasks() const;
    void loadTasks();
    void saveTasks();

private:
    std::vector<std::string> tasks;
};
