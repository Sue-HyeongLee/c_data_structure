#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CLinkedList.h"
#include "Employee.h"

void ShowInformation(Employee* employee);

void WhoIs(List* list, const char* name, int num);

int main(void)
{
	Employee* person1 = malloc(sizeof(Employee));
	strcpy(person1->name, "이수정");
	person1->ssn = 112;

	Employee* person2 = malloc(sizeof(Employee));
	strcpy(person2->name, "이수형");
	person2->ssn = 113;

	Employee* person3 = malloc(sizeof(Employee));
	strcpy(person3->name, "이수진");
	person3->ssn = 114;

	Employee* person4 = malloc(sizeof(Employee));
	strcpy(person4->name, "이수개");
	person4->ssn = 115;

	List list;
	ListInit(&list);

	LInsert(&list, person1);
	LInsert(&list, person2);
	LInsert(&list, person3);
	LInsert(&list, person4);
	WhoIs(&list, "이수정", 3);
}

void ShowInformation(Employee* employee) {
	printf("이름은 %s, 사번은 %d입니다. \n", employee->name, employee->ssn);
}

void WhoIs(List* list, const char* name, int num) {
	Employee* data;
	int nodeNum = LCount(list);
	if (nodeNum != 0) {
		LFirst(list, &data);
		if (strcmp(data->name, name)==0) {
			for (int i = 0; i < num; i++) {
				LNext(list, &data);
			}
			ShowInformation(data);
			return;
		}
		
		for (int i = 0; i < nodeNum - 1; i++) {
			LNext(list, &data);
			if (strcmp(data->name, name)==0) {
				for (int i = 0; i < num; i++) {
					LNext(list, &data);
				}
				ShowInformation(data);
				return;
			}
		}
	}
}