#ifndef __ddViewManager_h
#define __ddViewManager_h

#include <QWidget>

class QTabWidget;
class ddViewBase;

class ddViewManager : public QWidget
{
    Q_OBJECT

public:

  ddViewManager(QWidget* parent=0);
  virtual ~ddViewManager();

  QTabWidget* tabWidget() const;

  ddViewBase* findView(const QString& viewName) const;

  ddViewBase* createView(const QString& viewName, const QString& viewType, int pageIndex=-1);

  void switchToView(const QString& viewName);

  ddViewBase* currentView() const;

  QString viewName(ddViewBase* view);

signals:

  void currentViewChanged(ddViewBase* previousView, ddViewBase* currentView);

protected slots:

  void onCurrentTabChanged(int currentIndex);

protected:

  void addDefaultPage();

  void addView(ddViewBase* view, const QString& viewName, int pageIndex=-1);

  class ddInternal;
  ddInternal* Internal;

  Q_DISABLE_COPY(ddViewManager);

};

#endif
