# c语言调用shell脚本

```

#include<stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	FILE * fp;
	char buffer[80];
	fp=popen("./test.sh","r");
	while(fgets(buffer, sizeof(buffer), fp))
	{
		printf("%s",buffer);
	}
	pclose(fp);
	return 0;
}

```
