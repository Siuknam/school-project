// ConsoleApplication21.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <list>
#include <map>
#include<iomanip>
#include<ctime>
#include<Windows.h>
#include<time.h>
#include<stack>
#include<string>
#include<sstream>
#include<vector>
#include<array>
#pragma warning(disable :4996)
using namespace std;

class SmartPhone {
public:
    string id = "skatl";
    string pw = "tldnr133";
    string name = "남시욱";
    string num = "010-7788-3617";
    string scnum = "32171354";
    void Changepinpo() {
        int sec;
        string temp;
        cout << "1.ID 변경 2.PW 변경 3.이름 변경 4.전화번호 변경 5.학번 변경 6.종료" << endl;
        cin >> sec;
        switch (sec)
        {
        case 1:
            cout << "변경할 아이디를 입력하세요" << endl;
            cin >> temp;
            id = temp;
            cout << "아이디는" << id << "로 변경되었습니다" << endl;
            break;
        case 2:
            cout << "변경할 비밀번호를 입력하세요" << endl;
            cin >> temp;
            pw = temp;
            cout << "비밀번호는" << pw << "로 변경되었습니다" << endl;
            break;
        case 3:
            cout << "변경할 아이디를 입력하세요" << endl;
            cin >> temp;
            name = temp;
            cout << "이름은" << name << "로 변경되었습니다" << endl;
            break;
        case 4:
            cout << "변경할 전화번호 입력하세요" << endl;
            cin >> temp;
            num = temp;
            cout << "전화번호는" << num << "로 변경되었습니다" << endl;
        case 5:
            cout << "변경할 학번을 입력하세요" << endl;
            cin >> temp;
            scnum = temp;
            cout << "학번은" << scnum << "로 변경되었습니다" << endl;
        case 6:
            cout << "메뉴를 종료합니다" << endl;
            break;
        default:
            break;
        }
    };
    void Show() {
        cout << "ID :" << id << endl;
        cout << "PW :" << pw << endl;
        cout << "이름 :" << name << endl;
        cout << "전화번호 :" << num << endl;
        cout << "학번" << scnum << endl;
    };
    void run() {
        string inpid;
        string inpw;
        int log=0;
        cout << "3회 입력 실패시 로그인 불가" << endl;
        for (int i = 0; i < 3; i++) {
            cout << "ID를 입력하세요" << endl;
            cin >> inpid;
            cout << "PW를 입력하세요" << endl;
            cin >> inpw;
            if (id.compare(inpid) == 0 && pw.compare(inpw) == 0) {
                log = 1;
                break;
            }
        }
        if (log == 1) {
            cout << "로그인 성공" << endl;
            cout << "1.사용자 정보 보기 2.사용자 정보 변경 3.전화번호부 4.달력 5.계산기 6.시계 7.포커 8.종료" << endl;

        }
        else {
            cout << "로그인 실패" << endl;
        }
            

    };
};
class PhoneDirectory : public SmartPhone {
public:

    map<string, string>phninpo;
    map<string, string>::iterator iter;
    map<string, string>perinpo;

    string insname;
    string insnumb;
    string chinpo;
    string chnumb;
    int relen;
    PhoneDirectory() {
        phninpo["010-7788-3617"] = "남시욱";
        phninpo["010-9974-7612"] = "김대희";
        phninpo["010-6711-6358"] = "김민재";
        phninpo["010-5240-1221"] = "홍정우";
        perinpo["010-7788-3617"] = "대학생,23살";
        perinpo["010-9974-7612"] = "공장다님,23살,친구";
        perinpo["010-6711-6358"] = "상근,23살,결혼함";
        perinpo["010-5240-1221"] = "대학생,23살";
        size_t len = phninpo.size();
        relen = len;
    };
    void InsertPhnum() {
        cout << "이름을 입력하세요" << endl;
        cin >> insname;
        cout << "번호를 입력하세요" << endl;
        cin >> insnumb;
        cout << "추가정보를 입력하세요" << endl;
        cin >> chinpo;
        phninpo.insert(pair<string, string>(insnumb, insname));
        perinpo.insert(pair<string, string>(insnumb, chinpo));
        size_t len = phninpo.size();
        relen = len;
    };
    void ChangePhnum() {
        cout << "수정시킬 번호을 입력하세요" << endl;
        cin >> insnumb;
        iter = phninpo.find(insnumb);
        if (iter != phninpo.end())
        {
            cout << "수정할 번호를 입력하세요" << endl;
            cin >> chnumb;
            cout << "수정할 이름을 입력하세요" << endl;
            cin >> insname;
            cout << "수정할 추가정보를 입력하세요" << endl;
            cin >> chinpo;
            phninpo.erase(iter);
            perinpo.erase(insnumb);
            phninpo.insert(pair<string, string>(chnumb, insname));
            perinpo.insert(pair<string, string>(chnumb, chinpo));

        }


    };
    void DeletePhnum() {
        cout << "삭제할 번호를 입력하세요" << endl;
        cin >> insnumb;
        iter = phninpo.find(insnumb);
        if (iter != phninpo.end())
        {
            phninpo.erase(iter);
            perinpo.erase(insnumb);
        }
    };
    void ResearchPhnum() {
        cout << "찾으실 번호를 입력하세요" << endl;
        cin >> insnumb;
        iter = phninpo.find(insnumb);
        if (iter != phninpo.end())
        {
            cout << "번호 :" << iter->first << "이름 :" << iter->second << endl;
            cout << "추가정보 :" << perinpo.lower_bound(insnumb)->second << endl;
        }
    };




};

