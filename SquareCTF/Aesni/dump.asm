
aesni:     file format elf32-i386


Disassembly of section .text:

08048060 <.text>:
 8048060:	0f 10 0d 77 80 04 08 	movups xmm1,XMMWORD PTR ds:0x8048077
 8048067:	8d 35 f1 81 04 08    	lea    esi,ds:0x80481f1
 804806d:	b9 06 00 00 00       	mov    ecx,0x6
 8048072:	e9 05 01 00 00       	jmp    0x804817c
 8048077:	66 6c                	data16 ins BYTE PTR es:[edi],dx
 8048079:	61                   	popa   
 804807a:	70 2d                	jo     0x80480a9
 804807c:	64 30 64 38 34       	xor    BYTE PTR fs:[eax+edi*1+0x34],ah
 8048081:	31 31                	xor    DWORD PTR [ecx],esi
 8048083:	65 63 30             	arpl   WORD PTR gs:[eax],si
 8048086:	36 2d 2d 20 61 6c    	ss sub eax,0x6c61202d
 804808c:	6f                   	outs   dx,DWORD PTR ds:[esi]
 804808d:	6b 20 26             	imul   esp,DWORD PTR [eax],0x26
 8048090:	20 6d 62             	and    BYTE PTR [ebp+0x62],ch
 8048093:	79 63                	jns    0x80480f8
 8048095:	7a 6b                	jp     0x8048102
 8048097:	6f                   	outs   dx,DWORD PTR ds:[esi]
 8048098:	77 73                	ja     0x804810d
 804809a:	6b 69 7b 63          	imul   ebp,DWORD PTR [ecx+0x7b],0x63
 804809e:	ba 22 06 5b db       	mov    edx,0xdb5b0622
 80480a3:	f5                   	cmc    
 80480a4:	ec                   	in     al,dx
 80480a5:	56                   	push   esi
 80480a6:	00 52 5b             	add    BYTE PTR [edx+0x5b],dl
 80480a9:	aa                   	stos   BYTE PTR es:[edi],al
 80480aa:	fa                   	cli    
 80480ab:	60                   	pusha  
 80480ac:	52                   	push   edx
 80480ad:	09 42 5c             	or     DWORD PTR [edx+0x5c],eax
 80480b0:	5d                   	pop    ebp
 80480b1:	de 67 ed             	fisub  WORD PTR [edi-0x13]
 80480b4:	d5 5f                	aad    0x5f
 80480b6:	08 eb                	or     bl,ch
 80480b8:	56                   	push   esi
 80480b9:	56                   	push   esi
 80480ba:	56                   	push   esi
 80480bb:	54                   	push   esp
 80480bc:	bb af 7f 54 0d       	mov    ebx,0xd547faf
 80480c1:	43                   	inc    ebx
 80480c2:	5f                   	pop    edi
 80480c3:	0e                   	push   cs
 80480c4:	d4 5f                	aam    0x5f
 80480c6:	08 df                	or     bh,bl
 80480c8:	6e                   	outs   dx,BYTE PTR ds:[esi]
 80480c9:	4a                   	dec    edx
 80480ca:	d7                   	xlat   BYTE PTR ds:[ebx]
 80480cb:	50                   	push   eax
 80480cc:	48                   	dec    eax
 80480cd:	b4 0b                	mov    ah,0xb
 80480cf:	4f                   	dec    edi
 80480d0:	02 53 bb             	add    dl,BYTE PTR [ebx-0x45]
 80480d3:	a7                   	cmps   DWORD PTR ds:[esi],DWORD PTR es:[edi]
 80480d4:	55                   	push   ebp
 80480d5:	5b                   	pop    ebx
 80480d6:	00 5d 4b             	add    BYTE PTR [ebp+0x4b],bl
 80480d9:	5b                   	pop    ebx
 80480da:	aa                   	stos   BYTE PTR es:[edi],al
 80480db:	d4 6d                	aam    0x6d
 80480dd:	9c                   	pushf  
 80480de:	1a ca                	sbb    cl,dl
 80480e0:	53                   	push   ebx
 80480e1:	d1 56 0a             	rcl    DWORD PTR [esi+0xa],1
 80480e4:	ec                   	in     al,dx
 80480e5:	5f                   	pop    edi
 80480e6:	00 52 5b             	add    BYTE PTR [edx+0x5b],dl
 80480e9:	bf d8 54 60 1d       	mov    edi,0x1d6054d8
 80480ee:	dd 7e 3f             	fnstsw WORD PTR [esi+0x3f]
 80480f1:	4f                   	dec    edi
 80480f2:	74 7a                	je     0x804816e
 80480f4:	69 5d 78 61 47 6d 46 	imul   ebx,DWORD PTR [ebp+0x78],0x466d4761
 80480fb:	01 1b                	add    DWORD PTR [ebx],ebx
 80480fd:	26 71 0d             	es jno 0x804810d
 8048100:	61                   	popa   
 8048101:	37                   	aaa    
 8048102:	37                   	aaa    
 8048103:	3b 37                	cmp    esi,DWORD PTR [edi]
 8048105:	69 37 31 39 63 6f    	imul   esi,DWORD PTR [edi],0x6f633931
 804810b:	64 5a                	fs pop edx
 804810d:	7b 2b                	jnp    0x804813a
 804810f:	41                   	inc    ecx
 8048110:	31 37                	xor    DWORD PTR [edi],esi
 8048112:	30 67 6d             	xor    BYTE PTR [edi+0x6d],ah
 8048115:	6a 36                	push   0x36
 8048117:	65 62 32             	bound  esi,QWORD PTR gs:[edx]
 804811a:	32 31                	xor    dh,BYTE PTR [ecx]
 804811c:	16                   	push   ss
 804811d:	4a                   	dec    edx
 804811e:	56                   	push   esi
 804811f:	5c                   	pop    esp
 8048120:	5d                   	pop    ebp
 8048121:	6b 80 02 53 ea 13 d5 	imul   eax,DWORD PTR [eax+0x13ea5302],0xffffffd5
 8048128:	5e                   	pop    esi
 8048129:	0f bc 10             	bsf    edx,DWORD PTR [eax]
 804812c:	6e                   	outs   dx,BYTE PTR ds:[esi]
 804812d:	93                   	xchg   ebx,eax
 804812e:	c0 f3 40             	shl    bl,0x40
 8048131:	0a 5d 87             	or     bl,BYTE PTR [ebp-0x79]
 8048134:	5f                   	pop    edi
 8048135:	5a                   	pop    edx
 8048136:	d8 61 eb             	fsub   DWORD PTR [ecx-0x15]
 8048139:	86 03                	xchg   BYTE PTR [ebx],al
 804813b:	0e                   	push   cs
 804813c:	3e a3 4d 7c 50 07    	mov    ds:0x7507c4d,eax
 8048142:	92                   	xchg   edx,eax
 8048143:	95                   	xchg   ebp,eax
 8048144:	b0 64                	mov    al,0x64
 8048146:	33 38                	xor    edi,DWORD PTR [eax]
 8048148:	3b 60 2a             	cmp    esp,DWORD PTR [eax+0x2a]
 804814b:	65 1b 75 20          	sbb    esi,DWORD PTR gs:[ebp+0x20]
 804814f:	5f                   	pop    edi
 8048150:	35 3f 38 67 6c       	xor    eax,0x6c67383f
 8048155:	64 65 63 68 34       	fs arpl WORD PTR gs:[eax+0x34],bp
 804815a:	3e 0c 50             	ds or  al,0x50
 804815d:	2c 2a                	sub    al,0x2a
 804815f:	13 60 64             	adc    esp,DWORD PTR [eax+0x64]
 8048162:	30 64 38 62          	xor    BYTE PTR [eax+edi*1+0x62],ah
 8048166:	33 62 3f             	xor    esp,DWORD PTR [edx+0x3f]
 8048169:	64 34 64             	fs xor al,0x64
 804816c:	82 6e 4c 70          	sub    BYTE PTR [esi+0x4c],0x70
 8048170:	50                   	push   eax
 8048171:	06                   	push   es
 8048172:	b9 54 52 53 51       	mov    ecx,0x51535254
 8048177:	ca 85 12             	retf   0x1285
 804817a:	07                   	pop    es
 804817b:	91                   	xchg   ecx,eax
 804817c:	89 f7                	mov    edi,esi
 804817e:	89 0d a1 81 04 08    	mov    DWORD PTR ds:0x80481a1,ecx
 8048184:	0f 10 05 a1 81 04 08 	movups xmm0,XMMWORD PTR ds:0x80481a1
 804818b:	66 0f 38 dc c1       	aesenc xmm0,xmm1
 8048190:	0f 10 16             	movups xmm2,XMMWORD PTR [esi]
 8048193:	66 0f ef d0          	pxor   xmm2,xmm0 										addroundkey 1byte?
 8048197:	0f 11 16             	movups XMMWORD PTR [esi],xmm2
 804819a:	83 c6 10             	add    esi,0x10
 804819d:	e0 df                	loopne 0x804817e
 804819f:	ff e7                	jmp    edi
	...
 80481b1:	ea 02 1f 77 62 db 11 	jmp    0x11db:0x62771f02
 80481b8:	42                   	inc    edx
 80481b9:	43                   	inc    ebx
 80481ba:	10 34 95 46 93 9d 81 	adc    BYTE PTR [edx*4-0x7e626cba],dh
 80481c1:	65 5a                	gs pop edx
 80481c3:	12 dc                	adc    bl,ah
 80481c5:	d2 04 5a             	rol    BYTE PTR [edx+ebx*2],cl
 80481c8:	82 c0 59             	add    al,0x59
 80481cb:	8c 93 09 10 5d e0    	mov    WORD PTR [ebx-0x1fa2eff7],ss
 80481d1:	f3 42                	repz inc edx
 80481d3:	1b b4 66 6c d3 05 08 	sbb    esi,DWORD PTR [esi+eiz*2+0x805d36c]
 80481da:	ea 04 55 06 00 bb 9a 	jmp    0x9abb:0x65504
 80481e1:	00 7f 28             	add    BYTE PTR [edi+0x28],bh
 80481e4:	16                   	push   ss
 80481e5:	60                   	pusha  
 80481e6:	34 30                	xor    al,0x30
 80481e8:	37                   	aaa    
 80481e9:	31 63 37             	xor    DWORD PTR [ebx+0x37],esp
 80481ec:	31 60 31             	xor    DWORD PTR [eax+0x31],esp
 80481ef:	69 30 45 80 f6 05    	imul   esi,DWORD PTR [eax],0x5f68045
 80481f5:	3a 1d 5c 17 56 66    	cmp    bl,BYTE PTR ds:0x6656175c
 80481fb:	d0 56 0e             	rcl    BYTE PTR [esi+0xe],1
 80481fe:	8d 66 04             	lea    esp,[esi+0x4]
 8048201:	97                   	xchg   edi,eax
 8048202:	03 02                	add    eax,DWORD PTR [edx]
 8048204:	b2 4a                	mov    dl,0x4a
 8048206:	07                   	pop    es
 8048207:	53                   	push   ebx
 8048208:	07                   	pop    es
 8048209:	d8 97 50 bb 6d ff    	fcom   DWORD PTR [edi-0x9244b0]
 804820f:	ac                   	lods   al,BYTE PTR ds:[esi]
 8048210:	aa                   	stos   BYTE PTR es:[edi],al
 8048211:	33 8e 9e ea cc 03    	xor    ecx,DWORD PTR [esi+0x3ccea9e]
 8048217:	5b                   	pop    ebx
 8048218:	8e 9d 58 42 5f 47    	mov    ds,WORD PTR [ebp+0x475f4258]
 804821e:	82 57 5d b8          	adc    BYTE PTR [edi+0x5d],0xb8
 8048222:	22 8b b9 4a 0f ea    	and    cl,BYTE PTR [ebx-0x15f0b547]
 8048228:	04 5b                	add    al,0x5b
 804822a:	57                   	push   edi
 804822b:	52                   	push   edx
 804822c:	bb 4d ff ac aa       	mov    ebx,0xaaacff4d
 8048231:	4e                   	dec    esi
 8048232:	2c 75                	sub    al,0x75
 8048234:	49                   	dec    ecx
 8048235:	2d 63 36 3e 39       	sub    eax,0x393e3663
 804823a:	65 65 31 64 35 6a    	gs xor DWORD PTR gs:[ebp+esi*1+0x6a],esp
 8048240:	65 58                	gs pop eax
 8048242:	23 7f 56             	and    edi,DWORD PTR [edi+0x56]
 8048245:	79 34                	jns    0x804827b
 8048247:	36 36 38 62 6b       	ss cmp BYTE PTR ss:[edx+0x6b],ah
 804824c:	6a 64                	push   0x64
 804824e:	62 6b 31             	bound  ebp,QWORD PTR [ebx+0x31]
 8048251:	36 d5 9c             	ss aad 0x9c
 8048254:	3c 82                	cmp    al,0x82
 8048256:	03 0e                	add    ecx,DWORD PTR [esi]
 8048258:	5b                   	pop    ebx
 8048259:	d9 e9                	fldl2t 
 804825b:	29 82 05 5e e1 57    	sub    DWORD PTR [edx+0x57e15e05],eax
 8048261:	30 4c 18 22          	xor    BYTE PTR [eax+ebx*1+0x22],cl
 8048265:	10 0a                	adc    BYTE PTR [edx],cl
 8048267:	87 d8                	xchg   eax,ebx
 8048269:	05 59 d9 35 b0       	add    eax,0xb035d959
 804826e:	d7                   	xlat   BYTE PTR ds:[ebx]
 804826f:	5e                   	pop    esi
 8048270:	5b                   	pop    ebx
 8048271:	91                   	xchg   ecx,eax
 8048272:	44                   	inc    esp
 8048273:	14 39                	adc    al,0x39
 8048275:	00 36                	add    BYTE PTR [esi],dh
 8048277:	cc                   	int3   
 8048278:	b3 fe                	mov    bl,0xfe
 804827a:	af                   	scas   eax,DWORD PTR es:[edi]
 804827b:	ab                   	stos   DWORD PTR es:[edi],eax
 804827c:	ff e3                	jmp    ebx
 804827e:	cd ce                	int    0xce
 8048280:	59                   	pop    ecx
 8048281:	07                   	pop    es
 8048282:	7a 7b                	jp     0x80482ff
 8048284:	42                   	inc    edx
 8048285:	30 64 37 38          	xor    BYTE PTR [edi+esi*1+0x38],ah
 8048289:	62 61 32             	bound  esp,QWORD PTR [ecx+0x32]
 804828c:	36 64 35 69 31 68 08 	ss fs xor eax,0x8683169
 8048293:	16                   	push   ss
 8048294:	3f                   	aas    
 8048295:	41                   	inc    ecx
 8048296:	91                   	xchg   ecx,eax
 8048297:	84 56 08             	test   BYTE PTR [esi+0x8],dl
 804829a:	59                   	pop    ecx
 804829b:	4a                   	dec    edx
 804829c:	56                   	push   esi
 804829d:	b0 83                	mov    al,0x83
 804829f:	5f                   	pop    edi
 80482a0:	0f a5 71 89          	shld   DWORD PTR [ecx-0x77],esi,cl
 80482a4:	bb 50 58 bf 5a       	mov    ebx,0x5abf5850
 80482a9:	00 56 5a             	add    BYTE PTR [esi+0x5a],dl
 80482ac:	b2 ca                	mov    dl,0xca
 80482ae:	ff a4 f8 0d 29 7b 12 	jmp    DWORD PTR [eax+edi*8+0x127b290d]
 80482b5:	35 60 37 33 36       	xor    eax,0x36333760
 80482ba:	6e                   	outs   dx,BYTE PTR ds:[esi]
 80482bb:	39 6a 39             	cmp    DWORD PTR [edx+0x39],ebp
 80482be:	34 6e                	xor    al,0x6e
 80482c0:	30                   	.byte 0x30
