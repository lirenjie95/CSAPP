
bomb:     file format elf32-i386


Disassembly of section .init:

080487a0 <_init>:
 80487a0:	53                   	push   %ebx
 80487a1:	83 ec 08             	sub    $0x8,%esp
 80487a4:	e8 00 00 00 00       	call   80487a9 <_init+0x9>
 80487a9:	5b                   	pop    %ebx
 80487aa:	81 c3 4b 38 00 00    	add    $0x384b,%ebx
 80487b0:	8b 83 fc ff ff ff    	mov    -0x4(%ebx),%eax
 80487b6:	85 c0                	test   %eax,%eax
 80487b8:	74 05                	je     80487bf <_init+0x1f>
 80487ba:	e8 11 01 00 00       	call   80488d0 <__gmon_start__@plt>
 80487bf:	e8 bc 02 00 00       	call   8048a80 <frame_dummy>
 80487c4:	e8 27 10 00 00       	call   80497f0 <__do_global_ctors_aux>
 80487c9:	83 c4 08             	add    $0x8,%esp
 80487cc:	5b                   	pop    %ebx
 80487cd:	c3                   	ret    

Disassembly of section .plt:

080487d0 <cuserid@plt-0x10>:
 80487d0:	ff 35 f8 bf 04 08    	pushl  0x804bff8
 80487d6:	ff 25 fc bf 04 08    	jmp    *0x804bffc
 80487dc:	00 00                	add    %al,(%eax)
	...

080487e0 <cuserid@plt>:
 80487e0:	ff 25 00 c0 04 08    	jmp    *0x804c000
 80487e6:	68 00 00 00 00       	push   $0x0
 80487eb:	e9 e0 ff ff ff       	jmp    80487d0 <_init+0x30>

080487f0 <fflush@plt>:
 80487f0:	ff 25 04 c0 04 08    	jmp    *0x804c004
 80487f6:	68 08 00 00 00       	push   $0x8
 80487fb:	e9 d0 ff ff ff       	jmp    80487d0 <_init+0x30>

08048800 <dup@plt>:
 8048800:	ff 25 08 c0 04 08    	jmp    *0x804c008
 8048806:	68 10 00 00 00       	push   $0x10
 804880b:	e9 c0 ff ff ff       	jmp    80487d0 <_init+0x30>

08048810 <fgets@plt>:
 8048810:	ff 25 0c c0 04 08    	jmp    *0x804c00c
 8048816:	68 18 00 00 00       	push   $0x18
 804881b:	e9 b0 ff ff ff       	jmp    80487d0 <_init+0x30>

08048820 <fclose@plt>:
 8048820:	ff 25 10 c0 04 08    	jmp    *0x804c010
 8048826:	68 20 00 00 00       	push   $0x20
 804882b:	e9 a0 ff ff ff       	jmp    80487d0 <_init+0x30>

08048830 <signal@plt>:
 8048830:	ff 25 14 c0 04 08    	jmp    *0x804c014
 8048836:	68 28 00 00 00       	push   $0x28
 804883b:	e9 90 ff ff ff       	jmp    80487d0 <_init+0x30>

08048840 <sleep@plt>:
 8048840:	ff 25 18 c0 04 08    	jmp    *0x804c018
 8048846:	68 30 00 00 00       	push   $0x30
 804884b:	e9 80 ff ff ff       	jmp    80487d0 <_init+0x30>

08048850 <__stack_chk_fail@plt>:
 8048850:	ff 25 1c c0 04 08    	jmp    *0x804c01c
 8048856:	68 38 00 00 00       	push   $0x38
 804885b:	e9 70 ff ff ff       	jmp    80487d0 <_init+0x30>

08048860 <rewind@plt>:
 8048860:	ff 25 20 c0 04 08    	jmp    *0x804c020
 8048866:	68 40 00 00 00       	push   $0x40
 804886b:	e9 60 ff ff ff       	jmp    80487d0 <_init+0x30>

08048870 <fwrite@plt>:
 8048870:	ff 25 24 c0 04 08    	jmp    *0x804c024
 8048876:	68 48 00 00 00       	push   $0x48
 804887b:	e9 50 ff ff ff       	jmp    80487d0 <_init+0x30>

08048880 <gethostname@plt>:
 8048880:	ff 25 28 c0 04 08    	jmp    *0x804c028
 8048886:	68 50 00 00 00       	push   $0x50
 804888b:	e9 40 ff ff ff       	jmp    80487d0 <_init+0x30>

08048890 <getenv@plt>:
 8048890:	ff 25 2c c0 04 08    	jmp    *0x804c02c
 8048896:	68 58 00 00 00       	push   $0x58
 804889b:	e9 30 ff ff ff       	jmp    80487d0 <_init+0x30>

080488a0 <puts@plt>:
 80488a0:	ff 25 30 c0 04 08    	jmp    *0x804c030
 80488a6:	68 60 00 00 00       	push   $0x60
 80488ab:	e9 20 ff ff ff       	jmp    80487d0 <_init+0x30>

080488b0 <system@plt>:
 80488b0:	ff 25 34 c0 04 08    	jmp    *0x804c034
 80488b6:	68 68 00 00 00       	push   $0x68
 80488bb:	e9 10 ff ff ff       	jmp    80487d0 <_init+0x30>

080488c0 <__memmove_chk@plt>:
 80488c0:	ff 25 38 c0 04 08    	jmp    *0x804c038
 80488c6:	68 70 00 00 00       	push   $0x70
 80488cb:	e9 00 ff ff ff       	jmp    80487d0 <_init+0x30>

080488d0 <__gmon_start__@plt>:
 80488d0:	ff 25 3c c0 04 08    	jmp    *0x804c03c
 80488d6:	68 78 00 00 00       	push   $0x78
 80488db:	e9 f0 fe ff ff       	jmp    80487d0 <_init+0x30>

080488e0 <exit@plt>:
 80488e0:	ff 25 40 c0 04 08    	jmp    *0x804c040
 80488e6:	68 80 00 00 00       	push   $0x80
 80488eb:	e9 e0 fe ff ff       	jmp    80487d0 <_init+0x30>

080488f0 <__libc_start_main@plt>:
 80488f0:	ff 25 44 c0 04 08    	jmp    *0x804c044
 80488f6:	68 88 00 00 00       	push   $0x88
 80488fb:	e9 d0 fe ff ff       	jmp    80487d0 <_init+0x30>

08048900 <strcasecmp@plt>:
 8048900:	ff 25 48 c0 04 08    	jmp    *0x804c048
 8048906:	68 90 00 00 00       	push   $0x90
 804890b:	e9 c0 fe ff ff       	jmp    80487d0 <_init+0x30>

08048910 <__isoc99_sscanf@plt>:
 8048910:	ff 25 4c c0 04 08    	jmp    *0x804c04c
 8048916:	68 98 00 00 00       	push   $0x98
 804891b:	e9 b0 fe ff ff       	jmp    80487d0 <_init+0x30>

08048920 <fopen@plt>:
 8048920:	ff 25 50 c0 04 08    	jmp    *0x804c050
 8048926:	68 a0 00 00 00       	push   $0xa0
 804892b:	e9 a0 fe ff ff       	jmp    80487d0 <_init+0x30>

08048930 <__strcpy_chk@plt>:
 8048930:	ff 25 54 c0 04 08    	jmp    *0x804c054
 8048936:	68 a8 00 00 00       	push   $0xa8
 804893b:	e9 90 fe ff ff       	jmp    80487d0 <_init+0x30>

08048940 <__printf_chk@plt>:
 8048940:	ff 25 58 c0 04 08    	jmp    *0x804c058
 8048946:	68 b0 00 00 00       	push   $0xb0
 804894b:	e9 80 fe ff ff       	jmp    80487d0 <_init+0x30>

08048950 <fputc@plt>:
 8048950:	ff 25 5c c0 04 08    	jmp    *0x804c05c
 8048956:	68 b8 00 00 00       	push   $0xb8
 804895b:	e9 70 fe ff ff       	jmp    80487d0 <_init+0x30>

08048960 <tmpfile@plt>:
 8048960:	ff 25 60 c0 04 08    	jmp    *0x804c060
 8048966:	68 c0 00 00 00       	push   $0xc0
 804896b:	e9 60 fe ff ff       	jmp    80487d0 <_init+0x30>

08048970 <socket@plt>:
 8048970:	ff 25 64 c0 04 08    	jmp    *0x804c064
 8048976:	68 c8 00 00 00       	push   $0xc8
 804897b:	e9 50 fe ff ff       	jmp    80487d0 <_init+0x30>

08048980 <__fprintf_chk@plt>:
 8048980:	ff 25 68 c0 04 08    	jmp    *0x804c068
 8048986:	68 d0 00 00 00       	push   $0xd0
 804898b:	e9 40 fe ff ff       	jmp    80487d0 <_init+0x30>

08048990 <gethostbyname@plt>:
 8048990:	ff 25 6c c0 04 08    	jmp    *0x804c06c
 8048996:	68 d8 00 00 00       	push   $0xd8
 804899b:	e9 30 fe ff ff       	jmp    80487d0 <_init+0x30>

080489a0 <strtol@plt>:
 80489a0:	ff 25 70 c0 04 08    	jmp    *0x804c070
 80489a6:	68 e0 00 00 00       	push   $0xe0
 80489ab:	e9 20 fe ff ff       	jmp    80487d0 <_init+0x30>

080489b0 <connect@plt>:
 80489b0:	ff 25 74 c0 04 08    	jmp    *0x804c074
 80489b6:	68 e8 00 00 00       	push   $0xe8
 80489bb:	e9 10 fe ff ff       	jmp    80487d0 <_init+0x30>

080489c0 <close@plt>:
 80489c0:	ff 25 78 c0 04 08    	jmp    *0x804c078
 80489c6:	68 f0 00 00 00       	push   $0xf0
 80489cb:	e9 00 fe ff ff       	jmp    80487d0 <_init+0x30>

080489d0 <__ctype_b_loc@plt>:
 80489d0:	ff 25 7c c0 04 08    	jmp    *0x804c07c
 80489d6:	68 f8 00 00 00       	push   $0xf8
 80489db:	e9 f0 fd ff ff       	jmp    80487d0 <_init+0x30>

080489e0 <__sprintf_chk@plt>:
 80489e0:	ff 25 80 c0 04 08    	jmp    *0x804c080
 80489e6:	68 00 01 00 00       	push   $0x100
 80489eb:	e9 e0 fd ff ff       	jmp    80487d0 <_init+0x30>

Disassembly of section .text:

