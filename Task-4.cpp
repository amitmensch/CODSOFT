#include <iostream>
#include <vector>
#include <string>
#include <limits>

struct Task {
    std::string description;
    bool isCompleted = false;
};

void addTask(std::vector<Task>& tasks) {
    std::string description;
    std::cout << "Enter the task description: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, description);
    tasks.push_back({description, false});
    std::cout << "Task added successfully!\n";
}

void viewTasks(const std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "The to-do list is empty.\n";
        return;
    }
    std::cout << "--- To-Do List ---\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << i + 1 << ". ";
        std::cout << (tasks[i].isCompleted ? "[X] " : "[ ] ");
        std::cout << tasks[i].description << "\n";
    }
    std::cout << "------------------\n";
}

void markTaskCompleted(std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "The to-do list is empty. Nothing to mark.\n";
        return;
    }
    viewTasks(tasks);
    int taskNumber;
    std::cout << "Enter the number of the task to mark as completed: ";
    std::cin >> taskNumber;

    if (std::cin.fail() || taskNumber < 1 || taskNumber > static_cast<int>(tasks.size())) {
        std::cout << "Invalid task number. Please try again.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } else {
        tasks[taskNumber - 1].isCompleted = true;
        std::cout << "Task " << taskNumber << " marked as completed!\n";
    }
}

void removeTask(std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "The to-do list is empty. Nothing to remove.\n";
        return;
    }
    viewTasks(tasks);
    int taskNumber;
    std::cout << "Enter the number of the task to remove: ";
    std::cin >> taskNumber;

    if (std::cin.fail() || taskNumber < 1 || taskNumber > static_cast<int>(tasks.size())) {
        std::cout << "Invalid task number. Please try again.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } else {
        tasks.erase(tasks.begin() + (taskNumber - 1));
        std::cout << "Task removed successfully!\n";
    }
}

int main() {
    std::vector<Task> tasks;
    int choice;

    while (true) {
        std::cout << "\n--- To-Do List Manager ---\n";
        std::cout << "1. Add a task\n";
        std::cout << "2. View tasks\n";
        std::cout << "3. Mark a task as completed\n";
        std::cout << "4. Remove a task\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        // Input validation
        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a number from the menu.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                markTaskCompleted(tasks);
                break;
            case 4:
                removeTask(tasks);
                break;
            case 5:
                std::cout << "Exiting program. Goodbye!\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    }

    return 0;
}
