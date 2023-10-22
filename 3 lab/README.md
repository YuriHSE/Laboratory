# Задание(вариант 28)
Вычислить приближенное значение функции, вычислив сумму конечного числа элементов ряда двумя способами, используя разные типы циклов:
1) С заданной точностью;
2) Для заданного количества членов ряда.
Переход к способу вычисления реализовать с помощью оператора выбора.
<img width="1049" src="https://github.com/YuriHSE/Laboratory/assets/145991450/c00446be-2b06-4dd5-b7ae-7cb04046ff5f">


## Решение
#### [Решение 1 (циклы)](https://github.com/YuriHSE/Laboratory/blob/main/3%20lab/3_cycles.c)
#### [Решение 2 (рекурсии)](https://github.com/YuriHSE/Laboratory/blob/main/3%20lab/3_recursion.c)
#### [Полный код программы для сравнений получаемых значений](https://github.com/YuriHSE/Laboratory/blob/main/3%20lab/3.cycles%2Brecursion.c)
## Тесты
### Тест 1
```
Enter the value x, n and accuracy: 2131 2 3
Incorrect value, try again: 0.5 7 5
How to calculate a function: through a cycle WHILE or through a cycle FOR, write the number 1 or 2 accordingly
Enter the value: 1
Result through cycles: 0.81598
Result through recursion: 0.81598                                                                                          
```
Данную задачу я решил тремя способами, два из которых это через разные циклы (по условию), а одно через рекурсию, чтобы сравнить получаемые значения и выявить наиболее эффективный способ. В первом тесте показан самый обычный случай
