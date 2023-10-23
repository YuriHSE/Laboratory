# Задание(вариант 28)
Вычислить приближенное значение функции, вычислив сумму конечного числа элементов ряда двумя способами, используя разные типы циклов:
1) С заданной точностью;
2) Для заданного количества членов ряда.
Переход к способу вычисления реализовать с помощью оператора выбора.
<img width="1049" src="https://github.com/YuriHSE/Laboratory/assets/145991450/c00446be-2b06-4dd5-b7ae-7cb04046ff5f">


## Решение
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
Данную задачу можно решить несколькими способами, а именно через циклы и рекурсию. Наш алгоритм позволяет вычислять значение функции и для больших n, так как мы не вычисляем отдельно знаменатель и числитель, а считаем сразу готовое слагаемое путём домножения его на обыкновенну дробь $\frac{2n-1}{2n}$. В данной работе хотелось бы рассмотреть оба подхода, чтобы сравнить полученные результаты и выявить наиболее точный способ. Сразу скажу, что переменные в каждом из способов приведены к соотвественно одинаковым типам данных.
В данном тесте разобран обычный случай с небольшим n через цикл WHILE, полученные ответы совпадают.
### Тест 2
```
Enter the value x, n and accuracy: -0.1231231 30 10
How to calculate a function: through a cycle WHILE or through a cycle FOR, write the number 1 or 2 accordingly
Enter the value: 2
Result through cycles: 1.0679002429
Result through recursion: 1.0679002429                                                                                                                                                      
```
Здесь мы проверили работу через цикл FOR, принцип абсолютно тот же, заодно и обработали отрицательное число.
### Тест 3
```                                            
Enter the value x, n and accuracy: 0.21342432542543 500 20
How to calculate a function: through a cycle WHILE or through a cycle FOR, write the number 1 or 2 accordingly
Enter the value: 1
Result through cycles: 0.90780725982744536751
Result through recursion: 0.90780725982744525648                                                                                                                                                    
```
А вот теперь мы видим расхождение, начиная с $10^{-16}$. Сразу заметим, что использовался цикл WHILE. Давайте приведём ещё один пример:
### Тест 4
```
Enter the value x, n and accuracy: 0.123456789 1000 30
How to calculate a function: through a cycle WHILE or through a cycle FOR, write the number 1 or 2 accordingly
Enter the value: 2
Result through cycles: 0.943456353521454627042430729489
Result through recursion: 0.943456353521454627042430729489                                                                                                                                                
```
А вот здесь ноль отличий, хотя и n большое, и точность высокая. Использовали цикл FOR.
### Тест 5
```
Enter the value x, n and accuracy: 0.23413255636 1500 25
How to calculate a function: through a cycle WHILE or through a cycle FOR, write the number 1 or 2 accordingly
Enter the value: 1
Result through cycles: 0.9001587251863836236509542
Result through recursion: 0.9001587251863831795617443                                                                                          
```
А вот здесь опять расхождение, и снова с $10^{-16}$. Выходит, что проблема кроется в цикле WHILE, хотя с FOR принципы похожие. Такая проблема может возникнуть из-за переполненного стека, ведь какое бы мы не вводили x, отличия начинаются с одного и того же места, возможно причина кроется в копировании нашего n для вычисления вложенного цикла WHILE, и компилятор уже не справляется всё высчитывать с большой точностью.
### Тест 6
```
Enter the value x, n and accuracy: 0.987654321 10000 30
How to calculate a function: through a cycle WHILE or through a cycle FOR, write the number 1 or 2 accordingly
Enter the value: 2
Result through cycles: 0.709299365612989674012567320460
Result through recursion: 0.709299365612989451967962395429                                                                 
                                           
```
Но я решил проверить всё ещё раз и ввести уже гораздо большее n, значение функции считается значительно дольше, но всё равно в рамках 1 секунды. И что мы видим? Теперь и для цикла FOR нашлось расхождение, и на удивление опять с $10^{-16}$. Попробуем ввести то же самое значение для WHILE:
### Тест 7
```
Enter the value x, n and accuracy: 0.987654321 10000 30 
How to calculate a function: through a cycle WHILE or through a cycle FOR, write the number 1 or 2 accordingly
Enter the value: 1
Result through cycles: 0.709299365612986232321190982475
Result through recursion: 0.709299365612989451967962395429                                                                 
```
Полученные значения из рекурсий конечно совпадают, а вот с циклами беда. Мало того что значения не совпадают для точности выше $10^{-12}$, так ещё и с этого места идёт опять расходение с рекурсией. Вобщем работает это очень странно, но что мы можем отметить в итоге: наш алгоритм очень хорош, по сути ограничение есть лишь по времени; в теории решение через циклы дожно быть поточнее, так как при каждом вызове рекурсивная функция добавляется в специальный стек, место в котором ограничено, и если вызовов окажется слишком много, память программы переполнится, что приведёт к ошибке; на небольших значениях n или accuracy всё работает точно и одинаково быстро.

