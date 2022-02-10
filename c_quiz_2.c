#define _CRT_SECURE_NO_WARNINGS
#define MAX 51
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct bookLinkedList {
	char bookTitle[MAX];
	char bookPub[MAX];
	int bookPrice;
	struct bookLinkedList* nextBookAddress;
}book;

void InsertList(book* bookList);
void SortByTitle(book* bookList);
void SortByPubName(book* bookList);
void SortByPrice(book* bookList);
void PrintSortList(book* bookList);
void PrintSortLinkedList(book* sortBookList);
void Swap(book* bookList1, book* bookList2);
void Sample(book* bookList);

int bookCount;

void main() {

	book* bookList = (book*)malloc(sizeof(book));
	Sample(bookList);
	while (1) {
		system("cls");
		printf("1.�Է�\n");
		printf("2.���\n");
		switch (getch()) {
		case '1':
			system("cls");
			InsertList(bookList);
			SortByTitle(bookList);
			break;
		case '2':
			PrintSortList(bookList);
			break;
		}
	}
}

void InsertList(book* bookList) {
	if (bookList->nextBookAddress == 0) {
		book* newBook = (book*)malloc(sizeof(book));
		printf("���� = ");
		scanf("%s", newBook->bookTitle);
		printf("���ǻ� = ");
		scanf("%s", newBook->bookPub);
		printf("���� = ");
		scanf("%d", &(newBook->bookPrice));
		newBook->nextBookAddress = 0;
		bookList->nextBookAddress = newBook;
		bookCount++;
	}
	else 
		InsertList(bookList->nextBookAddress);
}
void SortByTitle(book* bookList) {
	book* cur = bookList;
	for (int i = 0; i < bookCount; i++) {
		for (int j = 0; j < bookCount - 1 - i; j++) {
			if (strcmp(cur->bookTitle, cur->nextBookAddress->bookTitle) > 0)
				Swap(cur, cur->nextBookAddress);
			cur = cur->nextBookAddress;
		}
		cur = bookList;
	}
}
void SortByPubName(book* bookList) {
	book* cur = bookList;
	for (int i = 0; i < bookCount; i++) {
		for (int j = 0; j < bookCount - 1 - i; j++) {
			if (strcmp(cur->bookPub, cur->nextBookAddress->bookPub) > 0) {
				Swap(cur, cur->nextBookAddress);
			}
			cur = cur->nextBookAddress;
		}
		cur = bookList;
	}
}
void SortByPrice(book* bookList) {
	book* cur = bookList;
	for (int i = 0; i < bookCount; i++) {
		for (int j = 0; j < bookCount - 1 - i; j++) {
			if (cur->bookPrice > cur->nextBookAddress->bookPrice) {
				Swap(cur, cur->nextBookAddress);
			}
			cur = cur->nextBookAddress;
		}
		cur = bookList;
	}
}
void PrintSortList(book* bookList) {
	book* sortBookList=bookList;
	while (1) {
		system("cls");
		printf("       ����          ���ǻ�      ����\n");
		PrintSortLinkedList(sortBookList);
		printf("\n");
		printf("1. Ÿ��Ʋ��\n");
		printf("2. ���ǻ��\n");
		printf("3. ���ݼ�\n");
		printf("4. ����ȭ��\n");
		switch (getch()) {
		case '1':
			SortByTitle(sortBookList);
			break;
		case '2':
			SortByPubName(sortBookList);
			break;
		case '3':
			SortByPrice(sortBookList);
			break;
		case '4':
			return;
		}
	}
}
void PrintSortLinkedList(book* sortBookList) {
	printf(" %-15s%-15s%-10d\n", sortBookList->bookTitle, sortBookList->bookPub, sortBookList->bookPrice);
	if (sortBookList->nextBookAddress == 0)
		return;
	else
		PrintSortLinkedList(sortBookList->nextBookAddress);
}
void Swap(book* book1, book* book2) {
	char titleTmp[MAX];
	char pubTmp[MAX];
	int priceTmp;
	strcpy(titleTmp, book1->bookTitle);
	strcpy(pubTmp, book1->bookPub);
	priceTmp = book1->bookPrice;
	strcpy(book1->bookTitle, book2->bookTitle);
	strcpy(book1->bookPub, book2->bookPub);
	book1->bookPrice = book2->bookPrice;
	strcpy(book2->bookTitle, titleTmp);
	strcpy(book2->bookPub, pubTmp);
	book2->bookPrice = priceTmp;
	

}

void Sample(book* bookList) {
	book* newBook;
	strcpy(bookList->bookTitle, "ȥ��C");
	strcpy(bookList->bookPub, "�Ѻ��̵��");
	bookList->bookPrice = 24000;
	bookList->nextBookAddress = 0;
	newBook = (book*)malloc(sizeof(book));
	strcpy(newBook->bookTitle, "������");
	strcpy(newBook->bookPub, "������");
	newBook->bookPrice = 1000;
	newBook->nextBookAddress = 0;
	bookList->nextBookAddress = newBook;
	newBook = (book*)malloc(sizeof(book));
	strcpy(newBook->bookTitle, "������");
	strcpy(newBook->bookPub, "ŸŸŸ");
	newBook->bookPrice = 2000;
	newBook->nextBookAddress = 0;
	bookList->nextBookAddress->nextBookAddress = newBook;

	bookCount = 3;
}