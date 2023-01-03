#include<stdio.h>

int main() {

	char c[100];
	scanf("%s", &c);
	int j = 0;
	int cnt = 0;
	while (c[j] != '\0') {
		if (c[j] == 'c'&&(c[j + 1] == '=' || c[j + 1] == '-')) {	
			cnt++;
			j += 2;
		}
		else if (c[j] == 'd') {
			if (c[j + 1] == '-') {
				cnt++;
				j += 2;
			}
			else if (c[j + 1] == 'z'&&c[j + 2] == '=') {
				cnt++;
				j += 3;
			}
			else {
				cnt++;
				j++;
			}
		}
		else if (c[j] == 'l'&&c[j + 1] == 'j') {
			cnt++;
			j += 2;
		}
		else if (c[j] == 'n'&&c[j + 1] == 'j') {
			cnt++;
			j += 2;
		}
		else if (c[j] == 's'&&c[j + 1] == '=') {
			cnt++;
			j +=2 ;
		}
		else if (c[j] == 'z'&&c[j + 1] == '=') {
			cnt++;
			j += 2;
		}
		else {
			cnt++;
			j++;
		}
	}
	printf("%d", cnt);


	return 0;
}