080489f0 <_start>:
 80489f0:	31 ed                	xor    %ebp,%ebp
 80489f2:	5e                   	pop    %esi
 80489f3:	89 e1                	mov    %esp,%ecx
 80489f5:	83 e4 f0             	and    $0xfffffff0,%esp
 80489f8:	50                   	push   %eax
 80489f9:	54                   	push   %esp
 80489fa:	52                   	push   %edx
 80489fb:	68 e0 97 04 08       	push   $0x80497e0
 8048a00:	68 70 97 04 08       	push   $0x8049770
 8048a05:	51                   	push   %ecx
 8048a06:	56                   	push   %esi
 8048a07:	68 a4 8a 04 08       	push   $0x8048aa4
 8048a0c:	e8 df fe ff ff       	call   80488f0 <__libc_start_main@plt>
 8048a11:	f4                   	hlt    
 8048a12:	90                   	nop
 8048a13:	90                   	nop
 8048a14:	90                   	nop
 8048a15:	90                   	nop
 8048a16:	90                   	nop
 8048a17:	90                   	nop
 8048a18:	90                   	nop
 8048a19:	90                   	nop
 8048a1a:	90                   	nop
 8048a1b:	90                   	nop
 8048a1c:	90                   	nop
 8048a1d:	90                   	nop
 8048a1e:	90                   	nop
 8048a1f:	90                   	nop

08048a20 <__do_global_dtors_aux>:
 8048a20:	55                   	push   %ebp
 8048a21:	89 e5                	mov    %esp,%ebp
 8048a23:	53                   	push   %ebx
 8048a24:	83 ec 04             	sub    $0x4,%esp
 8048a27:	80 3d 84 c7 04 08 00 	cmpb   $0x0,0x804c784
 8048a2e:	75 3f                	jne    8048a6f <__do_global_dtors_aux+0x4f>
 8048a30:	a1 88 c7 04 08       	mov    0x804c788,%eax
 8048a35:	bb 20 bf 04 08       	mov    $0x804bf20,%ebx
 8048a3a:	81 eb 1c bf 04 08    	sub    $0x804bf1c,%ebx
 8048a40:	c1 fb 02             	sar    $0x2,%ebx
 8048a43:	83 eb 01             	sub    $0x1,%ebx
 8048a46:	39 d8                	cmp    %ebx,%eax
 8048a48:	73 1e                	jae    8048a68 <__do_global_dtors_aux+0x48>
 8048a4a:	8d b6 00 00 00 00    	lea    0x0(%esi),%esi
 8048a50:	83 c0 01             	add    $0x1,%eax
 8048a53:	a3 88 c7 04 08       	mov    %eax,0x804c788
 8048a58:	ff 14 85 1c bf 04 08 	call   *0x804bf1c(,%eax,4)
 8048a5f:	a1 88 c7 04 08       	mov    0x804c788,%eax
 8048a64:	39 d8                	cmp    %ebx,%eax
 8048a66:	72 e8                	jb     8048a50 <__do_global_dtors_aux+0x30>
 8048a68:	c6 05 84 c7 04 08 01 	movb   $0x1,0x804c784
 8048a6f:	83 c4 04             	add    $0x4,%esp
 8048a72:	5b                   	pop    %ebx
 8048a73:	5d                   	pop    %ebp
 8048a74:	c3                   	ret    
 8048a75:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
 8048a79:	8d bc 27 00 00 00 00 	lea    0x0(%edi,%eiz,1),%edi

08048a80 <frame_dummy>:
 8048a80:	55                   	push   %ebp
 8048a81:	89 e5                	mov    %esp,%ebp
 8048a83:	83 ec 18             	sub    $0x18,%esp
 8048a86:	a1 24 bf 04 08       	mov    0x804bf24,%eax
 8048a8b:	85 c0                	test   %eax,%eax
 8048a8d:	74 12                	je     8048aa1 <frame_dummy+0x21>
 8048a8f:	b8 00 00 00 00       	mov    $0x0,%eax
 8048a94:	85 c0                	test   %eax,%eax
 8048a96:	74 09                	je     8048aa1 <frame_dummy+0x21>
 8048a98:	c7 04 24 24 bf 04 08 	movl   $0x804bf24,(%esp)
 8048a9f:	ff d0                	call   *%eax
 8048aa1:	c9                   	leave  
 8048aa2:	c3                   	ret    
 8048aa3:	90                   	nop

08048aa4 <main>:
 8048aa4:	55                   	push   %ebp
 8048aa5:	89 e5                	mov    %esp,%ebp
 8048aa7:	53                   	push   %ebx
 8048aa8:	83 e4 f0             	and    $0xfffffff0,%esp
 8048aab:	83 ec 10             	sub    $0x10,%esp
 8048aae:	8b 45 08             	mov    0x8(%ebp),%eax
 8048ab1:	8b 5d 0c             	mov    0xc(%ebp),%ebx
 8048ab4:	83 f8 01             	cmp    $0x1,%eax
 8048ab7:	75 0c                	jne    8048ac5 <main+0x21>
 8048ab9:	a1 60 c7 04 08       	mov    0x804c760,%eax
 8048abe:	a3 90 c7 04 08       	mov    %eax,0x804c790
 8048ac3:	eb 74                	jmp    8048b39 <main+0x95>
 8048ac5:	83 f8 02             	cmp    $0x2,%eax
 8048ac8:	75 49                	jne    8048b13 <main+0x6f>
 8048aca:	c7 44 24 04 f2 9b 04 	movl   $0x8049bf2,0x4(%esp)
 8048ad1:	08 
 8048ad2:	8b 43 04             	mov    0x4(%ebx),%eax
 8048ad5:	89 04 24             	mov    %eax,(%esp)
 8048ad8:	e8 43 fe ff ff       	call   8048920 <fopen@plt>
 8048add:	a3 90 c7 04 08       	mov    %eax,0x804c790
 8048ae2:	85 c0                	test   %eax,%eax
 8048ae4:	75 53                	jne    8048b39 <main+0x95>
 8048ae6:	8b 43 04             	mov    0x4(%ebx),%eax
 8048ae9:	89 44 24 0c          	mov    %eax,0xc(%esp)
 8048aed:	8b 03                	mov    (%ebx),%eax
 8048aef:	89 44 24 08          	mov    %eax,0x8(%esp)
 8048af3:	c7 44 24 04 48 98 04 	movl   $0x8049848,0x4(%esp)
 8048afa:	08 
 8048afb:	c7 04 24 01 00 00 00 	movl   $0x1,(%esp)
 8048b02:	e8 39 fe ff ff       	call   8048940 <__printf_chk@plt>
 8048b07:	c7 04 24 08 00 00 00 	movl   $0x8,(%esp)
 8048b0e:	e8 cd fd ff ff       	call   80488e0 <exit@plt>
 8048b13:	8b 03                	mov    (%ebx),%eax
 8048b15:	89 44 24 08          	mov    %eax,0x8(%esp)
 8048b19:	c7 44 24 04 65 98 04 	movl   $0x8049865,0x4(%esp)
 8048b20:	08 
 8048b21:	c7 04 24 01 00 00 00 	movl   $0x1,(%esp)
 8048b28:	e8 13 fe ff ff       	call   8048940 <__printf_chk@plt>
 8048b2d:	c7 04 24 08 00 00 00 	movl   $0x8,(%esp)
 8048b34:	e8 a7 fd ff ff       	call   80488e0 <exit@plt>
 8048b39:	e8 0b 06 00 00       	call   8049149 <initialize_bomb>
 8048b3e:	c7 04 24 cc 98 04 08 	movl   $0x80498cc,(%esp)
 8048b45:	e8 56 fd ff ff       	call   80488a0 <puts@plt>
 8048b4a:	c7 04 24 08 99 04 08 	movl   $0x8049908,(%esp)
 8048b51:	e8 4a fd ff ff       	call   80488a0 <puts@plt>
 8048b56:	e8 47 0a 00 00       	call   80495a2 <read_line>
 8048b5b:	89 04 24             	mov    %eax,(%esp)
 8048b5e:	e8 ad 00 00 00       	call   8048c10 <phase_1>
 8048b63:	e8 50 0b 00 00       	call   80496b8 <phase_defused>
 8048b68:	c7 04 24 34 99 04 08 	movl   $0x8049934,(%esp)
 8048b6f:	e8 2c fd ff ff       	call   80488a0 <puts@plt>
 8048b74:	e8 29 0a 00 00       	call   80495a2 <read_line>
 8048b79:	89 04 24             	mov    %eax,(%esp)
 8048b7c:	e8 b3 00 00 00       	call   8048c34 <phase_2>
 8048b81:	e8 32 0b 00 00       	call   80496b8 <phase_defused>
 8048b86:	c7 04 24 7f 98 04 08 	movl   $0x804987f,(%esp)
 8048b8d:	e8 0e fd ff ff       	call   80488a0 <puts@plt>
 8048b92:	e8 0b 0a 00 00       	call   80495a2 <read_line>
 8048b97:	89 04 24             	mov    %eax,(%esp)
 8048b9a:	e8 df 00 00 00       	call   8048c7e <phase_3>
 8048b9f:	e8 14 0b 00 00       	call   80496b8 <phase_defused>
 8048ba4:	c7 04 24 9d 98 04 08 	movl   $0x804989d,(%esp)
 8048bab:	e8 f0 fc ff ff       	call   80488a0 <puts@plt>
 8048bb0:	e8 ed 09 00 00       	call   80495a2 <read_line>
 8048bb5:	89 04 24             	mov    %eax,(%esp)
 8048bb8:	e8 7f 01 00 00       	call   8048d3c <phase_4>
 8048bbd:	e8 f6 0a 00 00       	call   80496b8 <phase_defused>
 8048bc2:	c7 04 24 60 99 04 08 	movl   $0x8049960,(%esp)
 8048bc9:	e8 d2 fc ff ff       	call   80488a0 <puts@plt>
 8048bce:	e8 cf 09 00 00       	call   80495a2 <read_line>
 8048bd3:	89 04 24             	mov    %eax,(%esp)
 8048bd6:	e8 ad 01 00 00       	call   8048d88 <phase_5>
 8048bdb:	e8 d8 0a 00 00       	call   80496b8 <phase_defused>
 8048be0:	c7 04 24 ac 98 04 08 	movl   $0x80498ac,(%esp)
 8048be7:	e8 b4 fc ff ff       	call   80488a0 <puts@plt>
 8048bec:	e8 b1 09 00 00       	call   80495a2 <read_line>
 8048bf1:	89 04 24             	mov    %eax,(%esp)
 8048bf4:	e8 38 02 00 00       	call   8048e31 <phase_6>
 8048bf9:	e8 ba 0a 00 00       	call   80496b8 <phase_defused>
 8048bfe:	b8 00 00 00 00       	mov    $0x0,%eax
 8048c03:	8b 5d fc             	mov    -0x4(%ebp),%ebx
 8048c06:	c9                   	leave  
 8048c07:	c3                   	ret    
 8048c08:	90                   	nop
 8048c09:	90                   	nop
 8048c0a:	90                   	nop
 8048c0b:	90                   	nop
 8048c0c:	90                   	nop
 8048c0d:	90                   	nop
 8048c0e:	90                   	nop
 8048c0f:	90                   	nop

