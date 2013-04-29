#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>

struct dir_file
{
	int inode;
	short record_len;
	char name_len;
	char file_type;
	char name;
};

struct inode
{
	short st_mode;
	short user;
	int size;
	int time[4];
	short group;
	short links;
	int bc;
	int flags;
	int os;
	int blocks[15];
};

typedef struct dir_file	dir_file_t;

void myputns(char * buf, int len)
{
	int i = 0;

	putchar('\t');
	for (i = 0; i < len; i++)
		putchar(buf[i]);
	putchar('\n');
}

#define INODE_SIZE		128
#define INODE_TABLE_ADDR	0x2000
#define inode(x)	(INODE_TABLE_ADDR + INODE_SIZE * (x-1))

#define BLOCK_SIZE		1024
#define block(x)		(BLOCK_SIZE * x)

int main(int argc, char *argv[])
{
	char * filename = "fs";
	int fd = 0;
	int counter = 0;
	char * p;
	int * inode;
	dir_file_t * pdir;
	struct inode * in;

	int len;

	if (argc >= 2)
		filename = argv[1];

	printf("open file %s \n", filename);

	fd = open(filename, O_RDWR);
	if (fd < 0)
	{
		printf("open file %s failed\n", filename);
		return 0;
	}

	p = mmap(NULL, 1024*1024, PROT_WRITE, MAP_SHARED, fd, 0);
	close(fd);	
	
	counter = 0;
	/* ext2 demo code */
	pdir = (dir_file_t *)(p + 0x6000);
	len = 0;
	do 
	{	
	//	inode = (int *)(p + 0x6000);
		printf("inode = 0x%x\n", pdir->inode);
		//printf("\trecord len = 0x%x\n", pdir->record_len);
		//printf("\tnode name = %s\n", &(pdir->name));
		myputns(&(pdir->name), pdir->name_len);
		//printf("\tfile type = %d\n", pdir->file_type);

		if (pdir->file_type == 1)
		{
	//		int * block0 = (int *)(p + inode(pdir->inode) + 40);
			//printf("block 0 is at %d\n", *block0);
		//	printf("data is <%s>\n", (char *)(p + block(*block0)));
			in = (struct inode *)(p + inode(pdir->inode));
			#define PRINT(x)	printf(#x " = %d\n", x)
			PRINT(in->size);
			PRINT(in->blocks[0]);
			myputns((char *)(p + block(in->blocks[0])), in->size);
		}

		len += pdir->record_len;

		pdir = (dir_file_t *)((int)pdir + pdir->record_len);
	} while (len < 1024);

	munmap(p, 10);

	return 0;
}


