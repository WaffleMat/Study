#include <stdio.h>
#include <Windows.h>
#include <string.h>
#include <conio.h>
#pragma warning(disable:4996) // scanf 에러 무시

void ShowStudList(); // 메뉴 1번 리스트 출력 함수
void Mod_Info(); // 정보수정 함수
void ShowStudList_Sub(); // 리스트 출력 함수
void Inst_Info(); // 학생정보 추가 함수
void Del_Info(); // 학생정보 삭제 함수

char c; // 키 입력 대기 전역변수

//////////// 학생정보 구조체
struct Student {
	char name[20];
	char ID[20];
	char phoneNum[20];
};

//////////// 학생정보
struct Student std[5] = {
		{"kim", "111-111", "010-1111-1111"},
		{"park", "222-222", "010-2222-2222"},
		{"choi", "333-333", "010-3333-3333"},
		{"lee", "444-444", "010-4444-4444"},
		{"cho", "555-555", "010-5555-5555"}
};

//////////// 메뉴 1번 리스트 출력
void ShowStudList() {

	system("cls"); // 화면 클리어
	//int Student_Num = 5;
	while (1) {
		ShowStudList_Sub();

		printf("\n\n");

		// 키를 눌렀을때 화면 이동
		printf("press any key...\n");
		c = getch();
		system("cls");
		break;

	}

}

//////////// 리스트 출력
void ShowStudList_Sub() {
	for (int i = 0; i < 5; i++) {
		printf("%d. 이름 : %s, 주민번호 : %s, 전화번호 : %s\n", i + 1, std[i].name, std[i].ID, std[i].phoneNum);
	}
}

//////////// 정보수정
void Mod_Info() {
	int std_num = 0;
	char tmp_name[20];
	char tmp_ID[20];
	char tmp_phone[20];

	system("cls");

	ShowStudList_Sub();

	printf("\n\n수정할 학생 번호 : ");
	scanf_s("%d", &std_num);

	printf("\n\n이름 : ");
	scanf("%s", &tmp_name);
	printf("주민번호 : ");
	scanf("%s", &tmp_ID);
	printf("전화번호 : ");
	scanf("%s", &tmp_phone);


	strcpy(std[std_num - 1].name, tmp_name);
	strcpy(std[std_num - 1].ID, tmp_ID);
	strcpy(std[std_num - 1].phoneNum, tmp_phone);

	system("cls");

	ShowStudList_Sub();

	printf("\n\n수정 되었습니다.\n\n");

	printf("press any key...\n");
	c = getch();

}

//////////// 정보 추가
void Inst_Info() {
	system("cls");
	printf("추가 예정...\n\n");

	printf("press any key...\n");
	c = getch();
}

//////////// 정보 삭제
void Del_Info() {
	system("cls");
	printf("추가 예정...\n\n");

	printf("press any key...\n");
	c = getch();
}


//////////// MAIN
int main() {

	int select = 0;

	while (select != 5) {
		system("cls");

		printf("**             ***********             **\n");
		printf("**             연락처 관리             **\n");
		printf("**             ***********             **\n");
		printf("**// 1. 리스트 // 2. 추가 // 3. 삭제 // 4. 수정 // 5. 종료 //**\n");
		printf("메뉴를 선택 : ");
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
				printf("-- %d초 후 종료...\r", 3 - i); // 제자리 출력 카운트 후 종료
				Sleep(1000);
			}
			break;
		default:
			printf("잘못된 입력\n\n");
			system("cls");
			printf("press any key...\n");
			c = getch();
		}
	}

}