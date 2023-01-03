#include<stdio.h>

int main() {

	int num[26] = { 0 };
	char c;
	scanf("%c", &c);
	while (c != '\n') {
		if (c >= 'A'&&c <= 'Z')c = c + 'a' - 'A';
		for (int i = (int)'a'; i <= (int)'z'; i++) {
			if (c == (char)i) {
				num[i-'a']++;
				break;
			}
		}
		scanf("%c", &c);
	}
	int j = 0;
	int flag = 0;
	for (int i = 1; i < 26; i++) {
		if (num[i] > num[j]) {
			flag = 0;
			j = i;
		}
		else if (num[i] == num[j]) {
			flag = 1;
		}
	}
	if (flag)printf("?");
	else printf("%c", 'A'+j);
	return 0;
}