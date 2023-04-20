#include "mmlineedit.h"

#include <QApplication>

MMLineEdit::MMLineEdit(QWidget *parent)
    :QLineEdit(parent) {
    setAttribute(Qt::WA_InputMethodEnabled, true);
    setInputMethodHints(inputMethodHints() | Qt::InputMethodHint::ImhNone);
}

MMLineEdit::MMLineEdit(const QString& text, QWidget *parent)
    : QLineEdit(text, parent) {
    setAttribute(Qt::WA_InputMethodEnabled, true);
    setInputMethodHints(inputMethodHints() | Qt::InputMethodHint::ImhNone);
}

bool
MMLineEdit::event(QEvent* e) {

    const auto keyboard_rect = QGuiApplication::inputMethod()->keyboardRectangle();
    const auto keyboard_visible = QGuiApplication::inputMethod()->isVisible();
    const auto global_y = QWidget::mapToGlobal(rect().topLeft()).y() + height();
    const auto k_global_y = keyboard_rect.topLeft().y();
    const auto diff = k_global_y - global_y;
    const auto need_to_move = diff < 0;

    /* move main widget */
    if (keyboard_visible && !m_moved && need_to_move) {
        m_moved = true;
        m_lastDiff = diff;
        const auto g = parentWidget()->frameGeometry();
        parentWidget()->move(g.x(), g.y() - qAbs(m_lastDiff));
    }
    /* roll back */
    if (!keyboard_visible && m_moved) {
        m_moved = false;
        const auto g = parentWidget()->frameGeometry();
        parentWidget()->move(g.x(), g.y() + qAbs(m_lastDiff));
    }
    return QLineEdit::event(e);
}
