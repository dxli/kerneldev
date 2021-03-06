#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>

#include "const.h"

#include "cadmdichild.h"

#include "cad/document/abstractdocument.h"
#include "cad/document/undomanager.h"

#include "imainwindow.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public IMainWindow {
        Q_OBJECT

    public:
        explicit MainWindow(QWidget* parent = 0);
        virtual ~MainWindow();

        int randInt(int low, int high);

        virtual CadMdiChild* createMdiChild();
        virtual CadMdiChild* activeMdiChild() const;
        void updateMenus();
        void setActiveSubWindow(QWidget* window);

    protected:
    private slots:



        void on_actionNew_triggered();
        void on_actionRedo_triggered();
        void on_actionUndo_triggered();
        void on_actionAdd_Random_Circles_triggered();
        void on_actionAdd_Random_Arc_triggered();
        void on_actionClear_Undoable_Stack_triggered();
        void on_actionAdd_Random_Lines_triggered();

    private:
        bool eventFilter(QObject* object, QEvent* event);

        void addToolbars();

    private:
        Ui::MainWindow* ui;
        QSignalMapper* windowMapper;

};

#endif // MAINWINDOW_H
