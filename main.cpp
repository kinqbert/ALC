#include <iostream>
#include <ctime>
#include <thread>

#define start1 510
#define end1 605
#define start2 625
#define end2 720
#define start3 740
#define end3 835
#define start4 855
#define end4 950

using namespace std;

// 0 - пари немає
// 1 - АСД
// 2 - програмування
// 3 - дискретна математика
// 4 - лінійна алгебра
// 5 - фізика
// 6 - матаналіз
// 7 - історія
// 8 - англійська мова
// 9 - ФП

int convertInMinutes (int hours, int minutes)
{
    return hours * 60 + minutes;
}

bool lectureRightNow (int currentDay, int currentTime, bool isFirstWeek)
{
    switch (currentDay)
    {
        case 0:
        {
            if ((currentTime >= start1 && currentTime <= start2) || (currentTime >= start2 && currentTime <= end2) || (currentTime >= start3 && currentTime <= end3) || (currentTime >= start4 && currentTime <= end4))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        case 1:
        {
            if (currentTime >= start3 && currentTime <= end3)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        case 2:
        {
            if ((currentTime >= start1 && currentTime <= start2) || (currentTime >= start2 && currentTime <= end2) || (currentTime >= start3 && currentTime <= end3))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        case 3:
        {
            if ((currentTime >= start1 && currentTime <= start2) || (currentTime >= start2 && currentTime <= end2) || (currentTime >= start3 && currentTime <= end3))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        case 4:
        {
            if ((currentTime >= start1 && currentTime <= start2) || (currentTime >= start2 && currentTime <= end2) || (currentTime >= start3 && currentTime <= end3))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        default:
        {
            return false;
        }
    }
}

void currentLecture (int currentDay, int currentTime, bool isFirstWeek, string* command)
{
    string algorithmsAndDataStructures = "link1";
    string programming = "link1";
    string discreteMath = "link1";
    string linearAlgebra = "link1";
    string physics = "link1";
    string physicsLab = "link1";
    string mathematicalAnalysisLecture = "link1";
    string mathematicalAnalysisPractice = "link1";
    string history = "link1";
    string english = "link1";
    string physicalEducation = "link1";

    cout << "// current lecture: ";

    switch (currentDay)
    {
        case 0:
        {
            if ((currentTime >= start1 && currentTime <= start2))
            {
                cout << "Linear Algebra (lecture) with Bochonov Y.E.\n// link: " << linearAlgebra;
                *command = "start " + linearAlgebra;
            }
            else if (currentTime >= start2 && currentTime <= end2)
            {
                cout << "Mathematical Logic and Theory of Algorithms (lecture) with Statkevych V.M.\n// link: " << discreteMath;
                *command = "start " + discreteMath;
            }
            else if (currentTime >= start3 && currentTime <= end3)
            {
                cout << "Physics of Oscillatory-Wave Processes (lecture) with Kalyta V.M.\n// link: " << physics;
                *command = "start " + physics;
            }
            else if (currentTime >= start4 && currentTime <= end4)
            {
                cout << "Ukraine in Context of European Development (lecture) with Khytrovska Y.V.\n// link: " << history;
                *command = "start " + history;
            }
            else
            {
                cout << "no lecture right now";
            }
        }
        case 1:
        {
            if (currentTime >= start3 && currentTime <= end3)
            {
                cout << "Ukraine in Context of European Development (practice) with Khytrovska Y.V.\n// link: " << history;
                *command = "start " + history;
            }
            else
            {
                cout << "no lecture right now";
            }
        }
        case 2:
        {
            if ((currentTime >= start1 && currentTime <= start2))
            {
                cout << "Algorithms and Data Structures (lecture) with Kleshch K. and Yakovchuk O.\n// link: " << algorithmsAndDataStructures;
                *command = "start " + algorithmsAndDataStructures;
            }
            else if (currentTime >= start2 && currentTime <= end2)
            {
                cout << "Mathematical Analysis (lecture) with Nomirovskyi D.A.\n// link: " << mathematicalAnalysisLecture;
                *command = "start " + mathematicalAnalysisLecture;
            }
            else if (currentTime >= start3 && currentTime <= end3)
            {
                cout << "Mathematical Analysis (lecture) with Nomirovskyi D.A.\n// link: " << mathematicalAnalysisLecture;
                *command = "start " + mathematicalAnalysisLecture;
            }
            else
            {
                cout << "no lecture right now";
            }
        }
        case 3:
        {
            if ((currentTime >= start1 && currentTime <= start2))
            {
                cout << "Mathematical Logic and Theory of Algorithms (practice) with Statkevych V.M.\n// link: " << discreteMath;
                *command = "start " + discreteMath;
            }
            else if (currentTime >= start2 && currentTime <= end2)
            {
                cout << "Mathematical Analysis (practice) with Minarchenko O.M.\n// link: " << mathematicalAnalysisPractice;
                *command = "start " + mathematicalAnalysisPractice;
            }
            else if (currentTime >= start3 && currentTime <= end3)
            {
                cout << "English Course (practice) with Duchanina N.M.\n// link: " << english;
                *command = "start " + english;
            }
            else
            {
                cout << "no lecture right now";
            }
        }
        case 4:
        {
            if ((currentTime >= start1 && currentTime <= start2))
            {
                cout << "Linear Algebra (practice) with Bochonov Y.E.\n// link: " << linearAlgebra;
                *command = "start " + linearAlgebra;
            }
            else if (currentTime >= start2 && currentTime <= end2)
            {
                cout << "Physical Education (practice) with Zacharova I.Y.\n// link: " << physicalEducation;
                *command = "start " + physicalEducation;
            }
            else if (currentTime >= start3 && currentTime <= end3)
            {
                cout << "Physics of Oscillatory-Wave Processes (lecture) with Kalyta V.M.\n// link for the second group: " << physicsLab;
                *command = "start " + physicsLab;
            }
            else
            {
                cout << "no lecture right now";
            }
        }
        default:
        {
            cout << "no lecture right now";
        }
    }
}

void welcomeText (tm tm)
{
    cout << "// today is  ";
    switch (tm.tm_wday)
    {
        case 0:
            cout << "Sunday";
            break;
        case 1:
            cout << "Monday";
            break;
        case 2:
            cout << "Tuesday";
            break;
        case 3:
            cout << "Wednesday";
            break;
        case 4:
            cout << "Thursday";
            break;
        case 5:
            cout << "Friday";
            break;
        case 6:
            cout << "Saturday";
            break;
    }
    cout << endl;

    cout << "// current time:" << tm.tm_hour << ":" << tm.tm_min << ":" << tm.tm_sec << endl;
}


int main()
{
    string command;

    // наповнення розкладу теперішніми парами
//    const int daysInWeek = 5, maxLectures = 4;
//
//    int currentSchedule[daysInWeek][maxLectures];
//
//    for (int i = 0; i < daysInWeek; i++)
//    {
//        for (int k = 0; k < maxLectures; k++)
//        {
//            currentSchedule[i][k] = 0;
//        }
//    }
//
//    currentSchedule[0][0] = 4;
//    currentSchedule[0][1] = 6;
//    currentSchedule[0][2] = 5;
//    currentSchedule[0][3] = 7;
//
//    currentSchedule[1][2] = 7;
//
//    currentSchedule[2][0] = 1;
//    currentSchedule[2][1] = 6;
//    currentSchedule[2][2] = 6;
//
//    currentSchedule[3][0] = 3;
//    currentSchedule[3][1] = 6;
//    currentSchedule[3][2] = 8;
//
//    currentSchedule[4][0] = 4;
//    currentSchedule[4][1] = 9;
//    currentSchedule[4][2] = 5;

    time_t t = time(nullptr);
    tm tm = *localtime(&t);

    welcomeText (tm);

    currentLecture (tm.tm_wday, convertInMinutes(tm.tm_hour, tm.tm_min), true, &command);

    system(command.c_str());

    system("pause");

    return 0;
}