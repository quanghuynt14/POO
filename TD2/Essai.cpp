#include <cstring>
#include <iostream>
using namespace std;

static char * rallonger(char * chaine, char * reference) {
    char * p = new char[strlen(reference) + 1];
    unsigned int i;
    for (i = 0; i < (strlen(reference) - strlen(chaine)); p[i++] = '0') {}
    p[i] = '\0';
    strcat(p, chaine);
    delete [] chaine;
    return p;
}

static void ajuster(char *& ch1, char *& ch2) {
    if (strlen(ch1) != strlen(ch2)) {
        if (strlen(ch1) > strlen(ch2)) {
            ch2 = rallonger(ch2, ch1);
        } else {
            ch1 = rallonger(ch1, ch2);
        }
    }
}

int main() {
    char * chaine1;
    char * chaine2;
    chaine1 = new char[4 + 1];
    chaine1 = strcpy(chaine1, "0101");
    chaine2 = new char[2 + 1];
    chaine2 = strcpy(chaine2, "01");

    ajuster(chaine1, chaine2);
    //printf("%s\n", "\0");
    cout << chaine1 << "\n" << chaine2 << "\n";
    int h = 0;
    cout << &h;
    return 0;
}