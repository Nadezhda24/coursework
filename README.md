***Калькулятор 8-х чисел***
====================================
**Цель** : разработка программы «Калькулятор восьмеричных чисел» на языке С++ с использованием объектно-ориентированного программирования, выполняющей функции традиционного счетного устройства.

-----------
**Задача**:  реализовать  функции традиционного калькулятора : 
* сложение ( + )
* вычитание( - )
* умножение( * )
* деление без остатка ( div )
* деление с остатком ( / ).
По запросу пользователя программа должна отображать подробную
информацию о том, как был сформирован результат в понятном для пользователя виде.
 
 Выражение для вычисления вводится в виде строки, например:
 (042 / 02 + 03 * (045 – 032) – 06).

-------------
 **Программные требования и способ запуска** 
 Для реализации была  выбрана интегрированная среда разработки  С++Builder XE8. 
 Для запуска программы, необходимо установить c++ builder версии XE8, в нем вам нужно открыть проект с помощью раздела File - open project и выбрать Project.cbproj.По открытию проекта выберете раздел Run - Run или нажмите F9.

 -----------------
 ***Описание пользовательского интерфейса***
  При запуске программы пользователь видит перед собой главное окно приложения

 ![calculator] (https://github.com/Nadezhda24/coursework/raw/master/cl.jpg)

  Размер главного окна не изменяем. Интерфейс привычен для пользователя, так как имеет вид стандартного калькулятора.
  Ввод данных может быть выполнен только по нажатию кнопок расположенных на экране. Обозначение кнопок «(»,  «)», «div», «/», « * », «-», «+»,  «.», «0», «1», «2», «3», «4», «5», «6», «7», «8», «9» при нажатии будут выводиться в соответствующее текстовое поле.
  При нажатии «=» пользователь запускает калькулятор. Если строка ввода выражения оказалась пустой, то выведется соответствующее сообщение:

 ![Message missing expression] (https://github.com/Nadezhda24/coursework/raw/master/vv.jpg)

  Так же могут возникнуть ситуации, когда пользователь введет некорректное выражение, которое невозможно подсчитать. В этом случае выведется следующее сообщение и очиститься строка ввода выражения:

  ![Expression error message] (https://github.com/Nadezhda24/coursework/raw/master/vvv.jpg)

  Кнопка «accuracy» позволяет переключить поле ввода выражения, расположенное сверху, в пассивное состояние, тем самым переведя поле ввода точности, расположенное над кнопками, в активное. Выполняется и обратное переключение активности полей. При нажатии этой кнопки поле, в которое пользователь будет вводить выражение, изменяет свой цвет. Данная визуальная подсказка упрощает работу с калькулятором. Если поле ввода точности находится в активном состоянии, то пользователю запрещается вводить какие-либо символы за исключением цифр, находящихся в диапазоне от «1» до «15», в противном случае будет выведено сообщение об ошибке, изображенное на рисунках ниже, в зависимости от ситуации.

  ![Input accuracy error message] (https://github.com/Nadezhda24/coursework/raw/master/vvvv.jpg)

  ![Accuracy message] (https://github.com/Nadezhda24/coursework/raw/master/vvvvv.jpg)

  Кнопка «show» позволяет пользователю посмотреть подробный результат вычислений. По нажатию данной кнопки открывается дочернее окно, размер которого можно менять, при необходимости появляется полоса прокрутки для более удобной работы с окном:

  ![Show] (https://github.com/Nadezhda24/coursework/raw/master/show.jpg)
 
