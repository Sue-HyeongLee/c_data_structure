#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "ArrayList.h"

int main(void)
{
	List list;
	NameCard* namecard;
	ListInit(&list);

	NameCard* namecard1 = MakeNameCard("이수형 ", "010-1234-5785");
	NameCard* namecard2 = MakeNameCard("이도형 ", "010-1121-5795");
	NameCard* namecard3 = MakeNameCard("박준상 ", "010-1263-5185");

	LInsert(&list, namecard1 );
	LInsert(&list, namecard2 );
	LInsert(&list, namecard3 );

	if (LFirst(&list, &namecard)) {
		if (NameCompare(namecard, "이수형 ") == 0)
			ShowNameCardInfo(namecard);
		while (LNext(&list, &namecard)) {
			if (NameCompare(namecard, "이수형 ") == 0)
				ShowNameCardInfo(namecard);
		}
		
	}

	if (LFirst(&list, &namecard)) {
		if (NameCompare(namecard, "이수형 ") == 0)
			ChangePhoneNum(namecard, "010-8863-5785");
		while (LNext(&list, &namecard)) {
			if (NameCompare(namecard, "이수형 ") == 0)
				ChangePhoneNum(namecard, "010-8863-5785");
		}

	}

	if (LFirst(&list, &namecard)) {
		if (NameCompare(namecard, "이도형 ") == 0) {
			namecard = LRemove(&list);
			free(namecard);
		}
			
		while (LNext(&list, &namecard)) {
			if (NameCompare(namecard, "이도형 ") == 0) {
				namecard = LRemove(&list);
				free(namecard);
			}
		}

	}

	if (LFirst(&list, &namecard)) {
		ShowNameCardInfo(namecard);
		while (LNext(&list, &namecard)) {
			ShowNameCardInfo(namecard);
		}

	}
}