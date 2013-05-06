# hanzhong Term 4 class notes

## day1 (4.24 - 4hours) File IO
	 2275  git
	 2276  ping github.com
	 2277  ping 8.8.8.8
	 2278  git --help
	 2344  man find
	 2282  find . -name *.h
	 2344  man grep 
	 2283  grep "Linus" *
	 2296  grep -n "Linux" *
	 2303  grep -r -n "Linux" *
	 2340  find . -name "*.c"  > log
	 2342  find . -name "*.c"  | wc -l
	 2351  find . -name "*.c" -exec ls -l {} \;
	 2356  find . -name "*.c" -exec cat {} \;
	 2357  find . -name "*.c" -exec cat {} \; | wc -l
	 2357  find . -name "*.c" -exec cat {} >> log.c \; 

### about git
	$ git clone https://github.com/limingth/APLE.git
	$ cd APLE
	$ ls 
	$ gedit hanzhong4.notes.md
	$ git pull

	$ git status
	$ git add .
	$ git commit -a -m "M notes.md"
	$ git push
	
	$ git pull

### Team A B C

A1 :-> A3 -> A5
张金铭 李恩荣  董晨龙
A2 :-> A4 -> A6
王立龙 刘伟  刘毅

B1 :-> B3 -> B5
张蔓  张登辉  吴楠楠
B2 :-> B4 -> B6
闫东  闫威   焦敏超

C1 :-> C3 -> C5
曹晶  李鹏 
C2 :-> C4 -> C6
李攀  王少锋

张金铭，董晨龙，闫东
220     212   210

### Keywords of C Language

	A1: 31
	A2: 29
	B1: 54 -> 29
	B2: 24
	C1: 29
	C2: 29

keywords summary

	if else 

	break continue 

	switch case default 

	for do while goto 

	void char int short long float double 

	struct enum union typedef 

	auto static extern register volatile const signed unsigned 

	return sizeof

Not keywords

	main strcpy strlen

	NULL --> #define NULL   (void *)0

	find /usr/include -name "stddef.h"
	/usr/include/linux/stddef.h

### Prime Number 求素数
	in: 100
	out: 25 97

	in: 1000
	out: 168 997

	in: 10000
	out: 1229 9973

	in: 100000
	out: 9592 99991

	in: 1000000
	out: 78498 999983


	main() 
	{



	}

	int a = 0;
	int a=0;

	for (i = 0; i < 100; i++)
	for(i=0;i<100;i++)

	for ()
	{
		for () 
		{
			if () {

			}

			if ()
			{

			}

		}
	}	


	:%s/printf/debug/gc

	#define printf 	//
	#define debug 	printf

	#define debug(fmt, args...)		fprintf(stderr, fmt, ##args)


	./a.out 2>/dev/null
	./a.out 2>log


## day2 (4.25 - 7hours) Basic 4 api

printf("hello, world\n");
-------------------------------
write(1,)/read(0,)/open()/close()
-------------------------------
/dev/ttyS0 -> uart drivers
/dev/fb0 -> lcd drivers -> Registers (bus, mem, cache)



// a : 0x9888
// b : 0x988c
// c : 0x9890
int add(int a, int b, int c)
{
	int x; // 0x8888
	int y; // 0x8884
	int z; // 0x8880

	for ()
	{
		int tmp;
	}

}

APP (C, Linux, DS)
	1. #include <stdio.h>
	2. /usr/include/stdio.h
	3.  int printf(const char * format, ...);
 	    int scanf(const char * format, ...);
	4. #include <stdarg.h>
		va_list ap;
		va_start(ap, format)
		va_arg(ap, int)
		va_end(ap)
	5. '%' -> var number
	6. &format -> int * ap;
	7. va_start() -> ap = &format; ap++;
	8. va_arg() -> (int)(*(int *)ap)
	9. va_end -> ap;
	10. %c, %s, %d, %x, %o, %p
	11. putchar(ch); -> write(STDOUT-1, &ch, 1byte);
-------------

SYS (OS, System Call)
-------------

HW (ARM, Linux Device Driver)

### Advanced Programming of Linux

* APUE 
	
