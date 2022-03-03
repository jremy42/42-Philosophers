#!/bin/bash

echo "test 1>"
valgrind --log-file="leak" --leak-check=full --show-leak-kinds=all --undef-value-errors=no --error-exitcode=240 --errors-for-leak-kinds=all ./philo_bonus
if [  "$?" -ne "240" ]
then
echo -e "valgrind     : \033[32m[OK]\033[0m"
else
echo -e "valgrind     : \033[31m[NOK]\033[0m"
cat leak
fi
rm -rf leak

echo "test 2>"
valgrind --log-file="leak" --leak-check=full --show-leak-kinds=all --undef-value-errors=no --error-exitcode=240 --errors-for-leak-kinds=all ./philo_bonus 1
if [  "$?" -ne "240" ]
then
echo -e "valgrind     : \033[32m[OK]\033[0m"
else
echo -e "valgrind     : \033[31m[NOK]\033[0m"
cat leak
fi
rm -rf leak

echo "test 3>"
valgrind --log-file="leak" --leak-check=full --show-leak-kinds=all --undef-value-errors=no --error-exitcode=240 --errors-for-leak-kinds=all ./philo_bonus 201 60 60 60
if [  "$?" -ne "240" ]
then
echo -e "valgrind     : \033[32m[OK]\033[0m"
else
echo -e "valgrind     : \033[31m[NOK]\033[0m"
cat leak
fi
rm -rf leak

echo "test 4>"
valgrind --log-file="leak" --leak-check=full --show-leak-kinds=all --undef-value-errors=no --error-exitcode=240 --errors-for-leak-kinds=all ./philo_bonus "" "" "" "" ""
if [  "$?" -ne "240" ]
then
echo -e "valgrind     : \033[32m[OK]\033[0m"
else
echo -e "valgrind     : \033[31m[NOK]\033[0m"
cat leak
fi
rm -rf leak

echo "test 5>"
valgrind --log-file="leak" --leak-check=full --show-leak-kinds=all --undef-value-errors=no --error-exitcode=240 --errors-for-leak-kinds=all ./philo_bonus 0 200 200 200 200 
if [  "$?" -ne "240" ]
then
echo -e "valgrind     : \033[32m[OK]\033[0m"
else
echo -e "valgrind     : \033[31m[NOK]\033[0m"
cat leak
fi
rm -rf leak

echo "test 6>"
valgrind --log-file="leak" --leak-check=full --show-leak-kinds=all --undef-value-errors=no --error-exitcode=240 --errors-for-leak-kinds=all ./philo_bonus 5 200 200 200 0
if [  "$?" -ne "240" ]
then
echo -e "valgrind     : \033[32m[OK]\033[0m"
else
echo -e "valgrind     : \033[31m[NOK]\033[0m"
cat leak
fi
rm -rf leak

echo "test 7>"
valgrind --log-file="leak" --leak-check=full --show-leak-kinds=all --undef-value-errors=no --error-exitcode=240 --errors-for-leak-kinds=all ./philo_bonus 5 -60 60 60
if [  "$?" -ne "240" ]
then
echo -e "valgrind     : \033[32m[OK]\033[0m"
else
echo -e "valgrind     : \033[31m[NOK]\033[0m"
cat leak
fi
rm -rf leak

echo "test 8>"
valgrind --log-file="leak" --leak-check=full --show-leak-kinds=all --undef-value-errors=no --error-exitcode=240 --errors-for-leak-kinds=all ./philo_bonus 5 6ab0 60 60
if [  "$?" -ne "240" ]
then
echo -e "valgrind     : \033[32m[OK]\033[0m"
else
echo -e "valgrind     : \033[31m[NOK]\033[0m"
cat leak
fi
rm -rf leak