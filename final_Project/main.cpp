#include <iostream>
#include <stdio.h>
#include "Calage.h"

using namespace std;

int main()
{
	int choice1, choiceEnd;
	int residentNum;
	while (1) {
		cout << "������ �����ϼ���." << endl;
		cout << "1. �ְ���\n" << "2. �߰���" << endl;
		cin >> choice1;
		cout << "�ֹι�ȣ ���ڸ� 6�ڸ��� �Է��ϼ���." << endl;
		cin >> residentNum;

		Price p(choice1, residentNum);
		
		cout << "��� �߱� �Ͻðڽ��ϱ�?" << endl;
		cout << "1. Ƽ�� �߱�\n" << "2. ����" << endl;
		cin >> choiceEnd;
		if (choiceEnd == 2) {
			cout << "�̿����ּż� �����մϴ�." << endl;
			break;
		}
		
	}
}