#-------------------------------------------------
#
# Project created by QtCreator 2020-09-23T15:03:46
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Football_Manager1
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    team.cpp \
    player.cpp \
    chooseteamdialog.cpp \
    afterchooseteamdialog.cpp \
    choosegoalkeeperdialog.cpp \
    beforegame1dialog.cpp \
    choosecaptaindialog.cpp \
    choosevicecaptaindialog.cpp \
    beforegame2dialog.cpp \
    beforegame3dialog.cpp \
    beforegame4dialog.cpp \
    beforegame5dialog.cpp \
    aftergamewindialog_1.cpp \
    aftergamewindialog_2.cpp \
    aftergamewindialog_3.cpp \
    aftergamewindialog_4.cpp \
    aftergamefaildialog_1.cpp \
    aftergamefaildialog_2.cpp \
    aftergamefaildialog_3.cpp \
    aftergamefaildialog_4.cpp \
    aftergamefaildialog_5.cpp \
    aftergamedrawdialog_1.cpp \
    aftergamedrawdialog_2.cpp \
    aftergamedrawdialog_3.cpp \
    redcarddialog.cpp \
    currentcommanddialog.cpp \
    changeformationdialog.cpp \
    midtalkdialog.cpp

HEADERS += \
        mainwindow.h \
    team.h \
    player.h \
    chooseteamdialog.h \
    afterchooseteamdialog.h \
    choosegoalkeeperdialog.h \
    beforegame1dialog.h \
    choosecaptaindialog.h \
    choosevicecaptaindialog.h \
    beforegame2dialog.h \
    beforegame3dialog.h \
    beforegame4dialog.h \
    beforegame5dialog.h \
    aftergamewindialog_1.h \
    aftergamewindialog_2.h \
    aftergamewindialog_3.h \
    aftergamewindialog_4.h \
    aftergamefaildialog_1.h \
    aftergamefaildialog_2.h \
    aftergamefaildialog_3.h \
    aftergamefaildialog_4.h \
    aftergamefaildialog_5.h \
    aftergamedrawdialog_1.h \
    aftergamedrawdialog_2.h \
    aftergamedrawdialog_3.h \
    redcarddialog.h \
    currentcommanddialog.h \
    changeformationdialog.h \
    midtalkdialog.h

FORMS += \
        mainwindow.ui \
    chooseteamdialog.ui \
    afterchooseteamdialog.ui \
    choosegoalkeeperdialog.ui \
    beforegame1dialog.ui \
    choosecaptaindialog.ui \
    choosevicecaptaindialog.ui \
    beforegame2dialog.ui \
    beforegame3dialog.ui \
    beforegame4dialog.ui \
    beforegame5dialog.ui \
    aftergamewindialog_1.ui \
    aftergamewindialog_2.ui \
    aftergamewindialog_3.ui \
    aftergamewindialog_4.ui \
    aftergamefaildialog_1.ui \
    aftergamefaildialog_2.ui \
    aftergamefaildialog_3.ui \
    aftergamefaildialog_4.ui \
    aftergamefaildialog_5.ui \
    aftergamedrawdialog_1.ui \
    aftergamedrawdialog_2.ui \
    aftergamedrawdialog_3.ui \
    redcarddialog.ui \
    currentcommanddialog.ui \
    changeformationdialog.ui \
    midtalkdialog.ui

RESOURCES += \
    res.qrc

RC_FILE = FM_icon.rc


