#include <iostream>
#include <vector>
#include <string>
#include <ctime>
using namespace std;

struct ToDoItem 
{
    string task;
    bool isDone;
};

int main() 
{
    int option, num, taskIndex;
    string task;
    vector <ToDoItem> myList;

    while (true) 
    {
        cout<< "                      " <<endl;
        cout<< "1. Create your List"    <<endl;
        cout<< "2. See Your List"       <<endl;
        cout<< "3. Delete Your List"    <<endl;
        cout<< "4. Mark As Done"        <<endl;
        cout<< "5. Exit."               <<endl;

        cout<< "Enter your choice : "   <<endl;
        cin >> option;

        if (option == 1) 
        {  
                cout << "\nWrite your list here"<< endl;
                cin.ignore();
                getline(cin, task);

                ToDoItem newItem;
                newItem.task = task;
                newItem.isDone = false;

                myList.push_back(newItem);
                cout << "\nTask saved successfully! " << endl;
            
            continue;
        }

        else if (option == 2) 
        {
            cout << "\nToDo List : " << endl;
            if (myList.empty()) 
            {
                cout << "No tasks." << endl;
            }
            else 
            {
                for (int i = 0; i < myList.size(); i++) 
                {
                    cout << i + 1 << ". ";
                    cout << "[" << (myList[i].isDone ? "Completed" : "Pending") << "] ";
                    cout << myList[i].task << endl;

                    time_t t = time(0);  
                    tm* now = localtime(&t);
                    cout << "   " 
                    << now->tm_mday << '/' 
                    << (now->tm_mon + 1) << '/' 
                    << (now->tm_year + 1900) << "\n";
                }
            }
            cout << "\nnumber of tasks : " << myList.size() << endl;
            continue;  
        }   
    
        else if (option == 3) 
        {
            cout<< "\nEnter the number you want to delete : ";
            cin >> num;
            if (num >= 1 && num <= myList.size()) 
            {
                myList.erase(myList.begin() + num - 1);
                cout << "Task deleted successfully!" << endl;
            } 
            else 
            {
                cout << "invalid task number." << endl;
            }
            continue;
        }

        else if (option == 4) 
        {
            cout << "\nEnter the number you want to mark as done : ";
            cin  >> taskIndex;
            if (taskIndex > 0 && taskIndex <= myList.size()) 
            {
                myList[taskIndex - 1].isDone = !myList[taskIndex - 1].isDone;
                cout << "Task status updated successfully!" << endl;
            }
            else 
            {
                cout << "Invalid task number." << endl;
            }
            continue;
        }

        else if (option == 5) 
        {
            break;
        }

        else 
        {
            cout << "\nInvalid number. Try again." << endl;
            continue;
        }
        return 0;
    }
}
