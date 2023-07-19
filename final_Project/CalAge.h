#pragma once
#include <stdio.h>
#include <iostream>
#include <cstdio>
#include <ctime>

class CalAge
{
private:
	int residentNumber;
	int age, cal;
	int a, b;
	int date = 719;
	int year = 2023;
	

public:
	
	CalAge(int ResNum) {
		
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
};


class Price :public CalAge
{
private:
	int aage;
	int price;
	int adultDayPrice = 56000, youthDayPrice =47000, childDayPrice = 44000, seniorDayPrice = 44000;
	int adultNightPrice = 46000, youthNightPrice = 40000, childNightPrice = 37000, seniorNightPrice = 37000;


public:
	Price(int day, int ResNum) : CalAge(ResNum) {

		aage = getAge();

		if (aage <= 2) {
			price = 0;
		}
		else if (aage >= 3 && aage <= 12) {
			if (day == 1) {
				price = childDayPrice;
			}
			else if (day == 2) {
				price = childNightPrice;
			}
		}
		else if (aage >= 13 && aage <= 18) {
			if (day == 1) {
				price = youthDayPrice;
			}
			else if (day == 2) {
				price = youthNightPrice;
			}
		}
		else if (aage >= 19 && aage <= 64) {
			if (day == 1) {
				price = adultDayPrice;
			}
			else if (day == 2) {
				price = adultNightPrice;
			}
		}
		else if (aage >= 65) {
			if (day == 1) {
				price = seniorDayPrice;
			}
			else if (day == 2) {
				price = seniorNightPrice;
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
	Significant(int day, int significant, int ResNum) : Price(day, ResNum) {

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

};