all:
	gcc -Wall -Werror -ansi -o BankingApp BankingApp.c client.c clients.c date_time.c encrypt.c linked_list.c main.c transaction.c transactions.c -lm