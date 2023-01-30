#include <iostream>
#include <QApplication>
#include <QSplitter>
#include<QFileSystemModel>
#include <QTreeView>
#include <QListView>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    QSplitter *splitter = new QSplitter;

    QFileSystemModel *model = new QFileSystemModel;
    model->setRootPath(QDir::currentPath());

    QTreeView *tree = new QTreeView(splitter);
    tree->setModel(model);
    tree->setRootIndex(model->index(QDir::currentPath()));

    QListView *list = new QListView(splitter);
    list->setModel(model);
    list->setRootIndex(model->index(QDir::currentPath()));

    splitter->setWindowTitle("Two views onto the same file system model.");
    splitter->show();

    return app.exec();
}
