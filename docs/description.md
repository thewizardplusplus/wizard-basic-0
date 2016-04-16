## Wizard BASIC 4

Wizard BASIC 4 &mdash; компилируемый высокоуровневый язык программирования.

### Исходники

Файлы исходного кода должны быть в кодировке ASCII.

### Ключевые слова

11 ключевых слов: `and`, `as`, `define`, `end`, `go to`, `if`, `label`, `let`, `not`, `or`, `then`.

### Типы

#### Числа

Тип: с плавающей запятой, 4 байт.

Копирование: по значению.

Хранение: на стеке.

Определение: `/\d+|(\d+.\d*)|(\d*.\d+)/`.

#### Логические значения

В качестве ложного логического значения принимается число 0.

В качестве истинного логического значения принимаются числа, отличные от 0.

#### Строковые константы

Определение: оператор `"define", identifier, "as", ? /"([^"\\]|(\\(t|n|r|"|\\)))*"/ ?, line break`.

### Операции

Перечислены в порядке убывания приоритета.

Приоритет | Операция | Описание | Ассоциативность
--- | --- | --- | ---
1 | `not` | логическое отрицание | правая
2 | `*` | умножение | левая
2 | `/` | деление | левая
3 | `+` | сложение | левая
3 | `-` | вычитание | левая
4 | `<` | меньше | левая
4 | `>` | больше | левая
5 | `=` | равенство | левая
6 | `and` | конъюнкция | левая
7 | `or` | дизъюнкция | левая

### Вызов функции

```
identifier, "(", [expression, {",", expression}], ")"
```

Является выражением.

### Объявление переменных и присваивание

```
"let", identifier, "=", expression, line break
```

Оператор.

### Управляющие конструкции

#### Метки

Объявление: оператор `"label", identifier, line break`.

Переход: оператор `"go to", identifier, line break`.

#### Условие

```
"if", expression, "then", line break,
	statement, line break
"end", line break
```

Оператор.

### Комментарии

Однострочные: `? /^\s*note(\s[^\n]*)?\n/ ?`.

### Рантайм

* модуль `system`:
	* `Number Exit(Number code)`;
	* модуль `system.io`:
		* `Number ShowNumber(Number number)`;
		* `Number ShowString(String string)`;
* модуль `maths`:
	* `Number Sin(Number number)`;
	* `Number Cos(Number number)`;
	* `Number Tg(Number number)`;
	* `Number Arcsin(Number number)`;
	* `Number Arccos(Number number)`;
	* `Number Arctg(Number number)`;
	* `Number Arctg2(Number y, Number x)`;
	* `Number Pow(Number base, Number exponent)`;
	* `Number Exp(Number number)`;
	* `Number Sqrt(Number number)`;
	* `Number Ln(Number number)`;
	* `Number Lg(Number number)`;
	* `Number Abs(Number number)`;
	* `Number Trunc(Number number)`;
	* `Number Rand(Number number)`.
