#include <stdio.h>
#include <pthread.h>

#define UP  { 0x1b, 0x5b, 0x41 }
#define DOWN	{ 0x1b, 0x5b, 0x42 }
#define RIGHT	{ 0x1b, 0x5b, 0x43 }
#define LEFT	{ 0x1b, 0x5b, 0x44 }

typedef struct key
{
	char value[4];
	char name[16];
} key_t;

key_t keys[] = 
{
	{ UP, "dir up" },
	{ DOWN, "dir down" },
	{ RIGHT, "dir right" },
	{ LEFT, "dir left" },
};

typedef struct dir
{
	int dx;
	int dy;
} dir_t;

dir_t dirs[] =
{
	{ -1, 0 },
	{ 1, 0 },
	{ 0, 1 },
	{ 0, -1 },
};

#define ROW	25
#define COL	25
struct snake
{
	int x;
	int y;
	dir_t dir;
} xiaolong = { ROW/2, COL/2, { 0, 1 } };

struct snake_body
{
	int x;
	int y;
	struct snake_body * next;
};

struct snake_body * head; 
struct snake_body * tail;

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t has_product = PTHREAD_COND_INITIALIZER;

int eaten = 0;

int foodx = ROW/2, foody = COL/2;

int board[ROW][COL];

void * producer(void * arg)
{
	key_t current_key;

	while (1)
	{
		char c;
		int i;

		c = getchar();
//		printf("c = %x\n\r", c);

		if (c == 'q' || c == 3)
		{
			system("stty -raw echo");
			//pthread_exit(NULL);
			exit(0);
		}

		if (c == 0x1b && getchar() == 0x5b)
		{
			c = getchar();
			for (i = 0; i < sizeof(keys)/sizeof(keys[0]); i++)
			{
				if (c == keys[i].value[2])
				{
					pthread_mutex_lock(&lock);
					current_key = keys[i];
					printf("producer: %s\r\n", keys[i].name);

					xiaolong.dir = dirs[i];
					xiaolong.x += xiaolong.dir.dx;
					xiaolong.y += xiaolong.dir.dy;

					if (xiaolong.x == foodx && xiaolong.y == foody)
					{
						foodx = rand() % ROW;
						foody = rand() % COL;
					}

					pthread_mutex_unlock(&lock);
					pthread_cond_signal(&has_product);
				}
			}
		}
	}
}

void * producer2(void * arg)
{
	while (1)
	{
		//sleep(1);
		usleep(1000*500);

		pthread_mutex_lock(&lock);
		xiaolong.x += xiaolong.dir.dx;
		xiaolong.y += xiaolong.dir.dy;

		if (head == tail)	// only 1 node
		{
			head->x = xiaolong.x;
			head->y = xiaolong.y;
		}
		else	// at least 2 node
		{
			struct snake_body * p;
			tail->x = xiaolong.x;
			tail->y = xiaolong.y;	// old tail -> new head
			tail->next = head;
			p = head;
			head = tail;

			while (p->next != tail)
				p = p->next;

			tail = p;
			tail->next = NULL;
		}

		if (xiaolong.x == foodx && xiaolong.y == foody)
		{
			struct snake_body * pbody;
			pbody = malloc(sizeof(*pbody));
			pbody->x = xiaolong.x;
			pbody->y = xiaolong.y;

			pbody->next = head;
			head = pbody;

			foodx = rand() % ROW;
			foody = rand() % COL;
		}

		pthread_mutex_unlock(&lock);

		pthread_cond_signal(&has_product);
	}
}


void * consumer(void * arg)
{
	while (1)
	{
		int i, j;

		pthread_mutex_lock(&lock);
		pthread_cond_wait(&has_product, &lock);

		//printf("consumer: %s\r\n", current_key.name);
		system("clear");
#if 0	
		for (i = 0; i < ROW; i++)
		{
			for (j = 0; j < COL; j++)
			{
				if (i == xiaolong.x && j == xiaolong.y)
					printf("@ ");
				else
					if (i == foodx && j == foody)
						printf("$ ");
					else
						printf(". ");
			}
			printf("\n\r");
		}
#endif


		for (i = 0; i < ROW; i++)
			for (j = 0; j < COL; j++)
				board[i][j] = '.';

		board[foodx][foody] = '$';
		struct snake_body * p = head;
		do
		{
			board[p->x][p->y] = '#';
			p = p->next;
		} while (p != NULL);

		for (i = 0; i < ROW; i++)
		{
			for (j = 0; j < COL; j++)
			{
				printf("%c ", board[i][j]);
			}
			printf("\n\r");
		}

		pthread_mutex_unlock(&lock);
	}
}

int main(void)
{
	// producer, consumer
	pthread_t pid, pid2, cid;

	struct snake_body * pbody;
	pbody = malloc(sizeof(*pbody));
	pbody->x = xiaolong.x;
	pbody->y = xiaolong.y;

	head = pbody;
	tail = pbody;

	pbody = malloc(sizeof(*pbody));
	pbody->x = xiaolong.x;
	pbody->y = xiaolong.y - 1;
	tail = pbody;
	head->next = tail;
	tail->next = NULL;

	system("stty raw -echo");

	pthread_create(&pid, NULL, producer, NULL);
	pthread_create(&pid2, NULL, producer2, NULL);
	pthread_create(&cid, NULL, consumer, NULL);

	pthread_join(pid, NULL);
	pthread_join(pid2, NULL);
	pthread_join(cid, NULL);

	system("stty -raw echo");

	return 0;
}
