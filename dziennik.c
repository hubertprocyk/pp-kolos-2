#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UCZNIOW 100
#define MAX_DLUGOSC_NAZWISKA 50

struct Uczen {
    char nazwisko[MAX_DLUGOSC_NAZWISKA];
    int oceny[5]; // Zakładamy, że uczniowie mają 5 ocen
    int obecnosci;
};

void wyswietlListeObecnosci(Uczen* listaUczniow, int iloscUczniow) {
    printf("\nLista obecności:\n");
    for (int i = 0; i < iloscUczniow; i++) {
        printf("%s - %d obecności\n", listaUczniow[i].nazwisko, listaUczniow[i].obecnosci);
    }
}

void wyswietlListeOcen(Uczen* listaUczniow, int iloscUczniow) {
    printf("\nLista ocen:\n");
    for (int i = 0; i < iloscUczniow; i++) {
        printf("%s - Oceny: ", listaUczniow[i].nazwisko);
        for (int j = 0; j < 5; j++) {
            printf("%d ", listaUczniow[i].oceny[j]);
        }
        printf("\n");
    }
}

void wprowadzOceny(Uczen* listaUczniow, int iloscUczniow) {
    int numerUcznia, ocena;
    printf("\nWprowadź oceny:\n");

    printf("Podaj numer ucznia (od 1 do %d): ", iloscUczniow);
    scanf("%d", &numerUcznia);

    if (numerUcznia < 1 || numerUcznia > iloscUczniow) {
        printf("Nieprawidłowy numer ucznia.\n");
        return;
    }

    printf("Podaj oceny ucznia %s (5 ocen): ", listaUczniow[numerUcznia - 1].nazwisko);
    for (int i = 0; i < 5; i++) {
        scanf("%d", &ocena);
        listaUczniow[numerUcznia - 1].oceny[i] = ocena;
    }
}

void wprowadzObecnosci(Uczen* listaUczniow, int iloscUczniow) {
    int numerUcznia, obecnosci;
    printf("\nWprowadź obecności:\n");

    printf("Podaj numer ucznia (od 1 do %d): ", iloscUczniow);
    scanf("%d", &numerUcznia);

    if (numerUcznia < 1 || numerUcznia > iloscUczniow) {
        printf("Nieprawidłowy numer ucznia.\n");
        return;
    }

    printf("Podaj liczbę obecności ucznia %s: ", listaUczniow[numerUcznia - 1].nazwisko);
    scanf("%d", &obecnosci);
    listaUczniow[numerUcznia - 1].obecnosci = obecnosci;
}

int main() {
    Uczen listaUczniow[MAX_UCZNIOW];
    int iloscUczniow;

    printf("Podaj ilosc uczniow (max %d): ", MAX_UCZNIOW);
    scanf("%d", &iloscUczniow);

    if (iloscUczniow > MAX_UCZNIOW) {
        printf("Za duza liczba uczniow. Maksymalna liczba uczniow to %d.\n", MAX_UCZNIOW);
        return 1;
    }

    // Inicjalizacja danych uczniow
    for (int i = 0; i < iloscUczniow; i++) {
        printf("Podaj nazwisko ucznia %d: ", i + 1);
        scanf("%s", listaUczniow[i].nazwisko);
        listaUczniow[i].obecnosci = 0;

        // Inicjalizacja ocen
        for (int j = 0; j < 5; j++) {
            listaUczniow[i].oceny[j] = 0;
        }
    }

    int wybor;

    do {
        printf("\nMENU:\n");
        printf("1. Wyświetl listę obecności\n");
        printf("2. Wyświetl listę ocen\n");
        printf("3. Wprowadź oceny\n");
        printf("4. Wprowadź obecności\n");
        printf("0. Wyjście\n");

        printf("Wybierz opcję: ");
        scanf("%d", &wybor);

        switch (wybor) {
            case 1:
                wyswietlListeObecnosci(listaUczniow, iloscUczniow);
                break;
            case 2:
                wyswietlListeOcen(listaUczniow, iloscUczniow);
                break;
            case 3:
                wprowadzOceny(listaUczniow, iloscUczniow);
                break;
            case 4:
                wprowadzObecnosci(listaUczniow, iloscUczniow);
                break;
            case 0:
                printf("Dziękujemy za skorzystanie z programu.\n");
                break;
            default:
                printf("Nieprawidłowy wybór. Spróbuj ponownie.\n");
        }
    } while (wybor != 0);

    return 0;
}
