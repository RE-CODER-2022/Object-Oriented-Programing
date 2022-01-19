#include <iostream>
#include <cstring>
using namespace std;

class univ
{
private:
	char U_Name[20]; // 학교 이름
	int year; // 학년
	char U_StuID[20]; // 학번

public:
	void setU_name(char *U_Names){ strcpy(U_Name, U_Names); } // 학교 이름 setter 함수
	void setU_StuID(char* U_StuIDs) { strcpy(U_StuID, U_StuIDs); } // 학번 setter 함수
	void setYear(int Years) { this->year = Years; } // 학년 setter 함수
		
	char* getU_name() { return U_Name; } // 학교 이름 getter 함수(main에서 출력하기 위해)
	char* getU_StuID() { return U_StuID; } // 학번 getter 함수(main에서 출력하기 위해)
	int getYear() { return year; } // 학교 이름 getter 함수(main에서 출력하기 위해)
};

class cie :public univ
{
private:
	char Object_Oriented_Programming; // 객프 성적
	char Digital_Logic_Circuit; // 디논 성적

public:
	void setOOP(char OOPs) { this->Object_Oriented_Programming = OOPs; } // 객프 성적 setter 함수
	void setDLC(char DLCs) { this->Digital_Logic_Circuit = DLCs; } // 디논 성적 setter 함수

	char getOOP() { return Object_Oriented_Programming; } // 객프 성적 getter 함수
	char getDLC() { return Digital_Logic_Circuit; } // 디논 성적 getter 함수
};

class stu_infor :public cie
{
private:
	char Name[10]; // 학생 이름
	int age; // 학생 나이

public:
	void setName(char* Names) { strcpy(Name, Names); } // 학생 이름 setter 함수
	void setAge(int ages) { this->age = ages; } // 학생 나이 setter 함수

	char* getName() { return Name; } // 학생 이름 getter 함수
	int getAge() { return age; } // 학생 나이 getter 함수
};

int main(void)
{
	char choice[20]; // INSERT, FIND, EXIT 선택
	char univ_name[20]; // 학교 이름
	int stu_year; // 학년
	char OOP_grade; // 객프 학점
	char DLC_grade; // 디논 학점
	char stu_name[20]; // 학생 이름
	char stu_num[20]; // 학생 학번
	int stu_age; // 학생 나이
	int count = 0; // 배열 index
	stu_infor infor[100]; // 클래스 배열


	while (1) // 무한루프
	{
		cin >> choice; 

		if (!strcmp(choice, "INSERT")) // 학생 정보 입력
		{
			cout << "학교 : ";
			cin >> univ_name;
			infor[count].setU_name(univ_name);

			cout << "학번 : ";
			cin >> stu_num;
			infor[count].setU_StuID(stu_num);

			cout << "학년 : ";
			cin >> stu_year;
			infor[count].setYear(stu_year);

			cout << "객체지향프로그래밍 학점 :";
			cin >> OOP_grade;
			infor[count].setOOP(OOP_grade);

			cout << "디지털논리회로 학점 :";
			cin >> DLC_grade;
			infor[count].setDLC(DLC_grade);

			cout << "이름 :";
			cin >> stu_name;
			infor[count].setName(stu_name);

			cout << "나이 :";
			cin >> stu_age;
			infor[count].setAge(stu_age);

			count++;
		}

		else if (!strcmp(choice, "FIND")) // 학생 정보 불러오기
		{
			cin >> stu_name >> stu_num;

			for (int j = 0; j < 100; j++)
			{
				if (!strcmp(stu_name, infor[j].getName()) && !strcmp(stu_num, infor[j].getU_StuID()))
				{
					cout << "학교 : " << infor[j].getU_name() << endl;
					cout << "학번 : " << infor[j].getU_StuID() << endl;
					cout << "학년 : " << infor[j].getYear() << endl;
					cout << "객체지향프로그래밍 학점 :" << infor[j].getOOP() << endl;
					cout << "디지털논리회로 학점 :" << infor[j].getDLC() << endl;
				}
			}
		}
		else // INSERT, FIND 외의 모든 문자들은 전부 break(EXIT 포함)
			break;
	}

	return 0;
}