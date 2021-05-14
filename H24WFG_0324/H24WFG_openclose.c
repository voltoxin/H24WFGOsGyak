#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/file.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main()
{

    int file = open("H24WFG.txt",O_RDWR);
    char rd[128];
    int buffer;
    char wr[128] = "Kanya Alexander Programtervezo Informatikus H24WFG";

    if (file == -1)
    {
        perror("Open() error");
	exit(-1);
    }
    else
    {
        printf("Sikeres megnyitas.\n\n");
    }

    buffer = write(file, wr, strlen(wr));
    if (wr < 0) printf("Hiba tortent a fajl kiolvasasnal\n");
    else printf("Kiirt szoveg: %s\nMerete: %d byte\n\n",wr,buffer);

    printf("A kurzor pozicionalva a kovetkezo helyre: %ld\n\n", lseek(file, 0, SEEK_SET));

    buffer = read(file, rd, sizeof(rd) / sizeof(char));
    if(rd < 0) printf("Hiba a beolvasasnal.\n");
    else printf("Beolvasott szoveg: %s\nMerete: %d byte\n\n",rd,buffer);


    return 0;
}
