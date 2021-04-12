/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel-sol <adel-sol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 14:40:24 by adel-sol          #+#    #+#             */
/*   Updated: 2021/04/12 11:10:29 by adel-sol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

char	*checker(int ret)
{
	if (ret == 0)
		return ("[KO]");
	return ("[OK]");
}

void	test_ft_strlen(void)
{
	printf("\n=== Test: ft_strlen ===\n");
	printf("Hello world: %s\n", checker(strlen("Hello world") == ft_strlen("Hello world")));
	printf("Empty string: %s\n", checker(strlen("") == ft_strlen("")));
	printf("Short string: %s\n", checker(strlen("123") == ft_strlen("123")));
	printf("Long string: %s\n", checker(strlen("adfadsfadsfadfadsfadsfadsfad") == ft_strlen("adfadsfadsfadfadsfadsfadsfad")));
	printf("Diff size: %s\n", checker(strlen("123") != ft_strlen("1234")));
	printf("\n");
}

void	test_ft_strcpy(void)
{
	char	buff[100];

	printf("\n=== Test: ft_strcpy ===\n");
	printf("Simple check 1: %s\n", checker(strcpy(buff, "hello") == ft_strcpy(buff, "hello")));
	printf("Simple check 2: %s\n", checker(strcpy(buff, "world") == ft_strcpy(buff, "world")));
	printf("Short copy: %s\n", checker(strcpy(buff, "h") == ft_strcpy(buff, "h")));
	printf("Long copy: %s\n", checker(strcpy(buff, "hhhhhhhhhhhhhhhhhh") == ft_strcpy(buff, "hhhhhhhhhhhhhhhhhh")));
	printf("\n");
}

void	test_ft_strcmp(void)
{
	printf("\n=== Test: ft_strcmp ===\n");
	printf("Equal 1: %s\n", checker(strcmp("hello", "hello") == ft_strcmp("hello", "hello")));
	printf("Equal 2: %s\n", checker(strcmp("helloworld", "helloworld") == ft_strcmp("helloworld", "helloworld")));
	printf("First longer: %s\n", checker(strcmp("hello", "hel") * ft_strcmp("hello", "hel") > 0));
	printf("Second longer: %s\n", checker(strcmp("hel", "hello") * ft_strcmp("hel", "hello") > 0));
	printf("Minor diff 1: %s\n", checker(strcmp("hello", "hellp") * ft_strcmp("hello", "hellp") > 0));
	printf("Minor diff 2: %s\n", checker(strcmp("maan", "maam") * ft_strcmp("maan", "maam") > 0));
	printf("\n");
}

void	test_ft_read(void)
{
	int		fd;
	char	str[25];

	printf("\n=== Test: ft_read ===\n");
	fd = open("ft_strlen.s", O_RDONLY);
	ft_read(fd, str, 13);
	str[13] = 0;
	printf("Read first line of .s: %s\n", checker(!strcmp("section .text", str)));
	close(fd);
	fd = open("Makefile", O_RDONLY);
	ft_read(fd, str, 4);
	str[4] = 0;
	printf("Read makefile: %s\n", checker(!strcmp("NAME", str)));
	close(fd);
	printf("\n");
}

void	test_ft_write(void)
{
	printf("\n=== Test: ft_write ===\n");
	ft_write(1, "Write on console: [OK]\n", 23);
	ft_write(1, "Write slightly more on console: [OK]\n", 38);
	printf("\n");
}

void	test_ft_strdup(void)
{
	char	*my;
	char	*base;

	printf("\n=== Test: ft_strdup ===\n");
	my = ft_strdup("Hello");
	base = strdup("Hello");
	printf("Hello dup: %s\n", checker(!strcmp(base, my)));
	free(my);
	free(base);
	my = ft_strdup("A");
	base = strdup("A");
	printf("Short dup: %s\n", checker(!strcmp(base, my)));
	free(my);
	free(base);
	my = ft_strdup("Long long long dup");
	base = strdup("Long long long dup");
	printf("Long dup: %s\n", checker(!strcmp(base, my)));
	free(my);
	free(base);
	printf("\n");
}

void	test_ft_list_size(void)
{
	t_list begin;
	t_list lst[3];

	begin.next = NULL;
	lst[0].next = NULL;
	lst[1].next = NULL;
	lst[2].next = NULL;
	printf("\n=== Test: ft_list_size ===\n");
	printf("List size null: %s\n", checker(0 == ft_list_size(NULL)));
	printf("One element: %s\n", checker(1 == ft_list_size(&begin)));
	begin.next = &lst[0];
	printf("Two elements: %s\n", checker(2 == ft_list_size(&begin)));
	lst[0].next = &lst[1];
	printf("Three elements: %s\n", checker(3 == ft_list_size(&begin)));
	lst[1].next = &lst[2];
	printf("Four elements: %s\n", checker(4 == ft_list_size(&begin)));
	printf("\n");
}

void	test_ft_list_push_front(void)
{
	t_list	lst[3];
	t_list	*res;
	int		x;
	int		y;

	x = 10;
	y = 5;
	lst[0].data = &y;
	lst[0].next = &lst[1];
	lst[1].next = &lst[2];
	lst[2].next = NULL;
	res = &lst[0];
	ft_list_push_front(&res, &x);
	printf("\n=== Test: ft_list_push_front ===\n");
	printf("Push to 3 elem list, check count 4: %s\n", checker(4 == ft_list_size(res)));
	printf("Check new elem value: %s\n", checker(10 == *((int *)res->data)));
	printf("Check next elem value: %s\n", checker(5 == *((int *)res->next->data)));
	printf("Check if list is terminated: %s\n", checker(res->next->next->next->next == NULL));
	res = NULL;
	ft_list_push_front(&res, &y);
	printf("Create a new list with push front, check size: %s\n", checker(1 == ft_list_size(res)));
	printf("Check new list first elem value: %s\n", checker(5 == *((int *)res->data)));
	printf("\n");
}

void	test_ft_list_remove_if(void)
{
	t_list	*res;
	char	*a = strdup("Hello");
	char	*b = strdup("Hellp");
	char	*c = strdup("Hello");
	char	*d = strdup("Hsdf");
	int		(*cmp_ptr)(const char *, const char *) = &strcmp;
	void	(*fr)(void *) = &free;

	res = NULL;
	ft_list_push_front(&res, a);
	ft_list_push_front(&res, b);
	ft_list_push_front(&res, c);
	ft_list_push_front(&res, d);
	printf("\n=== Test: ft_list_remove_if ===\n");
	ft_list_remove_if(&res, "Hello", cmp_ptr, fr);
	c = strdup("Hellp");
	printf("Check if really removed normal: %s\n", checker(2 == ft_list_size(res)));
	printf("Check resulting data normal: %s\n", checker(!ft_strcmp(res->data, "Hsdf") && !ft_strcmp(res->next->data, "Hellp")));
	ft_list_push_front(&res, c);
	ft_list_remove_if(&res, "Hellp", cmp_ptr, fr);
	printf("Check if really removed complex: %s\n", checker(1 == ft_list_size(res)));
	printf("Check resulting data complex: %s\n", checker(!ft_strcmp(res->data, "Hsdf") && res->next == NULL));
	ft_list_remove_if(&res, "Hsdf", cmp_ptr, fr);
	printf("Clear the list: %s\n", checker(0 == ft_list_size(res)));
	printf("\n");
}

int		cmp_str(const char *a, const char *b)
{
	int		c;

	c = strlen(a) - strlen(b);
	if (c == 0)
		return (strcmp(a, b));
	return (c);
}

void	test_ft_list_sort(void)
{
	char	a[] = "Hello";
	char	b[] = "my";
	char	c[] = "dear";
	char	d[] = "me";
	t_list	lst[4];
	t_list	*res;

	lst[0].data = a;
	lst[0].next = &lst[1];
	lst[1].data = b;
	lst[1].next = &lst[2];
	lst[2].data = c;
	lst[2].next = &lst[3];
	lst[3].data = d;
	lst[3].next = NULL;
	res = &lst[0];
	printf("\n=== Test: ft_list_sort ===\n");
	ft_list_sort(&res, strcmp);
	printf("Check size of list: %s\n", checker(4 == ft_list_size(res)));
	printf("Check first element: %s\n", checker(!strcmp(lst[0].data, "Hello")));
	printf("Check second element: %s\n", checker(!strcmp(lst[1].data, "dear")));
	printf("Check third element: %s\n", checker(!strcmp(lst[2].data, "me")));
	printf("Check fourth element: %s\n", checker(!strcmp(lst[3].data, "my")));
	printf("\n");
}

int		main(int argc, char *argv[])
{
	if (argc > 2)
		return (-1);
	test_ft_strlen();
	test_ft_strcpy();
	test_ft_strcmp();
	test_ft_read();
	test_ft_write();
	test_ft_strdup();
	if (argc == 2 && !strcmp(argv[1], "bonus"))
	{
		test_ft_list_size();
		test_ft_list_push_front();
		test_ft_list_remove_if();
		test_ft_list_sort();
	}
	return (0);
}