* Outline
	- chp1: File I/O
	- chp2: File System
	- chp3: Process
	- chp8: Thread
	- chp6: Signal
	- chp7: Job Control

	- chp4: Shell Script
	- chp5: Regular Expression
	 
	- chp9: TCP/IP Basics
	- chp10: Socket

### 1.1 标准C库 系统调用 软中断
printf
* Lib C
* System Call (of OS)  write/Linux	SYSWrite/windows
* Software Interrupt (of CPU) INT80/X86   SWI/ARM

helloworld of ASM
* Software Interrupt

write(xx, xx, xx)
     ebx ecx, edx
      1  msg  len
  STDOUT  “hello"    5

exit(0)   ebx:0

ld --verbose

#### code

PLT: Procedure Linkage Table

glibc = libc + system call 

write() + int $0x80

文件描述符 fd - file descriptor
STDOUT = 1

buf - buffer address

len - size of msg (exclude '\0')

#include <unistd.h>

	$ cd /usr/src/linux-headers-3.2.0-29-generic-pae
	$ vi arch/arm/include/asm/unistd.h 
	$ vi arch/x86/include/asm/unistd_32.h 

#include <asm/xxx.h>

asm ->  src/arch/arm/include/asm

	ld -dynamic-linker /lib/ld-linux.so.2 -lc /usr/lib/gcc/i686-linux-gnu/4.6/../../../i386-linux-gnu/crti.o /usr/lib/gcc/i686-linux-gnu/4.6/crtbegin.o -L/usr/lib/gcc/i686-linux-gnu/4.6 -L/usr/lib/gcc/i686-linux-gnu/4.6/../../../i386-linux-gnu -L/usr/lib/gcc/i686-linux-gnu/4.6/../../../../lib -L/lib/i386-linux-gnu -L/lib/../lib -L/usr/lib/i386-linux-gnu -L/usr/lib/../lib -L/usr/lib/gcc/i686-linux-gnu/4.6/../../.. hello2.o /usr/lib/gcc/i686-linux-gnu/4.6/crtend.o /usr/lib/gcc/i686-linux-gnu/4.6/../../../i386-linux-gnu/crtn.o -o hello2

ld -lc (crt1.o) crti.o crtbegin.o crtend.o crtn.o -dynamic-linker /lib/ld-linux.so.2
	-o hello2

* /usr/lib/i386xxx/libc.so
* libc.so.6
* libc-2.15.so

gcc -v hello.c

### 1.2 文件FILE*指针和 fd文件描述符
	#include <stdio.h>
	FILE * fp；
	fp = fopen(xxx);

	typedef struct _IO_FILE FILE;

	vi /usr/include/libio.h +273
	struct _IO_FILE {
		int _flags;
		...
		...
		int _fileno;
	}

	stdin->_fileno == 0
	stdout->_fileno == 1
	stderr->_fileno == 2

