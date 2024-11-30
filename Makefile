make:
	@cc -Wall -Wextra -Wall -g *.c libft.a
test_cat_wc:
	@./a.out "/usr/bin/cat main.c NULL NULL NULL" "/usr/bin/wc -l NULL NULL NULL"
test_ls_wc:
	@./a.out "/usr/bin/ls -l NULL NULL NULL" "/usr/bin/wc -c NULL NULL NULL"
test_ls_open:
	@./a.out "/usr/bin/ls -l NULL 1 NULL" 
test_ls_append:
	@./a.out "/usr/bin/ls -l NULL NULL 1" 
test_heredoc:
	@./a.out "/usr/bin/cat -E EOF NULL NULL"
valgrind:
	@valgrind --track-origins=yes ./a.out "/usr/bin/cat main.c NULL NULL NULL"
