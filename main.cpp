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

#define N 5
#define M 4
#define AMOUNT_OF_SUBJECTS 11

using namespace std;

// 0 - пари немає
// 1 - АСД
// 2 - програмування
// 3 - дискретна математика
// 4 - лінійна алгебра
// 5 - фізика
// 6 - фізика, лаб 2 підгрупа
// 7 - матаналіз, лекція
// 8 - матаналіз, практика
// 9 - історія
// 10 - англійська мова
// 11 - ФП

int convertInMinutes (int hours, int minutes)
{
    return hours * 60 + minutes;
}

int convertDays (int a)
{
    if (a >= 5)
    {
        return 0;
    }
    return a;
}

bool lectureRightNow (int currentDay, int currentTime, bool firstWeek)
{
    switch (currentDay)
    {
        case 1:
        {
            if ((currentTime >= start1 && currentTime <= end1) || (currentTime >= start2 && currentTime <= end2) || (currentTime >= start3 && currentTime <= end3) || (currentTime >= start4 && currentTime <= end4))
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
            if (currentTime >= start3 && currentTime <= end3)
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
            if ((currentTime >= start1 && currentTime <= end1) || (currentTime >= start2 && currentTime <= end2) || (currentTime >= start3 && currentTime <= end3))
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
            if ((currentTime >= start1 && currentTime <= end1) || (currentTime >= start2 && currentTime <= end2) || (currentTime >= start3 && currentTime <= end3))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        case 5:
        {
            if ((currentTime >= start1 && currentTime <= end1) || (currentTime >= start2 && currentTime <= end2) || (currentTime >= start3 && currentTime <= end3))
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

void currentLecture (int currentDay, int currentTime, bool firstWeek, string* command, string link[AMOUNT_OF_SUBJECTS])
{
    switch (currentDay)
    {
        case 1:
        {
            if ((currentTime >= start1 && currentTime <= start2))
            {
                cout << "Linear Algebra (lecture) with Bochonov Y.E.\n// link: " << link[3] << endl;
                *command = "start " + link[3];
            }
            else if (currentTime >= start2 && currentTime <= end2)
            {
                cout << "Mathematical Logic and Theory of Algorithms (lecture) with Statkevych V.M.\n// link: " << link[2] << endl;
                *command = "start " + link[2];
            }
            else if (currentTime >= start3 && currentTime <= end3)
            {
                cout << "Physics of Oscillatory-Wave Processes (lecture) with Kalyta V.M.\n// link: " << link[4] << endl;
                *command = "start " + link[4];
            }
            else if (currentTime >= start4 && currentTime <= end4 && firstWeek)
            {
                cout << "Ukraine in Context of European Development (lecture) with Khytrovska Y.V.\n// link: " << link[8] << endl;
                *command = "start " + link[8];
            }
            break;
        }
        case 2:
        {
            if (currentTime >= start2 && currentTime <= end2 && !firstWeek)
            {
                cout << "Ukraine in Context of European Development (practice) with Khytrovska Y.V.\n// link: " << link[8] << endl;
                *command = "start " + link[8];
            }
            if (currentTime >= start3 && currentTime <= end3)
            {
                cout << "Ukraine in Context of European Development (practice) with Khytrovska Y.V.\n// link: " << link[8] << endl;
                *command = "start " + link[8];
            }
            break;
        }
        case 3:
        {
            if ((currentTime >= start1 && currentTime <= start2))
            {
                cout << "Algorithms and Data Structures (lecture) with Kleshch K. and Yakovchuk O.\n// link: " << link[0] << endl;
                *command = "start " + link[0];
            }
            else if (currentTime >= start2 && currentTime <= end2)
            {
                cout << "Mathematical Analysis (lecture) with Nomirovskyi D.A.\n// link: " << link[6] << endl;
                *command = "start " + link[6];
            }
            else if (currentTime >= start3 && currentTime <= end3)
            {
                cout << "Mathematical Analysis (lecture) with Nomirovskyi D.A.\n// link: " << link[6] << endl;
                *command = "start " + link[6];
            }
            break;
        }
        case 4:
        {
            if ((currentTime >= start1 && currentTime <= start2))
            {
                cout << "Mathematical Logic and Theory of Algorithms (practice) with Statkevych V.M.\n// link: " << link[2] << endl;
                *command = "start " + link[2];
            }
            else if (currentTime >= start2 && currentTime <= end2)
            {
                cout << "Mathematical Analysis (practice) with Minarchenko O.M.\n// link: " << link[7] << endl;
                *command = "start " + link[7];
            }
            else if (currentTime >= start3 && currentTime <= end3)
            {
                cout << "English Course (practice) with Duchanina N.M.\n// link: " << link[9] << endl;
                *command = "start " + link[9];
            }
            break;
        }
        default:
        {
            if ((currentTime >= start1 && currentTime <= start2))
            {
                cout << "Linear Algebra (practice) with Bochonov Y.E.\n// link: " << link[3] << endl;
                *command = "start " + link[3];
            }
            else if (currentTime >= start2 && currentTime <= end2)
            {
                cout << "Physical Education (practice) with Zacharova I.Y.\n// link: " << link[10] << endl;
                *command = "start " + link[10];
            }
            else if (currentTime >= start3 && currentTime <= end3)
            {
                cout << "Physics of Oscillatory-Wave Processes (lecture) with Kalyta V.M.\n// link for the second group: " << link[5] << endl;
                *command = "start " + link[5];
            }
        }
    }
}

void welcomeText (tm tm)
{
    cout << "// today is ";
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

    cout << "// current time:" << tm.tm_hour << ":" << ((tm.tm_min < 10) ? "0" : "") << tm.tm_min << ":" << tm.tm_sec << endl;
}

void fillArray (const int daysInWeek, const int maxLectures, int schedule[N][M], bool firstWeek)
{
    for (int i = 0; i < daysInWeek; i++)
    {
        for (int k = 0; k < maxLectures; k++)
        {
            schedule[i][k] = 0;
        }
    }

    if (firstWeek)
    {
        schedule[0][0] = 4;
        schedule[0][1] = 3;
        schedule[0][2] = 5;
        schedule[0][3] = 9;

        schedule[1][2] = 9;

        schedule[2][0] = 1;
        schedule[2][1] = 7;
        schedule[2][2] = 7;

        schedule[3][0] = 3;
        schedule[3][1] = 8;
        schedule[3][2] = 10;

        schedule[4][0] = 4;
        schedule[4][1] = 11;
        schedule[4][2] = 6;
    }
    else
    {
        schedule[0][0] = 4;
        schedule[0][1] = 3;
        schedule[0][2] = 5;

        schedule[1][2] = 8;
        schedule[1][2] = 2;

        schedule[2][0] = 1;
        schedule[2][1] = 2;
        schedule[2][2] = 7;

        schedule[3][0] = 3;
        schedule[3][1] = 8;
        schedule[3][2] = 10;

        schedule[4][0] = 4;
        schedule[4][1] = 11;
        schedule[4][2] = 5;
    }
}

void timeToTheNextLecture (int currentTime, int currentDay, bool firstWeek, string* command, int schedule[N][M], string link[AMOUNT_OF_SUBJECTS])
{
    const int dayTime = 1440;
    int daysLeft = 0, hoursLeft = 0, minutesLeft = 0, nextLectureNumber = 0, nextLectureDay = currentDay - 1;

    if (currentDay >= 1 && currentDay <= 5)
    {
        if (currentTime < start1)
        {
            minutesLeft = start1 - currentTime;
            nextLectureNumber = 0;
        }
        else if (currentTime > end1 && currentTime < start2)
        {
            minutesLeft = start2 - currentTime;
            nextLectureNumber = 1;
        }
        else if (currentTime > end2 && currentTime < start3)
        {
            minutesLeft = start3 - currentTime;
            nextLectureNumber = 2;
        }
        else if (currentTime > end3 && currentTime < start4)
        {
            minutesLeft = start4 - currentTime;
            nextLectureNumber = 3;
        }
        else
        {
            minutesLeft = dayTime - currentTime + start1;
            nextLectureNumber = 0;
            nextLectureDay++;
            if (currentDay == 5)
            {
                nextLectureDay += 2;
            }
        }
    }
    else if (currentDay == 6)
    {
        minutesLeft = dayTime - currentTime + start1 + dayTime;
        nextLectureDay += 2;
        nextLectureNumber = 0;
    }
    else if (currentDay == 7)
    {
        minutesLeft = dayTime - currentTime + start1;
        nextLectureDay += 1;
        nextLectureNumber = 0;
    }

    nextLectureDay = convertDays(nextLectureDay);

    while (schedule[nextLectureDay][nextLectureNumber] == 0)
    {
        while (nextLectureNumber < 4 && schedule[nextLectureDay][nextLectureNumber] == 0)
        {
            nextLectureNumber++;
            minutesLeft += 135;
        }
        if (schedule[nextLectureDay][nextLectureNumber] != 0)
        {
            break;
        }
        nextLectureNumber = 0;
        nextLectureDay++;
        //minutesLeft -= 135 * 4;
        nextLectureDay = convertDays(nextLectureDay);
    }

    while (minutesLeft >= 60)
    {
        hoursLeft++;
        minutesLeft -= 60;
    }

    while (hoursLeft >= 24)
    {
        daysLeft++;
        hoursLeft -= 24;
    }

    cout << "// time left until next lecture" << endl;
    cout << "// " << daysLeft << " days, " << hoursLeft << " hours and " << minutesLeft << " minutes" << endl;
    cout << "// next lecture: ";

    nextLectureDay = convertDays(nextLectureDay);

//    switch (schedule[nextLectureDay][nextLectureNumber])
//    {
//        case 1:
//            cout << "Algorithms and Data Structures (lecture) with Kleshch K. and Yakovchuk O.\n// link: " << link[0] << endl;
//            break;
//        case 2:
//            cout << "Programming and Algorithmization (lecture) with Romanov V.V.\n// link: " << link[1] << endl;
//            break;
//        case 3:
//            cout << "Mathematical Logic and Theory of Algorithms (lecture) with Statkevych V.M.\n// link: " << link[2] << endl;
//            break;
//        case 4:
//            cout << "Linear Algebra (lecture) with Bochonov Y.E.\n// link: " << link[3] << endl;
//            break;
//        case 5:
//            cout << "Physics of Oscillatory-Wave Processes (lecture) with Kalyta V.M.\n// link for the second group: " << link[5] << endl;
//            break;
//        case 6:
//            cout << "Physics (laboratory) with Ivanova I.M.\n// link for the second group: " << link[5] << endl;
//            break;
//        case 7:
//            cout << "Mathematical Analysis (practice) with Minarchenko O.M.\n// link: " << link[7] << endl;
//            break;
//        case 8:
//            cout << "Mathematical Analysis (lecture) with Nomirovskyi D.A.\n// link: " << link[6] << endl;
//            break;
//        case 9:
//            cout << "Ukraine in Context of European Development (practice) with Khytrovska Y.V.\n// link: " << link[8] << endl;
//            break;
//        case 10:
//            cout << "English Course (practice) with Duchanina N.M.\n// link: " << link[9] << endl;
//            break;
//        case 11:
//            cout << "Physical Education (practice) with Zacharova I.Y.\n// link: " << link[10] << endl;
//            break;
//    }

    currentLecture (nextLectureDay, (nextLectureNumber == 0 ? start1 : (nextLectureNumber == 1 ? start2 : (nextLectureNumber == 3 ? start3 : start4))), firstWeek, command, link);
}

int main()
{
    time_t t = time(nullptr);
    tm tm = *localtime(&t);

    const int daysInWeek = 5, maxLectures = 4;

    string command;

    int schedule[N][M];

    bool firstWeek = (((tm.tm_yday + 1) / 7) & 2) == 0;

    string links[11];

    links[0] = "https://www.google.com/"; // ASD
    links[1] = "https://www.google.com/"; // programming
    links[2] = "https://www.google.com/"; // discrete math
    links[3] = "https://www.google.com/"; // linear algebra
    links[4] = "https://www.google.com/"; // physics
    links[5] = "https://www.google.com/"; // physics lab
    links[6] = "https://www.google.com/"; // mathematical analysis lectures
    links[7] = "https://www.google.com/"; // mathematical analysis practice
    links[8] = "https://www.google.com/"; // history
    links[9] = "https://www.google.com/"; // english
    links[10] = "https://www.google.com/"; // PE

    fillArray(daysInWeek, maxLectures, schedule, firstWeek);

    welcomeText (tm);

    if (lectureRightNow(tm.tm_wday, convertInMinutes(tm.tm_hour, tm.tm_min), firstWeek))
    {
        cout << "// current lecture: ";
        currentLecture (tm.tm_wday, convertInMinutes(tm.tm_hour, tm.tm_min), firstWeek, &command, links);
    }
    else
    {
        timeToTheNextLecture(convertInMinutes(tm.tm_hour, tm.tm_min), tm.tm_wday, firstWeek, &command, schedule, links);
    }

    system(command.c_str());

    system("pause");

    return 0;
}