#### fd (file descriptor)
www.kernel.org -> vmlinux

	$ grep -r -n "^struct task_struct" * | grep "{" 
	include/linux/sched.h:1227:struct task_struct {
	$ vi include/linux/sched.h +1227

	$ grep -r -n "^struct files_struct" * | grep "{" 
	grep: sourceinclude/linux/fdtable.h:44:struct files_struct {

	$ vi include/linux/fdtable.h +44

	$ grep -r -n "BITS_PER_LONG" * | grep "#define BITS"
	arch/arm/include/asm/types.h:17:#define BITS_PER_LONG 32

	进程打开文件描述符表，有一个数组，一共可以支持打开32个文件。

	$ vi /usr/include/unistd.h 
	 210 /* Standard file descriptors.  */
	 211 #define STDIN_FILENO    0       /* Standard input.  */
	 212 #define STDOUT_FILENO   1       /* Standard output.  */
	 213 #define STDERR_FILENO   2       /* Standard error output.  */
	
### 1.3 1.4 1.5 open/read/write/close
	$ vi i386-linux-gnu/bits/fcntl.h +34

	 31 /* open/fcntl - O_SYNC is only implemented on blocks devices and on files
	 32    located on a few file systems.  */
	 33 #define O_ACCMODE          0003
	 34 #define O_RDONLY             00
	 35 #define O_WRONLY             01
	 36 #define O_RDWR               02
	 37 #define O_CREAT            0100 /* not fcntl */
	 38 #define O_EXCL             0200 /* not fcntl */
	 39 #define O_NOCTTY           0400 /* not fcntl */
	 40 #define O_TRUNC           01000 /* not fcntl */
	 41 #define O_APPEND          02000
	 42 #define O_NONBLOCK        04000
	 43 #define O_NDELAY        O_NONBLOCK
	 44 #define O_SYNC         04010000
	 45 #define O_FSYNC          O_SYNC
	 46 #define O_ASYNC          020000



设置文件权限位时我们一般忽略了suid/guid的存在，现在看看它们到底是怎么回事。
suid/guid是什么？ 

suid意味着如果A用户对属于他自己的shell脚本文件设置了这种权限，那么其他用户在执行这个脚本的时候就拥有了A用户的权限。所以，如果 root用户对某一脚本设置了这一权限的话则其他用户执行该脚本的时候则拥有了root用户权限。同理，guid意味着执行相应脚本的用户则拥有了该文件 所属用户组中用户的权限。 

为什么使用suid/guid？ 

举个例子：要对数据库系统进行备份需要有系统管理权限，那么我可以写几个脚本，并设置了它们的guid，这样我指定的一些用户只要执行这些脚本就 能够完成相应的工作，而无须以数据库管理员的身份登录，以免不小心破坏了数据库服务器。通过执行这些脚本，他们可以完成数据库备份及其他管理任务，但是在 这些脚本运行结束之后，他们就又回复到他们作为普通用户的权限。 

有相当一些命令也设置了suid和guid。如果想找出这些命令，可以进入/bin或/sb in目录，执行下面的命令： 

$ ls -l | grep '^...s' 
上面的命令是用来查找suid文件的； 

$ ls -l | grep '^...s..s' 
上面的命令是用来查找suid和guid的。 

如何设置suid/guid？ 

如果希望设置suid，那么就将相应的权限位之前的那一位设置为4；如果希望设置guid，那么就将相应的权限位之前的那一位设置为2；如果希望两者都置位，那么将相应的权限位之前的那一位设置为4+2。 

一旦设置了这一位，一个s将出现在x的位置上。记住：在设置suid或guid的同时，相应的执行权限位必须要被设置。例如，如果希望设置guid，那么必须要让该用户组具有执行权限。 

如果想要对文件login设置suid，它当前所具有的权限为rwx rw- r-- (741)，需要在使用chmod命令时在该权限数字的前面加上一个4，即chmod 4741，这将使该文件的权限变为rws rw- r--。 

$ chmod 4741 login 

还可以使用符号方式来设置suid/guid。如果某个文件具有这样的权限： rwx r-x r-x，那么可以这样设置其suid/guid： 

chmod u+s <filename> 
chmod u+g <filename>

## day3 (4.26 - 4hours) Pro 4 api
### Project 1 - mytee
mytee

mytee log.c 


### 1.6 lseek
	lseek(fd, offset, SEEK_SET);

### 1.7 fcntl
	O_RDONLY:   bit 1	002
	O_NONBLOCK: bit 11	800
	-----------------------------
	O_RDONLY | O_NONBLOCK	802


	./a.out 1>log	1: stdout   ==== ./a.out >log   === ./a.out >      log
	./a.out 1 >log  1: argv[1]
	./a.out 1 >log   ==== ./a.out 1 >      log
   

	$ ./fcntl2 
	argc = 1
	flags = 2
	flags = 2
	flags = 2
	$ ./fcntl2 < /dev/tty
	argc = 1
	flags = 8000
	flags = 2
	flags = 2
	$ ./fcntl2 > tmp
	$ cat tmp 
	argc = 1
	flags = 2
	flags = 8001
	flags = 2
	$ ./fcntl2 2>>tmp2
	argc = 1
	flags = 2
	flags = 2
	flags = 8401
	$ ./fcntl2 2<>tmp2
	argc = 1
	flags = 2
	flags = 2
	flags = 8002
	$ ./fcntl2 1>/dev/null 2>&1
	$ ./fcntl2 1>log 2>&1
	$ cat log
	argc = 1
	flags = 2
	flags = 8001
	flags = 8001

### 1.8 ioctl

$ vi i386-linux-gnu/sys/ioctl.h 
$ grep -rn "^struct winsize" *
asm-generic/termios.h:14:struct winsize {
i386-linux-gnu/bits/ioctl-types.h:28:struct winsize
$ 

$ grep -rn "TIOCGWINSZ" *
asm-generic/ioctls.h:37:#define TIOCGWINSZ	0x5413
$ vi asm-generic/ioctls.h 
$ 

### 1.9 mmap

## day4 (4.28 - 4hours) File System

0	/		2
1	hello.c 	3 4
2	aabb		5
3	text.txt	4

### 2.1 mount 命令
#### mount usb disk

	dmesg
	mount
	/dev/sda1	/dev/hda1	/dev/hdc1
	/dev/sdb1
	mount | grep sdb

	$ mount /dev/sdb1 /mnt
	mount: only root can do that
	$ sudo mount /dev/sdb1 /mnt

	$ mount | grep sdb
	/dev/sdb1 on /mnt type vfat (rw)


#### mount nfs 

	$ exportfs
	The program 'exportfs' is currently not installed.  You can install it by typing:
	sudo apt-get install nfs-kernel-server
	$ sudo apt-get install nfs-kernel-server

	$ sudo vi /etc/exports 
	/home/ (ro)

	$ service portmap start[restart]     

	$ sudo service nfs-kernel-server start

	$ mount -t nfs 192.168.1.124:/home  /tmp


#### mount ext2	

$ dd if=/dev/zero of=fs count=1024 bs=1k
$ mke2fs fs
$ sudo mount -t ext2 -o loop fs tmp
$ ls tmp/
lost+found

$ dumpe2fs
	first data block 1 (block 0 is boot block, block 1 is fs data block)
	block size = 1024 （block 0 -- block 1023)

### 2.2 Ext2 文件系统
#### inode table 索引节点表
* 16 block * 8 item/block = 128 inodes
* 128 bytes/inode
* Info
	- size of file
	- block[0] - block[14]

#### dir file structure 目录文件的组织结构
* 不定长度，长度信息在第2个字段。
* inode 节点号是第1个字段
* Info
	- Inode num (ls -i -l)
	- Subdir/File name 
	- name len

#### File data blocks indexing 文件数据块索引方法
* direct indexing
	- block[0] - block[11] 
	- 12 blocks * 1024bytes = 12K
* Indirect indexing
* 1 level
	- block[12]
	- 1block = 1024bytes = 256 blocks -> 256K
* 2 level
	- block[13]
	- 256 * 256 = 2^16 = 64K blocks -> 64M
* 3 level
	- block[14]
	- 256 * 256 * 256 = 2^24 = 16M blocks -> 16G

#### inode table
128 个 inode -> 128 bits -> 16 bytes -> 4 words (32bits)
fi[0]-[3]  
* int inode_is_free(int num)
* int get_free_inode()
* void release_inode()

## day5 (4.29 - 10hours) Ext2 Project
### Project 2.1: ls 和 cat 命令实现
* 对于任意 fs （dd创建的大小，inode数量，data block 的起始位置都从 fs 中自动获取）
* 能够实现对于根目录下的 ls 和 cat 命令 （ls, cat test.txt）
* 争取实现2级目录结构下的 ls 和 cat 命令 （ls aabb, cat aabb/test.txt）

	./a.out fs
		$ ls
		$ cat test.txt

Data struct Refer to
	$ vi /usr/src/linux-headers-3.2.0-29-generic-pae/include/linux/ext2_fs.h
	
	struct ext2_super_block;
	struct ext2_group_desc;
	struct ext2_inode;
	struct ext2_dir_entry_2;

	int curr_inode = 2;	// root inode = 2
	
API function name Refer to
	int namei(char *filename);	 /home/akaedu/test.txt
	struct inode * get_inode(int inode);
		- "."
		- "test.txt"
		- "aabb"
	void * get_block(int block);
		- "test.txt": char *
		- "/" : struct ext2_dir_entry_2 *
	struct ext2_super_block * get_super_block();	return (s e *)0x400;
	int putns(char * buf, int n);
	
	get_super_block()->inode_count, inode_size, block_count, 
	(struct ext2_group_desc *)get_block(2)->inode_table
	(struct ext2_inode *)get_inode(2)->size

	// cat test.txt
	struct ext2_inode * p;
	p = get_inode(namei("test.txt"));
	putns(get_block(p->block[0]), p->size);

### Project 2.2: open/read/write/close 系统调用实现
* 在正确理解 ext2 文件系统组织结构的前提下，自己设计并实现一个类 ext2 文件系统
* 对次要的数据结构做大量简化，保留长度，不定长的可以实现为定长
* 要求实现对于一个文件的 open, read, write, close 这4个函数接口。
* 尽量在数据结构的起名和设计上，模仿和照搬 Linux Ext2 原来的名称。
* 可以退化到只要能工作就行。


### 2.3 VFS 虚拟文件系统

	PCB (task_struct)
	-----
	files_struct (fd_array[fd])
	------------
        file (f_dentry   f_op)
	---------------
	     /               	\ (file_operations)
	---------------				|
	dentry					|
          /  					|
	inode (i_op: inode_operations)		|
	/		|			|
	superblock	|			|
	--------------- |-----------------------|--
			hardware(disk/device)	

#### dup 和 dup2
fd_array[1] -> (stdout) <-|
fd_array[3] -> ("log.c")  |
 	[4] ---------------

4 fd = dup(1); -> stdout
4 fd = dup(3); -> log.c

4 fd = dup2(1, 4);

## day6 (4.30 - 7hours) Process
### 3.1 进程控制块

	struct task_struct {
		pid_t pid;	
		
		struct mm_struct *mm,

		/* open file information */
		struct files_struct *files;

		/* signal handlers */
		struct signal_struct *signal;
		struct sighand_struct *sighand;

				
### 3.2.1 exit 和 _exit
* exit 库函数，需要包含 stdlib.h

* _exit 系统调用，需要包含 unistd.h

* 如果程序出错，不影响在 shell 下面的执行，但会影响 makefile 中执行。
	- 解决办法是在 makefile 运行的命令前面加上 - ，表示忽略

### 3.2.2 环境变量
* extern char **environ;
* int main(int argc, char *argv[], char *env[]);
* char *getenv(char *name);


### 3.3.1 fork 函数
* 一次运行，返回两次
* 父进程返回子进程id，子进程返回0
* 父子进程的数据段，代码段是完全一样的，但分别属于不同的虚拟地址空间
* 父子进程的 file 结构体在内核中，是共享的。

### 3.3.2 exec 函数
* execlp
	- l: "ifconfig", ”eth0", "192.168.0.100"
	- p: search in $PATH
* execve
	- v: "/sbin/ifconfig", argv[],
	- e: env[]

### Project 3: read/write process
父进程创建子进程，子进程负责接受用户输入，写入log文件。父进程负责读log文件，打印输入信息。


### 3.3.3 wait & waitpid 函数
* zombie 僵尸进程
	- Z+ 表示在前台
	- Z  表示在后台
	- R+ 表示正常运行在前台
	- R  表示正常运行在后台

* wait()

* wait(&status)
	- son "how to end"
	- exit(0)	status = 0x0000
	- exit(100)	status = 0x6400
	- exit(0x89)	status = 0x8900
	
	- kill son	status = 0x0f
	- seg fault	status = 0x8b

	/usr/include/i386-linux-gnu/bits/waitstatus.h:32:
	#define	__WTERMSIG(status)	((status) & 0x7f)

	 28 /* If WIFEXITED(STATUS), the low-order 8 bits of the status.  */
	 29 #define __WEXITSTATUS(status)   (((status) & 0xff00) >> 8)
	 30 
	 31 /* If WIFSIGNALED(STATUS), the terminating signal.  */
	 32 #define __WTERMSIG(status)      ((status) & 0x7f)
	 33 
	 34 /* If WIFSTOPPED(STATUS), the signal that stopped the child.  */
	 35 #define __WSTOPSIG(status)      __WEXITSTATUS(status)
	 36 
	 37 /* Nonzero if STATUS indicates normal termination.  */
	 38 #define __WIFEXITED(status)     (__WTERMSIG(status) == 0)
	 39 
	 40 /* Nonzero if STATUS indicates termination by a signal.  */
	 41 #define __WIFSIGNALED(status) \
	 42   (((signed char) (((status) & 0x7f) + 1) >> 1) > 0)
	 
	 8b = 1000 1011
	 7f = 0111 1111
                 0 1011 = 0b + 1 = 0C >> 1 = 0110 > 0


	$ kill -n 11 19185
	$ 
	$ ./a.out 
	son running...
	status = 0x8b
	father running...
	$ 


## day7 (5.1 - 7hours) IPC

### pipe 管道
* 没人写，直接读，则读会阻塞
* 写关闭，然后读，则直接返回0
* 先写入，然后读，则读完全部数据之后继续阻塞
* 先写入，然后关闭写，则读完全部数据之后还会返回0

* 没人读，直接写，则写没问题。
* 读关闭，然后写，则write函数出错不返回，程序退出，错误码141
* 先读取，然后写，则读一开始就阻塞，没可能往里写
* 先读取，然后关闭读，则读一开始就阻塞，没可能关闭读

* 如果只写，不读，则写满64K之后，写进程会阻塞。

### Project 4: 剪刀-石头-布 游戏
* 无名管道 pipe
	- 父进程创建1个子进程
	- 父进程 和 子进程 随机产生一个手势，可以是剪刀，石头，布 中间的任意一个
	- 比赛3次，三局两胜，打印出谁是最后胜利者。

* 如何设计
	- 父 -> 儿   ，儿子负责打印
	- 父进程要关闭读
	- 子进程要关闭写
	- 父把数据传给儿子，儿子拿到直接判别，打印当局结果
	- 父亲每传送一次，sleep(1)
	- 儿子判别输赢后，打印，结束时运行 kill 命令，通过 getppid() 获得父亲的pid号。

	- srand(time(NULL));
	- 0，1，2 = rand() % 3		剪刀0，石头1，布2

	- int cmp(a, b)
	  {
		if (a == b)
                	return 0;
		a b
		1 0	0 1
		2 1	1 2
		0 2	2 0
		if (a - b == 1 || a - b == -2)
			return 1;

		return -1;

	  }

* 有名管道 fifo
	- 两个应用程序 a1 和 a2
	- 随机产生1个手势，然后PK
	- 程序根据3局2胜，打印出各自输赢的结果。

## day8 (5.2 - 4hours) Thread

### pthread_create

* pthread_t 
	$ grep -rn "pthread_t" /usr/include/  | grep typedef
	/usr/include/thread_db.h:243:typedef pthread_t thread_t;
	/usr/include/i386-linux-gnu/bits/pthreadtypes.h:36:typedef unsigned long int pthread_t;
	$ 

* start_routine
	void *(*start_routine) (void *)

* about pthread diff

	pthid 2 = b75d7b40
	pthid 2 = b6dd6b40
	pthid 2 = b65d5b40
	pthid 2 = b5dd4b40

* diff
	- pthid (高地址) -> &arg (线程参数在栈空间) -> &tmp (线程内的局部变量最后分配，在栈顶)
	- pthid1 (低地址) - pthid2 (高地址) = b5dd4b40 - b65d5b40
	- 先创建的线程在低地址，后创建的在高地址，可以认为是 malloc 出来的地址，不是在栈上的地址
	- b65d5b40 - b5dd4b40 = 0x801000  就是创建一个线程所需要的空间 8M

	arg is my test thread
	pthid is  b5dd4b40
	&arg is 0xb5dd4370
	&tmp is 0xb5dd435c
	&global is 0x804a020

	arg is my test thread
	pthid is  b65d5b40
	&arg is 0xb65d5370
	&tmp is 0xb65d535c
	&global is 0x804a020

	arg is my test thread
	pthid is  b6dd6b40
	&arg is 0xb6dd6370
	&tmp is 0xb6dd635c
	&global is 0x804a020

	arg is my test thread
	pthid is  b75d7b40
	&arg is 0xb75d7370
	&tmp is 0xb75d735c
	&global is 0x804a020


### Project 5: 倒计时
请通过创建线程的方法，实现一个倒计时5秒的提示。
如果用户在5秒之内按了回车键，则中止倒计时，打印输出 Welcome to shell 进入 Shell 模式。
如果用户一直没有按回车键，则倒计时结束后，打印输出 Booting Linux kernel ... 

* 设计思路
	- 主程序创建线程T，T接受用户输入。
	- 主程序打印5秒倒计时，打印过程中判别 flag 变量是否 == 1，1表示已经有了用户输入，
	- 如有则跳出循环，如没有则继续倒计时，直到5秒用尽，打印 Booting
	- 线程T 读取标准输入，如有用户输入，则设置标志位 flag 变量为1，如无则设为0
	- 在上题中，用户必须按回车键才能打断倒计时，想一想，怎样能够实现用户按下任意键就可以进入shell模式？

## day9 (5.3 - 4hours) ITS: Inter-Thread Synchronization

### Project 6: 打印1秒钟能够输出的最多的数字个数。
使用 printf("%d\n", counter++); 

* 设计思路1	37652
	- 主程序创建线程T，线程T 进行 sleep 1秒，定义1个flag，完了设为1.
	- 主程序负责打印，判断flag是否为1，为1则跳出循环。

* 设计思路2	37872
	- 主程序创建线程T，主程序中 sleep 1秒。直接结束。
	- 线程T负责不断打印。其他什么也不管。

* 设计思路3	28354
	- 主程序创建线程T，线程T sleep 1秒。直接结束。
	- 主程序负责不断打印。其他什么也不管。

### Mutex 
#### static 静态初始化
	pthread_mutex_t mylock = PTHREAD_MUTEX_INITIALIZER;
	pthread_mutex_lock(&mylock);
	pthread_mutex_unlock(&mylock);

#### dynamic 动态初始化
        pthread_mutex_t tmp;
	plock = &tmp;
        //plock = malloc(sizeof(pthread_mutex_t));
        pthread_mutex_init(plock, NULL);

	pthread_mutex_lock(plock);
	pthread_mutex_unlock(plock);

#### pthread_mutex_t 
	$ grep -rn "pthread_mutex_t" /usr/include/  | grep }
	/usr/include/i386-linux-gnu/bits/pthreadtypes.h:73:} pthread_mutex_t;
	$ vi /usr/include/i386-linux-gnu/bits/pthreadtypes.h +73

### Project 7: 采用线程同步机制解决剪刀石头布的问题

## day10 (5.4 - 7hours) Signal
标准输出缓冲区的大小是 1024 个字节。只有用 \n 强制输出缓冲区，或者用 fflush(stdout) 输出缓冲，否则只有积累到1024个字节才会输出一次。

如何实现大小写的转换，最简单的方法是 （不能用 if 来实现） 用位操作来实现
 0x41 'a' -> 0x61 'A'
         ^0x20
 0x61 'A' -> 0x41 'a'

	异或操作的作用
	1) 大小写转换
	2) 两数交换 SWAP(a, b) 	a = a ^ b; b = a ^ b; a = a ^ b;
	3) 求一个数二进制表示中 bit 1 的个数。  while (n = n ^ (n - 1))


