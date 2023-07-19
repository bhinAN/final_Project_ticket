#include <iostream>
#include <stdio.h>
#include "Calage.h"

using namespace std;

int main()
{
	int choice1, choiceEnd;
	int residentNum;
	while (1) {
		cout << "권종을 선택하세요." << endl;
		cout << "1. 주간권\n" << "2. 야간권" << endl;
		cin >> choice1;
		cout << "주민번호 앞자리 6자리를 입력하세요." << endl;
		cin >> residentNum;

		Price p(choice1, residentNum);
		
		cout << "계속 발권 하시겠습니까?" << endl;
		cout << "1. 티켓 발권\n" << "2. 종료" << endl;
		cin >> choiceEnd;
		if (choiceEnd == 2) {
			cout << "이용해주셔서 감사합니다." << endl;
			break;
		}
		
	}
}