#ifndef BLADE_WINDOW_H
#define BLADE_WINDOW_H

#include <QOpenGLWindow>
#include <QOpenGLFunctions>

class BladeWindow : public QOpenGLWindow,
               protected QOpenGLFunctions
{
  Q_OBJECT

// OpenGL Events
public:
  ~BladeWindow();

  void initializeGL();
  void resizeGL(int width, int height);
  void paintGL();
  void teardownGL();

private:
  // Private Helpers
  void printContextInformation();
};

#endif // BLADE_WINDOW_H
