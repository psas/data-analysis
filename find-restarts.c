#include <stdio.h>
#include <arpa/inet.h>

int main(void)
{
	uint32_t buf[4];
	int idx = 0;
	uint32_t last_time = 0;
	while(fread(buf, sizeof buf, 1, stdin))
	{
		uint32_t current_time = ntohl(buf[1]);
		if(current_time != 0)
		{
			if(current_time < last_time)
				printf("%d\n", idx);
			last_time = current_time;
		}
		++idx;
	}
	return 0;
}