08048c10 <phase_1>:
 8048c10:	83 ec 1c             	sub    $0x1c,%esp
 8048c13:	c7 44 24 04 84 99 04 	movl   $0x8049984,0x4(%esp)
 8048c1a:	08 
 8048c1b:	8b 44 24 20          	mov    0x20(%esp),%eax
 8048c1f:	89 04 24             	mov    %eax,(%esp)
 8048c22:	e8 ad 03 00 00       	call   8048fd4 <strings_not_equal>
 8048c27:	85 c0                	test   %eax,%eax
 8048c29:	74 05                	je     8048c30 <phase_1+0x20>
 8048c2b:	e8 33 09 00 00       	call   8049563 <explode_bomb>
 8048c30:	83 c4 1c             	add    $0x1c,%esp
 8048c33:	c3                   	ret    

08048c34 <phase_2>:
 8048c34:	53                   	push   %ebx
 8048c35:	83 ec 38             	sub    $0x38,%esp
 8048c38:	8d 44 24 18          	lea    0x18(%esp),%eax
 8048c3c:	89 44 24 04          	mov    %eax,0x4(%esp)
 8048c40:	8b 44 24 40          	mov    0x40(%esp),%eax
 8048c44:	89 04 24             	mov    %eax,(%esp)
 8048c47:	e8 1c 0a 00 00       	call   8049668 <read_six_numbers>
 8048c4c:	83 7c 24 18 01       	cmpl   $0x1,0x18(%esp)
 8048c51:	74 05                	je     8048c58 <phase_2+0x24>
 8048c53:	e8 0b 09 00 00       	call   8049563 <explode_bomb>
 8048c58:	bb 01 00 00 00       	mov    $0x1,%ebx
 8048c5d:	89 d8                	mov    %ebx,%eax
 8048c5f:	83 c3 01             	add    $0x1,%ebx
 8048c62:	89 da                	mov    %ebx,%edx
 8048c64:	0f af 54 84 14       	imul   0x14(%esp,%eax,4),%edx
 8048c69:	39 54 84 18          	cmp    %edx,0x18(%esp,%eax,4)
 8048c6d:	74 05                	je     8048c74 <phase_2+0x40>
 8048c6f:	e8 ef 08 00 00       	call   8049563 <explode_bomb>
 8048c74:	83 fb 06             	cmp    $0x6,%ebx
 8048c77:	75 e4                	jne    8048c5d <phase_2+0x29>
 8048c79:	83 c4 38             	add    $0x38,%esp
 8048c7c:	5b                   	pop    %ebx
 8048c7d:	c3                   	ret    

08048c7e <phase_3>:
 8048c7e:	83 ec 2c             	sub    $0x2c,%esp
 8048c81:	8d 44 24 1c          	lea    0x1c(%esp),%eax
 8048c85:	89 44 24 0c          	mov    %eax,0xc(%esp)
 8048c89:	8d 44 24 18          	lea    0x18(%esp),%eax
 8048c8d:	89 44 24 08          	mov    %eax,0x8(%esp)
 8048c91:	c7 44 24 04 7a 9d 04 	movl   $0x8049d7a,0x4(%esp)
 8048c98:	08 
 8048c99:	8b 44 24 30          	mov    0x30(%esp),%eax
 8048c9d:	89 04 24             	mov    %eax,(%esp)
 8048ca0:	e8 6b fc ff ff       	call   8048910 <__isoc99_sscanf@plt>
 8048ca5:	83 f8 01             	cmp    $0x1,%eax
 8048ca8:	7f 05                	jg     8048caf <phase_3+0x31>
 8048caa:	e8 b4 08 00 00       	call   8049563 <explode_bomb>
 8048caf:	83 7c 24 18 07       	cmpl   $0x7,0x18(%esp)
 8048cb4:	77 3c                	ja     8048cf2 <phase_3+0x74>
 8048cb6:	8b 44 24 18          	mov    0x18(%esp),%eax
 8048cba:	ff 24 85 e0 99 04 08 	jmp    *0x80499e0(,%eax,4)
 8048cc1:	b8 ae 02 00 00       	mov    $0x2ae,%eax
 8048cc6:	eb 3b                	jmp    8048d03 <phase_3+0x85>
 8048cc8:	b8 5e 00 00 00       	mov    $0x5e,%eax
 8048ccd:	eb 34                	jmp    8048d03 <phase_3+0x85>
 8048ccf:	b8 b4 01 00 00       	mov    $0x1b4,%eax
 8048cd4:	eb 2d                	jmp    8048d03 <phase_3+0x85>
 8048cd6:	b8 15 01 00 00       	mov    $0x115,%eax
 8048cdb:	eb 26                	jmp    8048d03 <phase_3+0x85>
 8048cdd:	b8 60 00 00 00       	mov    $0x60,%eax
 8048ce2:	eb 1f                	jmp    8048d03 <phase_3+0x85>
 8048ce4:	b8 94 02 00 00       	mov    $0x294,%eax
 8048ce9:	eb 18                	jmp    8048d03 <phase_3+0x85>
 8048ceb:	b8 fc 01 00 00       	mov    $0x1fc,%eax
 8048cf0:	eb 11                	jmp    8048d03 <phase_3+0x85>
 8048cf2:	e8 6c 08 00 00       	call   8049563 <explode_bomb>
 8048cf7:	b8 00 00 00 00       	mov    $0x0,%eax
 8048cfc:	eb 05                	jmp    8048d03 <phase_3+0x85>
 8048cfe:	b8 b2 02 00 00       	mov    $0x2b2,%eax
 8048d03:	3b 44 24 1c          	cmp    0x1c(%esp),%eax
 8048d07:	74 05                	je     8048d0e <phase_3+0x90>
 8048d09:	e8 55 08 00 00       	call   8049563 <explode_bomb>
 8048d0e:	83 c4 2c             	add    $0x2c,%esp
 8048d11:	c3                   	ret    

08048d12 <func4>:
 8048d12:	83 ec 1c             	sub    $0x1c,%esp
 8048d15:	8b 54 24 20          	mov    0x20(%esp),%edx
 8048d19:	b8 01 00 00 00       	mov    $0x1,%eax
 8048d1e:	85 d2                	test   %edx,%edx
 8048d20:	7e 16                	jle    8048d38 <func4+0x26>
 8048d22:	83 ea 01             	sub    $0x1,%edx
 8048d25:	89 14 24             	mov    %edx,(%esp)
 8048d28:	e8 e5 ff ff ff       	call   8048d12 <func4>
 8048d2d:	8d 14 c5 00 00 00 00 	lea    0x0(,%eax,8),%edx
 8048d34:	29 c2                	sub    %eax,%edx
 8048d36:	89 d0                	mov    %edx,%eax
 8048d38:	83 c4 1c             	add    $0x1c,%esp
 8048d3b:	c3                   	ret    

08048d3c <phase_4>:
 8048d3c:	83 ec 2c             	sub    $0x2c,%esp
 8048d3f:	8d 44 24 1c          	lea    0x1c(%esp),%eax
 8048d43:	89 44 24 08          	mov    %eax,0x8(%esp)
 8048d47:	c7 44 24 04 7d 9d 04 	movl   $0x8049d7d,0x4(%esp)
 8048d4e:	08 
 8048d4f:	8b 44 24 30          	mov    0x30(%esp),%eax
 8048d53:	89 04 24             	mov    %eax,(%esp)
 8048d56:	e8 b5 fb ff ff       	call   8048910 <__isoc99_sscanf@plt>
 8048d5b:	83 f8 01             	cmp    $0x1,%eax
 8048d5e:	75 07                	jne    8048d67 <phase_4+0x2b>
 8048d60:	83 7c 24 1c 00       	cmpl   $0x0,0x1c(%esp)
 8048d65:	7f 05                	jg     8048d6c <phase_4+0x30>
 8048d67:	e8 f7 07 00 00       	call   8049563 <explode_bomb>
 8048d6c:	8b 44 24 1c          	mov    0x1c(%esp),%eax
 8048d70:	89 04 24             	mov    %eax,(%esp)
 8048d73:	e8 9a ff ff ff       	call   8048d12 <func4>
 8048d78:	3d 91 cb 01 00       	cmp    $0x1cb91,%eax
 8048d7d:	74 05                	je     8048d84 <phase_4+0x48>
 8048d7f:	e8 df 07 00 00       	call   8049563 <explode_bomb>
 8048d84:	83 c4 2c             	add    $0x2c,%esp
 8048d87:	c3                   	ret    

08048d88 <phase_5>:
 8048d88:	53                   	push   %ebx
 8048d89:	83 ec 18             	sub    $0x18,%esp
 8048d8c:	8b 5c 24 20          	mov    0x20(%esp),%ebx
 8048d90:	89 1c 24             	mov    %ebx,(%esp)
 8048d93:	e8 23 02 00 00       	call   8048fbb <string_length>
 8048d98:	83 f8 06             	cmp    $0x6,%eax
 8048d9b:	74 05                	je     8048da2 <phase_5+0x1a>
 8048d9d:	e8 c1 07 00 00       	call   8049563 <explode_bomb>
 8048da2:	ba 00 00 00 00       	mov    $0x0,%edx
 8048da7:	b8 00 00 00 00       	mov    $0x0,%eax
 8048dac:	0f be 0c 03          	movsbl (%ebx,%eax,1),%ecx
 8048db0:	83 e1 0f             	and    $0xf,%ecx
 8048db3:	03 14 8d 00 9a 04 08 	add    0x8049a00(,%ecx,4),%edx
 8048dba:	83 c0 01             	add    $0x1,%eax
 8048dbd:	83 f8 06             	cmp    $0x6,%eax
 8048dc0:	75 ea                	jne    8048dac <phase_5+0x24>
 8048dc2:	83 fa 1e             	cmp    $0x1e,%edx
 8048dc5:	74 05                	je     8048dcc <phase_5+0x44>
 8048dc7:	e8 97 07 00 00       	call   8049563 <explode_bomb>
 8048dcc:	83 c4 18             	add    $0x18,%esp
 8048dcf:	5b                   	pop    %ebx
 8048dd0:	c3                   	ret    

