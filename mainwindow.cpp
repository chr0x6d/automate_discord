#include <QtWidgets>

#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QWidget(parent) {
    QString q_info = tr(
        "To use this program you must have python3 and pyautogui \'pip install pyautogui\'.\n\n\
This program will only work on 1920x1080 pixel screens and with discord open in full-screen.\n\n\
Discord must be visible on top-left corner of screen before launching a script, to click it into focus.\n\n\
To stop pyautogui running push your cursor to a screen corner repeatedly and the script will stop.\n\n\
BEFORE USE: Hover over button to know what to do before launching script.\n\n\
The script you select will run immediately when you click a button.");

    info_label = new QLabel(q_info);

    line_break = new QFrame();
    line_break->setFixedHeight(10);
    line_break->setFrameShape(QFrame::HLine);
    line_break->setFrameShadow(QFrame::Sunken);

    delete_messages = new QPushButton(tr("Delete Messages"));
    friend_request = new QPushButton(tr("Mass Friend Request"));

    run_text = new QLineEdit();
    message_text = new QLineEdit();

    auto_dm = new QPushButton(tr("Auto DM"));
    auto_message = new QPushButton(tr("Auto Message"));

    QGridLayout *mainLayout = new QGridLayout;

    delete_messages->setToolTip(tr("Will delete messages in the CURRENTLY OPEN discord channel.\nYou must pre-open the dm/server chat you want to clear your messages from."));
    friend_request->setToolTip(tr("Place target server at TOP of your discord server list.\nWill move through the server and friend request users.\nWill scroll past admin/bot accounts to avoid friending them."));
    auto_dm->setToolTip(tr("Place target server at TOP of your discord server list.\nWill move through the server and DM users with the message you set.\nWill scroll past admin/bot accounts to avoid messaging them."));
    auto_message->setToolTip(tr("Will spam messages in the CURRENTLY OPEN discord channel.\nYou must pre-open the dm/server chat you want to spam your set message into."));

    message_text->setPlaceholderText(tr("Set message to use here. Enter comma separated text for multi-line messages (e.g. hey, hello)"));
    run_text->setPlaceholderText(tr("Enter the number of times you want the script to run (leave empty for infinite runs)"));

    mainLayout->addWidget(info_label, 0, 0, 1, 2);
    mainLayout->addWidget(line_break, 1, 0, 1, 2);
    mainLayout->addWidget(delete_messages, 2, 0);
    mainLayout->addWidget(friend_request, 2, 1);
    mainLayout->addWidget(run_text, 3, 0, 1, 2);
    mainLayout->addWidget(message_text, 4, 0, 1, 2);
    mainLayout->addWidget(auto_dm, 5, 0);
    mainLayout->addWidget(auto_message, 5, 1);

    setLayout(mainLayout);

    connect(delete_messages, SIGNAL(released()), this, SLOT(deleteMessages()));
    connect(friend_request, SIGNAL(released()), this, SLOT(friendRequest()));
    connect(auto_dm, SIGNAL(released()), this, SLOT(autoDm()));
    connect(auto_message, SIGNAL(released()), this, SLOT(autoMessage()));

}

MainWindow::~MainWindow() {
    delete info_label;
    delete delete_messages;
    delete friend_request;
    delete message_text;
    delete auto_dm;
    delete auto_message;
}

// Helper Methods
int MainWindow::getRuns() {
    QString q_run = run_text->text();
    return q_run.toInt();
}

std::vector<std::string> MainWindow::getMessage() {
    QString q_msg = message_text->text();
    std::string msg = q_msg.toStdString();

    std::stringstream stream_msg(msg);
    std::vector<std::string> result;

    while (stream_msg.good()) {
        std::string sub;
        getline(stream_msg, sub, ',');
        result.push_back(sub);
    }
    return result;
}

// Button-Specific methods
void MainWindow::deleteMessages() {
    std::string script = "./delete_messages.py ";

    int runs = getRuns();
    script += (std::to_string(runs) + ' ');

    system(script.c_str());
}

void MainWindow::friendRequest() {
    std::string script = "./friend_request.py ";

    int runs = getRuns();
    script += (std::to_string(runs) + ' ');

    system(script.c_str());
}

void MainWindow::autoDm() {
    std::string script = "./auto_dm.py ";
    std::vector<std::string> msgs = getMessage();

    int runs = getRuns();
    script += (std::to_string(runs) + ' ');

    for (std::string str : msgs) {
        script += str;
    }
    system(script.c_str());
}

void MainWindow::autoMessage() {
    std::string script = "./auto_message.py ";
    std::vector<std::string> msgs = getMessage();

    int runs = getRuns();
    script += (std::to_string(runs) + ' ');

    for (std::string str : msgs) {
        script += str;
    }
    system(script.c_str());
}
