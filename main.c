#include <stdio.h>
#include <sys/file.h>

#include "dog.h"

int main(int argc, char *argv[])
{
        	FILE *fp;
		
        	int ch;
		
		int line = 0;
		int print_$ = 0;
		int print_esc = 0;
		int pag = 0;
		
		char *filename;
		
		int firstfile = 1;
		int bell = 0;
		int lock = 0;
		
		for (int i = 1; i < argc; i++) {
				char *arg = argv[i];
				if (*arg++ == '-') {
					firstfile++;
					while (*arg != '\0') {
						switch(*arg++) {
							case 'l':
								line = 1;
								break;
							case 'e':
								print_esc = 1;
								break;
							case 'd':
								print_$ = 1;
								break;
							case 'p':
								pag = 1;
								break;
							case 'b':
								bell = 1;
								break;
							case 'n':
								blank = 1;
								break;
							case 'f':
								lock = 1;
								break;
							case 'h':
								puts("\n-l = print line numbers\n-e = print escape codes\n-d = print $ at the end of every line\n-p = pagination - a very useful feature !\n-b = on error ring terminal bell\n-f = lock file\n-n = "); 
								break;
							default:
								fprintf(stderr, "Unkown option: %s\nDo -h for help\n", argv[i]);
								break;
							};
						}
					}
		filename = argv[argc];
		if (firstfile == argc) {
			fp = stdin;
			filecopy(fp, stdout, line, print_$, print_esc, pag, blank);
		} else {
			
			for (int b = firstfile;b < argc; b++) {
				if ((fp = fopen(argv[b], "rb")) != NULL) {
					if (lock == 1) {
						if ((flock(fp, LOCK_EX)) != 0) {
							fprintf(stderr, "ERROR: COULD NOT LOCK FILE\n");
							if (bell == 1) {
								puts("\a");
								}
						} else {
							puts("LOCKED\n");
						}
						filecopy(fp, stdout, line, print_$, print_esc, pag, blank);
						fclose(fp);
			} else {
				if (bell == 1) {
					puts("\a");
					}
				fprintf(stderr, "GRR: DOG CAN NOT DIG UP FILE");
				}
				
			}
		}
		flock(fp, LOCK_UN);
		return 0;
	}
					
}
