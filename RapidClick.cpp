#include <iostream>
#include <windows.h>
using std::cout;
using std::cin;

void numberedClick();
void unlimitedClick();

int main()
{
    SetConsoleTitle("RapidClick");

    int clickChoice = 0;

    cout << "CTRL & ALT button used together will start the clicks.\nAfter the limited clicks end,";
    cout << "press these again to restart the limited clicks.\n";
    cout << "These buttons will start/pause/resume clicks when using unlimited clicks\n\n";

    cout << "The ESC button will have you exit at any time during clicks.\nIncorrect button usage will yield no response by the program.\n\n\n";

    cout << "Would you like to use a finite number of clicks or unlimited?\n";

    do
    {
        cout << "\nEnter (1) for a set number of clicks or (2) for unlimited clicks -> ";
        cin >> clickChoice;
        switch(clickChoice)
        {
            case 1:
                numberedClick();
                break;

            case 2:
                unlimitedClick();
                break;

            default:
                cout << "\nThat was not a valid choice. Try again.\n";
        }

    }
    while (clickChoice != 1 && clickChoice != 2);

    cout << "\n\nPress ENTER to exit. . .\n";

    cin.ignore();
    cin.get();
    return 0;
}

void numberedClick()
{
     int clicksDesired = 0;

     cout<< "Enter amount of rapid clicks you would like -> ";
     cin >> clicksDesired;

     //unending loops
     while (1)
     {
         //return to main with escape
         if (GetAsyncKeyState(VK_ESCAPE))
             return;

         if (GetAsyncKeyState(VK_CONTROL) && GetAsyncKeyState(VK_MENU))
         {
             int clicksDelivered = 0;

             while (clicksDelivered <= clicksDesired)
             {
                 //return to main with escape
                 if (GetAsyncKeyState(VK_ESCAPE))
                     return;

                 mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
                 mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
                 clicksDelivered++;
                 Sleep(200);
             }
         }
        }
    Sleep(500);
}


void unlimitedClick()
{
    //undending loop
    while (1)
    {
         //return to main with escape
         if (GetAsyncKeyState(VK_ESCAPE))
                    return;

         if (GetAsyncKeyState(VK_CONTROL) && GetAsyncKeyState(VK_MENU))
         {
            while (1)
            {
                //return to main with escape
                if (GetAsyncKeyState(VK_ESCAPE))
                    return;

                //break the loop and go up one level in the function with break
                if (GetAsyncKeyState(VK_CONTROL) && GetAsyncKeyState(VK_MENU))
                    break;

                mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
                mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
                Sleep(200);
            }
         }
         Sleep(500);
    }
}
