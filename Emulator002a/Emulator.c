#define _CRT_SECURE_NO_DEPRECATE
#define MAXCODE 0x100000
#include <stdio.h>
#include "Help.h"

typedef unsigned char byte;
typedef unsigned short word;

byte AL, AH, BL, BH, CL, CH, DL, DH;
word AX, BX, CX, DX;
word FLAGS, IP, ES, SS, DS, CS, SP, BP, DI, SI;

byte code[MAXCODE];
byte opcode;

main() {
	FILE* f;
	f = fopen("SAMPLE.com", "rb");
	if (!f) return -1;
	fread(code, 1, MAXCODE, f);
	fclose(f);

	IP = 0;
	while (1) {
		opcode = code[IP++];
		printf("%02X \t", IP);
		switch (opcode) {
		case 0x02:
			AL = AL + AL;
			break;
		case 0xB0:
			AL = 1;
			break;
		case 0xC0:
			//if (AL < (1 << sizeof(byte) * 8)) leftRotate(AL, 1);
			//else rightRotate(AL, 1);
			break;
		case 0xCD:
			opcode = code[IP++];
			if (opcode == 0x20) return 0;
		//default:
			//printf("%02X \n", opcode);
		}
		printf("AL=%d \n", AL);
	}


/*
	while (1) {
		opcode = code[IP++];
		printf("%02X \t", IP);
		switch (opcode) {
		case 0xCD:
			opcode = code[IP++];
			if (opcode == 0x20) return 0;
		default:
			printf("%02X \n", opcode);
		}
		//printf("AL=%d \n", AL);
	}
*/
}