#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void GetValueFromLineEdit(); //Jedna funkcja pobierajaca ciag znakow z LINE EDIT.
    void Messages(const char*); //Jedna funkcja korzystajaca z Qmessage Box otrzymujaca wskaznik do tekstu.
    void Operation(int);
    void History(const char*);
    void Change_dot_to_przecinek();
    void Change_przecinek_to_dot();

private slots:
    //Lista funkcji dla przyciskow.
    void on_dodaj_clicked();
    void on_licz_clicked();
    void on_mnoz_clicked();
    void on_odejmij_clicked();
    void on_jeden_clicked();
    void on_dwa_clicked();
    void on_zero_clicked();
    void on_trzy_clicked();
    void on_cztery_clicked();
    void on_piec_clicked();
    void on_szesc_clicked();
    void on_siedem_clicked();
    void on_osiem_clicked();
    void on_dziewiec_clicked();
    void on_dziel_clicked();
    void on_backspace_clicked();
    void on_clear_clicked();
    void on_kwadrat_clicked();
    void on_pierwiastek_clicked();
    void on_przecinek_clicked();

private:
    Ui::MainWindow *ui;
    double liczba, suma;
    int counter=0, operation=0, length_of_line;
    QString historia="";
    QString linia=""; //zmienna Qstring do niej pobierany jest ciag znakow z LINE EDIT.
    //operation:
    /*
    0-dodawanie
    1-odejmowanie
    2-mnozenie
    3-dzielenie
    */
};

#endif // MAINWINDOW_H