class Schedule : public SmartPhone {
public:
    int month;
    int days[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
    int startwk[12] = { 3,6,0,3,5,1,3,6,2,4,0,2 };
    char Day[7][3] = { "일","월","화","수","목","금","토" };
    int outmonth[12][32] = {0};
    map<int, string>date6;
    map<int, string>date7;
    map<int, string>date8;
    map<int, string>date9;
    map<int, string>date10;
    map<int, string>date11;
    map<int, string>date12;
    map<int, string>::iterator it;
    time_t curtimne = time(0);
    int thisday;
    int thismon;
    int inpmon;
    int inpday;
    string sche;

    Schedule() {
        date6[19] = "프로그래밍 시험";
        date6[25] = "수학시험";
        date7[14] = "내생일";
        date6[29] = "방학시작!";
    };

    void ShowCalender() {
        cout << "출력할 월을 입력하세요" << endl;
        cin >> month;
        for (int i = 0; i < 12; i++) {
            for (int j = 1; j <= days[i]; j++)
            {
                outmonth[i][j] = j;
            }
        }
        for (int i = 0; i < 7; i++)
        {
            cout << setw(2) << Day[i] << "  ";
        }
        cout << endl;

        for (int i = 0; i < startwk[month - 1]; i++) {
            cout << setw(2) << "    ";
        }

        int count = startwk[month - 1];
        for (int i = 1; i <= 32; i++) {
            count++;
            if (outmonth[month - 1][i] == 0)
                break;
            switch (month)
            {
            case 6:
                if (date6[i].empty() == false)
                    cout << "*";
                break;
            case 7:
                if (date7[i].empty() == false)
                    cout << "*";
                break;
            case 8:
                if (date8[i].empty() == false)
                    cout << "*";
                break;
            case 9:
                if (date9[i].empty() == false)
                    cout << "*";
                break;
            case 10:
                if (date10[i].empty() == false)
                    cout << "*";
                break;
            case 11:
                if (date11[i].empty() == false)
                    cout << "*";
                break;
            case 12:
                if (date12[i].empty() == false)
                    cout << "*";
                break;
            default:
                break;
            }
            cout << setw(2) << outmonth[month - 1][i] << "  ";
            if (count % 7 == 0)
                cout << endl;
        }
        tm* tlocaltime = localtime(&curtimne);
        thisday = tlocaltime->tm_mday;
        thismon = tlocaltime->tm_mon+1;
        cout << endl;
        switch (thismon)
        {
        case 6:
            it = date6.find(thisday);
            if (it != date6.end())
            {
                cout << month << "  " << thisday << "일정 :" << it->second << endl;
            }
            break;
        case 7:
            it = date7.find(thisday);
            if (it != date7.end())
            {
                cout << month << "  " << thisday << "일정 :" << it->second << endl;
            }
            break;
        case 8:
            it = date8.find(thisday);
            if (it != date8.end())
            {
                cout << month << "  " << thisday << "일정 :" << it->second << endl;
            }
            break;
        case 9:
            it = date9.find(thisday);
            if (it != date9.end())
            {
                cout << month << "  " << thisday << "일정 :" << it->second << endl;
            }
            break;
        case 10:
            it = date10.find(thisday);
            if (it != date10.end())
            {
                cout << month << "  " << thisday << "일정 :" << it->second << endl;
            }
            break;
        case 11:
            it = date11.find(thisday);
            if (it != date11.end())
            {
                cout << month << "  " << thisday << "일정 :" << it->second << endl;
            }
            break;
        case 12:
            it = date12.find(thisday);
            if (it != date12.end())
            {
                cout << month << "  " << thisday << "일정 :" << it->second << endl;
            }
            break;
        default:
            break;
        }

    };
    void InsertSchedule() {
        cout << "일정을 추가및 변경할 월을 입력하세요" << endl;
        cin >> inpmon;
        switch (inpmon)
        {
        case 6:
            cout << "일정을추가및 변경할 일을 입력하세요" << endl;
            cin >> inpday;
            it = date6.find(inpday);
            cout << "현재 일정:" << it->second << endl;
            cout << "추가및 변경할 일정을 입력하세요" << endl;
            getline(cin,sche);
            date6[inpday] = sche;
            break;
        case 7:
            cout << "일정을 추가및 변경할 일을 입력하세요" << endl;
            cin >> inpday;
            it = date7.find(inpday);
            cout << "현재 일정:" << it->second << endl;
            cout << "추가및 변경할 일정을 입력하세요" << endl;
            cin >> sche;
            date7[inpday] = sche;
            break;
        case 8:
            cout << "일정을 추가및 변경할 일을 입력하세요" << endl;
            cin >> inpday;
            it = date8.find(inpday);
            cout << "현재 일정:" << it->second << endl;
            cout << "추가및 변경할 일정을 입력하세요" << endl;
            cin >> sche;
            date8[inpday] = sche;
            break;
        case 9:
            cout << "일정을 추가및 변경할 일을 입력하세요" << endl;
            cin >> inpday;
            it = date9.find(inpday);
            cout << "현재 일정:" << it->second << endl;
            cout << "추가및 변경할 일정을 입력하세요" << endl;
            cin >> sche;
            date9[inpday] = sche;
            break;
        case 10:
            cout << "일정을 추가및 변경할 일을 입력하세요" << endl;
            cin >> inpday;
            it = date10.find(inpday);
            cout << "현재 일정:" << it->second << endl;
            cout << "추가및 변경할 일정을 입력하세요" << endl;
            cin >> sche;
            date10[inpday] = sche;
            break;
        case 11:
            cout << "일정을 추가및 변경할 일을 입력하세요" << endl;
            cin >> inpday;
            it = date11.find(inpday);
            cout << "현재 일정:" << it->second << endl;
            cout << "추가및 변경할 일정을 입력하세요" << endl;
            cin >> sche;
            date11[inpday] = sche;
            break;
        case 12:
            cout << "일정을 추가및 변경할 일을 입력하세요" << endl;
            cin >> inpday;
            it = date12.find(inpday);
            cout << "현재 일정:" << it->second << endl;
            cout << "추가및 변경할 일정을 입력하세요" << endl;
            cin >> sche;
            date12[inpday] = sche;
            break;
        default:
            break;
        }
    };
    void ReasearchSchedule() {
        cout << "일정을 검색할 월을 입력하세요" << endl;
        cin >> inpmon;
        switch (inpmon)
        {
        case 6:
            cout << "일정을 검색할 날짜를 입력하세요" << endl;
            cin >> inpday;
            it = date6.find(inpday);
            cout << "일정 :" << it->second << endl;
            break;
        case 7:
            cout << "일정을 검색할 날짜를 입력하세요" << endl;
            cin >> inpday;
            it = date7.find(inpday);
            cout << "일정 :" << it->second << endl;
            break;
        case 8:
            cout << "일정을 검색할 날짜를 입력하세요" << endl;
            cin >> inpday;
            it = date8.find(inpday);
            cout << "일정 :" << it->second << endl;
            break;
        case 9:
            cout << "일정을 검색할 날짜를 입력하세요" << endl;
            cin >> inpday;
            it = date9.find(inpday);
            cout << "일정 :" << it->second << endl;
            break;
        case 10:
            cout << "일정을 검색할 날짜를 입력하세요" << endl;
            cin >> inpday;
            it = date10.find(inpday);
            cout << "일정 :" << it->second << endl;
            break;
        case 11:
            cout << "일정을 검색할 날짜를 입력하세요" << endl;
            cin >> inpday;
            it = date11.find(inpday);
            cout << "일정 :" << it->second << endl;
            break;
        case 12:
            cout << "일정을 검색할 날짜를 입력하세요" << endl;
            cin >> inpday;
            it = date12.find(inpday);
            cout << "일정 :" << it->second << endl;
            break;
        default:
            break;
        }
    };

};

class Clock : public SmartPhone {
public:
    int count = 0;
    int inday;
    int inhour;
    int inmin;
    void Showtime() {
        cout << "시계 실행후 1분뒤 자동으로 종료됩니다" << endl;
        for (;;) {
            
            time_t curtime2 = time(0);
            tm* tlocaltime = localtime(&curtime2);
            cout << "\t";
            cout << tlocaltime->tm_year + 1900 << "년 ";
            cout << tlocaltime->tm_mon + 1 << "월 ";
            cout << tlocaltime->tm_mday << "일 ";
            cout << tlocaltime->tm_hour << "시 ";
            cout << tlocaltime->tm_min << "분 ";
            cout << tlocaltime->tm_sec << "초 ";
            cout << endl;
            _sleep(1000);
            count++;
            system("cls");
            if (count == 60)
                break;
        }
    };
    void Alarm() {
        cout << "알람 설정" << endl;
        cout << "일 // 시 // 분 // 을 입력해주세요 예)19 23 17)" << endl;
        cin >> inday >> inhour >> inmin;
        cout << inday << inhour << inmin;
        for (;;) {
            time_t curtime2 = time(0);
            tm* tlocaltime = localtime(&curtime2);
            cout << "\t";
            cout << tlocaltime->tm_year + 1900 << "년 ";
            cout << tlocaltime->tm_mon + 1 << "월 ";
            cout << tlocaltime->tm_mday << "일 ";
            cout << tlocaltime->tm_hour << "시 ";
            cout << tlocaltime->tm_min << "분 ";
            cout << tlocaltime->tm_sec << "초 ";
            cout << "째깍";
            if (tlocaltime->tm_mday == inday && tlocaltime->tm_hour == inhour && tlocaltime->tm_min==inmin) {
                for (int i = 0; i < 10; i++) {
                    cout << "따르르르르르르를를으릉릉르을을으릉" << endl;
                }
                break;
            }
            _sleep(1000);
            system("cls");
        }
    };

};

class Calculator :public SmartPhone {
public:
    struct oper
    {
        int rak;
        string opq;
    };
    stack<int> number;
    stack<oper> op;
    int firstrak;
    int temp;
    int temp2;
    int result;
        string inp;
    void calcul() {
        temp2 = number.top();
        number.pop();
        temp = number.top();
        number.pop();
        string oper = op.top().opq;
        op.pop();
        if (oper == "*")
            result = temp * temp2;
        else if (oper == "/")
            result = temp / temp2;
        else if (oper == "+")
            result = temp + temp2;
        else if (oper == "-")
            result = temp - temp2;
        number.push(result);
    };
    void calrun() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        cout << "연산식을 입력하세요 // 사칙연산 // ()포함 =제외 // 문자마다 공백필요" << endl;
        getline(cin,inp);
        std::istringstream cast(inp);
        string token;

