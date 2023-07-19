#include <iostream>
#include <stdio.h>
#include "Calage.h"

using namespace std;

int main()
{
	int choice1, choice2, choiceEnd;
	int residentNum;
	int a, b;
	while (1) {
		cout << "권종을 선택하세요." << endl;
		cout << "1. 주간권\n" << "2. 야간권" << endl;
		while (1)
		{
			cin >> choice1;
			if (choice1 == 1 || choice1 == 2) {
				break;
			}
			else {
				cout << "다시 선택해주세요." << endl;
			}
		}
		cout << endl;
		//권종 선택
	
		cout << "주민번호 앞자리 6자리를 입력하세요." << endl;
		cin >> residentNum;
		cout << endl;
		//주민번호 입력

		cout << "우대상항을 선택하세요." << endl;
		cout << "1. 없음\n" << "2. 장애인\n" << "3. 국가유공자\n" << 
			"4. 다자녀\n" << "5. 임산부" << endl;

		while (1)
		{
			cin >> choice2;
			if (choice2 == 1 || choice2 == 2 || choice2 == 3 || choice2 == 4 || choice2 == 5) {
				break;
			}
			else {
				cout << "다시 선택해주세요." << endl;
			}
		}
		cout << endl;
		//우대사항 선택

		Significant P(choice1, choice2, residentNum);
		//class 호출

		cout << "계속 발권 하시겠습니까?" << endl;
		cout << "1. 티켓 발권\n" << "2. 종료" << endl;
		
		while (1)
		{
			cin >> choiceEnd;
			if (choiceEnd == 1 || choiceEnd == 2) {
				break;
			}
			else {
				cout << "다시 선택해주세요." << endl;
			}
		}

		if (choiceEnd == 2) {
			cout << "이용해주셔서 감사합니다.\n" << endl;
			break;
		}
		

	}
}