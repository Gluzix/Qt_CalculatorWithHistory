#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_licz_clicked()
{
    if(ui->linia->text()!="")
    {
        if(counter>0)
        {
            GetValueFromLineEdit();
            switch(operation)
            {
                case 0: History(" "); suma=suma+liczba;break;
                case 1: History(" "); suma=suma-liczba;break;
                case 2: History(" "); suma=suma*liczba;break;
                case 3: History(" "); suma=suma/liczba;break;
                case 4: History(" "); suma = pow(suma, liczba);break;
            }
            linia=QString::number(suma);
            Change_dot_to_przecinek();
            ui->linia->setText(linia);
            linia="";
        }
        counter=0;
    }
}

void MainWindow::on_mnoz_clicked()
{
    History(" * ");
    Operation(2);
}

void MainWindow::on_dziel_clicked()
{
    History(" / ");
    Operation(3);
}

void MainWindow::on_dodaj_clicked()
{
    History(" + ");
    Operation(0);
}

void MainWindow::on_odejmij_clicked()
{
    History(" - ");
    Operation(1);
}

void MainWindow::on_kwadrat_clicked()
{
    History(" ^ ");
    Operation(4);
}

void MainWindow::on_pierwiastek_clicked()
{
    GetValueFromLineEdit();
    liczba=sqrt(liczba);
    linia=QString::number(liczba);
    Change_dot_to_przecinek();
    ui->linia->setText(linia);
    History("√  ");
    Change_przecinek_to_dot();
}

void MainWindow::on_jeden_clicked()
{
    linia=linia+"1";
    ui->linia->setText(linia);
}

void MainWindow::on_dwa_clicked()
{
    linia=linia+"2";
    ui->linia->setText(linia);
}

void MainWindow::on_zero_clicked()
{
    linia=linia+"0";
    ui->linia->setText(linia);
}

void MainWindow::on_trzy_clicked()
{
    linia=linia+"3";
    ui->linia->setText(linia);
}

void MainWindow::on_cztery_clicked()
{
    linia=linia+"4";
    ui->linia->setText(linia);
}

void MainWindow::on_piec_clicked()
{
    linia=linia+"5";
    ui->linia->setText(linia);
}

void MainWindow::on_szesc_clicked()
{
    linia=linia+"6";
    ui->linia->setText(linia);
}

void MainWindow::on_siedem_clicked()
{
    linia=linia+"7";
    ui->linia->setText(linia);
}

void MainWindow::on_osiem_clicked()
{
    linia=linia+"8";
    ui->linia->setText(linia);
}

void MainWindow::on_dziewiec_clicked()
{
    linia=linia+"9";
    ui->linia->setText(linia);
}

void MainWindow::on_przecinek_clicked()
{
    linia=linia+",";
    ui->linia->setText(linia);
}


void MainWindow::on_backspace_clicked()
{
    if(linia!="")
    {
        linia.chop(1);
        ui->linia->setText(linia);
    }
    else
    {
        Messages("Nie ma czego cofac!");
    }
}

void MainWindow::on_clear_clicked()
{
    ui->linia->clear();
    linia="";
    History("\n------------------------\n");
}

void MainWindow::GetValueFromLineEdit()
{
    linia=ui->linia->text();
    Change_przecinek_to_dot();
    liczba=linia.toDouble();
}

void MainWindow::Messages(const char *wiadomosc)
{
    QMessageBox msg;
    msg.setText(wiadomosc);
    msg.exec();
}

void MainWindow::Operation(int x)
{
    if(ui->linia->text()!="")
     {
         GetValueFromLineEdit();
         if(counter==0)
         {
             suma=liczba;
         }
         else if(counter>0)
         {
             if(operation!=x)
             {
                 switch(operation)
                 {
                    case 0: suma=suma+liczba;break;
                    case 1: suma=suma-liczba;break;
                    case 2: suma=suma*liczba;break;
                    case 3: suma=suma/liczba;break;
                    case 4: suma = pow(suma, liczba);break;
                 }
             }
             else
             {
                 switch(x)
                 {
                    case 0: suma=suma+liczba;break;
                    case 1: suma=suma-liczba;break;
                    case 2: suma=suma*liczba;break;
                    case 3: suma=suma/liczba;break;
                    case 4: suma = pow(suma, liczba);break;
                 }
             }
         }
         counter=1;
     }
     else
     {
         Messages("Kurde puste pole!");
     }
        ui->linia->clear();
        linia="";
        operation=x;
}

void MainWindow::History(const char *part)
{
    historia=historia+linia;
    historia=historia+part;
    ui->historia->setPlainText(historia);
}

void MainWindow::Change_dot_to_przecinek()
{
    int length=linia.length();

    for(int i=0; i<length; i++)
    {
        if(linia[i]=='.')
        {
            linia[i]=',';
        }
    }
}

void MainWindow::Change_przecinek_to_dot()
{
    int length=linia.length();
    for(int i=0; i<length; i++)
    {
        if(linia[i]==',')
        {
            linia[i]='.';
        }
    }
}
