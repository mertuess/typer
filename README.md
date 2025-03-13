# Typer
## Описание
---
Typer — это приложение для Linux, предназначенное для улучшения навыков скорописи и тренировки слепой печати. С помощью Typer вы сможете повысить скорость и точность набора текста, а также научиться печатать, не глядя на клавиатуру.

## Установка
### Установка из исходного кода
---
1. Клонируйте репозиторий:
```bash
git clone https://github.com/mertuess/typer.git
cd ./typer
```

2. Установите зависимости:

Ubuntu:
```bash
sudo apt-get install build-essential cmake libncurses5-dev
```

Arch:
```bash
sudo pacman -S build-essential cmake ncurses
```

3. Соберите проект:
```bash
mkdir ./build
cd ./build
cmake ..
make
```

4. Установите приложение:
```bash
sudo make install
```

## Использование
---
После установки запустите приложение из терминала:
```bash
typer
```

## Лицензия
---
Typer распространяется под лицензией MIT. Подробнее см. в файле [LICENSE](../typer/main/LICENSE).

## Обратная связь
Если у вас есть вопросы, предложения или вы обнаружили ошибку, пожалуйста, создайте [issue в репозитории](https://github.com/mertuess/typer/issues).

___

## Description
---
Typer is a Linux application designed to improve your typing speed and accuracy, as well as help you master touch typing. With Typer, you can enhance your keyboard skills, learn to type without looking at the keyboard, and track your progress over time.

## Installation
### Building from source
---
1. Clone the repository:
```bash
git clone https://github.com/mertuess/typer.git
cd ./typer
```

2. Install dependencies:

Ubuntu:
```bash
sudo apt-get install build-essential cmake libncurses5-dev
```

Arch:
```bash
sudo pacman -S build-essential cmake ncurses
```

3. Build the project:
```bash
mkdir ./build
cd ./build
cmake ..
make
```

4. Install the app:
```bash
sudo make install
```

## Using
---
After installation, launch the app from the terminal:
```bash
typer
```

## License
---
Typer is distributed under the MIT License. For more details, see the [LICENSE](../typer/main/LICENSE) file.

## Feedback
---
If you have any questions, suggestions, or bug reports, please open an [issue in the repository](https://github.com/mertuess/typer/issues).
