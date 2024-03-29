# task2.2b

На примере стоек регистрации в аэропорту смоделировать работу простейшей системы балансировки нагрузки, функционирующей по принципу «Power of Two Choices». Стойки регистрации для обслуживания новых пассажиров должны выбираться следующим образом: определяются две случайные стойки регистрации, а среди них выбирается та, очередь к которой является более короткой. Вводится информация о количестве стоек регистрации (целое число) и прибывающих пассажирах. Формат записи, содержащей информацию о пассажире: id/ta/ts, где id — идентификатор пассажира (строка), ta — время прибытия пассажира (натуральное число), ts — время обслуживания пассажира (натуральное число). Пример ввода: 2 a/1/20 b/1/15 c/2/10 d/5/8 e/6/5 f/6/9. Для каждого момента времени, в который изменяется состояние очередей на стойках регистрации, должно быть сформировано текстовое представление их текущего состояния.


Пример вывода:

0 1 2 5

№1 №1 a №1 a c №1 a c

№2 №2 b №2 b   №2 b d

Очередь к каждой стойке регистрации должна быть представлена с помощью логической структуры данных «очередь»

«Работа со стеком, очередью, двусторонней очередью»
Необходимо спроектировать и разработать на языке C библиотеку, реализующую логическую структуру данных «стек», «дек» или «очередь», и прикладную программу, которая её использует. Данные для обработки программой вводятся из входного потока. Каждая строка, вводимая пользователем, должна обрабатываться отдельно. Завершение ввода (завершение работы программы) определяется концом файла.
В ходе выполнения задачи должны быть разработаны:
1. Библиотека, реализующая логическую структуру данных «стек», «дек» или «очередь» на основе вектора и на основе списка. Т.е. должно быть реализовано два варианта решения, если не
указано иное.
2. Прикладная программа, использующая разработанную библиотеку.


Примечания:
1. Библиотека должна состоять из нескольких файлов, среди которых обязательно должен быть заголовочный файл, определяющий интерфейс взаимодействия с разрабатываемой структурой данных. Данный интерфейс должен быть общим для обеих реализаций.
2. Использование глобальных переменных не допускается.
3. Исходные коды должны быть логичным образом разбиты на несколько файлов (необходимо использовать как *.c-файлы, так и *.h-файлы).
4. Выбор конкретной реализации структуры данных должен осуществляться на этапе сборки путём указания соответствующих флагов.
5. Программа должна корректным образом обрабатывать все данные, которые может ввести пользователь.
6. Реализация логической структуры данных «стек», «дек» или «очередь» на основе вектора должна обеспечивать корректную работу в рамках области памяти переменного размера, которая единожды выделяется на этапе создания экземпляра структуры, т.е. при добавлении новых записей может произойти переполнение, данная ситуация должна обрабатываться штатным образом, если в задании не оговорено иное.
7. Использование массивов переменной длины (VLA — variable length arrays) не допускается.
8. Реализация логической структуры «стек», «дек» или «очередь» на основе списка должна обеспечивать корректную работу с произвольным количеством записей, т.е. при добавлении новых записей переполнение невозможно.
9. При реализации на основе списка должно отдаваться предпочтение списочным структурам, использующим меньшее количество памяти — односвязные предпочтительнее двусвязных, кольцевые предпочтительнее линейных, если это целесообразно в контексте задачи.
10. Программа должна корректным образом работать с памятью, для проверки необходимо использовать соответствующие программные средства, например: valgrind, санитайзеры, встроенные в IDE средства.
