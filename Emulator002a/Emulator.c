#define _CRT_SECURE_NO_DEPRECATE
#define MAXCODE 0x100000
#include <stdio.h>

typedef unsigned char byte;
typedef unsigned short word;
typedef unsigned int dword;

byte AL, AH, BL, BH, CL, CH, DL, DH;
word AX, CX, DX, BX, SP, BP, SI, DI;
word flags, IP, ES, SS, DS, CS;

byte regs8[8] = { AL, AH, CL, CH, DL, DH, BL, BH };
byte regs16[8] = { AX, CX, DX, BX, SP, BP, SI, DI };

//int flags[8];

byte code[MAXCODE];
byte opcode;



void cop(byte& opcode) {
	byte o = opcode;

	printf("%02X \t", o);
}

int main() {

	FILE* f;
	f = fopen("C:\\csc210\\SAMPLE2.com", "rb");
	if (!f) return -1;
	fread(code, 1, MAXCODE, f);
	fclose(f);

	IP = 0;
	flags = 0x00000000;
	while (1) {
		opcode = code[IP++];

		//printf("%02X \t", IP);
		switch (opcode) {
		case 0x0f:
			//legacy lock
			opcode = code[IP++];
			switch (opcode) {
			case 0x04:
				//shld reg16,reg16,imm8/reg32,reg32,imm8 SF,ZF,CF,PF/OF,AF ?
				//shld mem16,reg16,imm8/mem32,reg32,imm8 SF,ZF,CF,PF/OF,AF ?
				break;
			case 0x05:
				//shld reg16,reg16,CL/reg32,reg32,CL SF,ZF,CF,PF/OF,AF ?
				//shld mem16,reg16,CL/mem32,reg32,CL SF,ZF,CF,PF/OF,AF ?
				break;
			case 0x80:
				//jo rel32
				break;
			case 0x81:
				//jno rel32
				break;
			case 0x82:
				//jb rel32
				//jnae
				//jc rel32
				break;
			case 0x83:
				//jae rel32
				//jnb
				//jnc rel32
				break;
			case 0x84:
				//je rel32
				//jz
				break;
			case 0x85:
				//jne rel32
				//knz
				break;
			case 0x86:
				//jbe rel32
				//jna
				break;
			case 0x87:
				//ja rel32
				//jnbe
				break;
			case 0x88:
				//js rel32
				break;
			case 0x89:
				//jns rel32
				break;
			case 0x8A:
				//jp rel32
				//jpe
				break;
			case 0x8B:
				//jnp rel32
				//jpo
				break;
			case 0x8C:
				//jl rel32
				//jnge
				break;
			case 0x8D:
				//jge rel32
				//jnl
				break;
			case 0x8E:
				//jle rel32
				//jng
				break;
			case 0x8F:
				//jg rel32
				//jnle
				break;
			case 0xA0:
				//push FS
				break;
			case 0xA1:
				//pop FS
				break;
			case 0xA8:
				//push GS
				break;
			case 0xA9:
				//pop GS
				break;
			case 0xAC:
				//shrd reg16, reg16, imm8 / reg32, reg32, imm8 SF,ZF,CF,PF/OF,AF ?
				//shrd mem16, reg16, imm8 / mem32, reg32, imm8 SF,ZF,CF,PF/OF,AF ?
				break;
			case 0xAD:
				//shrd reg16, reg16, CL / reg32, reg32, CL SF,ZF,CF,PF/OF,AF ?
				//shrd mem16, reg16, CL / mem32, reg32, CL SF,ZF,CF,PF/OF,AF ?
				break;
			case 0xAF:
				//imul reg16, reg16 / reg32, reg32 OF,CF/SF,ZF,PF,AF,?
				//imul reg16, mem16 / reg32, mem32 OF,CF/SF,ZF,PF,AF,?
				break;
			case 0xB6:
				//movzx reg16, reg8 / reg32, re8
				//movzx reg16, mem8 / reg32, mem8
				break;
			case 0xB7:
				//movzx reg32, reg16
				//movzx reg32, mem16
				break;
			case 0xBE:
				//movsx reg16, re8 / reg32, reg8
				//movsx reg16, mem8 / reg32, mem8
				break;
			case 0xBF:
				//movsx reg32, reg16
				//movsx reg32, mem16
				break;
			}

			break;
		case 0xf2:
			//repne/repnz
			break;
		case 0xf3:
			//repe/repz
			break;
		case 0xcd:
			opcode = code[IP++];
			if (opcode == 0x20) return 0;
		default:
			cop(opcode);
			//printf("%02X \t", opcode);
			break;
		}
		printf("AL=%d \t AH=%d \t CF=%d \n", AL, AH, flags);
	}
	return 0;
}