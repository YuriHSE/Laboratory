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
Enter the value x, n and accuracy: 1 2 3 
Incorrect value, try again: 0.123535 20 20
How to calculate a function: through a cycle WHILE or through a cycle FOR, write the number 1 or 2 accordingly
Enter the value: 1
Result through cycles: 0.94342351522578749012
Result through recursion: 0.94342351522578749012                                                                           
```
Данную задачу можно решить несколькими способами, а именно через циклы и рекурсию. Сразу скажу, что решение через циклы выглядит и работает гораздо лучше, чем через рекурсию, так как там мы не вычисляем отдельно числитель и знаменатель дроби, а вычисляем лишь произведение обыкновенных дробей. Но разобрать оба способа всё же стоит.
В данном тесте разобран обычный случай с небольшим n через цикл WHILE, полученные ответы совпадают.
### Тест 2
```
Enter the value x, n and accuracy: -0.121314314 32 10
How to calculate a function: through a cycle WHILE or through a cycle FOR, write the number 1 or 2 accordingly
Enter the value: 2
Result through cycles: 1.0668005334
Result through recursion: 1.0668005334                                                                                     
```
Здесь мы проверили работу через цикл FOR, принцип абсолютно тот же, заодно и обработали отрицательное число.
### Тест 3
```
Enter the value x, n and accuracy: 0.12345 33 10
How to calculate a function: through a cycle WHILE or through a cycle FOR, write the number 1 or 2 accordingly
Enter the value: 1
Result through cycles: 0.9434592042
Result through recursion: -inf                                                                                             
```
А вот теперь рассотрим крайний случай, а именно для n = 33. -inf означает, что результат функции вышел за пределы допустимого диапозона значений для нашего типа данных. Заметим, что каждый раз мы отдельно вычисляли числитель и знаменатель, поэтому и неудивительно, что стек переполнен. 
### Тест 4
```
Enter the value x, n and accuracy: 0.988765 34 7 
How to calculate a function: through a cycle WHILE or through a cycle FOR, write the number 1 or 2 accordingly
Enter the value: 2
Result through cycles: 0.7415028
Result through recursion: nan                                                                                              
```
Ну и при дальнейшем увеличении соответственно будет вылазить nan, что означает неопределённость, то есть дальнейшее действие для числа с плавающей точкой не может быть выполнено.
### Тест 5
```
Enter the value x, n and accuracy: 0.123456789 1000 10
How to calculate a function: through a cycle WHILE or through a cycle FOR, write the number 1 or 2 accordingly
Enter the value: 1
Result through cycles: 0.9434563535
Result through recursion: nan                                                                                              
```
С циклами же всё отлично, по сути ограничение есть лишь по времени. Но стоит сказать, что это проблема не самих рекурсий, а в принципе алгоритма. Да, конечно при каждом вызове рекурсивная функция добавляется в специальный стек, место в котором ограничено, и если вызовов окажется слишком много, память программы переполнится, что приведёт к ошибке. Но в данном случае всё-таки ошибка в алгоритмах.
