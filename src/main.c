#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

size_t ft_strlen(const char *str);
char *ft_strcpy(char *dest, const char* src);
int ft_strcmp(const char *str1, const char *str2);
size_t ft_write(int fd, const void *buf, size_t count);
size_t ft_read(int fd, const void *buf, size_t count);
char *ft_strdup(const char *str);

int main()
{
		char str1[] = "Hello world!";
		char str2[] = "";
		int fd;
		char buffer[100];
		char *dup1;
		char *dup2;

		printf("----- FT_STRLEN -----\n");
		printf("\"%s\"	expected: %ld, result: %ld\n", str1, strlen(str1), ft_strlen(str1));
		printf("\"%s\"	expected: %ld, result: %ld\n", str2, strlen(str2), ft_strlen(str2));

		printf("\n----- FT_STRCPY -----\n");
		printf("\"%s\"	expected: \"%s\", result: \"%s\"\n", str1, strcpy(buffer, str1), ft_strcpy(buffer, str1));
		printf("\"%s\"	expected: \"%s\", result: \"%s\"\n", str2, strcpy(buffer, str2), ft_strcpy(buffer, str2));

		printf("\n----- FT_STRCMP -----\n");
		printf("\"%s\", \"%s\" 	expected: %d, result: %d\n", str1, str2, strcmp(str1, str2), ft_strcmp(str1, str2));
		printf("\"%s\", \"%s\" 	expected: %d, result: %d\n", str2, str1, strcmp(str2, str1), ft_strcmp(str2,str1));
		printf("\"%s\", \"%s\" 	expected: %d, result: %d\n", str1, str1, strcmp(str1, str1), ft_strcmp(str1, str1));

		printf("\n----- FT_WRITE -----\n");
		printf("\"%s\" 	expected: ", str1);
		fflush(stdout);
		write(1, str1, strlen(str1));
		printf(", result: ");
		fflush(stdout);
		ft_write(1, str1, strlen(str1));
		printf("\n\"%s\" 	expected: ", str2);
		write(1, str2, strlen(str2));
		printf(", result: ");
		ft_write(42, str2, strlen(str2));
		write(42, str1, strlen(str1));
		printf("\n%s 	expected: %s, ", "errno", strerror(errno));
		ft_write(42, str1, strlen(str1));
		printf("result: %s\n", strerror(errno));

		printf("\n----- FT_READ -----\n");
		fd = open("src/main.c", O_RDONLY);
		read(fd, buffer, 100);
		printf("%s\nexpected:\n\"%s\"", "src/main.c, 100", buffer);
		close(fd);
		fd = open("src/main.c", O_RDONLY);
		ft_read(fd, buffer, 100);
		printf("\nresult:\n\"%s\"\n", buffer);
		close(fd);
		read(42, buffer, 100);
		printf("%s 	expected: %s, ", "errno", strerror(errno));
		ft_read(42, buffer, 100);
		printf("result: %s\n", strerror(errno));

		printf("\n----- FT_STRDUP -----\n");
		dup1 = strdup(str1);
		dup2 = ft_strdup(str1);
		printf("\"%s\"	expected: \"%s\", result: \"%s\"\n", str1, dup1, dup2);
		free(dup1);
		free(dup2);
		dup1 = strdup(str2);
		dup2 = ft_strdup(str2);
		printf("\"%s\"	expected: \"%s\", result: \"%s\"\n", str2, dup1, dup2);
		free(dup1);
		free(dup2);

		return (EXIT_SUCCESS);
}
