#define _CRT_SECURE_NO_DEPRECATE
#define DEBUG true
#define OS true //true if using microsoft visual studio, false if using g++
#define MAXCODE 0x100000
#include <iostream>

typedef unsigned char byte;
typedef unsigned short word;
typedef unsigned int dword;

byte AL=0x00, AH = 0x00, BL = 0x00, BH = 0x00, CL = 0x00, CH = 0x00, DL = 0x00, DH = 0x00;
word AX = 0x0000, CX = 0x0000, DX = 0x0000, BX = 0x0000, SP = 0x0000, BP = 0x0000, SI = 0x0000, DI = 0x0000;
word flags = 0x0000, IP = 0x0000, ES = 0x0000, SS = 0x0000, DS = 0x0000, CS = 0x0000;

byte regs8[8] = { AL, AH, CL, CH, DL, DH, BL, BH };
word regs16[8] = { AX, CX, DX, BX, SP, BP, SI, DI };

byte code[MAXCODE];
byte opcode = 0x00;

void cop(byte opcode);
void dumpRegisters();

//0x00FF = 255
word combine(byte low, byte hi)
{
	word combined = hi << 8 | low;
	return combined;
}

// Assumes little endian
void printBits(size_t const size, void const* const ptr)
{
	unsigned char* b = (unsigned char*)ptr;
	unsigned char byte;
	int i, j;

	for (i = size - 1; i >= 0; i--) {
		for (j = 7; j >= 0; j--) {
			byte = (b[i] >> j) & 1;
			printf("%u", byte);
		}
	}
	puts("");
}

void addreg8(byte reg8a, byte reg8b) {
	if (reg8a > 0xFF - reg8b) {
		flags = flags | (1 << 6);
	}
	reg8a += reg8b;
}

/*
* 
* 
* 00,01,02,03,04,05
10,11,12,13,14,15
70,71,72,73,74,75,76,77,78,79,7a,7b,7c,7d,7e,7f
80,81,83,84,85,86,87
88,89,8A,8B,8C,8D,8E,8F
91,92,93,94,95,96,97,98,99,9a,9c,9d,a0,a1,a2,a3,a4,a5,a6,a7
c6,c7
e2
* 
* 
* 
*/


