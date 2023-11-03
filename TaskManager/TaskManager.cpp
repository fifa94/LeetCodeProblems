#include "TaskManager.hpp"

int main()
{
    enum StatesEnum
    {
        TASK_MGR_ST_IDLE = 0,
        TASK_MGR_ST_ADD_TASK = 1,
        TASK_MGR_ST_SHOW_TASKS = 2,
        TASK_MGR_ST_DELETE_TASK = 3,
        TASK_MGR_ST_EXIT = 99
    };

    TaskManager taskManagerObj;
    bool running = 1;
    std::string taskLocal;
    std::string taskDescriptionLocal;
    std::string action;
    std::string delete_index;

    StatesEnum State = TASK_MGR_ST_IDLE;
    StatesEnum LastState = TASK_MGR_ST_EXIT;

    while (running)
    {
        switch (State)
        {
        case TASK_MGR_ST_IDLE:

            if (LastState != State)
            {
                LastState = State;
                std::cout << "==========================" << std::endl;
                std::cout << "Zapis ciselnou hodnotu, dle nabidky" << std::endl;
                std::cout << "1     = pridat ukol do ukolnicku" << std::endl;
                std::cout << "2     = vypsat ukoly z ukolnicku" << std::endl;
                std::cout << "3     = smazat ukol" << std::endl;
                std::cout << "99    = konec" << std::endl;
                std::cout << "==========================" << std::endl;
            }

            std::cin >> action;

            if (action == "1")
            {
                action = "0";
                State = TASK_MGR_ST_ADD_TASK;
            }
            else if (action == "2")
            {
                action = "0";
                State = TASK_MGR_ST_SHOW_TASKS;
            }
            else if (action == "3")
            {
                action = "0";
                State = TASK_MGR_ST_DELETE_TASK;
            }
            else if (action == "99")
            {
                action = "0";
                State = TASK_MGR_ST_EXIT;
            }

            break;

        case TASK_MGR_ST_EXIT:
            std::cout << "==========================" << std::endl;
            std::cout << " == Ukoncuji ukolnicek ==" << std::endl;
            std::cout << "==========================" << std::endl;
            running = 0;

            break;

        case TASK_MGR_ST_ADD_TASK:

            if (LastState != State)
            {
                LastState = State;
                std::cout << "==========================" << std::endl;
                std::cout << "1     = pridat ukol do ukolnicku" << std::endl;
                std::cout << "99    = konec" << std::endl;
                std::cout << "==========================" << std::endl;
            }

            std::cin >> action;

            if (action == "1")
            {
                std::cin >> taskLocal >> taskDescriptionLocal;

                if (taskManagerObj.addNewTask(taskLocal, taskDescriptionLocal))
                {
                    action = "0";

                    taskLocal.erase();
                    taskDescriptionLocal.erase();

                    State = TASK_MGR_ST_IDLE;
                }
                else
                {
                    std::cout << "==========================" << std::endl;
                    std::cout << "Je treba zadat nazev ukolu a jeho popis" << std::endl;
                    std::cout << "==========================" << std::endl;
                }
            }
            else if (action == "99")
            {
                action = "0";
                State = TASK_MGR_ST_EXIT;
            }

            break;

        case TASK_MGR_ST_SHOW_TASKS:

            if (LastState != State)
            {
                LastState = State;
                std::cout << "==========================" << std::endl;
                taskManagerObj.printAllTasks();
                std::cout << "==========================" << std::endl;
                State = TASK_MGR_ST_IDLE;
            }

            break;

        case TASK_MGR_ST_DELETE_TASK:

            if (LastState != State)
            {
                LastState = State;
                std::cout << "==========================" << std::endl;
                taskManagerObj.printAllTasks();
                std::cout << "==========================" << std::endl;
                std::cout << "1     = Smazat ukol" << std::endl;
                std::cout << "99    = konec" << std::endl;
                std::cout << "==========================" << std::endl;
            }

            std::cin >> action;

            if (action == "1")
            {
                std::cin >> delete_index;
                int index = std::stoi(delete_index);

                if (taskManagerObj.deleteTask(index))
                {
                    std::cout << "==========================" << std::endl;
                    taskManagerObj.printAllTasks();
                    std::cout << "==========================" << std::endl;
                    action = "0";
                    delete_index = "0";
                    State = TASK_MGR_ST_IDLE;
                }
                else
                {
                    action = "0";
                    delete_index = "0";
                    State = TASK_MGR_ST_IDLE;
                    std::cout << "==========================" << std::endl;
                    std::cout << "Zaznam nebyl smazan. Vracim se zpet do menu" << std::endl;
                    std::cout << "==========================" << std::endl;
                }
            }
            else if (action == "99")
            {
                action = "0";
                State = TASK_MGR_ST_EXIT;
            }

            break;
        default:

            std::cout << "==========================" << std::endl;
            std::cout << "Neplatny prikaz" << std::endl;
            std::cout << "==========================" << std::endl;

            State = TASK_MGR_ST_IDLE;

            break;
        }
    }

    return 0;
}