#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>

#include <QWidget>

class QLineEdit;
class QLabel;
class QPushButton;
class QFrame;

class MainWindow : public QWidget {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void deleteMessages();
    void friendRequest();
    void autoDm();
    void autoMessage();

private:
    QLabel* info_label;
    QFrame* line_break;
    QPushButton* delete_messages;
    QPushButton* friend_request;
    QLineEdit* run_text;
    QLineEdit* message_text;
    QPushButton* auto_dm;
    QPushButton* auto_message;

    int getRuns();
    std::vector<std::string> getMessage();
};

#endif
