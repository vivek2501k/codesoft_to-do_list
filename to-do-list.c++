#include <iostream>
#include <vector>
using namespace std;

// Task structure to represent a task
struct Task {
    string description;
    bool completed;
};

// Function to add a task to the to-do list
void addTask(vector<Task>& todoList, const string& description) {
    Task task;
    task.description = description;
    task.completed = false;
    todoList.push_back(task);
    cout << "Task added: " << description << endl;
}

// Function to view all tasks in the to-do list
void viewTasks(const vector<Task>& todoList) {
    if (todoList.empty()) {
        cout << "No tasks in the to-do list." << endl;
    } else {
        cout << "To-Do List:" << endl;
        for (size_t i = 0; i < todoList.size(); i++) {
            cout << i + 1 << ". ";
            if (todoList[i].completed) {
                cout << "[Completed] ";
            }
            cout << todoList[i].description << endl;
        }
    }
}

// Function to delete a task from the to-do list
void deleteTask(vector<Task>& todoList, int taskIndex) {
    if (taskIndex >= 1 && taskIndex <= static_cast<int>(todoList.size())) {
        cout << "Task deleted: " << todoList[taskIndex - 1].description << endl;
        todoList.erase(todoList.begin() + taskIndex - 1);
    } else {
        cout << "Invalid task index. No task deleted." << endl;
    }
}

int main() {
    vector<Task> todoList;

    cout << "TO-DO LIST MANAGER" << endl;

    while (true) {
        cout << "\nOptions:" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Delete Task" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                cin.ignore(); // Clear newline from previous input
                cout << "Enter task description: ";
                string description;
                getline(cin, description);
                addTask(todoList, description);
                break;
            }
            case 2: {
                viewTasks(todoList);
                break;
            }
            case 3: {
                viewTasks(todoList);
                if (!todoList.empty()) {
                    cout << "Enter the task number to delete: ";
                    int taskIndex;
                    cin >> taskIndex;
                    deleteTask(todoList, taskIndex);
                }
                break;
            }
            case 4: {
                cout << "Goodbye!" << endl;
                return 0;
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
            }
        }
    }

    return 0;
}