08048dd1 <fun6>:
 8048dd1:	57                   	push   %edi
 8048dd2:	56                   	push   %esi
 8048dd3:	53                   	push   %ebx
 8048dd4:	8b 7c 24 10          	mov    0x10(%esp),%edi
 8048dd8:	8b 77 08             	mov    0x8(%edi),%esi
 8048ddb:	c7 47 08 00 00 00 00 	movl   $0x0,0x8(%edi)
 8048de2:	89 f8                	mov    %edi,%eax
 8048de4:	85 f6                	test   %esi,%esi
 8048de6:	75 33                	jne    8048e1b <fun6+0x4a>
 8048de8:	eb 43                	jmp    8048e2d <fun6+0x5c>
 8048dea:	89 d1                	mov    %edx,%ecx
 8048dec:	8b 51 08             	mov    0x8(%ecx),%edx
 8048def:	85 d2                	test   %edx,%edx
 8048df1:	74 08                	je     8048dfb <fun6+0x2a>
 8048df3:	39 1a                	cmp    %ebx,(%edx)
 8048df5:	7f f3                	jg     8048dea <fun6+0x19>
 8048df7:	89 cf                	mov    %ecx,%edi
 8048df9:	eb 02                	jmp    8048dfd <fun6+0x2c>
 8048dfb:	89 cf                	mov    %ecx,%edi
 8048dfd:	39 d7                	cmp    %edx,%edi
 8048dff:	90                   	nop
 8048e00:	74 05                	je     8048e07 <fun6+0x36>
 8048e02:	89 77 08             	mov    %esi,0x8(%edi)
 8048e05:	eb 02                	jmp    8048e09 <fun6+0x38>
 8048e07:	89 f0                	mov    %esi,%eax
 8048e09:	8b 4e 08             	mov    0x8(%esi),%ecx
 8048e0c:	89 56 08             	mov    %edx,0x8(%esi)
 8048e0f:	85 c9                	test   %ecx,%ecx
 8048e11:	74 1a                	je     8048e2d <fun6+0x5c>
 8048e13:	89 ce                	mov    %ecx,%esi
 8048e15:	89 c1                	mov    %eax,%ecx
 8048e17:	89 c7                	mov    %eax,%edi
 8048e19:	eb 04                	jmp    8048e1f <fun6+0x4e>
 8048e1b:	89 f8                	mov    %edi,%eax
 8048e1d:	89 f9                	mov    %edi,%ecx
 8048e1f:	89 ca                	mov    %ecx,%edx
 8048e21:	85 c9                	test   %ecx,%ecx
 8048e23:	74 d8                	je     8048dfd <fun6+0x2c>
 8048e25:	8b 1e                	mov    (%esi),%ebx
 8048e27:	39 19                	cmp    %ebx,(%ecx)
 8048e29:	7f c1                	jg     8048dec <fun6+0x1b>
 8048e2b:	eb d0                	jmp    8048dfd <fun6+0x2c>
 8048e2d:	5b                   	pop    %ebx
 8048e2e:	5e                   	pop    %esi
 8048e2f:	5f                   	pop    %edi
 8048e30:	c3                   	ret    

08048e31 <phase_6>:
 8048e31:	83 ec 1c             	sub    $0x1c,%esp
 8048e34:	c7 44 24 08 0a 00 00 	movl   $0xa,0x8(%esp)
 8048e3b:	00 
 8048e3c:	c7 44 24 04 00 00 00 	movl   $0x0,0x4(%esp)
 8048e43:	00 
 8048e44:	8b 44 24 20          	mov    0x20(%esp),%eax
 8048e48:	89 04 24             	mov    %eax,(%esp)
 8048e4b:	e8 50 fb ff ff       	call   80489a0 <strtol@plt>
 8048e50:	a3 74 c1 04 08       	mov    %eax,0x804c174
 8048e55:	c7 04 24 74 c1 04 08 	movl   $0x804c174,(%esp)
 8048e5c:	e8 70 ff ff ff       	call   8048dd1 <fun6>
 8048e61:	8b 40 08             	mov    0x8(%eax),%eax
 8048e64:	8b 40 08             	mov    0x8(%eax),%eax
 8048e67:	8b 40 08             	mov    0x8(%eax),%eax
 8048e6a:	8b 15 74 c1 04 08    	mov    0x804c174,%edx
 8048e70:	39 10                	cmp    %edx,(%eax)
 8048e72:	74 05                	je     8048e79 <phase_6+0x48>
 8048e74:	e8 ea 06 00 00       	call   8049563 <explode_bomb>
 8048e79:	83 c4 1c             	add    $0x1c,%esp
 8048e7c:	c3                   	ret    

08048e7d <fun7>:
 8048e7d:	53                   	push   %ebx
 8048e7e:	83 ec 18             	sub    $0x18,%esp
 8048e81:	8b 54 24 20          	mov    0x20(%esp),%edx
 8048e85:	8b 4c 24 24          	mov    0x24(%esp),%ecx
 8048e89:	85 d2                	test   %edx,%edx
 8048e8b:	74 37                	je     8048ec4 <fun7+0x47>
 8048e8d:	8b 1a                	mov    (%edx),%ebx
 8048e8f:	39 cb                	cmp    %ecx,%ebx
 8048e91:	7e 13                	jle    8048ea6 <fun7+0x29>
 8048e93:	89 4c 24 04          	mov    %ecx,0x4(%esp)
 8048e97:	8b 42 04             	mov    0x4(%edx),%eax
 8048e9a:	89 04 24             	mov    %eax,(%esp)
 8048e9d:	e8 db ff ff ff       	call   8048e7d <fun7>
 8048ea2:	01 c0                	add    %eax,%eax
 8048ea4:	eb 23                	jmp    8048ec9 <fun7+0x4c>
 8048ea6:	b8 00 00 00 00       	mov    $0x0,%eax
 8048eab:	39 cb                	cmp    %ecx,%ebx
 8048ead:	74 1a                	je     8048ec9 <fun7+0x4c>
 8048eaf:	89 4c 24 04          	mov    %ecx,0x4(%esp)
 8048eb3:	8b 42 08             	mov    0x8(%edx),%eax
 8048eb6:	89 04 24             	mov    %eax,(%esp)
 8048eb9:	e8 bf ff ff ff       	call   8048e7d <fun7>
 8048ebe:	8d 44 00 01          	lea    0x1(%eax,%eax,1),%eax
 8048ec2:	eb 05                	jmp    8048ec9 <fun7+0x4c>
 8048ec4:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 8048ec9:	83 c4 18             	add    $0x18,%esp
 8048ecc:	5b                   	pop    %ebx
 8048ecd:	c3                   	ret    

08048ece <secret_phase>:
 8048ece:	53                   	push   %ebx
 8048ecf:	83 ec 18             	sub    $0x18,%esp
 8048ed2:	e8 cb 06 00 00       	call   80495a2 <read_line>
 8048ed7:	c7 44 24 08 0a 00 00 	movl   $0xa,0x8(%esp)
 8048ede:	00 
 8048edf:	c7 44 24 04 00 00 00 	movl   $0x0,0x4(%esp)
 8048ee6:	00 
 8048ee7:	89 04 24             	mov    %eax,(%esp)
 8048eea:	e8 b1 fa ff ff       	call   80489a0 <strtol@plt>
 8048eef:	89 c3                	mov    %eax,%ebx
 8048ef1:	8d 40 ff             	lea    -0x1(%eax),%eax
 8048ef4:	3d e8 03 00 00       	cmp    $0x3e8,%eax
 8048ef9:	76 05                	jbe    8048f00 <secret_phase+0x32>
 8048efb:	e8 63 06 00 00       	call   8049563 <explode_bomb>
 8048f00:	89 5c 24 04          	mov    %ebx,0x4(%esp)
 8048f04:	c7 04 24 c0 c0 04 08 	movl   $0x804c0c0,(%esp)
 8048f0b:	e8 6d ff ff ff       	call   8048e7d <fun7>
 8048f10:	83 f8 01             	cmp    $0x1,%eax
 8048f13:	74 05                	je     8048f1a <secret_phase+0x4c>
 8048f15:	e8 49 06 00 00       	call   8049563 <explode_bomb>
 8048f1a:	c7 04 24 b0 99 04 08 	movl   $0x80499b0,(%esp)
 8048f21:	e8 7a f9 ff ff       	call   80488a0 <puts@plt>
 8048f26:	e8 8d 07 00 00       	call   80496b8 <phase_defused>
 8048f2b:	83 c4 18             	add    $0x18,%esp
 8048f2e:	5b                   	pop    %ebx
 8048f2f:	c3                   	ret    

08048f30 <sig_handler>:
 8048f30:	83 ec 1c             	sub    $0x1c,%esp
 8048f33:	c7 04 24 40 9a 04 08 	movl   $0x8049a40,(%esp)
 8048f3a:	e8 61 f9 ff ff       	call   80488a0 <puts@plt>
 8048f3f:	c7 04 24 03 00 00 00 	movl   $0x3,(%esp)
 8048f46:	e8 f5 f8 ff ff       	call   8048840 <sleep@plt>
 8048f4b:	c7 44 24 04 6c 9b 04 	movl   $0x8049b6c,0x4(%esp)
 8048f52:	08 
 8048f53:	c7 04 24 01 00 00 00 	movl   $0x1,(%esp)
 8048f5a:	e8 e1 f9 ff ff       	call   8048940 <__printf_chk@plt>
 8048f5f:	a1 80 c7 04 08       	mov    0x804c780,%eax
 8048f64:	89 04 24             	mov    %eax,(%esp)
 8048f67:	e8 84 f8 ff ff       	call   80487f0 <fflush@plt>
 8048f6c:	c7 04 24 01 00 00 00 	movl   $0x1,(%esp)
 8048f73:	e8 c8 f8 ff ff       	call   8048840 <sleep@plt>
 8048f78:	c7 04 24 74 9b 04 08 	movl   $0x8049b74,(%esp)
 8048f7f:	e8 1c f9 ff ff       	call   80488a0 <puts@plt>
 8048f84:	c7 04 24 10 00 00 00 	movl   $0x10,(%esp)
 8048f8b:	e8 50 f9 ff ff       	call   80488e0 <exit@plt>

08048f90 <invalid_phase>:
 8048f90:	83 ec 1c             	sub    $0x1c,%esp
 8048f93:	8b 44 24 20          	mov    0x20(%esp),%eax
 8048f97:	89 44 24 08          	mov    %eax,0x8(%esp)
 8048f9b:	c7 44 24 04 7c 9b 04 	movl   $0x8049b7c,0x4(%esp)
 8048fa2:	08 
 8048fa3:	c7 04 24 01 00 00 00 	movl   $0x1,(%esp)
 8048faa:	e8 91 f9 ff ff       	call   8048940 <__printf_chk@plt>
 8048faf:	c7 04 24 08 00 00 00 	movl   $0x8,(%esp)
 8048fb6:	e8 25 f9 ff ff       	call   80488e0 <exit@plt>

08048fbb <string_length>:
 8048fbb:	8b 54 24 04          	mov    0x4(%esp),%edx
 8048fbf:	b8 00 00 00 00       	mov    $0x0,%eax
 8048fc4:	80 3a 00             	cmpb   $0x0,(%edx)
 8048fc7:	74 09                	je     8048fd2 <string_length+0x17>
 8048fc9:	83 c0 01             	add    $0x1,%eax
 8048fcc:	80 3c 02 00          	cmpb   $0x0,(%edx,%eax,1)
 8048fd0:	75 f7                	jne    8048fc9 <string_length+0xe>
 8048fd2:	f3 c3                	repz ret 

