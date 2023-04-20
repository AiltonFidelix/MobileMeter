#ifndef MMLINEEDIT_H
#define MMLINEEDIT_H

#include <QObject>
#include <QLineEdit>

class MMLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    MMLineEdit(QWidget *parent = nullptr);
    MMLineEdit(const QString &text, QWidget *parent = nullptr);

protected:
    bool event(QEvent *e) override;

private:
    bool m_moved = false;
    int m_lastDiff = 0;
};

#endif // MMLINEEDIT_H