void cop(byte opcode) {
	switch (opcode) {
	case 0x02:
		//add reg8,reg8
		opcode = code[IP++];
		switch (opcode) {
		case 0xC0:
			//add al,al
			if (AL > 0xFF - AL) {
				flags = flags | (1 << 6);
			}
			AL += AL;
			break;
		case 0xC1:
			//add al,cl
			if (AL > 0xFF - CL) {
				flags = flags | (1 << 6);
			}
			AL += CL;
			break;
		case 0xC2:
			//add al,dl
			if (AL > 0xFF - DL) {
				flags = flags | (1 << 6);
			}
			AL += DL;
			break;
		case 0xC3:
			//add al,bl
			if (AL > 0xFF - BL) {
				flags = flags | (1 << 6);
			}
			AL += BL;
			break;
		case 0xC4:
			//add al,ah
			if (AL > 0xFF - AH) {
				flags = flags | (1 << 6);
			}
			AL += AH;
			break;
		case 0xC5:
			//add al,ch
			if (AL > 0xFF - CH) {
				flags = flags | (1 << 6);
			}
			AL += CH;
			break;
		case 0xC6:
			//add al,dh
			if (AL > 0xFF - DH) {
				flags = flags | (1 << 6);
			}
			AL += DH;
			break;
		case 0xC7:
			//add al,bh
			if (AL > 0xFF - BH) {
				flags = flags | (1 << 6);
			}
			AL += BH;
			break;
		case 0xC8:
			//add cl,al
			if (CL > 0xFF - AL) {
				flags = flags | (1 << 6);
			}
			CL += AL;
			break;
		case 0xC9:
			//add cl,cl
			if (CL > 0xFF - CL) {
				flags = flags | (1 << 6);
			}
			CL += CL;
			break;
		case 0xCA:
			//add cl,dl
			if (CL > 0xFF - DL) {
				flags = flags | (1 << 6);
			}
			CL += DL;
			break;
		case 0xCB:
			//add cl,bl
			if (CL > 0xFF - BL) {
				flags = flags | (1 << 6);
			}
			CL += BL;
			break;
		case 0xCC:
			//add cl,ah
			if (CL > 0xFF - AH) {
				flags = flags | (1 << 6);
			}
			CL += AH;
			break;
		case 0xCD:
			//add cl,ch
			if (CL > 0xFF - CH) {
				flags = flags | (1 << 6);
			}
			CL += CH;
			break;
		case 0xCE:
			//add cl,dh
			if (CL > 0xFF - DH) {
				flags = flags | (1 << 6);
			}
			CL += DH;
			break;
		case 0xCF:
			//add cl,bh
			if (CL > 0xFF - BH) {
				flags = flags | (1 << 6);
			}
			CL += BH;
			break;
		case 0xD0:
			//add dl,al
			if (DL > 0xFF - AL) {
				flags = flags | (1 << 6);
			}
			DL += AL;
			break;
		case 0xD1:
			//add dl,cl
			if (DL > 0xFF - CL) {
				flags = flags | (1 << 6);
			}
			DL += CL;
			break;
		case 0xD2:
			//add dl,dl
			if (DL > 0xFF - DL) {
				flags = flags | (1 << 6);
			}
			DL += DL;
			break;
		case 0xD3:
			//add dl,bl
			if (DL > 0xFF - BL) {
				flags = flags | (1 << 6);
			}
			DL += BL;
			break;
		case 0xD4:
			//add dl,ah
			if (DL > 0xFF - AH) {
				flags = flags | (1 << 6);
			}
			DL += AH;
			break;
		case 0xD5:
			//add dl,ch
			if (DL > 0xFF - CH) {
				flags = flags | (1 << 6);
			}
			DL += CH;
			break;
		case 0xD6:
			//add dl,dh
			if (DL > 0xFF - DH) {
				flags = flags | (1 << 6);
			}
			DL += DH;
			break;
		case 0xD7:
			//add dl,bh
			if (DL > 0xFF - BH) {
				flags = flags | (1 << 6);
			}
			DL += BH;
			break;
		case 0xD8:
			//add bl,al
			if (BL > 0xFF - AL) {
				flags = flags | (1 << 6);
			}
			BL += AL;
			break;
		case 0xD9:
			//add bl,cl
			if (BL > 0xFF - CL) {
				flags = flags | (1 << 6);
			}
			BL += CL;
			break;
		case 0xDA:
			//add bl,dl
			if (BL > 0xFF - DL) {
				flags = flags | (1 << 6);
			}
			BL += DL;
			break;
		case 0xDB:
			//add bl,bl
			if (BL > 0xFF - BL) {
				flags = flags | (1 << 6);
			}
			BL += BL;
			break;
		case 0xDC:
			//add bl,ah
			if (BL > 0xFF - AH) {
				flags = flags | (1 << 6);
			}
			BL += AH;
			break;
		case 0xDD:
			//add bl,ch
			if (BL > 0xFF - CH) {
				flags = flags | (1 << 6);
			}
			BL += CH;
			break;
		case 0xDE:
			//add bl,dh
			if (BL > 0xFF - DH) {
				flags = flags | (1 << 6);
			}
			BL += DH;
			break;
		case 0xDF:
			//add bl,bh
			if (BL > 0xFF - BH) {
				flags = flags | (1 << 6);
			}
			BL += BH;
			break;
		case 0xE0:
			//add ah,al
			if (AH > 0xFF - AL) {
				flags = flags | (1 << 6);
			}
			AH += AL;
			break;
		case 0xE1:
			//add ah,cl
			if (AH > 0xFF - CL) {
				flags = flags | (1 << 6);
			}
			AH += CL;
			break;
		case 0xE2:
			//add ah,dl
			if (AH > 0xFF - DL) {
				flags = flags | (1 << 6);
			}
			AH += DL;
			break;
		case 0xE3:
			//add ah,bl
			if (AH > 0xFF - BL) {
				flags = flags | (1 << 6);
			}
			AH += BL;
			break;
		case 0xE4:
			//add ah,ah
			if (AH > 0xFF - AH) {
				flags = flags | (1 << 6);
			}
			AH += AH;
			break;
		case 0xE5:
			//add ah,ch
			if (AH > 0xFF - CH) {
				flags = flags | (1 << 6);
			}
			AH += CH;
			break;
		case 0xE6:
			//add ah,dh
			if (AH > 0xFF - DH) {
				flags = flags | (1 << 6);
			}
			AH += DH;
			break;
		case 0xE7:
			//add ah,bh
			if (AH > 0xFF - BH) {
				flags = flags | (1 << 6);
			}
			AH += BH;
			break;
		case 0xE8:
			//add ch,al
			if (CH > 0xFF - AL) {
				flags = flags | (1 << 6);
			}
			CH += AL;
			break;
		case 0xE9:
			//add ch,cl
			if (CH > 0xFF - CL) {
				flags = flags | (1 << 6);
			}
			CH += CL;
			break;
		case 0xEA:
			//add ch,dl
			if (CH > 0xFF - DL) {
				flags = flags | (1 << 6);
			}
			CH += DL;
			break;
		case 0xEB:
			//add ch,bl
			if (CH > 0xFF - BL) {
				flags = flags | (1 << 6);
			}
			CH += BL;
			break;
		case 0xEC:
			//add ch,ah
			if (CH > 0xFF - AH) {
				flags = flags | (1 << 6);
			}
			CH += AH;
			break;
		case 0xED:
			//add ch,ch
			if (CH > 0xFF - CH) {
				flags = flags | (1 << 6);
			}
			CH += CH;
			break;
		case 0xEE:
			//add ch,dh
			if (CH > 0xFF - DH) {
				flags = flags | (1 << 6);
			}
			CH += DH;
			break;
		case 0xEF:
			//add ch,bh
			if (CH > 0xFF - BH) {
				flags = flags | (1 << 6);
			}
			CH += BH;
			break;
		case 0xF0:
			//add dh,al
			if (DH > 0xFF - AL) {
				flags = flags | (1 << 6);
			}
			DH += AL;
			break;
		case 0xF1:
			//add dh,cl
			if (DH > 0xFF - CL) {
				flags = flags | (1 << 6);
			}
			DH += CL;
			break;
		case 0xF2:
			//add dh,dl
			if (DH > 0xFF - DL) {
				flags = flags | (1 << 6);
			}
			DH += DL;
			break;
		case 0xF3:
			//add dh,bl
			if (DH > 0xFF - BL) {
				flags = flags | (1 << 6);
			}
			DH += BL;
			break;
		case 0xF4:
			//add dh,ah
			if (DH > 0xFF - AH) {
				flags = flags | (1 << 6);
			}
			DH += AH;
			break;
		case 0xF5:
			//add dh,ch
			if (DH > 0xFF - CH) {
				flags = flags | (1 << 6);
			}
			DH += CH;
			break;
		case 0xF6:
			//add dh,dh
			if (DH > 0xFF - DH) {
				flags = flags | (1 << 6);
			}
			DH += DH;
			break;
		case 0xF7:
			//add dh,bh
			if (DH > 0xFF - BH) {
				flags = flags | (1 << 6);
			}
			DH += BH;
			break;
		case 0xF8:
			//add bh,al
			if (BH > 0xFF - AL) {
				flags = flags | (1 << 6);
			}
			BH += AL;
			break;
		case 0xF9:
			//add bh,cl
			if (BH > 0xFF - CL) {
				flags = flags | (1 << 6);
			}
			BH += CL;
			break;
		case 0xFA:
			//add bh,dl
			if (BH > 0xFF - DL) {
				flags = flags | (1 << 6);
			}
			BH += DL;
			break;
		case 0xFB:
			//add bh,bl
			if (BH > 0xFF - BL) {
				flags = flags | (1 << 6);
			}
			BH += BL;
			break;
		case 0xFC:
			//add bh,ah
			if (BH > 0xFF - AH) {
				flags = flags | (1 << 6);
			}
			BH += AH;
			break;
		case 0xFD:
			//add bh,ch
			if (BH > 0xFF - CH) {
				flags = flags | (1 << 6);
			}
			BH += CH;
			break;
		case 0xFE:
			//add bh,dh
			if (BH > 0xFF - DH) {
				flags = flags | (1 << 6);
			}
			BH += DH;
			break;
		case 0xFF:
			//add bh,bh
			if (BH > 0xFF - BH) {
				flags = flags | (1 << 6);
			}
			BH += BH;
			break;
		}

		break;
	case 0x05:
		//add AX,imm16
		opcode = code[IP++];
		if (AX > 0xFFFF - opcode) {
			flags = flags | (1 << 6);
		}
		AL += opcode;
		opcode = code[IP++];
		AH += opcode; 
		AX = combine(AL, AH);
		break;
	case 0x81:
		//add reg16,imm16
		opcode = code[IP++];
		switch (opcode) {
		case 0xC1:
			//add cx,imm16
			opcode = code[IP++];
			CL = opcode;
			opcode = code[IP++];
			CH = opcode;
			if (CX > 0xFFFF - combine(CL, CH)) {
				flags = flags | (1 << 6);
			}
			CX += combine(CL, CH);
			break;
		case 0xC2:
			//add dx,imm16
			opcode = code[IP++];
			DL = opcode;
			opcode = code[IP++];
			DH = opcode;
			if (DX > 0xFFFF - combine(DL, DH)) {
				flags = flags | (1 << 6);
			}
			DX += combine(DL, DH);
			break;
		case 0xC3:
			//add bx,imm16
			opcode = code[IP++];
			BL = opcode;
			opcode = code[IP++];
			BH = opcode;
			if (BX > 0xFFFF - combine(BL,BH)) {
				flags = flags | (1 << 6);
			}
			BX += combine(BL,BH);
			break;
		case 0xC4:
			//add sp,imm16
			opcode = code[IP++];
			if (SP > 0xFFFF - combine(opcode, code[IP++])) {
				flags = flags | (1 << 6);
			}
			SP += combine(opcode, code[IP--]);
			break;
		case 0xC5:
			//add bp,imm16
			opcode = code[IP++];
			if (BP > 0xFFFF - combine(opcode, code[IP++])) {
				flags = flags | (1 << 6);
			}
			BP += combine(opcode, code[IP--]);
			break;
		case 0xC6:
			//add si,imm16
			opcode = code[IP++];
			if (SI > 0xFFFF - combine(opcode, code[IP++])) {
				flags = flags | (1 << 6);
			}
			SI += combine(opcode, code[IP--]);
			break;
		case 0xC7:
			//add di,imm16
			opcode = code[IP++];
			if (DI > 0xFFFF - combine(opcode, code[IP++])) {
				flags = flags | (1 << 6);
			}
			DI += combine(opcode, code[IP--]);
			break;
		}
		break;
	case 0xB0:
		//mov AL,imm8
		opcode = code[IP++];
		AL = opcode;
		break;
	case 0xB1:
		//mov CL,imm8
		opcode = code[IP++];
		CL = opcode;
		break;
	case 0xB2:
		//mov DL,imm8
		opcode = code[IP++];
		DL = opcode;
		break;
	case 0xB3:
		//mov BL,imm8
		opcode = code[IP++];
		BL = opcode;
		break;
	case 0xB4:
		//mov AH,imm8
		opcode = code[IP++];
		AH = opcode;
		break;
	case 0xB5:
		//mov CH,imm8
		opcode = code[IP++];
		CH = opcode;
		break;
	case 0xB6:
		//mov DH,imm8
		opcode = code[IP++];
		DH = opcode;
		break;
	case 0xB7:
		//mov BH,imm8
		opcode = code[IP++];
		BH = opcode;
		break;
	case 0xB8:
		//mov AX,imm16
		opcode = code[IP++];
		AL = opcode;
		opcode = code[IP++];
		AH = opcode;
		AX = combine(AL, AH);
		break;
	case 0xB9:
		//mov CX,imm16
		opcode = code[IP++];
		CL = opcode;
		opcode = code[IP++];
		CH = opcode;
		CX = combine(CL, CH);
		break;
	case 0xBA:
		//mov DX,imm16
		opcode = code[IP++];
		DL = opcode;
		opcode = code[IP++];
		DH = opcode;
		DX = combine(DL, DH);
		break;
	case 0xBB:
		//mov BX,imm16
		opcode = code[IP++];
		BL = opcode;
		opcode = code[IP++];
		BH = opcode;
		BX = combine(BL, BH);
		break;
	case 0xBC:
		//mov SP,imm16
		opcode = code[IP++];
		SP = combine(opcode, code[IP++]);
		break;
	case 0xBD:
		//mov BP,imm16
		opcode = code[IP++];
		BP = combine(opcode, code[IP++]);
		break;
	case 0xBE:
		//mov SI,imm16
		opcode = code[IP++];
		SI = combine(opcode, code[IP++]);
		break;
	case 0xBF:
		//mov DI,imm16
		opcode = code[IP++];
		DI = combine(opcode, code[IP++]);
		break;
	}
}

