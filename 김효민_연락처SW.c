#include <stdio.h>
#include <Windows.h>
#include <string.h>
#include <conio.h>
#pragma warning(disable:4996) // scanf ���� ����

void ShowStudList(); // �޴� 1�� ����Ʈ ��� �Լ�
void Mod_Info(); // �������� �Լ�
void ShowStudList_Sub(); // ����Ʈ ��� �Լ�
void Inst_Info(); // �л����� �߰� �Լ�
void Del_Info(); // �л����� ���� �Լ�

char c; // Ű �Է� ��� ��������

//////////// �л����� ����ü
struct Student {
	char name[20];
	char ID[20];
	char phoneNum[20];
};

//////////// �л�����
struct Student std[5] = {
		{"kim", "111-111", "010-1111-1111"},
		{"park", "222-222", "010-2222-2222"},
		{"choi", "333-333", "010-3333-3333"},
		{"lee", "444-444", "010-4444-4444"},
		{"cho", "555-555", "010-5555-5555"}
};

//////////// �޴� 1�� ����Ʈ ���
void ShowStudList() {

	system("cls"); // ȭ�� Ŭ����
	//int Student_Num = 5;
	while (1) {
		ShowStudList_Sub();

		printf("\n\n");

		// Ű�� �������� ȭ�� �̵�
		printf("press any key...\n");
		c = getch();
		system("cls");
		break;

	}

}

//////////// ����Ʈ ���
void ShowStudList_Sub() {
	for (int i = 0; i < 5; i++) {
		printf("%d. �̸� : %s, �ֹι�ȣ : %s, ��ȭ��ȣ : %s\n", i + 1, std[i].name, std[i].ID, std[i].phoneNum);
	}
}

//////////// ��������
void Mod_Info() {
	int std_num = 0;
	char tmp_name[20];
	char tmp_ID[20];
	char tmp_phone[20];

	system("cls");

	ShowStudList_Sub();

	printf("\n\n������ �л� ��ȣ : ");
	scanf_s("%d", &std_num);

	printf("\n\n�̸� : ");
	scanf("%s", &tmp_name);
	printf("�ֹι�ȣ : ");
	scanf("%s", &tmp_ID);
	printf("��ȭ��ȣ : ");
	scanf("%s", &tmp_phone);


	strcpy(std[std_num - 1].name, tmp_name);
	strcpy(std[std_num - 1].ID, tmp_ID);
	strcpy(std[std_num - 1].phoneNum, tmp_phone);

	system("cls");

	ShowStudList_Sub();

	printf("\n\n���� �Ǿ����ϴ�.\n\n");

	printf("press any key...\n");
	c = getch();

}

//////////// ���� �߰�
void Inst_Info() {
	system("cls");
	printf("�߰� ����...\n\n");

	printf("press any key...\n");
	c = getch();
}

//////////// ���� ����
void Del_Info() {
	system("cls");
	printf("�߰� ����...\n\n");

	printf("press any key...\n");
	c = getch();
}


//////////// MAIN
int main() {

	int select = 0;

	while (select != 5) {
		system("cls");

		printf("**             ***********             **\n");
		printf("**             ����ó ����             **\n");
		printf("**             ***********             **\n");
		printf("**// 1. ����Ʈ // 2. �߰� // 3. ���� // 4. ���� // 5. ���� //**\n");
		printf("�޴��� ���� : ");
		scanf_s("%d", &select);


		switch (select) {
		case 1:
			//system("cls");
			ShowStudList();
			continue;
		case 2:
			Inst_Info();
			continue;
		case 3:
			Del_Info();
			continue;
		case 4:
			Mod_Info();
			continue;

		case 5:
			printf("\n\n");
			for (int i = 0; i < 3; i++) {
				printf("-- %d�� �� ����...\r", 3 - i); // ���ڸ� ��� ī��Ʈ �� ����
				Sleep(1000);
			}
			break;
		default:
			printf("�߸��� �Է�\n\n");
			system("cls");
			printf("press any key...\n");
			c = getch();
		}
	}

}