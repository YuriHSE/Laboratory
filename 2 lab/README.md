# Задание (вариант 28)
Даны числа x и y. Определить, принадлежит ли точка с координатами (x,y) заштрихованной области, включая границы.
Оформить первое решение в виде вложенных условных операторов с простыми условиями.
Второе решение должно содержать один условный оператор со сложным логическим условием.
Третье решение должно быть оформлено в виде отдельной функции, вызываемой из основной программы. Функция не содержит условного оператора, а только логическое выражение.
<img width="2000" src="https://github.com/YuriHSE/Laboratory/assets/145991450/f3f72334-7009-4196-bd5e-3e9697da6bbd">
## Решение
#### [Решение](https://github.com/YuriHSE/Laboratory/blob/main/2%20lab/2.1%2B2%2B3.c)
## Тесты
### Тест 1 (1 четверть)
```
Enter the value x and y: 123adDASD 321ADFFSDFDF
Incorrect value, try again: 0.21432 0.145346
Values:
x = 0.214320   
y = 0.145346  
Result of the first decision: the point belongs
Result of the second decision: the point belongs
Result of the third decision: the point belongs                                                                                                                                       
```
В предыдущей лабораторной работе мы попытались настроить безопасный ввод на данных на C, однако у нас был недоработан лишь один случай, когда введённая строка состояла из чисел(только первые элементы) и знаков, однако в этой программе я исправил этот недочёт. Дело всё в работе функции scanf: функция считывает строку посимвольно и отбрасывает несоотвествующие спецификатору значения, но сохраняет их в буфер и передаёт в следующий scanf. В коде программы мы сделали сложное условие на scanf, тем самым каждая предыдущаая функция передаёт несоответсвующие элементы в следующую функцию и выдаёт ошибку, но проблема остаётся с последним значением, поэтому идея заключается в создании стороннего элемента (и сложного условия в начале), которому будут переданы оставшиеся значения от последнего scanf. Поэтому в теле бесконечного цикла(он не сломается, пока не будут выведены полностью соответствующие формату данные), мы создаём новый scanf для какой-то переменной символьного типа данных, а затем осуществляем проверку на её содержимое: если пользователь ввёл все значения правильно, то в данную переменную будет записан "\n" (на моё удивление переход на новую строку тоже где-то хранится, поэтому нельзя было просто проверить выражение на истинность(длину), кстати и этот подход можно назвать ленивым вводом, то есть необязательным), и ломается цикл, если же неправильно, то эти символы будут записаны в нашу переменную, далее чистим буфер от ранее введённых значений и отправляем пользователя "назад". В данном примере был рассмотрен тот самый "плохой" случай. В дальнейших примерах мы будем также рассматривать разные случаи на некорректный ввод данных, но уже не акцентировать на этом внимание.


Теперь перейдём к самой лабораторной работе. Наша задача определить, содержится ли введённая точка в заштрихованной области. Все необходимые способы для решения данной задачи мы сделали в одном файле, соотвественно вывод будет производиться для каждого решения. Теперь рассмотрим 1 четверть нашей системы координат. В первом тесте ввели внутри области, 
### Тест 2
```
Enter the value x and y: йуцв вфывыва
Incorrect value, try again: 0.4 0.2
Values:
x = 0.400000   
y = 0.200000  
Result of the first decision: the point belongs
Result of the second decision: the point belongs
Result of the third decision: the point belongs                                                                                                                                                                                                                                    ```
```
во втором тесте ввели пограничный случай, и вот тут стоит остановиться и задаться вопросом: а безопасно ли сравнение для типа double? С строгим больше и меньше всё понятно(также и с просто двумя числами), а вот с равенством не совсем. Дело в том, что числа с плавающей запятой не могут быть представлены точно, существует некая погрешность(но её, кстати, можно самому задавать), возможно равная 10^-6 или ещё меньше, и если у нас есть некоторое выражение сравнимое с вещественным числом, то мы можем взять модуль от разницы этих чисел и сравнить его со своим "эпсилон", я взял 10^-6. Точно так же мы делаем для выражений в других четвертях.
### Тест 3
```
Enter the value x and y: 12вввфы 12
Incorrect value, try again: 1 1
Values:
x = 1.000000   
y = 1.000000  
Result of the first decision: the point does not belong
Result of the second decision: the point does not belong
Result of the third decision: the point does not belong                                                                                                                                                                   
```
В третьем тесте взяли точку из 1 четверти за пределами заштрихованной области. Далее я приведу такие же примеры из других четвертей, но уже без описания, дабы не повторяться:
### Тест 4 (2 четверть)
```
Enter the value x and y: 0 0.2131
Values:
x = 0.000000   
y = 0.213100  
Result of the first decision: the point belongs
Result of the second decision: the point belongs
Result of the third decision: the point belongs                                                                                                                                                                            
```
### Тест 5
```
Enter the value x and y: -0.33455 0
Values:
x = -0.334550  
y = 0.000000  
Result of the first decision: the point belongs
Result of the second decision: the point belongs
Result of the third decision: the point belongs                                                                                                                                                                         
```
### Тест 6
```
Enter the value x and y: -0.5 0.5
Values:
x = -0.500000  
y = 0.500000  
Result of the first decision: the point does not belong
Result of the second decision: the point does not belong
Result of the third decision: the point does not belong                                                                                                                                                                
```
### Тест 7 (3 четверть)
```
Enter the value x and y: -0.5 -0.5
Values:
x = -0.500000  
y = -0.500000 
Result of the first decision: the point belongs
Result of the second decision: the point belongs
Result of the third decision: the point belongs                                                                                                                                                                            
```
### Тест 8
```
Enter the value x and y: -0.6 -0.8
Values:
x = -0.600000  
y = -0.800000 
Result of the first decision: the point belongs
Result of the second decision: the point belongs
Result of the third decision: the point belongs                                                                                                                                                            
```
### Тест 9
```
Enter the value x and y: -2 -2
Values:
x = -2.000000  
y = -2.000000 
Result of the first decision: the point does not belong
Result of the second decision: the point does not belong
Result of the third decision: the point does not belong                                                                                   
```
### Тест 10 (4 четверть)
```
Enter the value x and y: 0.4 -0.1
Values:
x = 0.400000   
y = -0.100000 
Result of the first decision: the point belongs
Result of the second decision: the point belongs
Result of the third decision: the point belongs                                                                            
```
### Тест 11
```
Enter the value x and y: 0.4 -0.2
Values:
x = 0.400000   
y = -0.200000 
Result of the first decision: the point belongs
Result of the second decision: the point belongs
Result of the third decision: the point belongs                                                                            
```
### Тест 12
```
Enter the value x and y: 2 -2
Values:
x = 2.000000   
y = -2.000000 
Result of the first decision: the point does not belongs
Result of the second decision: the point does not belong
Result of the third decision: the point does not belong                                                                  
```
