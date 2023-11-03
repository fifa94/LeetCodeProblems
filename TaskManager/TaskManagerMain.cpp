#include <limits>
#include <exception>

#include "TaskManager.hpp"

int main()
{
    enum StatesEnum
    {
        TASK_MGR_ST_IDLE = 0,
        TASK_MGR_ST_ADD_TASK = 1,
        TASK_MGR_ST_SHOW_TASKS = 2,
        TASK_MGR_ST_DELETE_TASK = 3,
        TASK_MGR_ST_BACK = 88,
        TASK_MGR_ST_EXIT = 99,
        TASK_MGR_ST_REPEAT = 999
    };

    enum AddTaskMenuEnum
    {
        DO_ACTION = 1,
        GO_BACK = 88,
        EXIT = 99
    };
    
    TaskManager taskManagerObj;
    bool running = 1;
    int action;
    int delete_index;
    std::string taskLocal;
    std::string taskDescriptionLocal;

    StatesEnum State = TASK_MGR_ST_IDLE;
    StatesEnum LastState = TASK_MGR_ST_EXIT;

    while (running)
    {
        if (LastState != State)
        {
            LastState = State;
            action = 0;

            switch (State)
            {
            /* ================= State =================*/
            case TASK_MGR_ST_IDLE:

                std::cout << "==========================" << std::endl;
                std::cout << "Zapis ciselnou hodnotu, dle nabidky" << std::endl;
                std::cout << "1     = pridat ukol do ukolnicku" << std::endl;
                std::cout << "2     = vypsat ukoly z ukolnicku" << std::endl;
                std::cout << "3     = smazat ukol" << std::endl;
                std::cout << "99    = konec" << std::endl;

                std::cout << "==========================" << std::endl;
                std::cout << "Zadejte hodnotu ";

                while (!(std::cin >> action))
                {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "==========================" << std::endl;
                    std::cout << "Neplatný vstup. Prosím, zadejte číslo: " << std::endl;
                    LastState = TASK_MGR_ST_REPEAT;
                }

                std::cout << "==========================" << std::endl;
                std::cout << "Zadana hodnota: " << action << std::endl;

                try
                {
                    switch (action)
                    {
                    case TASK_MGR_ST_ADD_TASK:
                        State = TASK_MGR_ST_ADD_TASK;
                        break;
                    case TASK_MGR_ST_SHOW_TASKS:
                        State = TASK_MGR_ST_SHOW_TASKS;
                        break;
                    case TASK_MGR_ST_DELETE_TASK:
                        State = TASK_MGR_ST_DELETE_TASK;
                        break;
                    case TASK_MGR_ST_EXIT:
                        State = TASK_MGR_ST_EXIT;
                        break;
                    default:
                        throw std::invalid_argument("Neexistujici operace");
                        LastState = TASK_MGR_ST_REPEAT;
                        break;
                    }
                }
                catch (const std::exception &e)
                {
                    LastState = TASK_MGR_ST_EXIT;
                    std::cout << "==========================" << std::endl;
                    std::cerr << e.what() << '\n'
                              << std::endl;
                }

                break;

            /* ================= State =================*/
            case TASK_MGR_ST_ADD_TASK:

                std::cout << "==========================" << std::endl;
                std::cout << "Zapis ciselnou hodnotu, dle nabidky" << std::endl;
                std::cout << "1     = pridat ukol do ukolnicku" << std::endl;
                std::cout << "88    = Zpet" << std::endl;
                std::cout << "99    = Ukoncit ukolnicek" << std::endl;

                std::cout << "==========================" << std::endl;
                std::cout << "Zadejte hodnotu ";

                while (!(std::cin >> action))
                {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "==========================" << std::endl;
                    std::cout << "Neplatný vstup. Prosím, zadejte číslo: " << std::endl;
                    LastState = TASK_MGR_ST_REPEAT;
                }

                std::cout << "==========================" << std::endl;
                std::cout << "Zadana hodnota: " << action << std::endl;

                try
                {
                    switch (action)
                    {
                    /* ================= State =================*/
                    case DO_ACTION:

                        try
                        {
                            std::cout << "==========================" << std::endl;
                            std::cout << "Zadejte popis ukolu" << std::endl;
                            std::cin >> taskLocal;

                            if (taskLocal.empty())
                            {
                                throw std::invalid_argument("Zadan prazny string misto nazvu ulohy.");
                            }

                            std::cout << "==========================" << std::endl;
                            std::cout << "Zadejte popis ukolu" << std::endl;
                            std::cin >> taskDescriptionLocal;

                            if (taskDescriptionLocal.empty())
                            {
                                throw std::invalid_argument("Zadan prazny string jako popis ulohy.");
                            }
                        }
                        catch (const std::exception &e)
                        {
                            std::cout << "==========================" << std::endl;
                            std::cerr << e.what() << '\n'
                                      << std::endl;
                            LastState = TASK_MGR_ST_REPEAT;
                        }

                        try
                        {
                            if (!taskManagerObj.addNewTask(taskLocal, taskDescriptionLocal))
                            {
                                throw "Necekana chyba";
                            }
                            
                        }
                        catch(const std::exception& e)
                        {
                            std::cout << "==========================" << std::endl;
                            std::cerr << e.what() << '\n'<< std::endl;
                        }
                        

                        State = TASK_MGR_ST_IDLE;

                        break;

                    /* ================= State =================*/
                    case GO_BACK:
                        State = TASK_MGR_ST_IDLE;
                        break;

                    /* ================= State =================*/
                    case EXIT:
                        State = TASK_MGR_ST_EXIT;
                        break;

                    /* ================= State =================*/
                    default:
                        throw std::invalid_argument("Neexistujici operace");
                        LastState = TASK_MGR_ST_REPEAT;
                        break;
                    }
                }
                catch (const std::exception &e)
                {
                    LastState = TASK_MGR_ST_REPEAT;
                    std::cout << "==========================" << std::endl;
                    std::cerr << e.what() << '\n'
                              << std::endl;
                }

                break;

                /* ================= State =================*/
            case TASK_MGR_ST_SHOW_TASKS:

                std::cout << "==========================" << std::endl;
                taskManagerObj.printAllTasks();
                State = TASK_MGR_ST_IDLE;

                break;

            /* ================= State =================*/
            case TASK_MGR_ST_DELETE_TASK:

                std::cout << "==========================" << std::endl;
                std::cout << "Zapis ciselnou hodnotu, dle nabidky" << std::endl;
                std::cout << "1     = Odebrat hodnoty" << std::endl;
                std::cout << "88    = Zpet" << std::endl;
                std::cout << "99    = Ukoncit ukolnicek" << std::endl;

                std::cout << "==========================" << std::endl;
                std::cout << "Zadejte hodnotu ";

                while (!(std::cin >> action))
                {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "==========================" << std::endl;
                    std::cout << "Neplatný vstup. Prosím, zadejte číslo: " << std::endl;
                    LastState = TASK_MGR_ST_REPEAT;
                }

                std::cout << "==========================" << std::endl;
                std::cout << "Zadana hodnota: " << action << std::endl;

                try
                {
                    switch (action)
                    {
                    /* ================= State =================*/
                    case DO_ACTION:

                        std::cout << "==========================" << std::endl;
                        std::cout << "Zadejte index ukolu ke smazani: ";

                        while (!(std::cin >> delete_index))
                        {
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            std::cout << "==========================" << std::endl;
                            std::cout << "Neplatný vstup. Prosím, zadejte číslo: " << std::endl;
                            LastState = TASK_MGR_ST_REPEAT;
                        }

                        try
                        {
                            if (!taskManagerObj.deleteTask(delete_index))
                            {
                                throw "Necekana chyba";
                            }
                            
                        }
                        catch(const std::exception& e)
                        {
                            std::cout << "==========================" << std::endl;
                            std::cerr << e.what() << '\n' << std::endl;
                        }
                        
                                    
                        State = TASK_MGR_ST_IDLE;
                        break;

                    /* ================= State =================*/
                    case GO_BACK:
                        State = TASK_MGR_ST_IDLE;
                        break;

                    /* ================= State =================*/
                    case EXIT:
                        State = TASK_MGR_ST_EXIT;
                        break;

                    /* ================= State =================*/
                    default:
                        throw std::invalid_argument("Neexistujici operace");
                        LastState = TASK_MGR_ST_REPEAT;
                        break;
                    }
                }
                catch (const std::exception &e)
                {
                    LastState = TASK_MGR_ST_REPEAT;
                    std::cout << "==========================" << std::endl;
                    std::cerr << e.what() << '\n'
                              << std::endl;
                }

                break;

            /* ================= State =================*/
            case TASK_MGR_ST_EXIT:

                std::cout << "==========================" << std::endl;
                std::cout << " == Ukoncuji ukolnicek ==" << std::endl;
                std::cout << "==========================" << std::endl;
                running = 0;

                break;
            }
        }
    }
    return 0;
}