08048fd4 <strings_not_equal>:
 8048fd4:	83 ec 10             	sub    $0x10,%esp
 8048fd7:	89 5c 24 04          	mov    %ebx,0x4(%esp)
 8048fdb:	89 74 24 08          	mov    %esi,0x8(%esp)
 8048fdf:	89 7c 24 0c          	mov    %edi,0xc(%esp)
 8048fe3:	8b 5c 24 14          	mov    0x14(%esp),%ebx
 8048fe7:	8b 74 24 18          	mov    0x18(%esp),%esi
 8048feb:	89 1c 24             	mov    %ebx,(%esp)
 8048fee:	e8 c8 ff ff ff       	call   8048fbb <string_length>
 8048ff3:	89 c7                	mov    %eax,%edi
 8048ff5:	89 34 24             	mov    %esi,(%esp)
 8048ff8:	e8 be ff ff ff       	call   8048fbb <string_length>
 8048ffd:	ba 01 00 00 00       	mov    $0x1,%edx
 8049002:	39 c7                	cmp    %eax,%edi
 8049004:	75 33                	jne    8049039 <strings_not_equal+0x65>
 8049006:	0f b6 03             	movzbl (%ebx),%eax
 8049009:	b2 00                	mov    $0x0,%dl
 804900b:	84 c0                	test   %al,%al
 804900d:	74 2a                	je     8049039 <strings_not_equal+0x65>
 804900f:	b2 01                	mov    $0x1,%dl
 8049011:	3a 06                	cmp    (%esi),%al
 8049013:	75 24                	jne    8049039 <strings_not_equal+0x65>
 8049015:	b8 00 00 00 00       	mov    $0x0,%eax
 804901a:	eb 08                	jmp    8049024 <strings_not_equal+0x50>
 804901c:	83 c0 01             	add    $0x1,%eax
 804901f:	3a 14 06             	cmp    (%esi,%eax,1),%dl
 8049022:	75 10                	jne    8049034 <strings_not_equal+0x60>
 8049024:	0f b6 54 03 01       	movzbl 0x1(%ebx,%eax,1),%edx
 8049029:	84 d2                	test   %dl,%dl
 804902b:	75 ef                	jne    804901c <strings_not_equal+0x48>
 804902d:	ba 00 00 00 00       	mov    $0x0,%edx
 8049032:	eb 05                	jmp    8049039 <strings_not_equal+0x65>
 8049034:	ba 01 00 00 00       	mov    $0x1,%edx
 8049039:	89 d0                	mov    %edx,%eax
 804903b:	8b 5c 24 04          	mov    0x4(%esp),%ebx
 804903f:	8b 74 24 08          	mov    0x8(%esp),%esi
 8049043:	8b 7c 24 0c          	mov    0xc(%esp),%edi
 8049047:	83 c4 10             	add    $0x10,%esp
 804904a:	c3                   	ret    

0804904b <open_clientfd>:
 804904b:	56                   	push   %esi
 804904c:	53                   	push   %ebx
 804904d:	83 ec 34             	sub    $0x34,%esp
 8049050:	8b 74 24 40          	mov    0x40(%esp),%esi
 8049054:	65 a1 14 00 00 00    	mov    %gs:0x14,%eax
 804905a:	89 44 24 2c          	mov    %eax,0x2c(%esp)
 804905e:	31 c0                	xor    %eax,%eax
 8049060:	c7 44 24 08 00 00 00 	movl   $0x0,0x8(%esp)
 8049067:	00 
 8049068:	c7 44 24 04 01 00 00 	movl   $0x1,0x4(%esp)
 804906f:	00 
 8049070:	c7 04 24 02 00 00 00 	movl   $0x2,(%esp)
 8049077:	e8 f4 f8 ff ff       	call   8048970 <socket@plt>
 804907c:	89 c3                	mov    %eax,%ebx
 804907e:	85 c0                	test   %eax,%eax
 8049080:	79 18                	jns    804909a <open_clientfd+0x4f>
 8049082:	c7 04 24 8d 9b 04 08 	movl   $0x8049b8d,(%esp)
 8049089:	e8 12 f8 ff ff       	call   80488a0 <puts@plt>
 804908e:	c7 04 24 08 00 00 00 	movl   $0x8,(%esp)
 8049095:	e8 46 f8 ff ff       	call   80488e0 <exit@plt>
 804909a:	89 34 24             	mov    %esi,(%esp)
 804909d:	e8 ee f8 ff ff       	call   8048990 <gethostbyname@plt>
 80490a2:	85 c0                	test   %eax,%eax
 80490a4:	75 18                	jne    80490be <open_clientfd+0x73>
 80490a6:	c7 04 24 9b 9b 04 08 	movl   $0x8049b9b,(%esp)
 80490ad:	e8 ee f7 ff ff       	call   80488a0 <puts@plt>
 80490b2:	c7 04 24 08 00 00 00 	movl   $0x8,(%esp)
 80490b9:	e8 22 f8 ff ff       	call   80488e0 <exit@plt>
 80490be:	8d 74 24 1c          	lea    0x1c(%esp),%esi
 80490c2:	c7 44 24 1c 00 00 00 	movl   $0x0,0x1c(%esp)
 80490c9:	00 
 80490ca:	c7 44 24 20 00 00 00 	movl   $0x0,0x20(%esp)
 80490d1:	00 
 80490d2:	c7 44 24 24 00 00 00 	movl   $0x0,0x24(%esp)
 80490d9:	00 
 80490da:	c7 44 24 28 00 00 00 	movl   $0x0,0x28(%esp)
 80490e1:	00 
 80490e2:	66 c7 44 24 1c 02 00 	movw   $0x2,0x1c(%esp)
 80490e9:	c7 44 24 0c 0c 00 00 	movl   $0xc,0xc(%esp)
 80490f0:	00 
 80490f1:	8b 50 0c             	mov    0xc(%eax),%edx
 80490f4:	89 54 24 08          	mov    %edx,0x8(%esp)
 80490f8:	8b 40 10             	mov    0x10(%eax),%eax
 80490fb:	8b 00                	mov    (%eax),%eax
 80490fd:	89 44 24 04          	mov    %eax,0x4(%esp)
 8049101:	8d 44 24 20          	lea    0x20(%esp),%eax
 8049105:	89 04 24             	mov    %eax,(%esp)
 8049108:	e8 b3 f7 ff ff       	call   80488c0 <__memmove_chk@plt>
 804910d:	0f b7 44 24 44       	movzwl 0x44(%esp),%eax
 8049112:	66 c1 c8 08          	ror    $0x8,%ax
 8049116:	66 89 44 24 1e       	mov    %ax,0x1e(%esp)
 804911b:	c7 44 24 08 10 00 00 	movl   $0x10,0x8(%esp)
 8049122:	00 
 8049123:	89 74 24 04          	mov    %esi,0x4(%esp)
 8049127:	89 1c 24             	mov    %ebx,(%esp)
 804912a:	e8 81 f8 ff ff       	call   80489b0 <connect@plt>
 804912f:	89 d8                	mov    %ebx,%eax
 8049131:	8b 54 24 2c          	mov    0x2c(%esp),%edx
 8049135:	65 33 15 14 00 00 00 	xor    %gs:0x14,%edx
 804913c:	74 05                	je     8049143 <open_clientfd+0xf8>
 804913e:	e8 0d f7 ff ff       	call   8048850 <__stack_chk_fail@plt>
 8049143:	83 c4 34             	add    $0x34,%esp
 8049146:	5b                   	pop    %ebx
 8049147:	5e                   	pop    %esi
 8049148:	c3                   	ret    

08049149 <initialize_bomb>:
 8049149:	56                   	push   %esi
 804914a:	53                   	push   %ebx
 804914b:	83 ec 64             	sub    $0x64,%esp
 804914e:	65 a1 14 00 00 00    	mov    %gs:0x14,%eax
 8049154:	89 44 24 5c          	mov    %eax,0x5c(%esp)
 8049158:	31 c0                	xor    %eax,%eax
 804915a:	c7 44 24 04 30 8f 04 	movl   $0x8048f30,0x4(%esp)
 8049161:	08 
 8049162:	c7 04 24 02 00 00 00 	movl   $0x2,(%esp)
 8049169:	e8 c2 f6 ff ff       	call   8048830 <signal@plt>
 804916e:	c7 44 24 04 40 00 00 	movl   $0x40,0x4(%esp)
 8049175:	00 
 8049176:	8d 44 24 1c          	lea    0x1c(%esp),%eax
 804917a:	89 04 24             	mov    %eax,(%esp)
 804917d:	e8 fe f6 ff ff       	call   8048880 <gethostname@plt>
 8049182:	85 c0                	test   %eax,%eax
 8049184:	75 14                	jne    804919a <initialize_bomb+0x51>
 8049186:	a1 20 c6 04 08       	mov    0x804c620,%eax
 804918b:	bb 00 00 00 00       	mov    $0x0,%ebx
 8049190:	8d 74 24 1c          	lea    0x1c(%esp),%esi
 8049194:	85 c0                	test   %eax,%eax
 8049196:	75 1a                	jne    80491b2 <initialize_bomb+0x69>
 8049198:	eb 63                	jmp    80491fd <initialize_bomb+0xb4>
 804919a:	c7 04 24 a9 9b 04 08 	movl   $0x8049ba9,(%esp)
 80491a1:	e8 fa f6 ff ff       	call   80488a0 <puts@plt>
 80491a6:	c7 04 24 08 00 00 00 	movl   $0x8,(%esp)
 80491ad:	e8 2e f7 ff ff       	call   80488e0 <exit@plt>
 80491b2:	89 74 24 04          	mov    %esi,0x4(%esp)
 80491b6:	89 04 24             	mov    %eax,(%esp)
 80491b9:	e8 42 f7 ff ff       	call   8048900 <strcasecmp@plt>
 80491be:	85 c0                	test   %eax,%eax
 80491c0:	74 10                	je     80491d2 <initialize_bomb+0x89>
 80491c2:	83 c3 01             	add    $0x1,%ebx
 80491c5:	8b 04 9d 20 c6 04 08 	mov    0x804c620(,%ebx,4),%eax
 80491cc:	85 c0                	test   %eax,%eax
 80491ce:	75 e2                	jne    80491b2 <initialize_bomb+0x69>
 80491d0:	eb 2b                	jmp    80491fd <initialize_bomb+0xb4>
 80491d2:	c7 44 24 04 50 00 00 	movl   $0x50,0x4(%esp)
 80491d9:	00 
 80491da:	c7 04 24 b6 9b 04 08 	movl   $0x8049bb6,(%esp)
 80491e1:	e8 65 fe ff ff       	call   804904b <open_clientfd>
 80491e6:	89 04 24             	mov    %eax,(%esp)
 80491e9:	e8 d2 f7 ff ff       	call   80489c0 <close@plt>
 80491ee:	8b 44 24 5c          	mov    0x5c(%esp),%eax
 80491f2:	65 33 05 14 00 00 00 	xor    %gs:0x14,%eax
 80491f9:	74 1f                	je     804921a <initialize_bomb+0xd1>
 80491fb:	eb 18                	jmp    8049215 <initialize_bomb+0xcc>
 80491fd:	c7 04 24 c1 9b 04 08 	movl   $0x8049bc1,(%esp)
 8049204:	e8 97 f6 ff ff       	call   80488a0 <puts@plt>
 8049209:	c7 04 24 08 00 00 00 	movl   $0x8,(%esp)
 8049210:	e8 cb f6 ff ff       	call   80488e0 <exit@plt>
 8049215:	e8 36 f6 ff ff       	call   8048850 <__stack_chk_fail@plt>
 804921a:	83 c4 64             	add    $0x64,%esp
 804921d:	5b                   	pop    %ebx
 804921e:	5e                   	pop    %esi
 804921f:	c3                   	ret    

