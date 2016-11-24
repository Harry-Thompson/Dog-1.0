#include <stdio.h>

void filecopy(FILE *ifp, FILE *ofp, int show_line_numbers, int show_dollar, int print_esc, int pag, int blank)
{
		int blank_line = 1;
  		int line = 1;
		int c;
		char last_ch = '\n';
		int pag_line = 1;
		char b;
	
		int bin = 0;
		
		while ((c = getc(ifp)) != EOF) {
			
			if (isascii(c) != 0) {
				printf("%-02x", c);
				bin = 1;
			}
			
			if (show_line_numbers == 1) {
				if (last_ch == '\n') {
					fprintf(ofp, "%-4d ", line++);
					}
				}
				
			if (blank == 1) {
				if (c == '\n') {
					fprintf(ofp, "%-4d ", bpank_line++);
					}
				}
			
			if (print_esc == 1) {
				if (c == '\n') {
					puts("\\n");
					}
				if (c == '\t') {
					puts("\\t");
					}
				}
			
			if (show_dollar == 1) {
				if (c == '\n') {
					puts("\t$");
					}
				}
				
			if (c == '\n') {
				pag_line++;
				}
			
			if (pag == 1) {
				if (pag_line == 30) {
					puts("\nPress enter to continue\n");
					getchar();
					pag_line = 0;
					}
				}
			if (bin != 0) {
				putc(c, ofp);
				last_ch = c;
			 	}
			}
		}