        while (cast >> token) {
            std::cout << token << std::endl;
            if (token == "(")
                op.push({0,token });
            else if (token == ")")
            {
                while (op.top().opq != "(")
                   calcul();
                op.pop();

            }
            else if (token == "*" || token == "/" || token == "+" || token == "-") {
                if (token == "*")
                    firstrak = 2;
                else if (token == "/")
                    firstrak = 2;
                else if (token == "+")
                    firstrak = 1;
                else if (token == "-")
                    firstrak = 1;

                while (!op.empty() && firstrak <= op.top().rak)
                    calcul();
                op.push({firstrak,token });
            }
            else
                number.push(stoi(token));
        }
        while (!op.empty())
            calcul();

        cout << number.top();
   
    };
           
};
class CardGame : public SmartPhone {
public:
    struct maincard {
       const char *shape;
        int rank;
    };
    int ran1, ran2;
    maincard temp;
    maincard set[52];
    maincard my[5];
    maincard player1[5];
    const char* inshape;
    int inrank,inrank2;
    int chrank,chrank2;
    int shcount=0;
    int nucount = 0;
    int shcount2 = 0;
    int nucount2 = 0;
    int index;
    int tmp;
    int index2;
    int tmp2;
    int paircount;
    int paircount2;
    int n = 0;
    int count = 0;