08049220 <blank_line>:
 8049220:	56                   	push   %esi
 8049221:	53                   	push   %ebx
 8049222:	83 ec 04             	sub    $0x4,%esp
 8049225:	8b 74 24 10          	mov    0x10(%esp),%esi
 8049229:	eb 14                	jmp    804923f <blank_line+0x1f>
 804922b:	e8 a0 f7 ff ff       	call   80489d0 <__ctype_b_loc@plt>
 8049230:	83 c6 01             	add    $0x1,%esi
 8049233:	0f be db             	movsbl %bl,%ebx
 8049236:	8b 00                	mov    (%eax),%eax
 8049238:	f6 44 58 01 20       	testb  $0x20,0x1(%eax,%ebx,2)
 804923d:	74 0e                	je     804924d <blank_line+0x2d>
 804923f:	0f b6 1e             	movzbl (%esi),%ebx
 8049242:	84 db                	test   %bl,%bl
 8049244:	75 e5                	jne    804922b <blank_line+0xb>
 8049246:	b8 01 00 00 00       	mov    $0x1,%eax
 804924b:	eb 05                	jmp    8049252 <blank_line+0x32>
 804924d:	b8 00 00 00 00       	mov    $0x0,%eax
 8049252:	83 c4 04             	add    $0x4,%esp
 8049255:	5b                   	pop    %ebx
 8049256:	5e                   	pop    %esi
 8049257:	c3                   	ret    

08049258 <skip>:
 8049258:	53                   	push   %ebx
 8049259:	83 ec 18             	sub    $0x18,%esp
 804925c:	a1 90 c7 04 08       	mov    0x804c790,%eax
 8049261:	89 44 24 08          	mov    %eax,0x8(%esp)
 8049265:	c7 44 24 04 50 00 00 	movl   $0x50,0x4(%esp)
 804926c:	00 
 804926d:	a1 8c c7 04 08       	mov    0x804c78c,%eax
 8049272:	8d 04 80             	lea    (%eax,%eax,4),%eax
 8049275:	c1 e0 04             	shl    $0x4,%eax
 8049278:	05 a0 c7 04 08       	add    $0x804c7a0,%eax
 804927d:	89 04 24             	mov    %eax,(%esp)
 8049280:	e8 8b f5 ff ff       	call   8048810 <fgets@plt>
 8049285:	89 c3                	mov    %eax,%ebx
 8049287:	85 c0                	test   %eax,%eax
 8049289:	74 0c                	je     8049297 <skip+0x3f>
 804928b:	89 04 24             	mov    %eax,(%esp)
 804928e:	e8 8d ff ff ff       	call   8049220 <blank_line>
 8049293:	85 c0                	test   %eax,%eax
 8049295:	75 c5                	jne    804925c <skip+0x4>
 8049297:	89 d8                	mov    %ebx,%eax
 8049299:	83 c4 18             	add    $0x18,%esp
 804929c:	5b                   	pop    %ebx
 804929d:	c3                   	ret    

0804929e <send_msg>:
 804929e:	55                   	push   %ebp
 804929f:	57                   	push   %edi
 80492a0:	56                   	push   %esi
 80492a1:	53                   	push   %ebx
 80492a2:	81 ec 9c 00 00 00    	sub    $0x9c,%esp
 80492a8:	8b 9c 24 b0 00 00 00 	mov    0xb0(%esp),%ebx
 80492af:	65 a1 14 00 00 00    	mov    %gs:0x14,%eax
 80492b5:	89 84 24 8c 00 00 00 	mov    %eax,0x8c(%esp)
 80492bc:	31 c0                	xor    %eax,%eax
 80492be:	c7 04 24 00 00 00 00 	movl   $0x0,(%esp)
 80492c5:	e8 36 f5 ff ff       	call   8048800 <dup@plt>
 80492ca:	89 44 24 2c          	mov    %eax,0x2c(%esp)
 80492ce:	83 f8 ff             	cmp    $0xffffffff,%eax
 80492d1:	75 18                	jne    80492eb <send_msg+0x4d>
 80492d3:	c7 04 24 e0 9b 04 08 	movl   $0x8049be0,(%esp)
 80492da:	e8 c1 f5 ff ff       	call   80488a0 <puts@plt>
 80492df:	c7 04 24 08 00 00 00 	movl   $0x8,(%esp)
 80492e6:	e8 f5 f5 ff ff       	call   80488e0 <exit@plt>
 80492eb:	c7 04 24 00 00 00 00 	movl   $0x0,(%esp)
 80492f2:	e8 c9 f6 ff ff       	call   80489c0 <close@plt>
 80492f7:	83 f8 ff             	cmp    $0xffffffff,%eax
 80492fa:	75 18                	jne    8049314 <send_msg+0x76>
 80492fc:	c7 04 24 f4 9b 04 08 	movl   $0x8049bf4,(%esp)
 8049303:	e8 98 f5 ff ff       	call   80488a0 <puts@plt>
 8049308:	c7 04 24 08 00 00 00 	movl   $0x8,(%esp)
 804930f:	e8 cc f5 ff ff       	call   80488e0 <exit@plt>
 8049314:	e8 47 f6 ff ff       	call   8048960 <tmpfile@plt>
 8049319:	89 44 24 28          	mov    %eax,0x28(%esp)
 804931d:	85 c0                	test   %eax,%eax
 804931f:	75 18                	jne    8049339 <send_msg+0x9b>
 8049321:	c7 04 24 07 9c 04 08 	movl   $0x8049c07,(%esp)
 8049328:	e8 73 f5 ff ff       	call   80488a0 <puts@plt>
 804932d:	c7 04 24 08 00 00 00 	movl   $0x8,(%esp)
 8049334:	e8 a7 f5 ff ff       	call   80488e0 <exit@plt>
 8049339:	8b 7c 24 28          	mov    0x28(%esp),%edi
 804933d:	89 7c 24 0c          	mov    %edi,0xc(%esp)
 8049341:	c7 44 24 08 1b 00 00 	movl   $0x1b,0x8(%esp)
 8049348:	00 
 8049349:	c7 44 24 04 01 00 00 	movl   $0x1,0x4(%esp)
 8049350:	00 
 8049351:	c7 04 24 1c 9c 04 08 	movl   $0x8049c1c,(%esp)
 8049358:	e8 13 f5 ff ff       	call   8048870 <fwrite@plt>
 804935d:	8b 44 24 28          	mov    0x28(%esp),%eax
 8049361:	89 44 24 04          	mov    %eax,0x4(%esp)
 8049365:	c7 04 24 0a 00 00 00 	movl   $0xa,(%esp)
 804936c:	e8 df f5 ff ff       	call   8048950 <fputc@plt>
 8049371:	c7 04 24 00 00 00 00 	movl   $0x0,(%esp)
 8049378:	e8 63 f4 ff ff       	call   80487e0 <cuserid@plt>
 804937d:	85 c0                	test   %eax,%eax
 804937f:	75 16                	jne    8049397 <send_msg+0xf9>
 8049381:	c7 44 24 3c 6e 6f 62 	movl   $0x6f626f6e,0x3c(%esp)
 8049388:	6f 
 8049389:	66 c7 44 24 40 64 79 	movw   $0x7964,0x40(%esp)
 8049390:	c6 44 24 42 00       	movb   $0x0,0x42(%esp)
 8049395:	eb 18                	jmp    80493af <send_msg+0x111>
 8049397:	c7 44 24 08 50 00 00 	movl   $0x50,0x8(%esp)
 804939e:	00 
 804939f:	89 44 24 04          	mov    %eax,0x4(%esp)
 80493a3:	8d 44 24 3c          	lea    0x3c(%esp),%eax
 80493a7:	89 04 24             	mov    %eax,(%esp)
 80493aa:	e8 81 f5 ff ff       	call   8048930 <__strcpy_chk@plt>
 80493af:	85 db                	test   %ebx,%ebx
 80493b1:	b8 cf 9b 04 08       	mov    $0x8049bcf,%eax
 80493b6:	ba d7 9b 04 08       	mov    $0x8049bd7,%edx
 80493bb:	0f 44 c2             	cmove  %edx,%eax
 80493be:	8b 15 8c c7 04 08    	mov    0x804c78c,%edx
 80493c4:	89 54 24 1c          	mov    %edx,0x1c(%esp)
 80493c8:	89 44 24 18          	mov    %eax,0x18(%esp)
 80493cc:	8d 44 24 3c          	lea    0x3c(%esp),%eax
 80493d0:	89 44 24 14          	mov    %eax,0x14(%esp)
 80493d4:	a1 00 c6 04 08       	mov    0x804c600,%eax
 80493d9:	89 44 24 10          	mov    %eax,0x10(%esp)
 80493dd:	c7 44 24 0c 00 c2 04 	movl   $0x804c200,0xc(%esp)
 80493e4:	08 
 80493e5:	c7 44 24 08 38 9c 04 	movl   $0x8049c38,0x8(%esp)
 80493ec:	08 
 80493ed:	c7 44 24 04 01 00 00 	movl   $0x1,0x4(%esp)
 80493f4:	00 
 80493f5:	8b 44 24 28          	mov    0x28(%esp),%eax
 80493f9:	89 04 24             	mov    %eax,(%esp)
 80493fc:	e8 7f f5 ff ff       	call   8048980 <__fprintf_chk@plt>
 8049401:	83 3d 8c c7 04 08 00 	cmpl   $0x0,0x804c78c
 8049408:	7e 51                	jle    804945b <send_msg+0x1bd>
 804940a:	be a0 c7 04 08       	mov    $0x804c7a0,%esi
 804940f:	bb 00 00 00 00       	mov    $0x0,%ebx
 8049414:	8d 6c 24 3c          	lea    0x3c(%esp),%ebp
 8049418:	83 c3 01             	add    $0x1,%ebx
 804941b:	89 74 24 1c          	mov    %esi,0x1c(%esp)
 804941f:	89 5c 24 18          	mov    %ebx,0x18(%esp)
 8049423:	89 6c 24 14          	mov    %ebp,0x14(%esp)
 8049427:	a1 00 c6 04 08       	mov    0x804c600,%eax
 804942c:	89 44 24 10          	mov    %eax,0x10(%esp)
 8049430:	c7 44 24 0c 00 c2 04 	movl   $0x804c200,0xc(%esp)
 8049437:	08 
 8049438:	c7 44 24 08 54 9c 04 	movl   $0x8049c54,0x8(%esp)
 804943f:	08 
 8049440:	c7 44 24 04 01 00 00 	movl   $0x1,0x4(%esp)
 8049447:	00 
 8049448:	89 3c 24             	mov    %edi,(%esp)
 804944b:	e8 30 f5 ff ff       	call   8048980 <__fprintf_chk@plt>
 8049450:	83 c6 50             	add    $0x50,%esi
 8049453:	39 1d 8c c7 04 08    	cmp    %ebx,0x804c78c
 8049459:	7f bd                	jg     8049418 <send_msg+0x17a>
 804945b:	8b 44 24 28          	mov    0x28(%esp),%eax
 804945f:	89 04 24             	mov    %eax,(%esp)
 8049462:	e8 f9 f3 ff ff       	call   8048860 <rewind@plt>
 8049467:	c7 44 24 18 70 9c 04 	movl   $0x8049c70,0x18(%esp)
 804946e:	08 
 804946f:	c7 44 24 14 80 9c 04 	movl   $0x8049c80,0x14(%esp)
 8049476:	08 
 8049477:	c7 44 24 10 85 9c 04 	movl   $0x8049c85,0x10(%esp)
 804947e:	08 
 804947f:	c7 44 24 0c 9c 9c 04 	movl   $0x8049c9c,0xc(%esp)
 8049486:	08 
 8049487:	c7 44 24 08 50 00 00 	movl   $0x50,0x8(%esp)
 804948e:	00 
 804948f:	c7 44 24 04 01 00 00 	movl   $0x1,0x4(%esp)
 8049496:	00 
 8049497:	c7 04 24 e0 cd 04 08 	movl   $0x804cde0,(%esp)
 804949e:	e8 3d f5 ff ff       	call   80489e0 <__sprintf_chk@plt>
 80494a3:	c7 04 24 e0 cd 04 08 	movl   $0x804cde0,(%esp)
 80494aa:	e8 01 f4 ff ff       	call   80488b0 <system@plt>
 80494af:	85 c0                	test   %eax,%eax
 80494b1:	74 18                	je     80494cb <send_msg+0x22d>
 80494b3:	c7 04 24 a5 9c 04 08 	movl   $0x8049ca5,(%esp)
 80494ba:	e8 e1 f3 ff ff       	call   80488a0 <puts@plt>
 80494bf:	c7 04 24 08 00 00 00 	movl   $0x8,(%esp)
 80494c6:	e8 15 f4 ff ff       	call   80488e0 <exit@plt>
 80494cb:	8b 44 24 28          	mov    0x28(%esp),%eax
 80494cf:	89 04 24             	mov    %eax,(%esp)
 80494d2:	e8 49 f3 ff ff       	call   8048820 <fclose@plt>
 80494d7:	85 c0                	test   %eax,%eax
 80494d9:	74 18                	je     80494f3 <send_msg+0x255>
 80494db:	c7 04 24 bf 9c 04 08 	movl   $0x8049cbf,(%esp)
 80494e2:	e8 b9 f3 ff ff       	call   80488a0 <puts@plt>
 80494e7:	c7 04 24 08 00 00 00 	movl   $0x8,(%esp)
 80494ee:	e8 ed f3 ff ff       	call   80488e0 <exit@plt>
 80494f3:	8b 44 24 2c          	mov    0x2c(%esp),%eax
 80494f7:	89 04 24             	mov    %eax,(%esp)
 80494fa:	e8 01 f3 ff ff       	call   8048800 <dup@plt>
 80494ff:	85 c0                	test   %eax,%eax
 8049501:	74 18                	je     804951b <send_msg+0x27d>
 8049503:	c7 04 24 d8 9c 04 08 	movl   $0x8049cd8,(%esp)
 804950a:	e8 91 f3 ff ff       	call   80488a0 <puts@plt>
 804950f:	c7 04 24 08 00 00 00 	movl   $0x8,(%esp)
 8049516:	e8 c5 f3 ff ff       	call   80488e0 <exit@plt>
 804951b:	8b 44 24 2c          	mov    0x2c(%esp),%eax
 804951f:	89 04 24             	mov    %eax,(%esp)
 8049522:	e8 99 f4 ff ff       	call   80489c0 <close@plt>
 8049527:	85 c0                	test   %eax,%eax
 8049529:	74 18                	je     8049543 <send_msg+0x2a5>
 804952b:	c7 04 24 f3 9c 04 08 	movl   $0x8049cf3,(%esp)
 8049532:	e8 69 f3 ff ff       	call   80488a0 <puts@plt>
 8049537:	c7 04 24 08 00 00 00 	movl   $0x8,(%esp)
 804953e:	e8 9d f3 ff ff       	call   80488e0 <exit@plt>
 8049543:	8b 84 24 8c 00 00 00 	mov    0x8c(%esp),%eax
 804954a:	65 33 05 14 00 00 00 	xor    %gs:0x14,%eax
 8049551:	74 05                	je     8049558 <send_msg+0x2ba>
 8049553:	e8 f8 f2 ff ff       	call   8048850 <__stack_chk_fail@plt>
 8049558:	81 c4 9c 00 00 00    	add    $0x9c,%esp
 804955e:	5b                   	pop    %ebx
 804955f:	5e                   	pop    %esi
 8049560:	5f                   	pop    %edi
 8049561:	5d                   	pop    %ebp
 8049562:	c3                   	ret    

