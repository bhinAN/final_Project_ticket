# final_Project_ticket
#include <stdio.h>
#include <iostream>
#include <cstdio>
#include <ctime>

class CalAge // 주민번호 앞자리를 이용하여 나이를 계산하는 클래스
{
private:
	int residentNumber; //주민번호
	int age, cal; //나이, cal--> 주민번호 앞자리
	int a, b; //계산식을 담기 위한 변수
	int month;
	int date;
	int year;
	int year_month_date;
  //현재 날짜를 받아올 변수들

public:
	
	CalAge(int ResNum) {
		
		std::time_t currentTime = std::time(nullptr);
		std::tm localTime = *std::localtime(&currentTime);
    //현재 날짜를 가져옴
		year = localTime.tm_year + 1900; //1900년도 부터 흘러간 시간을 넣음
		month =(localTime.tm_mon + 1) *100;
		date = month + localTime.tm_mday;
    //주민번호로 부터 지나간 시간을 계산하기 위해 월과 날짜를 조정
		year_month_date = (year * 10000) + date;
		residentNumber = ResNum;
		cal = residentNumber / 100000;
    
		if (cal == 9)
		{
			a = residentNumber / 10000;
			a = a + 1900;
			b = residentNumber % 10000;
			if (b <= date)
			{
				age = year - a;
				age = 1 + age;
			}
			else
			{
				age = year - a;
			}
			
		}
		else if (cal == 0)
		{
			a = residentNumber / 10000;
			a = a + 2000;
			b = residentNumber % 10000;
			if (b <= date)
			{
				age = year - a;
				age = 1 + age;
			}
			else 
			{
				age = year - a;
			}
		}
	}
	int getAge() {
		return age;


	}
	int getDate() {
		return year_month_date;
	}
};


class Price :public CalAge //가격을 계산하기 위한 클래스
{
private:
	int aage;
	int price;
	int adultDayPrice = 56000, youthDayPrice =47000, childDayPrice = 44000, seniorDayPrice = 44000;
	int adultNightPrice = 46000, youthNightPrice = 40000, childNightPrice = 37000, seniorNightPrice = 37000;
	const int MaxCount = 10;
	const int MinCount = 1;
	int count;


public:
	Price(int day, int ResNum, int ccount) : CalAge(ResNum) {

		aage = getAge();
		count = ccount;
		if (count<MinCount || count>MaxCount) {
			do {
				cout << "권장 개수를 다시 입력해 주세요.(최대 10개)." << endl;
				cin >> count;
				if (count<MinCount || count>MaxCount) {
					std::cout << "권장 개수를 다시 입력해 주세요.(최대 10개)." << endl;

				}
			} while (count<MinCount || count>MaxCount);
		}

		if (aage <= 2) {
			price = 0;
		}
		else if (aage >= 3 && aage <= 12) {
			if (day == 1) {
				price = childDayPrice * count;
			}
			else if (day == 2) {
				price = childNightPrice * count;
			}
		}
		else if (aage >= 13 && aage <= 18) {
			if (day == 1) {
				price = youthDayPrice * count;
			}
			else if (day == 2) {
				price = youthNightPrice * count;
			}
		}
		else if (aage >= 19 && aage <= 64) {
			if (day == 1) {
				price = adultDayPrice * count;
			}
			else if (day == 2) {
				price = adultNightPrice * count;
			}
		}
		else if (aage >= 65) {
			if (day == 1) {
				price = seniorDayPrice * count;
			}
			else if (day == 2) {
				price = seniorNightPrice * count;
			}
		}

	}
	int getPrice() {
		return price;
	}
};
class Significant : public Price
{
private:
	int pprice;
	int aa;
	int result;


public:
	Significant(int day, int significant, int ResNum, int count) : Price(day, ResNum, count) {

		pprice = getPrice();

		if (significant == 2) {
			aa = (pprice * 40) / 100;
			result = pprice - aa;
			std::cout << "가격은 " << result << "원 입니다.\n" << "감사합니다." << std::endl;
		}
		else if (significant == 3) {
			aa = (pprice * 50) / 100;
			result = pprice - aa;
			std::cout << "가격은 " << result << "원 입니다.\n" << "감사합니다." << std::endl;
		}
		else if (significant == 4) {
			aa = (pprice * 20) / 100;
			result = pprice - aa;
			std::cout << "가격은 " << result << "원 입니다.\n" << "감사합니다." << std::endl;
		}
		else if (significant == 5) {
			aa = (pprice * 15) / 100;
			result = pprice - aa;
			std::cout << "가격은 " << result << "원 입니다.\n" << "감사합니다." << std::endl;
		}
		else{
			result = pprice;
			std::cout << "가격은 " << result << "원 입니다.\n" << "감사합니다." << std::endl;
		}
		
		
	}
	int getPPrice() {
		return pprice;
	}

};
class List : public Significant
{
private:
	string dday;
	string ssignificant;
	int date;
	int age;
	int RResNum;
	int ccount;
	int pprice;
	int* values; // 동적 배열로 저장할 값들을 위한 포인터
	int size; // 현재 배열의 크기
	int capacity; // 현재 할당된 메모리 공간의 크기
	void resizeArray() {
		// 배열의 크기를 2배로 늘림
		capacity *= 2;
		int* tempArray = new int[capacity];
		for (int i = 0; i < size; ++i) {
			tempArray[i] = values[i];
		}
		delete[] values;
		values = tempArray;
	}

public:
	List(int day, int significant, int ResNum, int count) : Significant(day, significant, ResNum, count) {
		
		date = getDate();
		age = getAge();
		pprice = getPPrice();

		if (day == 1) {
			dday = "주간권";
		}
		else if (day == 2) {
			dday = "야간권";
		}
		if (significant == 1) {

		}

		capacity = 10;
		
	}

};
