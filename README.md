# Шахматы
- я сделал почти все, можно почти полноценно в них играть(насколько это возможно в консольных шахматах), пока что не реализованна рокирова и событие, если пешка дойдет до конца
+ пешка пока что не может первым ходом пройти две клетки(я забыл, что она так умет, в тот момент, когда писал это, но теперь мне лень ... потом сделаю...)
все фигуры умеют ходить
программа пока что никак не регистрирует победу
фигуры разделены на команды, но при вводе не нужно указывать к какой команде принадлежит фигура,
программа сама определит команду и в случае хода на место дружественной фигуры предупредит об этом, а в случае хода на вражескую фигуру уничтожит ее, если
это возможно (например, пешка не всегда уничтожает фигуру, на которую ходит), и сообщит об этом.
* обратите внимание, что не нужно указывать "х", если хотите атаковать, как это сказанно в задании, программа сама поймет, это просто ход или же вы уничтожаете фигуру
после хода программа спросит: "Хотим ли мы продолжить?" если написать какой-нибудь шлак - то программа посчитает, что мы согласны, если написать No/NO/nO/no,
то программа сросит хотим ли мы обнулить доску, если ввести шлак - то программа не станет ничего обнулять, но если согласится, то она сбросит месторасположение всех
фигур до изначальных
Формат ввода:
1. Название фигуры полностью на английском
2. Координаты на которых стоит эта фигура
3. -(дефис)
4. Координаты куда нужно походить
5. ;(точка с запятой)(не знаю точно зачем, но пусть будет, мини отсылка на с++)

Обратите внимание на регистр первой буквы  +  координаты вводятся только с большой буквы (например: А5)   +   без лишних пробелов (позже исправлю)
Названия всех Фигур + Ход, который 100% можно сделать с обновленной доски (когда все фигуры стоят на своих изначальных местах):
-KnightB1-C3;
-QweenD1-D6;
-KingE1-D1; //Если, конечно же, вы уже убрали оттуда ферзя
-BishopC1-E3;
-RookA1-A6;
-PawnA2-A3;

Обратите внимание, что программа позволяет делать ходы сквозь фигуры, такие ходы лежат только на совети "игроков"
вроде ничего не забыл, теперь про сообщения которые программа может выдать:

- **Error: This piece cannot make this move** - Выбранная вами фигура так не ходит, напимер пытаетесь пешко идти вправо и тп
- **Error: Initial data entered incorrectly** - Введенные координаты указывают за пределы доски
- **Error: There is no such figure in this area** - В указанных координатах нет такой фигуры
- **//The enemy figure 'Название фигуры' was destroyed** - Вражеская фигура уничтожена
- **//A friendly figure gets in the way** - Пытаетесь походить туда, где стоит дружественная фигура
- **//A enemy figure gets in the way** - Сообщение только для пешки, уперлись лбом во вражескую фигуру
- **-Error: Expected ';'** - Ожидалась точка с запятой, не спрашивайте зачем, я сам не знаю
- **-Error: Input data limit exceeded** - Введена какая-то хрень, скорее всего ошиблись с регистром
- **Error: The bad name** - Неправильное название фигуры
- **//The move was successful** - Пишет всегда, если все программа выполнилась и ход был сделан
- **//THE END\n//The chess board was destroed"** - Конец партии, или как-то так, выводит только если обнулить доску

с этим вроде все, теперь про функции и тп
 я не очень уверен в том, что нужно было комитить всякие приколы от Visual Studio, но пусть будут
 Все функции в названии которых название фигуры, отвечают за ход этой фигуры
 main - это main, тут все логично
 chess.h - Файл с классом, знали бы сколко времени ушло чтобы это работало...
 ChessPieces.h - Файл с заголовками
 FileWork - отвечает за записи в доску и с доски
ChessBoard - Файл с доской, но он вроде как в игноре, чтобы постоянно не менялся, скорее всего, если его вообще нет или он не правильно заполнен, то будет очень плохо
так как прога в начале работы не проверяет его на наличие чего-либо, а надо бы, но это потом...

MakeFile Вроде работает, но я не совсем понимаю, что именно он делат, если только компилирует, то все ок, ошибок нет, по крайней мере у меня

как-то так :)
ахах, только сейчас замети, что у меня во всем коде вместо Queen написано Qween, но пусть пока будет, так сказать авторское написание

--------

Поменял Qween на Queen
Теперь пробелы при вводе игнорируются
Добавил отслеживание ходов(тепеь ходы делаются строго по очереди)
А еще теперь пешка превращается в ферзя как только дойдет до конца доски 
