//2. Написати програму, яка перевіряє користувача на знання таблиці множення. Програма виводить на екран два числа, користувач має ввести їхній добуток.Розробити кілька рівнів складності(відрізняються складністю та кількістю питань).
//Вивести користувачеві оцінку його знань. Єдиною умовою є зчитування даних з файлу і запис даних в файл
#include <iostream>
#include <fstream>
using namespace std;   
int Result(int n, int m, int prod, int mark) {//функція в якій перевіряємо табличку множення та підраховуємо бали
    ifstream fileIn;
    string Path = "C:/Users/Яна/Desktop/table.txt";
    fileIn.open(Path);//відкриваємо файл за вказаним шляхом
    for (int i = 0; i < 12; i++)//використовуємо цикл для перевірки таблиці множення
    {       fileIn >> n;//зчитування даних з файлу-множник
            fileIn >> m;//зчитування даних з файлу-множник
            cout << n << "*" << m << "=";
            cin >> prod;//користувач вводить свій результат
            if (prod != n * m)cout << "Wrong answer. Right is =" << n * m << endl;
            else { cout << "Correct answer!" << endl; mark++; }//за правильні відповіді нараховуємо бали
        if(i==1)cout << "The second degree" << endl;//за допомогою даних умов оголошуємо  рывны перевірки
        if (i == 4)cout << "The third degree" << endl;
        if (i == 8)cout << "The fourth degree" << endl;
    }
    fileIn.close();//закриваємо файл	
    return mark;//функція повертає значення оцінки
}
int main()
{   int mark = 0, prod = 0;//оцынка та значення добутку, яке вводить користувач
    int n = 0, m = 0;//множники
    cout << "If you don't know the multiplication table well, we'll test your knowledge" << endl;
    cout << "Let's start with the first degree" << endl;
    mark = Result(n, m, prod, mark);//звертаємось до функції присвоємо її значення - mark
    ofstream file;
    string path = "C:/Users/Яна/Desktop/point.txt";
    file.open(path);//відкриваємо файл за вказаним шляхом
    if (!file.is_open())cout << "Didn't open" << endl;//якщо файл не видкривається- виводимо повідомлення про це
    else {
        cout << "File is open" << endl;//якщо файл  видкривається- виводимо повідомлення про це
        if (mark<=3) {//ставимо умову згідно якої оцінюємо знання
            file << "You don't know the multiplication table well. You get= " <<mark<<" ball" << endl;//вводимо значення результату у файл
        }
        if (mark <=6 and mark>3) {//ставимо умову згідно якої оцінюємо знання
            file << "You know the multiplication table  not well. You get= " << mark << " ball" << endl;//вводимо значення результату у файл
        }
        if (mark<=9 and mark>6) {//ставимо умову згідно якої оцінюємо знання
            file << "You know the multiplication table not bad. You get= " << mark << " ball" << endl;//вводимо значення результату у файл
        }
        if (mark <= 11 and mark > 9) {//ставимо умову згідно якої оцінюємо знання
            file << "You know the multiplication table almost well. You get= " << mark << " ball" << endl;//вводимо значення результату у файл
        }
        if(mark==12) {//максимальний результат
            file<< "Congradulation! You know multiplication table well. You get the highest ball-"<<mark << endl;//вводимо значення результату у файл
        }
        file.close();//закриваємо файл	
    }
}