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
		cout << "������ �����ϼ���." << endl;
		cout << "1. �ְ���\n" << "2. �߰���" << endl;
		while (1)
		{
			cin >> choice1;
			if (choice1 == 1 || choice1 == 2) {
				break;
			}
			else {
				cout << "�ٽ� �������ּ���." << endl;
			}
		}
		cout << endl;
		//���� ����
	
		cout << "�ֹι�ȣ ���ڸ� 6�ڸ��� �Է��ϼ���." << endl;
		cin >> residentNum;
		cout << endl;
		//�ֹι�ȣ �Է�

		cout << "�������� �����ϼ���." << endl;
		cout << "1. ����\n" << "2. �����\n" << "3. ����������\n" << 
			"4. ���ڳ�\n" << "5. �ӻ��" << endl;

		while (1)
		{
			cin >> choice2;
			if (choice2 == 1 || choice2 == 2 || choice2 == 3 || choice2 == 4 || choice2 == 5) {
				break;
			}
			else {
				cout << "�ٽ� �������ּ���." << endl;
			}
		}
		cout << endl;
		//������ ����

		Significant P(choice1, choice2, residentNum);
		//class ȣ��

		cout << "��� �߱� �Ͻðڽ��ϱ�?" << endl;
		cout << "1. Ƽ�� �߱�\n" << "2. ����" << endl;
		
		while (1)
		{
			cin >> choiceEnd;
			if (choiceEnd == 1 || choiceEnd == 2) {
				break;
			}
			else {
				cout << "�ٽ� �������ּ���." << endl;
			}
		}

		if (choiceEnd == 2) {
			cout << "�̿����ּż� �����մϴ�.\n" << endl;
			break;
		}
		

	}
}