* SIGINT 信号 （interrupt）
	- ctrl + c 产生
	- 只有前台程序能接收 （前台，后台的概念）

* 有用的几个命令
	- kill -l
	- man 7 signal
	- kill -n x pid

* 几种常见信号
	- SIGINT 用户按下 Ctrl + c
	- SIGSTP 用户按下 Ctrl + z
	- SIGQUIT 用户按下 Ctrl + \
	- SIGFPE 程序中有除0，产生浮点异常
	- SIGSEGV 程序中有访问非法内存地址，产生段错误
	- SIGTERM 程序用 kill 命令发送信号
	- SIGALRM 程序设置定时闹钟到时后中止

* 系统函数发出信号
	- kill(pid_t pid, int signo);
	- raise(int signo);
	- about(void);
	- alarm(unsigned int seconds);


### 6.3 阻塞信号
* 信号的基本概念
	- 产生 Generation
	- 递达 Delivery
	- 未决 Pending
	- 阻塞 Block
	- 忽略 Ignore

* 生活案例
	- 点菜模型
	- 入党申请模型
	- 送奶模型
	- 打电话模型
	- 中断模型

#### sigset_t 
	$ grep -rn "sigset_t" /usr/include/ | grep typedef
	/usr/include/i386-linux-gnu/asm/signal.h:15:typedef unsigned long sigset_t;

#### mysleep
* version 1
	- alarm(1);
	- pause();
* version 2
	- newact, oldact
	- restore oldact
* version 3
	- newact.sa_flags = 0 -> segmentation fault
* version 4
	- sigsuspend()





	
	