int main(int argc, char* argv[]) {
	FILE* f;
	if (OS) {
		f = fopen("C:\\csc210\\SAMPLE.COM", "rb");
		if (!f) {
			printf("fopen could not read this file in 'rb' mode");
			return -1;
		}
	}
	else {
		if (argc < 2) {
			printf("Compile like this: g++ Emulator.cpp\n");
			printf("Pass the path to the .com file if in same directory like this: ./a.out SAMPLE2.com\n");
			return -1;
		}
		f = fopen(argv[1], "rb");
		if (!f) {
			printf("fopen could not read this file in 'rb' mode");
			return -1;
		}
	}
	fread(code, 1, MAXCODE, f);
	fclose(f);

	IP = 0;
	flags = 0x00000000;
	while (1) {
		opcode = code[IP++];
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
			printf("\nRead byte 0xCD followed by terminator byte: %02X\nexiting . . .\n", opcode);
			if (opcode == 0x20) return 0;
		default:		
/*
			printf("%hhx %zu\n", opcode, sizeof(opcode));
			byte opcode2 = code[0];
			word an = opcode + opcode2;
			int bn = an*0xFFFF;
			printf("%04X \n", an);
			printf("%08X \n", bn);
			//printf("%02X \t", opcode);
*/


			cop(opcode);
			break;
		}
		dumpRegisters();
	}
	return 0;
}

void dumpRegisters() {
	printf("\n\nIP AFTER INSTRUCTION: %d %10s OPCODE: %02X\n", IP, " ", opcode);
	printf("AL=%02X \t AH=%02X \t AX=%04X \n", AL, AH, AX);
	printf("CL=%02X \t CH=%02X \t CX=%04X \n", CL, CH, CX);
	printf("DL=%02X \t DH=%02X \t DX=%04X \n", DL, DH, DX);
	printf("BL=%02X \t BH=%02X \t BX=%04X \n", BL, BH, BX);
	printf("SP=%04X \t BP=%04X \t SI=%04X \t DI=%04X \n", SP, BP, SI, DI);
	printf("FLAGS: "); printBits(sizeof(flags), &flags);
}