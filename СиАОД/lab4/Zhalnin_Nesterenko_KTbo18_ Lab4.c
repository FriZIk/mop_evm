#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>

struct list {
	char flag;
	char value[32];
	struct list* next;
};

typedef struct list* List;

struct info {
	int ud;
	int neud;
	int srednUd;
	int srednNeud;
};

typedef struct info* Info;

List mainTable[1024] = {0};

unsigned short getNumFromStr(char* str) 
{
	int length = strlen(str);
	unsigned short sum = 0;
	int i = 0;
	unsigned long long temp = 0;
	while (i<length) 
	{
		temp = str[i+1] ?((unsigned long long)str[i] << 8) + str[i + 1] : str[i];
		if (temp >= 0x10000000000000000) 
		{
			sum += 1;
		}
		sum += temp & 0x0111111111111111;
		i+=2;
	}
	return sum;
}  

int getHash(unsigned short num) 
{
	unsigned long long t = (unsigned long long)num * (unsigned long long)num;
	int res = (int)(t & ((unsigned long long)1023<<11)) >> 11;
	return res;
}

List initList() {
	List l = (List)malloc(sizeof(struct list));
	if (l == NULL) {
		printf("%s\n", "Funkciya malloc ne mozhet videlit pamyat'");
			return 0;
	}
	l->next = NULL;
	return l;
}

void put(char* str) {
	int length = strlen(str);
	int hash = getHash(getNumFromStr(str));
	List newList = initList();
	for (int i = 0; i < length; i++) {
		(newList->value)[i] = str[i];
	}
	(newList->value)[length] = '\0';
	newList->next = mainTable[hash];
	mainTable[hash] = newList;
}

void readWords(FILE* file) {
	int count = 100;
	char str[32];
	for (int i = 0; i < count; i++) {
		fscanf(file, "%s", str);
		
		put(str);
	}
}

Info findWord(Info info, char* str) {
	int hash = getHash(getNumFromStr(str));
	List l = mainTable[hash];
	
	int n = 0;
	if (l == NULL) {
		info->srednNeud++;
		info->neud++;
	}
	else {
		do {
			n++;
			if (!strcmp(str, l->value)) {
				info->srednUd += n;
				info->ud++;
				return info;
			}
			l = l->next;
		} while (l != NULL);
		info->srednNeud += n;
		info->neud++;
		return info;
	}
}

Info read(Info info, FILE* file) {
	char str[32];
	for (int i = 0; i < 500; i++) {
		fscanf(file, "%s\n", str);
		info = findWord(info,str);
	}
	return info;
}

int main() 
{
	setlocale(LC_ALL, "Russian");	
	Info infos[10];

	FILE* fin = fopen("IN11.txt","rt");
	FILE* fin2;
	
	for (int i = 0; i < 10; i++) {
		infos[i] = (Info)malloc(sizeof(struct info));
		if (infos[i] == NULL) {
			printf("%s\n", "Funkciya malloc ne mozhet videlit pamyat'");
			break;
		}
		infos[i]->neud = 0;
		infos[i]->ud = 0;
		infos[i]->srednNeud = 0;
		infos[i]->srednUd = 0;
		readWords(fin);
		fin2 = fopen("IN22.txt", "rt");
		infos[i] = read(infos[i],fin2);
	}
	printf("%s\n", "----------------------------------------------------------------------------------------------------------------");
	printf("%c %-20s %c%c %-40s %c%c %-40s %c\n", '|', " Степень заполнения", '|', '|', "   Количество", '|', '|', "   Среднее число попыток", '|');
	printf("%s\n", "----------------------------------------------------------------------------------------------------------------");
	printf("%c %-20s %c%c %-19s %c %-18s %c%c %-19s %c %-18s %c\n", '|', "*", '|', '|', "Удач", '|', "Неудач", '|', '|', "При удаче", '|', "При неудаче", '|');
	printf("%s\n", "----------------------------------------------------------------------------------------------------------------");
	for(int i = 0;i < 10;i++)
    {
        printf("%c %-20.1f %c%c %-19d %c %-18d %c%c %-19.3f %c %-18.3f %c\n", '|', i*0.1 + 0.1, '|', '|', infos[i]->ud, '|', infos[i]->neud, '|', '|', (float)infos[i]->srednUd / infos[i]->ud, '|', infos[i]->neud != 0 ? (float)infos[i]->srednNeud / infos[i]->neud : 0, '|');
        printf("%s\n", "----------------------------------------------------------------------------------------------------------------");
    }
	return 0;
} 