    void Cardrun() {
        count = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 13; j++)
            {
                if (i == 0)
                {
                    set[count].shape = "◆";
                }
                else if (i == 1)
                {
                    set[count].shape = "♥";
                }
                else if (i == 2)
                {
                    set[count].shape = "♠";
                }
                else if (i == 3)
                {
                    set[count].shape = "♣";
                }
                set[count].rank = j + 1;
                count++;
            }
        }
    };
    void Shuffle() {
        for (int i = 0; i < 100; i++)
        {
            ran1 = rand() % 52;
            ran2 = rand() % 52;
            temp = set[ran1];
            set[ran1] = set[ran2];
            set[ran2] = temp;           
        }

        for (int i = 0; i < 5; i++)
        {
            my[i]= set[i];
            my[i]= set[i];
            player1[i] = set[i + 5];
            player1[i] = set[i + 5];
            cout << i + 1 << "번째 카드 분배" << endl;
        }
        for (int i = 0; i < 5; i++)
        {
            index = i;
            index2 = i;
            for (int j = i + 1; j < 6; j++)
            {
                if (my[index].rank < my[j].rank)
                {
                    index = j;
                }
                if (player1[index2].rank < player1[index2].rank)
                {
                    index2 = j;
                }
            }
            tmp = my[i].rank;
            my[i].rank = my[index].rank;
            my[index].rank = tmp;
            tmp2 = player1[i].rank;
            my[i].rank = player1[index].rank;
            my[index2].rank = tmp2;
        }
        cout << "카드 분배 완료" << endl;
        for (int i = 0; i < 5; i++)
        {
            cout << my[i].rank << endl;
            cout << my[i].shape << endl;
        }
      
    };
    void CheckCardRank() {
        inrank = 0;
        inrank2 = 0;
        shcount = 0;
        shcount2 = 0;
        nucount = 0;
        nucount2 = 0;
        chrank = 0;
        chrank2 = 0;
        paircount = 0;
        paircount2 = 0;

        int asd2 = 1;
        for (int i = 0; i < 5; i++)
        {
            for (int j = asd2; j < 5; j++)
            {
                if (my[i].shape == my[j].shape)
                    shcount++;
                else if (my[i].rank == my[j].rank)
                    nucount++;
                if (player1[i].shape == player1[j].shape)
                    shcount2++;
                else if (player1[i].rank == player1[j].rank)
                    nucount2++;
            }
            asd2++;
        }


        for (int i = 0; i < 4;i++)
        {
            if (my[i + 1].rank - my[i].rank == 1)
                chrank++;
            else
            chrank = 0;
            if (player1[i + 1].rank - player1[i].rank == 1)
                chrank2++;
            else
                chrank2 = 0;
        }
       int asd = 1;
        for (int i = 0; i < 5; i++)
        { 
            for (int j = asd; j<5 ; j++)
            {
                if (my[i].rank == my[j].rank)
                    paircount++;
                if (player1[i].rank == player1[j].rank)
                    paircount2++;
            }
            asd++;
        }
        if (paircount == 4)
        {
            inrank = 11;
        }
        else if (paircount == 3)
        {
            inrank = 8;
        }
        else if (paircount == 2)
        {
            inrank = 7;
        }
        else if (paircount == 1)
        {
            inrank = 6;
        }
        else
        {
            inrank = 5;
        }
        if (paircount2 == 4)
        {
            inrank2 = 11;
        }
        else if (paircount2 == 3)
        {
            inrank2 = 8;
        }
        else if (paircount2 == 2)
        {
            inrank2 = 7;
        }
        else if (paircount2 == 1)
        {
            inrank2 = 6;
        }
        else
        {
            inrank2 = 5;
        }

        if (shcount >= 6)
        {
            inrank = 10;
        }
        else if (nucount >= 6)
        {
            inrank = 12;
        }
        if (shcount2 == 6)
        {
            inrank2 = 10;
        }
        else if (nucount2 >= 6)
        {
            inrank2 = 12;
        }
        if (shcount == 4 && chrank >= 4)
        {
            inrank = 13;
        }
        if (shcount2 == 4 && chrank2 >= 4)
        {
            inrank2 = 13;
        }
        if (chrank >= 4)
        {
            inrank = 9;
        }
        if (chrank2 >= 4)
        {
            inrank2 = 9;
        }
    };
    void Gameresult() {
        string res;
        if (inrank == inrank2)
        {
            cout << "무승부!!" << endl;
        }
        else if (inrank > inrank2)
        {
            switch (inrank)
            {
            case 13:
                cout << "스트레이트 플러쉬로 승리" << endl;
                break;
            case 12:
                cout << "포 카드로 승리" << endl;
                break;
            case 11:
                cout << "풀 하우스로 승리" << endl;
                break;
            case 10:
                cout << "플러쉬로 승리" << endl;
                break;
            case 9:
                cout << "스트레이트로 승리" << endl;
                break;
            case 8:
                cout << "트리플로 승리" << endl;
                break;
            case 7:
                cout << "투페어로 승리" << endl;
                break;
            case 6:
                cout << "원페어로 승리" << endl;
                break;
            }
        }
        else if (inrank < inrank2)
        {
            switch (inrank)
            {
            case 13:
                cout << "스트레이트 플러쉬로 패배" << endl;
                break;
            case 12:
                cout << "포 카드로 패배" << endl;
                break;
            case 11:
                cout << "풀 하우스로 패배" << endl;
                break;
            case 10:
                cout << "플러쉬로 패배" << endl;
                break;
            case 9:
                cout << "스트레이트로 패배" << endl;
                break;
            case 8:
                cout << "트리플로 패배" << endl;
                break;
            case 7:
                cout << "투페어로 패배" << endl;
                break;
            case 6:
                cout << "원페어로 패배" << endl;
                break;

            }
        }
    
    
    };  
    
};



