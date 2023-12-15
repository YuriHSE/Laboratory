# Задание (вариант 28)
Дана целочисленная матрица размера m x n.
Программа должна быть разбита на несколько функций и обязательно содержать: 
1) функцию формирования исходного массива;
2) функцию вывода исходного массива;
3) одну или более функций, реализующих вычислительную часть алгоритма. Все
функции должны содержать список параметров, причём адрес массива должен передаваться как параметр функции. Функция main должна содержать только операторы вызова функций.
Использовать статический массив. Дополнительных массивов не использовать!
<img width="855" alt="Снимок экрана 2023-12-15 в 17 03 03" src="https://github.com/YuriHSE/Laboratory/assets/145991450/deb79163-2f85-4607-bcb2-4be73f5d39a9">

## Решение
#### [Полный код программы](https://github.com/YuriHSE/Laboratory/blob/main/5%20lab/5.c)
## Тесты
### Тест 1
```
Enter number of rows: 1
Enter number of columns: 1
Enter elements of row 1 separated by space: 1

Matrix:
1 
Answer: 1.000000%                                                                   
```
В первом тесте задаем матрицу из одного элемента, тогда программа должна вывести это же число, что и происходит.
### Тест 2
```
Enter number of rows: 3
Enter number of columns: 3
Enter elements of row 1 separated by space: 1 1 1
Enter elements of row 2 separated by space: 2 2 2
Enter elements of row 3 separated by space: 3 3 3

Matrix:
1 1 1 
2 2 2 
3 3 3 
Answer: 2.500000%                                                                   
```
Здесь типичный пример, задаем квадратную матрицу, максимальные элементы соответственно равны 2 и 3, получаем ответ 2.5
### Тест 3
```
Enter number of rows: 5
Enter number of columns: 5
Enter elements of row 1 separated by space: 2 3 4 5 6
Enter elements of row 2 separated by space: 2 3 4 5 6
Enter elements of row 3 separated by space: 1 1 1 1 1
Enter elements of row 4 separated by space: 1 1 1 1 1
Enter elements of row 5 separated by space: 0 0 100 1 0

Matrix:
2 3 4 5 6 
2 3 4 5 6 
1 1 1 1 1 
1 1 1 1 1 
0 0 100 1 0 
Answer: 52.500000%                                                                  
```
В данном примере у нас есть несколько равных максимальных элементов выше главной диагонали, при этом заметим, что саму эту диагональ программа не считает, максимальные элементы в таком случае 5 и 100, получаем ответ 52.5
### Тест 4
```
Enter number of rows: 4
Enter number of columns: 4
Enter elements of row 1 separated by space: 1 1 1 1
Enter elements of row 2 separated by space: 2 2 2 2
Enter elements of row 3 separated by space: 3 3 3 3
Enter elements of row 4 separated by space: 4 4 4 4

Matrix:
1 1 1 1 
2 2 2 2 
3 3 3 3 
4 4 4 4 
Answer: 3.500000%                                                                   
```
Аналогичный пример, только уже есть равные максимальные элементы и выше, и ниже побочной диагонали.
### Тест 5
```
Enter number of rows: 2
Enter number of columns: 4
Enter elements of row 1 separated by space: 1 1 1 1
Enter elements of row 2 separated by space: 2 2 2 2

Matrix:
1 1 1 1 
2 2 2 2 
Answer: 1.500000%                                                                   
```
В данном примере мы ввели уже не квадратную матрицу а произвольную, в таком случае программа определяет побочную диагональ, как диагональ, начинающуюся с левого нижнего элемента. Таким образом максимальные элементы здесь 1 и 2, получаем соответствующий пример.
### Тест 6
```
Enter number of rows: 3
Enter number of columns: 2
Enter elements of row 1 separated by space: 1 1
Enter elements of row 2 separated by space: 2 2
Enter elements of row 3 separated by space: 3 3

Matrix:
1 1 
2 2 
3 3 
Answer: 2.500000%                                                                   
```
Аналогичный пример, только теперь количество строк болльше, чем столбцов. Максимальные элементы 2 и 3 соответственно.
### Тест 7
```
Enter number of rows: 1
Enter number of columns: 5
Enter elements of row 1 separated by space: 1 2 3 4 5

Matrix:
1 2 3 4 5 
Answer: 3.000000%                                                                   
```
А вот тут уже интересней. Побочная диагональ в такой матрице определяется, первый элемент, максимумы равны 1 и 5.
### Тест 8
```
Enter number of rows: 1
Enter number of columns: 6
Enter elements of row 1 separated by space: 2 3 5 7 11 13

Matrix:
2 3 5 7 11 13 
Answer: 7.500000%                                                                   
```
В данном тесте количество элементов уже чётное. Матрица разбивается на 2 части, и в соотвественных частях ищем максимальные элементы, получаем среднее 2 и 13.
### Тест 9
```
Enter number of rows: 5
Enter number of columns: 1
Enter elements of row 1 separated by space: 2
Enter elements of row 2 separated by space: 3
Enter elements of row 3 separated by space: 5
Enter elements of row 4 separated by space: 7
Enter elements of row 5 separated by space: 11

Matrix:
2 
3 
5 
7 
11 
Answer: 9.000000%                                                                   
```
С вертикальными матрицами аналогично, только побочная диагональ определяется как последний элемент. Максимумы соответственно равны 7 и 11.

