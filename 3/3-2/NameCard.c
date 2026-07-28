#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "NameCard.h"

NameCard* MakeNameCard(const char* name, const char* phone) {
	NameCard* namecard = (NameCard*)malloc(sizeof(NameCard));
	strcpy(namecard->name, name);
	strcpy(namecard->phone, phone);
	return namecard;
}

void ShowNameCardInfo(NameCard* pcard) {
	printf("이름은 %s입니다. \n", pcard->name);
	printf("핸드폰 번호는 %s입니다. \n", pcard->phone);
}

int NameCompare(NameCard* pcard, const char* name) {
	if (strcmp(pcard->name, name) == 0) {
		return 0;
	}
	else
		return 1;
}

void ChangePhoneNum(NameCard* pcard, const char* phone) {
	strcpy(pcard->phone, phone);
}