08049563 <explode_bomb>:
 8049563:	83 ec 1c             	sub    $0x1c,%esp
 8049566:	c7 04 24 0a 9d 04 08 	movl   $0x8049d0a,(%esp)
 804956d:	e8 2e f3 ff ff       	call   80488a0 <puts@plt>
 8049572:	c7 04 24 13 9d 04 08 	movl   $0x8049d13,(%esp)
 8049579:	e8 22 f3 ff ff       	call   80488a0 <puts@plt>
 804957e:	c7 04 24 00 00 00 00 	movl   $0x0,(%esp)
 8049585:	e8 14 fd ff ff       	call   804929e <send_msg>
 804958a:	c7 04 24 78 9a 04 08 	movl   $0x8049a78,(%esp)
 8049591:	e8 0a f3 ff ff       	call   80488a0 <puts@plt>
 8049596:	c7 04 24 08 00 00 00 	movl   $0x8,(%esp)
 804959d:	e8 3e f3 ff ff       	call   80488e0 <exit@plt>

080495a2 <read_line>:
 80495a2:	57                   	push   %edi
 80495a3:	53                   	push   %ebx
 80495a4:	83 ec 14             	sub    $0x14,%esp
 80495a7:	e8 ac fc ff ff       	call   8049258 <skip>
 80495ac:	85 c0                	test   %eax,%eax
 80495ae:	75 5e                	jne    804960e <read_line+0x6c>
 80495b0:	a1 60 c7 04 08       	mov    0x804c760,%eax
 80495b5:	39 05 90 c7 04 08    	cmp    %eax,0x804c790
 80495bb:	75 11                	jne    80495ce <read_line+0x2c>
 80495bd:	c7 04 24 2a 9d 04 08 	movl   $0x8049d2a,(%esp)
 80495c4:	e8 d7 f2 ff ff       	call   80488a0 <puts@plt>
 80495c9:	e8 95 ff ff ff       	call   8049563 <explode_bomb>
 80495ce:	c7 04 24 48 9d 04 08 	movl   $0x8049d48,(%esp)
 80495d5:	e8 b6 f2 ff ff       	call   8048890 <getenv@plt>
 80495da:	85 c0                	test   %eax,%eax
 80495dc:	74 0c                	je     80495ea <read_line+0x48>
 80495de:	c7 04 24 00 00 00 00 	movl   $0x0,(%esp)
 80495e5:	e8 f6 f2 ff ff       	call   80488e0 <exit@plt>
 80495ea:	a1 60 c7 04 08       	mov    0x804c760,%eax
 80495ef:	a3 90 c7 04 08       	mov    %eax,0x804c790
 80495f4:	e8 5f fc ff ff       	call   8049258 <skip>
 80495f9:	85 c0                	test   %eax,%eax
 80495fb:	75 11                	jne    804960e <read_line+0x6c>
 80495fd:	c7 04 24 2a 9d 04 08 	movl   $0x8049d2a,(%esp)
 8049604:	e8 97 f2 ff ff       	call   80488a0 <puts@plt>
 8049609:	e8 55 ff ff ff       	call   8049563 <explode_bomb>
 804960e:	8b 15 8c c7 04 08    	mov    0x804c78c,%edx
 8049614:	8d 1c 92             	lea    (%edx,%edx,4),%ebx
 8049617:	c1 e3 04             	shl    $0x4,%ebx
 804961a:	81 c3 a0 c7 04 08    	add    $0x804c7a0,%ebx
 8049620:	89 df                	mov    %ebx,%edi
 8049622:	b8 00 00 00 00       	mov    $0x0,%eax
 8049627:	b9 ff ff ff ff       	mov    $0xffffffff,%ecx
 804962c:	f2 ae                	repnz scas %es:(%edi),%al
 804962e:	f7 d1                	not    %ecx
 8049630:	83 e9 01             	sub    $0x1,%ecx
 8049633:	83 f9 4f             	cmp    $0x4f,%ecx
 8049636:	75 11                	jne    8049649 <read_line+0xa7>
 8049638:	c7 04 24 53 9d 04 08 	movl   $0x8049d53,(%esp)
 804963f:	e8 5c f2 ff ff       	call   80488a0 <puts@plt>
 8049644:	e8 1a ff ff ff       	call   8049563 <explode_bomb>
 8049649:	8d 04 92             	lea    (%edx,%edx,4),%eax
 804964c:	c1 e0 04             	shl    $0x4,%eax
 804964f:	c6 84 01 9f c7 04 08 	movb   $0x0,0x804c79f(%ecx,%eax,1)
 8049656:	00 
 8049657:	83 c2 01             	add    $0x1,%edx
 804965a:	89 15 8c c7 04 08    	mov    %edx,0x804c78c
 8049660:	89 d8                	mov    %ebx,%eax
 8049662:	83 c4 14             	add    $0x14,%esp
 8049665:	5b                   	pop    %ebx
 8049666:	5f                   	pop    %edi
 8049667:	c3                   	ret    