int main()
{
    PhoneDirectory test;
    Schedule test2;
    Clock test3;
    Calculator test4;
    CardGame test5;
    int choice;

    for (;;)
    {
        cout << "1.로그인 2.종료 "<<endl;
        cin >> choice;
        if (choice == 1)
        {
            test.run();
            cin >> choice;
            if (choice == 1)
            {
                test.Show();
            }
            else if (choice == 2)
            {
                test.Changepinpo();
            }
            else if (choice == 3)
            {
                
                for (;;) {
                    cout << "1.추가 2.수정 3.삭제 4.검색 5.이전" << endl;
                    cin >> choice;
                    if (choice == 1)
                    {
                        test.InsertPhnum();
                    }
                    else if (choice == 2)
                    {
                        test.ChangePhnum();
                    }
                    else if (choice == 3)
                    {
                        test.DeletePhnum();
                    }
                    else if (choice == 4)
                    {
                        test.ResearchPhnum();
                    }
                    else if (choice == 5)
                    {
                        break;
                    }
                    else
                    {
                        cout << "잘못된 입력" << endl;
                    }
                }
            }
            else if (choice == 4)
            {
                for (;;) {
                    cout << "1.달력 보기 2.일정 추가 3.일정 검색 4.이전" << endl;
                    cin >> choice;
                    if (choice == 1)
                    {
                        test2.ShowCalender();
                    }
                    else if (choice == 2)
                    {
                        test2.InsertSchedule();
                    }
                    else if (choice == 3)
                    {
                        test2.ReasearchSchedule();
                    }
                    else if (choice == 4)
                    {
                        break;
                    }
                    else
                    {
                        cout << "잘못된 입력" << endl
                    }
                }
                
            }
            else if (choice == 5)
            {
                for (;;) {
                    cout << "1.계산기 실행 2.이전" << endl;
                    cin >> choice;
                    if (choice == 1)
                    {
                        test4.calrun();
                    }
                    else if (choice == 2)
                    {
                        break;
                    }
                    else
                    {
                        cout << "잘못된 입력" << endl;
                    }
                }
            }
            else if (choice == 6)
            {
                for (;;) {
                    cout << "1.시계 2.알람 3.이전" << endl;
                    cin >> choice;
                    if (choice == 1)
                    {
                        test3.Showtime();
                    }
                    else if (choice == 2)
                    {
                        test3.Alarm();
                    }
                    else if (choice == 3)
                    {
                        break;
                    }
                    else {
                        cout << "잘못된 입력" << endl;
                    }
                }
            }
            else if (choice == 7)
            {
                for (;;) {
                    cout << "1.게임 시작 2.이전" << endl;
                    cin >> choice;
                    if (choice == 1)
                    {
                        test5.Cardrun();
                        test5.Shuffle();
                        test5.CheckCardRank();
                        test5.Gameresult();
                    }
                    else if (choice == 2)
                    {
                        break;
                    }
                    else
                    {
                        cout << "잘못된 입력" << endl;
                    }

                }
            }
        }
        else if (choice == 2)
        {
            break;
        }
        else {
            cout << "잘못된 입력" << endl;
        }

    }

}

