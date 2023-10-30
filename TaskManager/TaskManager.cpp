#include "TaskManager.hpp"

int main()
{
    TaskManager taskManagerObj;
    bool running = 1;
    std::string taskLocal;
    std::string taskDescriptionLocal;

    enum StatesEnum
    {
        TASK_MGR_ST_IDLE = 0,
        TASK_MGR_ST_ADD_TASK = 1,
        TASK_MGR_ST_SHOW_TASKS = 2,
        TASK_MGR_ST_EXIT = 99
    };

    StatesEnum State = TASK_MGR_ST_IDLE;
    StatesEnum LastState = TASK_MGR_ST_EXIT;

    std::string action;

    while (running)
    {
        switch (State)
        {
        case TASK_MGR_ST_IDLE:

            if (LastState != State)
            {
                LastState = State;
                std::cout << "Zapis ciselnou hodnotu, dle nabidky" << std::endl;
                std::cout << "1     = pridat ukol do ukolnicku" << std::endl;
                std::cout << "99    = konec" << std::endl;
            }

            std::cin >> action;

            if (action == "1")
            {
                action = "0";
                State = TASK_MGR_ST_ADD_TASK;
            }
            else if (action == "99")
            {
                action = "0";
                State = TASK_MGR_ST_EXIT;
            }

            break;

        case TASK_MGR_ST_EXIT:

            std::cout << " == Ukoncuji ukolnicek ==" << std::endl;
            running = 0;

            break;

        case TASK_MGR_ST_ADD_TASK:

            if (LastState != State)
            {
                LastState = State;
                std::cout << "1     = pridat ukol do ukolnicku" << std::endl;
                std::cout << "99    = konec" << std::endl;
            }

            std::cin >> action;

            if (action == "1")
            {
                std::cin >> taskLocal >> taskDescriptionLocal;

                if (taskManagerObj.addNewTask(taskLocal, taskDescriptionLocal))
                {
                    action = "0";
                    State = TASK_MGR_ST_IDLE;
                }
                else
                {
                   std::cout << "Je treba zadat nazev ukolu a jeho popis" << std::endl; 
                }
            }
            else if (action == "99")
            {
                action = "0";
                State = TASK_MGR_ST_EXIT;
            }

            break;

        default:

            std::cout << "Neplatny prikaz" << std::endl;

            State = TASK_MGR_ST_IDLE;

            break;
        }
    }

    return 0;
}