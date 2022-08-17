# push_swap

Этот проект включает в себя сортировку данных в стеке с ограниченным набором инструкций и наименьшим количеством ходов.

Цель состоит в том, чтобы отсортировать числа в порядке возрастания в стеке a. Для этого у вас есть следующие операции в вашем распоряжении:
- sa (swap a): поменять местами первые 2 элемента в верхней части стека a. Ничего не делать, если есть только один элемент или его нет.
- sb (swap b): поменять местами первые 2 элемента в верхней части стека b. Ничего не делать, если есть только один элемент или его нет.
- ss : sa и sb одновременно.
- pa (push a): взять первый элемент в верхней части b и поместить его в верхнюю часть a. Ничего не делать, если b пусто.
- pb (push b): взять первый элемент в верхней части a и поместить его в верхнюю часть b. Ничего не делать, если a пусто.
- ra (rotate a): сдвинуть вверх все элементы стека a на 1. Первый элемент становится последним.
- rb (rotate b): сдвинуть вверх все элементы стека b на 1. Первый элемент становится последним.
- rr : ra и rb одновременно.
- rra (reverse rotate a): сдвинуть вниз все элементы стека a на 1. Последний элемент становится первым.
- rrb (reverse rotate b): сдвинуть вниз все элементы стека b на 1. Последний элемент становится первым.
- ррр : рра и ррб одновременно.

Запуск приложения:
Из корневой папки, рядом с файлом Makefile, ввести в терминале команду: make && ./push_swap "последовательность не повторяющихся чисел, разделенных пробелом"
В терминал выводится последовательность комманд сортировки представляющих минимальное количество ходов.

Запуск бонусной части (приложение проверяющее отсортирован ли стек):
push_swap % make bonus && ./push_swap "последовательность не повторяющихся чисел, разделенных пробелом" | ./checker "та же самая последовательность чисел"
В терминал выводится конечный результат проверки (OK - стек отсортирован, NO - стек не отсортирован).