#define _CRT_SECURE_NO_DEPRECATE
#define MAXCODE 0x100000
#include <stdio.h>
#include "Help.h"

typedef unsigned char byte;
typedef unsigned short word;
typedef unsigned int dword;

byte AL, AH, BL, BH, CL, CH, DL, DH;
word AX, BX, CX, DX;
word flags, IP, ES, SS, DS, CS, SP, BP, DI, SI;
//int flags[8];

byte code[MAXCODE];
byte opcode;

main() {
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
		case 0x02:
			//add re g8,reg8
			opcode = code[IP++];
			switch (opcode) {
			case 0xC0:
				//add al,al
				if (AL > 0xFF - AL) {
					//flags[6] = 1;
					//flags ^= 1 << 6;
					//Set ZF and CF to 1 if not already
					flags = flags | (1 << 15);
					//flags = flags | (1 << 5);
					break;
				}
				AL += AL;
				break;
			case 0xC1:
				//add al,cl
				break;
			case 0xC2:
				//add al,dl
				break;
			case 0xC3:
				//add al,bl
				break;
			case 0xC4:
				//add al,ah
				break;
			case 0xC5:
				//add al,ch
				break;
			case 0xC6:
				//add al,dh
				break;
			case 0xC7:
				//add al,bh
				break;
			case 0xC8:
				//add cl,al
				break;
			case 0xC9:
				//add cl,cl
				break;
			case 0xCA:
				//add cl,dl
				break;
			case 0xCB:
				//add cl,bl
				break;
			case 0xCC:
				//add cl,ah
				break;
			case 0xCD:
				//add cl,ch
				break;
			case 0xCE:
				//add cl,dh
				break;
			case 0xCF:
				//add cl,ch
				break;
			case 0xD0:
				//add dl,al
				break;
			case 0xD1:
				//add dl,cl
				break;
			case 0xD2:
				//add dl,dl
				break;
			case 0xD3:
				//add dl,bl
				break;
			case 0xD4:
				//add dl,ah
				break;
			case 0xD5:
				//add dl,ch
				break;
			case 0xD6:
				//add dl,dh
				break;
			case 0xD7:
				//add dl,bh
				break;
			case 0xD8:
				//add bl,al
				break;
			case 0xD9:
				//add bl,cl
				break;
			case 0xDA:
				//add bl,dl
				break;
			case 0xDB:
				//add bl,bl
				break;
			case 0xDC:
				//add bl,ah
				break;
			case 0xDD:
				//add bl,ch
				break;
			case 0xDE:
				//add bl,dh
				break;
			case 0xDF:
				//add bl,bh
				break;
			case 0xE0:
				//add ah,al
				break;
			case 0xE1:
				//add ah,cl
				break;
			case 0xE2:
				//add ah,dl
				break;
			case 0xE3:
				//add ah,bl
				break;
			case 0xE4:
				//add ah,ah
				break;
			case 0xE5:
				//add ah,ch
				break;
			case 0xE6:
				//add ah,dh
				break;
			case 0xE7:
				//add ah,bh
				break;
			case 0xE8:
				//add ch,al
				break;
			case 0xE9:
				//add ch,cl
				break;
			case 0xEA:
				//add ch,dl
				break;
			case 0xEB:
				//add ch,bl
				break;
			case 0xEC:
				//add ch,ah
				break;
			case 0xED:
				//add ch,ch
				break;
			case 0xEE:
				//add ch,dh
				break;
			case 0xEF:
				//add ch,bh
				break;
			case 0xF0:
				//add dh,al
				break;
			case 0xF1:
				//add dh,cl
				break;
			case 0xF2:
				//add dh,dl
				break;
			case 0xF3:
				//add dh,bl
				break;
			case 0xF4:
				//add dh,ah
				break;
			case 0xF5:
				//add dh,ch
				break;
			case 0xF6:
				//add dh,dh
				break;
			case 0xF7:
				//add dh,bh
				break;
			case 0xF8:
				//add bh,al
				break;
			case 0xF9:
				//add bh,cl
				break;
			case 0xFA:
				//add bh,dl
				break;
			case 0xFB:
				//add bh,bl
				break;
			case 0xFC:
				//add bh,ah
				break;
			case 0xFD:
				//add bh,ch
				break;
			case 0xFE:
				//add bh,dh
				break;
			case 0xFF:
				//add bh,bh
				break;
			}
			break;
		case 0x03:
			//add reg16,reg16
			opcode = code[IP++];
			switch (opcode) {
			case 0xC0:
				//add ax,ax
				break;
			case 0xC1:
				//add ax,cx
				break;
			case 0xC2:
				//add ax,dx
				break;
			case 0xC3:
				//add ax,bx
				break;
			case 0xC4:
				//add ax,sp
				break;
			case 0xC5:
				//add ax,bp
				break;
			case 0xC6:
				//add ax,si
				break;
			case 0xC7:
				//add ax,di
				break;
			case 0xC8:
				//add cx,ax
				break;
			case 0xC9:
				//add cx,cx
				break;
			case 0xCA:
				//add cx,dx
				break;
			case 0xCB:
				//add cx,bx
				break;
			case 0xCC:
				//add cx,sp
				break;
			case 0xCD:
				//add cx,bp
				break;
			case 0xCE:
				//add cx,si
				break;
			case 0xCF:
				//add cx,di
				break;
			case 0xD0:
				//add dx,ax
				break;
			case 0xD1:
				//add dx,cx
				break;
			case 0xD2:
				//add dx,dx
				break;
			case 0xD3:
				//add dx,bx
				break;
			case 0xD4:
				//add dx,sp
				break;
			case 0xD5:
				//add dx,bp
				break;
			case 0xD6:
				//add dx,si
				break;
			case 0xD7:
				//add dx,di
				break;
			case 0xD8:
				//add bx,ax
				break;
			case 0xD9:
				//add bx,cx
				break;
			case 0xDA:
				//add bx,dx
				break;
			case 0xDB:
				//add bx,bx
				break;
			case 0xDC:
				//add bx,sp
				break;
			case 0xDD:
				//add bx,bp
				break;
			case 0xDE:
				//add bx,si
				break;
			case 0xDF:
				//add bx,di
				break;
			case 0xE0:
				//add sp,ax
				break;
			case 0xE1:
				//add sp,cx
				break;
			case 0xE2:
				//add sp,dx
				break;
			case 0xE3:
				//add sp,bx
				break;
			case 0xE4:
				//add sp,sp
				break;
			case 0xE5:
				//add sp,bp
				break;
			case 0xE6:
				//add sp,si
				break;
			case 0xE7:
				//add sp,di
				break;
			case 0xE8:
				//add bp,ax
				break;
			case 0xE9:
				//add bp,cx
				break;
			case 0xEA:
				//add bp,dx
				break;
			case 0xEB:
				//add bp,bx
				break;
			case 0xEC:
				//add bp,sp
				break;
			case 0xED:
				//add bp,bp
				break;
			case 0xEE:
				//add bp,si
				break;
			case 0xEF:
				//add bp,di
				break;
			case 0xF0:
				//add si,ax
				break;
			case 0xF1:
				//add si,cx
				break;
			case 0xF2:
				//add si,dx
				break;
			case 0xF3:
				//add si,bx
				break;
			case 0xF4:
				//add si,sp
				break;
			case 0xF5:
				//add si,bp
				break;
			case 0xF6:
				//add si,si
				break;
			case 0xF7:
				//add si,di
				break;
			case 0xF8:
				//add di,ax
				break;
			case 0xF9:
				//add di,cx
				break;
			case 0xFA:
				//add di,dx
				break;
			case 0xFB:
				//add di,bx
				break;
			case 0xFC:
				//add di,sp
				break;
			case 0xFD:
				//add di,bp
				break;
			case 0xFE:
				//add di,si
				break;
			case 0xFF:
				//add di,di
				break;
			}
			break;
		case 0x04:
			//add AL,imm8
			opcode = code[IP++];
			AL += opcode;
			break;
		case 0x86:
			//xchg reg8,reg8
			opcode = code[IP++];
			switch (opcode) {	
			case 0xC0: 
				//xchg al,al
				break;
			case 0xC1: 
				//xchg al,cl
				break; 
			case 0xC2: 
				//xchg al,dl
				break;
			case 0xC3: 
				//xchg al,bl
				break;
			case 0xE4:
				//xchg ah,ah
				break;
			case 0xE5:
				//xchg ah,ch
				break;
			case 0xE6:
				//xchg ah,dh
				break;
			case 0xE7:
				//xchg ah,bh
				break;
			}
			break;
		case 0x87:
			//xchg reg16,reg16
			opcode = code[IP++];
			switch (opcode) {
			case 0xC9:
				//xchg cx,cx
				break;
			case 0xCA:
				//xchg cx,dx
				break;
			case 0xCB:
				//xchg cx,bx
				break;
			case 0xCC:
				//xchg cx,sp
				break;
			case 0xCD:
				//xchg cx,bp
				break;
			case 0xCE:
				//xchg cx,si
				break;
			case 0xCF:
				//xchg cx,di
				break;
			case 0xD1:
				//xchg dx,cx
				break;
			case 0xD2:
				//xchg dx,dx
				break;
			case 0xD3:
				//xchg dx,bx
				break;
			case 0xD4:
				//xchg dx,sp
				break;
			case 0xD5:
				//xchg dx,bp
				break;
			case 0xD6:
				//xchg dx,si
				break;
			case 0xD7:
				//xchg dx,di
				break;
			case 0xD9:
				//xchg bx,cx
				break;
			case 0xDA:
				//xchg bx,dx
				break;
			case 0xDB:
				//xchg bx,bx
				break;
			case 0xDC:
				//xchg bx,sp
				break;
			case 0xDD:
				//xchg bx,bp
				break;
			case 0xDE:
				//xchg bx,si
				break;
			case 0xDF:
				//xchg bx,di
				break;
			}
			break;
		case 0x90:
			//nop
			break;
		case 0x91:
			//xchg ax,cx
			break;
		case 0x92:
			//xchg ax,dx
			break;
		case 0x93:
			//xchg ax,bx
			break;
		case 0x94:
			//xchg ax,sp
			break;
		case 0x95:
			//xchg ax,bp
			break;
		case 0x96:
			//xchg ax,si
			break;
		case 0x97:
			//xchg ax,di
			break;
		case 0xB0:
			//mov Al,imm8
			opcode = code[IP++];
			AL = opcode;
			break;
		case 0xB8:
			//mov AX,imm16
			opcode = code[IP++];
			AL = opcode;
			opcode = code[IP++];
			AH = opcode;
			break;
		case 0xB9:
			//mov CX,imm16
			opcode = code[IP++];
			CL = opcode;
			opcode = code[IP++];
			CH = opcode;
			break;
		case 0xBA:
			//mov DX,imm16
			opcode = code[IP++];
			DL = opcode;
			opcode = code[IP++];
			DH = opcode;
			break;
		case 0xBB:
			//mov BX,imm16
			opcode = code[IP++];
			BL = opcode;
			opcode = code[IP++];
			BH = opcode;
			break;
		case 0xCD:
			opcode = code[IP++];
			if (opcode == 0x20) return 0;
		}
		printf("AL=%d \t AH=%d \t CF=%d \n", AL, AH, flags);

	}
}