08049668 <read_six_numbers>:
 8049668:	83 ec 2c             	sub    $0x2c,%esp
 804966b:	8b 44 24 34          	mov    0x34(%esp),%eax
 804966f:	8d 50 14             	lea    0x14(%eax),%edx
 8049672:	89 54 24 1c          	mov    %edx,0x1c(%esp)
 8049676:	8d 50 10             	lea    0x10(%eax),%edx
 8049679:	89 54 24 18          	mov    %edx,0x18(%esp)
 804967d:	8d 50 0c             	lea    0xc(%eax),%edx
 8049680:	89 54 24 14          	mov    %edx,0x14(%esp)
 8049684:	8d 50 08             	lea    0x8(%eax),%edx
 8049687:	89 54 24 10          	mov    %edx,0x10(%esp)
 804968b:	8d 50 04             	lea    0x4(%eax),%edx
 804968e:	89 54 24 0c          	mov    %edx,0xc(%esp)
 8049692:	89 44 24 08          	mov    %eax,0x8(%esp)
 8049696:	c7 44 24 04 6e 9d 04 	movl   $0x8049d6e,0x4(%esp)
 804969d:	08 
 804969e:	8b 44 24 30          	mov    0x30(%esp),%eax
 80496a2:	89 04 24             	mov    %eax,(%esp)
 80496a5:	e8 66 f2 ff ff       	call   8048910 <__isoc99_sscanf@plt>
 80496aa:	83 f8 05             	cmp    $0x5,%eax
 80496ad:	7f 05                	jg     80496b4 <read_six_numbers+0x4c>
 80496af:	e8 af fe ff ff       	call   8049563 <explode_bomb>
 80496b4:	83 c4 2c             	add    $0x2c,%esp
 80496b7:	c3                   	ret    

080496b8 <phase_defused>:
 80496b8:	83 ec 7c             	sub    $0x7c,%esp
 80496bb:	65 a1 14 00 00 00    	mov    %gs:0x14,%eax
 80496c1:	89 44 24 6c          	mov    %eax,0x6c(%esp)
 80496c5:	31 c0                	xor    %eax,%eax
 80496c7:	c7 04 24 01 00 00 00 	movl   $0x1,(%esp)
 80496ce:	e8 cb fb ff ff       	call   804929e <send_msg>
 80496d3:	83 3d 8c c7 04 08 06 	cmpl   $0x6,0x804c78c
 80496da:	75 76                	jne    8049752 <phase_defused+0x9a>
 80496dc:	8d 44 24 1c          	lea    0x1c(%esp),%eax
 80496e0:	89 44 24 0c          	mov    %eax,0xc(%esp)
 80496e4:	8d 44 24 18          	lea    0x18(%esp),%eax
 80496e8:	89 44 24 08          	mov    %eax,0x8(%esp)
 80496ec:	c7 44 24 04 80 9d 04 	movl   $0x8049d80,0x4(%esp)
 80496f3:	08 
 80496f4:	c7 04 24 90 c8 04 08 	movl   $0x804c890,(%esp)
 80496fb:	e8 10 f2 ff ff       	call   8048910 <__isoc99_sscanf@plt>
 8049700:	83 f8 02             	cmp    $0x2,%eax
 8049703:	75 35                	jne    804973a <phase_defused+0x82>
 8049705:	c7 44 24 04 86 9d 04 	movl   $0x8049d86,0x4(%esp)
 804970c:	08 
 804970d:	8d 44 24 1c          	lea    0x1c(%esp),%eax
 8049711:	89 04 24             	mov    %eax,(%esp)
 8049714:	e8 bb f8 ff ff       	call   8048fd4 <strings_not_equal>
 8049719:	85 c0                	test   %eax,%eax
 804971b:	75 1d                	jne    804973a <phase_defused+0x82>
 804971d:	c7 04 24 9c 9a 04 08 	movl   $0x8049a9c,(%esp)
 8049724:	e8 77 f1 ff ff       	call   80488a0 <puts@plt>
 8049729:	c7 04 24 c4 9a 04 08 	movl   $0x8049ac4,(%esp)
 8049730:	e8 6b f1 ff ff       	call   80488a0 <puts@plt>
 8049735:	e8 94 f7 ff ff       	call   8048ece <secret_phase>
 804973a:	c7 04 24 fc 9a 04 08 	movl   $0x8049afc,(%esp)
 8049741:	e8 5a f1 ff ff       	call   80488a0 <puts@plt>
 8049746:	c7 04 24 28 9b 04 08 	movl   $0x8049b28,(%esp)
 804974d:	e8 4e f1 ff ff       	call   80488a0 <puts@plt>
 8049752:	8b 44 24 6c          	mov    0x6c(%esp),%eax
 8049756:	65 33 05 14 00 00 00 	xor    %gs:0x14,%eax
 804975d:	74 05                	je     8049764 <phase_defused+0xac>
 804975f:	e8 ec f0 ff ff       	call   8048850 <__stack_chk_fail@plt>
 8049764:	83 c4 7c             	add    $0x7c,%esp
 8049767:	c3                   	ret    
 8049768:	90                   	nop
 8049769:	90                   	nop
 804976a:	90                   	nop
 804976b:	90                   	nop
 804976c:	90                   	nop
 804976d:	90                   	nop
 804976e:	90                   	nop
 804976f:	90                   	nop

08049770 <__libc_csu_init>:
 8049770:	55                   	push   %ebp
 8049771:	57                   	push   %edi
 8049772:	56                   	push   %esi
 8049773:	53                   	push   %ebx
 8049774:	e8 69 00 00 00       	call   80497e2 <__i686.get_pc_thunk.bx>
 8049779:	81 c3 7b 28 00 00    	add    $0x287b,%ebx
 804977f:	83 ec 1c             	sub    $0x1c,%esp
 8049782:	8b 6c 24 30          	mov    0x30(%esp),%ebp
 8049786:	8d bb 20 ff ff ff    	lea    -0xe0(%ebx),%edi
 804978c:	e8 0f f0 ff ff       	call   80487a0 <_init>
 8049791:	8d 83 20 ff ff ff    	lea    -0xe0(%ebx),%eax
 8049797:	29 c7                	sub    %eax,%edi
 8049799:	c1 ff 02             	sar    $0x2,%edi
 804979c:	85 ff                	test   %edi,%edi
 804979e:	74 29                	je     80497c9 <__libc_csu_init+0x59>
 80497a0:	31 f6                	xor    %esi,%esi
 80497a2:	8d b6 00 00 00 00    	lea    0x0(%esi),%esi
 80497a8:	8b 44 24 38          	mov    0x38(%esp),%eax
 80497ac:	89 2c 24             	mov    %ebp,(%esp)
 80497af:	89 44 24 08          	mov    %eax,0x8(%esp)
 80497b3:	8b 44 24 34          	mov    0x34(%esp),%eax
 80497b7:	89 44 24 04          	mov    %eax,0x4(%esp)
 80497bb:	ff 94 b3 20 ff ff ff 	call   *-0xe0(%ebx,%esi,4)
 80497c2:	83 c6 01             	add    $0x1,%esi
 80497c5:	39 fe                	cmp    %edi,%esi
 80497c7:	75 df                	jne    80497a8 <__libc_csu_init+0x38>
 80497c9:	83 c4 1c             	add    $0x1c,%esp
 80497cc:	5b                   	pop    %ebx
 80497cd:	5e                   	pop    %esi
 80497ce:	5f                   	pop    %edi
 80497cf:	5d                   	pop    %ebp
 80497d0:	c3                   	ret    
 80497d1:	eb 0d                	jmp    80497e0 <__libc_csu_fini>
 80497d3:	90                   	nop
 80497d4:	90                   	nop
 80497d5:	90                   	nop
 80497d6:	90                   	nop
 80497d7:	90                   	nop
 80497d8:	90                   	nop
 80497d9:	90                   	nop
 80497da:	90                   	nop
 80497db:	90                   	nop
 80497dc:	90                   	nop
 80497dd:	90                   	nop
 80497de:	90                   	nop
 80497df:	90                   	nop

080497e0 <__libc_csu_fini>:
 80497e0:	f3 c3                	repz ret 

080497e2 <__i686.get_pc_thunk.bx>:
 80497e2:	8b 1c 24             	mov    (%esp),%ebx
 80497e5:	c3                   	ret    
 80497e6:	90                   	nop
 80497e7:	90                   	nop
 80497e8:	90                   	nop
 80497e9:	90                   	nop
 80497ea:	90                   	nop
 80497eb:	90                   	nop
 80497ec:	90                   	nop
 80497ed:	90                   	nop
 80497ee:	90                   	nop
 80497ef:	90                   	nop

080497f0 <__do_global_ctors_aux>:
 80497f0:	55                   	push   %ebp
 80497f1:	89 e5                	mov    %esp,%ebp
 80497f3:	53                   	push   %ebx
 80497f4:	83 ec 04             	sub    $0x4,%esp
 80497f7:	a1 14 bf 04 08       	mov    0x804bf14,%eax
 80497fc:	83 f8 ff             	cmp    $0xffffffff,%eax
 80497ff:	74 13                	je     8049814 <__do_global_ctors_aux+0x24>
 8049801:	bb 14 bf 04 08       	mov    $0x804bf14,%ebx
 8049806:	66 90                	xchg   %ax,%ax
 8049808:	83 eb 04             	sub    $0x4,%ebx
 804980b:	ff d0                	call   *%eax
 804980d:	8b 03                	mov    (%ebx),%eax
 804980f:	83 f8 ff             	cmp    $0xffffffff,%eax
 8049812:	75 f4                	jne    8049808 <__do_global_ctors_aux+0x18>
 8049814:	83 c4 04             	add    $0x4,%esp
 8049817:	5b                   	pop    %ebx
 8049818:	5d                   	pop    %ebp
 8049819:	c3                   	ret    
 804981a:	90                   	nop
 804981b:	90                   	nop

Disassembly of section .fini:

0804981c <_fini>:
 804981c:	53                   	push   %ebx
 804981d:	83 ec 08             	sub    $0x8,%esp
 8049820:	e8 00 00 00 00       	call   8049825 <_fini+0x9>
 8049825:	5b                   	pop    %ebx
 8049826:	81 c3 cf 27 00 00    	add    $0x27cf,%ebx
 804982c:	e8 ef f1 ff ff       	call   8048a20 <__do_global_dtors_aux>
 8049831:	83 c4 08             	add    $0x8,%esp
 8049834:	5b                   	pop    %ebx
 8049835:	c3                   	ret    
